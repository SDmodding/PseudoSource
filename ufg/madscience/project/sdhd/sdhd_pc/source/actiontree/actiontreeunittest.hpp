// File Line: 27
// RVA: 0x296760
void __fastcall TestClassA::~TestClassA(TestClassA *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&TestClassA::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 36
// RVA: 0x297250
const char *__fastcall TestClassB::GetClassname(TestClassB *this)
{
  return TestClassB::sClassName;
}

// File Line: 50
// RVA: 0x297260
const char *__fastcall TestClassC::GetClassname(TestClassC *this)
{
  return TestClassC::sClassName;
}

