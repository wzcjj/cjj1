struct point3{
    double x,y,z;
    point3(){}
    point3(double x,double y,double z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
};

struct vec3{
    double x,y,z;
    vec3(){}
    vec3(point3 a){
        x=a.x;
        y=a.y;
        z=a.z;
    }
    vec3(double x,double y,double z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    friend vec3 operator+(vec3 a,vec3 b){
        return vec3(a.x+b.x,a.y+b.y,a.z+b.z);
    }
    friend vec3 operator-(vec3 a,vec3 b){
        return vec3(a.x-b.x,a.y-b.y,a.z-b.z);
    }
    friend double operator*(vec3 a,vec3 b){
        return a.x*b.x+a.y*b.y+a.z*b.z;
    }
    friend vec3 operator*(vec3 a,double c){
        return vec3(a.x*c,a.y*c,a.z*c);
    }
    friend vec3 operator/(vec3 a,double c){
        return vec3(a.x/c,a.y/c,a.z/c);
    }
    double len(){
        return sqrt(x*x+y*y+z*z);
    }
    friend double angle(vec3 a,vec3 b){
        return a*b/a.len()/b.len();
    }
    friend vec3 operator%(vec3 a,vec3 b){
        return vec3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
    }
};

vec3 operator-(point3 a,point3 b){
    return vec3(a.x-b.x,a.y-b.y,a.z-b.z);
}

struct plane{
    point3 p0;
    vec3 n;
    plane(){}
    plane(point3 p,vec3 a){
        p0=p;
        n=a/a.len();
    }
    plane(point3 a,point3 b,point3 c){
        vec3 nn=(b-a)%(c-a);
        n=nn/nn.len();
        p0=a;
    }
};