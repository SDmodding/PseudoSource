// File Line: 24
// RVA: 0x31D330
void __fastcall MotionPhase::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x28ui64, "MemberMap::MotionPhase", 0i64, 1u);
  if ( v0 )
    MotionPhase::MotionPhase((MotionPhase *)v0);
}

// File Line: 58
// RVA: 0x2BE6A0
__int64 __fastcall FootStepLeftCondition::GetClassNameUID(FootStepLeftCondition *this)
{
  return FootStepLeftCondition::sClassNameUID;
}

// File Line: 89
// RVA: 0x2BE6C0
__int64 __fastcall FootStepRightCondition::GetClassNameUID(FootStepRightCondition *this)
{
  return FootStepRightCondition::sClassNameUID;
}

// File Line: 118
// RVA: 0x315180
void __fastcall AnimationFrameCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::AnimationFrameCondition", 0i64, 1u);
  if ( v0 )
    AnimationFrameCondition::AnimationFrameCondition((AnimationFrameCondition *)v0);
}

// File Line: 146
// RVA: 0x2C0810
const char *__fastcall AnimationBankRequestCondition::GetClassname(AnimationBankRequestCondition *this)
{
  return AnimationBankRequestCondition::sClassName;
}

// File Line: 184
// RVA: 0x2BDBB0
__int64 __fastcall AnimationRequiredIsLoadedCondition::GetClassNameUID(AnimationRequiredIsLoadedCondition *this)
{
  return AnimationRequiredIsLoadedCondition::sClassNameUID;
}

