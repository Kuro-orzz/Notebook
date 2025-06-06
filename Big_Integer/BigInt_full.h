#include "../template.h"

const int BASE_DIGITS = 9;
const int BASE = 1'000'000'000;

class BigInt {
public:
    int sign;
    vector<uint32_t> digit;

    BigInt(): sign(1) {}

    BigInt(const string &s) { *this = s; }

    BigInt(int64_t val) { *this = val; }

    BigInt &operator = (const BigInt &b) {
        sign = b.sign;
        digit = b.digit;
        return *this;
    }

    BigInt &operator = (const string &s) {
        read(s);
        return *this;
    }

    BigInt &operator = (int64_t val) {
        sign = val >= 0 ? 1 : -1;
        val = llabs(val);
        digit.clear();
        for (; val; val /= BASE) {
            digit.push_back(val % BASE);
        }
        return *this;
    }

    BigInt &operator += (const BigInt &b) {
        if (sign != b.sign) {
            BigInt t = b;
            t.sign *= -1;
            return *this -= t;
        }
        int carry = 0, len = (int)max(size(), b.size());
        for (size_t i = 0; i < len; i++) {
            int sum = carry;
            if (i < size()) sum += digit[i];
            if (i < b.size()) sum += b[i];
            if (i < size()) digit[i] = sum % BASE;
            else digit.push_back(sum % BASE);
            carry = sum / BASE;
        }
        if (carry) digit.push_back(carry);
        trim();
        return *this;
    }

    BigInt &operator -= (const BigInt &b) {
        if (sign != b.sign) {
            return *this += (-b);
        }
        if (__compare_abs(b) == -1) {
            BigInt t = b;
            t -= *this;
            t.sign *= -1;
            return *this = t;
        }
        int borrow = 0, len = (int)max(size(), b.size());
        for (size_t i = 0; i < len; i++) {
            int sub = -borrow;
            if (i < size()) sub += digit[i];
            if (i < b.size()) sub -= b[i];
            if (sub < 0) sub += BASE, borrow = 1;
            else borrow = 0;
            digit[i] = sub;
        }
        trim();
        return *this;
    }

    BigInt &operator *= (const BigInt &b) {
        return *this = karatsuba(*this, b);
    }

    // BigInt += Int
    BigInt &operator += (int64_t t) { return *this += BigInt(t); }
    BigInt &operator -= (int64_t t) { return *this -= BigInt(t); }
    BigInt &operator *= (int64_t t) { return *this *= BigInt(t); }

    BigInt operator - () const { 
        BigInt res = *this;
        if (!res.isZero()) res.sign *= -1;
        return res;
    } // -a;
    BigInt operator + () const { return BigInt(*this); } // +a;
    BigInt &operator ++ () { *this += 1; return *this; } // ++a;
    BigInt &operator -- () { *this -= 1; return *this; } // --a;
    BigInt operator ++ (int) {BigInt res = *this; *this += 1; return res;} // a++;
    BigInt operator -- (int) {BigInt res = *this; *this -= 1; return res;} // a--;

    // BigInt = BigInt + BigInt
    BigInt operator + (const BigInt &b) const { return BigInt(*this) += b; }
    BigInt operator - (const BigInt &b) const { return BigInt(*this) -= b; }
    BigInt operator * (const BigInt &b) const { return BigInt(*this) *= b; }

    // BigInt = BigInt + Int
    BigInt operator + (int64_t t) const { return BigInt(*this) += t; }
    BigInt operator - (int64_t t) const { return BigInt(*this) -= t; }
    BigInt operator * (int64_t t) const { return BigInt(*this) *= t; }

    // BigInt = Int + BigInt
    friend BigInt operator + (int64_t t, const BigInt &b) { BigInt res(t); res += b; return res; }
    friend BigInt operator - (int64_t t, const BigInt &b) { BigInt res(t); res -= b; return res; }
    friend BigInt operator * (int64_t t, const BigInt &b) { BigInt res(t); res *= b; return res; }

    uint32_t operator [] (const int i) const { assert(i >= 0 && i < size()); return digit[i]; }
    uint32_t &operator [] (const int i) { assert(i >= 0 && i < size()); return digit[i]; }

    // ------------------------- Comparison ---------------------
    bool operator < (const BigInt &b) const {
        if (sign != b.sign) {
            return sign < b.sign;
        }
        if (size() != b.size()) {
            return size() * sign < b.size() * b.sign;
        }
        for (int i = (int)size() - 1; i >= 0; i--) {
            if ((*this)[i] != b[i]) {
                return (*this)[i] * sign < b[i] * sign;
            }
        }
        return false;
    }

    bool operator > (const BigInt &b) const { return b < *this; }
    bool operator <= (const BigInt &b) const { return !(b < *this); }
    bool operator >= (const BigInt &b) const { return !(*this < b); }
    bool operator == (const BigInt &b) const { return !(*this < b) && !(b < *this); }
    bool operator != (const BigInt &b) const { return *this < b || b < *this; }

    bool operator == (int64_t t) const { return *this == BigInt(t); }
    bool operator != (int64_t t) const { return *this != BigInt(t); }
    bool operator < (int64_t t) const { return *this < BigInt(t); }
    bool operator <= (int64_t t) const { return *this <= BigInt(t); }
    bool operator > (int64_t t) const { return *this > BigInt(t); }
    bool operator >= (int64_t t) const { return *this >= BigInt(t); }

    // 0 if |a| == |b|
    // -1 if |a| < |b|
    // 1 if |a| > |b|
    int __compare_abs(const BigInt &b) {
        if (size() != b.size()) {
            return size() < b.size() ? -1 : 1;
        }
        for (int i = (int)size() - 1; i >= 0; i--) {
            if ((*this)[i] != b[i]) {
                return (*this)[i] < b[i] ? -1 : 1;
            }
        }
        return 0;
    }

    // -------------------- karatsuba ---------------------
    BigInt mul_simple(const BigInt &a, const BigInt &b) {
        BigInt x = a, y = b;
        BigInt res;
        res.sign = x.sign * y.sign;
        res.digit.resize(x.size() + y.size());
        for (int i = 0; i < (int)x.size(); i++) {
            uint64_t carry = 0;
            for (int j = 0; j < (int)y.size(); j++) {
                uint64_t cur = res[i+j] + carry;
                cur += 1ull * x[i] * y[j];
                res[i+j] = cur % BASE;
                carry = cur / BASE;
            }
            if (carry) res[i+(int)y.size()] += carry;
        }
        res.trim();
        if (res.isZero()) res.sign = 1;
        return res;
    }

    BigInt shifted(int k) const {
        if (isZero()) return *this;
        BigInt r = *this;
        r.digit.insert(r.digit.begin(), k, 0);
        return r;
    }

    BigInt karatsuba(const BigInt &a, const BigInt &b) {
        if (a.size() < 32 || b.size() < 32) {
            return mul_simple(a, b);
        }
        size_t n = max(a.size(), b.size());
        size_t k = n / 2;

        BigInt a_low, a_high, b_low, b_high;
        int m1 = min(k, a.size()), m2 = min(k, b.size());
        a_low.digit.assign(a.digit.begin(), a.digit.begin() + m1);
        a_high.digit.assign(a.digit.begin() + m1, a.digit.end());
        b_low.digit.assign(b.digit.begin(), b.digit.begin() + m2);
        b_high.digit.assign(b.digit.begin() + m2, b.digit.end());
        a_low.sign = a_high.sign = b_low.sign = b_high.sign = 1;
        a_low.trim(); a_high.trim();
        b_low.trim(); b_high.trim();


        BigInt z0 = karatsuba(a_low, b_low);
        BigInt z1 = karatsuba(a_high, b_high);
        BigInt z2 = karatsuba(a_low + a_high, b_low + b_high) - z1 - z0;
        BigInt res = z1.shifted(2 * k) + z2.shifted(k) + z0;
        res.trim();
        res.sign = (a.sign != b.sign ? -1 : 1);
        return res;
    }

    // ------------------------- Misc ---------------------------
    size_t size() const { return digit.size(); }

    bool isZero() const { return digit.empty(); }

    void trim() {
        while (!digit.empty() && !digit.back()) {
            digit.pop_back();
        }
        if (digit.empty()) sign = 1;
    }

    // ---------------------- Input Output ---------------------
    /* only use for decim number */
    void read(const string &s) {
        sign = (s[0] == '-' ? -1 : 1);
        digit.clear();
        int pos = (s[0] == '-' ? 1 : 0);
        for (int i = (int)s.size() - 1; i >= pos; i -= BASE_DIGITS) {
            int x = 0;
            int k = max(pos, i - BASE_DIGITS + 1);
            for (int j = k; j <= i; j++) {
                x = x * 10 + (s[j] - '0');
            }
            digit.push_back(x);
        }
        trim();
    }

    friend istream &operator >> (istream &in, BigInt &a) {
        string s; in >> s;
        a.read(s);
        return in;
    }

    friend ostream &operator << (ostream &out, const BigInt &a) {
        if (a.sign == -1 && !a.isZero()) out << '-';
        out << (a.digit.empty() ? 0 : a.digit.back());
        for (int i = (int)a.size() - 2; i >= 0; i--)
            out << setw(BASE_DIGITS) << setfill('0') << a[i];
        return out;
    }
};