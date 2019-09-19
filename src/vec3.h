#include <cmath>
#include <stdlib.h>
#include <iostream>

class vec3 {
public:
    vec3() {}
    vec3(float a, float b, float c) {v[0] = a, v[1] = b, v[2] = c;}
    //for position
    inline float x() const { return v[0];} 
    inline float y() const { return v[1];} 
    inline float z() const { return v[2];} 
    //for colors
    inline float r() const { return v[0];} 
    inline float g() const { return v[1];} 
    inline float b() const { return v[2];} 

    inline const vec3& operator + () {return *this;}
    inline vec3& operator - () {return vec3(-v[0], -v[1], -v[2]);}
    inline float operator [] (int i) const {return v[i];}
    inline float& operator [] (int i ) {return v[i];}

    inline vec3& operator += (const vec3& other);
    inline vec3& operator -= (const vec3& other);
    inline vec3& operator *= (const vec3& other);
    inline vec3& operator /= (const vec3& other);

    inline vec3& operator *= (const float para);
    inline vec3& operator /= (const float para);

    inline float square_length() const {
        return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
    }
    inline float length() const {
        return sqrt(square_length());
    }

    inline void make_unit_vector();

    float v[3];
};

inline std::istream& operator>>(std::istream& is, vec& v) {
    is >> v.v[0] >> v.v[1] >> v.v[2];
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const vec& v) {
    os << v.v[0] << v.v[1] << v.v[2];
    return os;
}

inline void vec3::make_unit_vector() {
    float k = 1.0 / length();
    v[0] *= k;
    v[1] *= k;
    v[2] *= k;
}

inline void vec3::operator + (const vec3& v1, const vec3& v2) {
    return vec3(v1[0]+v2[0], v1[1]+v2[1], v1[2]+v2[2]);
}

inline void vec3::operator - (const vec3& v1, const vec3& v2) {
    return vec3(v1[0]-v2[0], v1[1]-v2[1], v1[2]-v2[2]);
}

inline void vec3::operator * (const vec3& v1, const vec3& v2) {
    return vec3(v1[0]*v2[0], v1[1]*v2[1], v1[2]*v2[2]);
}

inline void vec3::operator / (const vec3& v1, const vec3& v2) {
    return vec3(v1[0]/v2[0], v1[1]/v2[1], v1[2]/v2[2]);
}


inline void vec3::operator * (const float p, const vec3& v) {
    return vec3(p*v[0], p*v[1], p*v[2]);
}

inline void vec3::operator * (const vec3& v, const float p) {
    return vec3(p*v[0], p*v[1], p*v[2]);
}

inline void vec3::operator / (const vec3& v, const float p) {
    return vec3(v[0]/p, v[1]/p, v[2]/p);
}

inline float dot(const vec3& v1, const vec3& v2) {
    return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}

inline vec3 cross(const vec3& v1, const vec3& v2) {
    return vec3(v1[1]*v2[2]-v1[2]*v2[1],
                -(v1[0]*v2[2] - v1[2]*v2[0]),
                v1[0]*v2[1] - v1[1]*v2[0]);
}











