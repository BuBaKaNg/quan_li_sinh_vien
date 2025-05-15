#define PROPERTY(type , name, funcName) \
private: \
    type name; \
    public: \
    type& get##funcName() { return name; } \
    void set##funcName(type value) { name = value; }
