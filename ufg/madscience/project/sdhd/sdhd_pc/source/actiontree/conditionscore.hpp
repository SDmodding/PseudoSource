// File Line: 19
// RVA: 0x2C12B0
const char *__fastcall FalseCondition::GetClassname(FalseCondition *this)
{
  return FalseCondition::sClassName;
}

// File Line: 40
// RVA: 0x31D710
NotCondition *__fastcall NotCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::NotCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &NotCondition::`vftable;
  return (NotCondition *)v1;
}

// File Line: 56
// RVA: 0x31D8B0
ORCondition *__fastcall ORCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::ORCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &ORCondition::`vftable;
  return (ORCondition *)v1;
}

// File Line: 74
// RVA: 0x26E320
__int64 __fastcall DebugTestCondition::GetClassNameUID(DebugTestCondition *this)
{
  return DebugTestCondition::sClassNameUID;
}

// File Line: 95
// RVA: 0x26E380
__int64 __fastcall PrintCondition::GetClassNameUID(PrintCondition *this)
{
  return PrintCondition::sClassNameUID;
}

// File Line: 124
// RVA: 0x31F4F0
void __fastcall QueryCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::QueryCondition", 0i64, 1u);
  if ( v0 )
    QueryCondition::QueryCondition((QueryCondition *)v0);
}

