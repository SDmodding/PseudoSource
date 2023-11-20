// File Line: 22
// RVA: 0x2C17E0
const char *__fastcall IsNISPlayingCondition::GetClassname(IsNISPlayingCondition *this)
{
  return IsNISPlayingCondition::sClassName;
}

// File Line: 38
// RVA: 0x31BC00
void __fastcall IsNISPlayingActionCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::IsNISPlayingActionCondition", 0i64, 1u);
  if ( v0 )
    IsNISPlayingActionCondition::IsNISPlayingActionCondition((IsNISPlayingActionCondition *)v0);
}

// File Line: 53
// RVA: 0x2BEB10
__int64 __fastcall IsNISControlledCondition::GetClassNameUID(IsNISControlledCondition *this)
{
  return IsNISControlledCondition::sClassNameUID;
}

// File Line: 70
// RVA: 0x2C17F0
const char *__fastcall IsNISSeamlessInCondition::GetClassname(IsNISSeamlessInCondition *this)
{
  return IsNISSeamlessInCondition::sClassName;
}

// File Line: 86
// RVA: 0x2C1800
const char *__fastcall IsNISSeamlessOutCondition::GetClassname(IsNISSeamlessOutCondition *this)
{
  return IsNISSeamlessOutCondition::sClassName;
}

// File Line: 102
// RVA: 0x31BBB0
void __fastcall IsNISPlayerControllableCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::IsNISPlayerControllableCondition",
         0i64,
         1u);
  if ( v0 )
    IsNISPlayerControllableCondition::IsNISPlayerControllableCondition((IsNISPlayerControllableCondition *)v0);
}

