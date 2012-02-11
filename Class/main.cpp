#include<iostream>
using namespace std;

#define PP(MSG) std::cout << ":" << __LINE__ << ": " << MSG << std::endl

class A{
public:
  explicit A(const std::string &n) : name(n){ PP("'" << name << "' constructor"); }
  ~A(){ PP("'" << name << "' de"); }
  A(const A &obj) : name(obj.name){ PP("'" << name << "' copy constructor"); }
  A &operator=(const A &obj){ PP("'" << name << "' = " << obj.name); name = obj.name; return *this; }
public:
  std::string name;
};

A global("global");

A getA(){ return global; }
A &getRef(){ return global; }

A getB(){ return A("inB"); }
//A &getRefB(){ return A("inB"); } // �ꎞ�ϐ� -> �Q�Ƃ͕Ԃ��Ȃ�

int main(){

#if 0
  A a  = getA();   // copy -> cost 1
  // A &b = getA();   // �G���[
  A c  = getRef(); // copy -> cost 1
  A &d = getRef(); // �Q�Ɠn�� -> cost 0
#endif

  A a  = getB();   // getB() ���ŃR���X�g���N�^1�� -> cost 1
  // A &b = getB();   // �G���[
  A c  = getRefBc();   // getB() ���ŃR���X�g���N�^1�� -> cost 1
  A &d = getRefBc();   // �G���[


  return 0;
}
