// File Line: 25
// RVA: 0x29D230
void __fastcall Phoneme::~Phoneme(Phoneme *this)
{
  UFG::qNode<Phoneme,Phoneme> *v1; // r8
  UFG::qNode<Phoneme,Phoneme> *v2; // rdx
  UFG::qNode<Phoneme,Phoneme> *v3; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Phoneme::`vftable';
  v1 = (UFG::qNode<Phoneme,Phoneme> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = this->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 30
// RVA: 0x2C3290
float __fastcall Phoneme::GetTime(TimePlotPoint *this)
{
  return this->mTimeValue;
}

// File Line: 50
// RVA: 0x2BF180
__int64 __fastcall Phoneme_Ee::GetClassNameUID(Phoneme_Ee *this)
{
  return Phoneme_Ee::sClassNameUID;
}

// File Line: 51
// RVA: 0x2C3150
const char *__fastcall Phoneme_Ee::GetMorphTargetModelSig(Phoneme_Ee *this)
{
  return "_EE";
}

// File Line: 52
// RVA: 0x2C3220
__int64 __fastcall Phoneme_Ee::GetPhonemeIndex(Phoneme_Ee *this)
{
  return (unsigned int)Phoneme_Ee::sPhonemeIndex;
}

// File Line: 65
// RVA: 0x5994D0
Phoneme_Eh *__fastcall Phoneme_Eh::Create()
{
  char *v0; // rcx
  _QWORD *v1; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x28ui64, "MemberMap::Phoneme_Eh", 0i64, 1u);
  if ( !v0 )
    return 0i64;
  *(_QWORD *)v0 = &Expression::IMemberMap::`vftable';
  *((_QWORD *)v0 + 1) = 0i64;
  v1 = v0 + 16;
  *v1 = v1;
  v1[1] = v1;
  *(_QWORD *)v0 = &Phoneme::`vftable';
  *((_DWORD *)v0 + 8) = 0;
  *(_QWORD *)v0 = &Phoneme_Eh::`vftable';
  return (Phoneme_Eh *)v0;
}

// File Line: 66
// RVA: 0x2C3160
const char *__fastcall Phoneme_Eh::GetMorphTargetModelSig(Phoneme_Eh *this)
{
  return "_EH";
}

// File Line: 67
// RVA: 0x2C3230
__int64 __fastcall Phoneme_Eh::GetPhonemeIndex(Phoneme_Eh *this)
{
  return (unsigned int)Phoneme_Eh::sPhonemeIndex;
}

// File Line: 80
// RVA: 0x2BF1D0
__int64 __fastcall Phoneme_Rr::GetClassNameUID(Phoneme_Rr *this)
{
  return Phoneme_Rr::sClassNameUID;
}

// File Line: 81
// RVA: 0x2C31A0
const char *__fastcall Phoneme_Rr::GetMorphTargetModelSig(Phoneme_Rr *this)
{
  return "_RR";
}

// File Line: 82
// RVA: 0x2C3270
__int64 __fastcall Phoneme_Rr::GetPhonemeIndex(Phoneme_Rr *this)
{
  return (unsigned int)Phoneme_Rr::sPhonemeIndex;
}

// File Line: 95
// RVA: 0x2BF1A0
__int64 __fastcall Phoneme_Fr::GetClassNameUID(Phoneme_Fr *this)
{
  return Phoneme_Fr::sClassNameUID;
}

// File Line: 96
// RVA: 0x2C3170
const char *__fastcall Phoneme_Fr::GetMorphTargetModelSig(Phoneme_Fr *this)
{
  return "_FR";
}

// File Line: 97
// RVA: 0x2C3240
__int64 __fastcall Phoneme_Fr::GetPhonemeIndex(Phoneme_Fr *this)
{
  return (unsigned int)Phoneme_Fr::sPhonemeIndex;
}

// File Line: 110
// RVA: 0x2C1E50
const char *__fastcall Phoneme_Mm::GetClassname(Phoneme_Mm *this)
{
  return Phoneme_Mm::sClassName;
}

// File Line: 111
// RVA: 0x2C3180
const char *__fastcall Phoneme_Mm::GetMorphTargetModelSig(Phoneme_Mm *this)
{
  return "_MM";
}

// File Line: 112
// RVA: 0x2C3250
__int64 __fastcall Phoneme_Mm::GetPhonemeIndex(Phoneme_Mm *this)
{
  return (unsigned int)Phoneme_Mm::sPhonemeIndex;
}

// File Line: 126
// RVA: 0x2BF160
__int64 __fastcall Phoneme_A0::GetClassNameUID(Phoneme_A0 *this)
{
  return Phoneme_A0::sClassNameUID;
}

// File Line: 127
// RVA: 0x2C3130
const char *__fastcall Phoneme_A0::GetMorphTargetModelSig(Phoneme_A0 *this)
{
  return "_A0";
}

// File Line: 128
// RVA: 0x2C3200
__int64 __fastcall Phoneme_A0::GetPhonemeIndex(Phoneme_A0 *this)
{
  return (unsigned int)Phoneme_A0::sPhonemeIndex;
}

// File Line: 141
// RVA: 0x2BF170
__int64 __fastcall Phoneme_AA::GetClassNameUID(Phoneme_AA *this)
{
  return Phoneme_AA::sClassNameUID;
}

// File Line: 142
// RVA: 0x2C3140
const char *__fastcall Phoneme_AA::GetMorphTargetModelSig(Phoneme_AA *this)
{
  return "_AA";
}

// File Line: 143
// RVA: 0x2C3210
__int64 __fastcall Phoneme_AA::GetPhonemeIndex(Phoneme_AA *this)
{
  return (unsigned int)Phoneme_AA::sPhonemeIndex;
}

// File Line: 156
// RVA: 0x2BF1C0
__int64 __fastcall Phoneme_OW::GetClassNameUID(Phoneme_OW *this)
{
  return Phoneme_OW::sClassNameUID;
}

// File Line: 157
// RVA: 0x2C3190
const char *__fastcall Phoneme_OW::GetMorphTargetModelSig(Phoneme_OW *this)
{
  return "_OW";
}

// File Line: 158
// RVA: 0x2C3260
__int64 __fastcall Phoneme_OW::GetPhonemeIndex(Phoneme_OW *this)
{
  return (unsigned int)Phoneme_OW::sPhonemeIndex;
}

