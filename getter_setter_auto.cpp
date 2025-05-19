#define PROPERTY(type , name, funcName) \
public: \
    type name; \
    public: \
    type& get##funcName() { return name; } \
    void set##funcName(type value) { name = value; }
