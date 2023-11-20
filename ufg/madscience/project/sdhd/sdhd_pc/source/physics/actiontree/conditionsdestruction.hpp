// File Line: 18
// RVA: 0x27BFA0
__int64 __fastcall DestructionDamageCondition::GetClassNameUID(DestructionDamageCondition *this)
{
  return DestructionDamageCondition::sClassNameUID;
}

// File Line: 48
// RVA: 0x318660
void __fastcall DestructionFractureCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::DestructionFractureCondition",
         0i64,
         1u);
  if ( v0 )
    DestructionFractureCondition::DestructionFractureCondition((DestructionFractureCondition *)v0);
}

