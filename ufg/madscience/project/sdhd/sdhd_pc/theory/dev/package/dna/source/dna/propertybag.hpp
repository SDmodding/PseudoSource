// File Line: 329
// RVA: 0x1A5550
UFG::qString *__fastcall DNA::PropertyData::GetName(DNA::PropertyData *this, UFG::qString *result)
{
  UFG::qString::qString(result, &this->mName);
  return result;
}

// File Line: 397
// RVA: 0x1A3F90
void __fastcall DNA::PropertyData::SetValueAction::SetValueAction(
        DNA::PropertyData::SetValueAction *this,
        DNA::PropertyData::Value *value)
{
  this->mPrev = &this->UFG::qNode<DNA::IAction,DNA::IAction>;
  this->mNext = &this->UFG::qNode<DNA::IAction,DNA::IAction>;
  this->vfptr = (DNA::IActionVtbl *)&DNA::IAction::`vftable;
  this->mIsValid = 1;
  *(_QWORD *)&this->mTypeId = 724266166i64;
  this->vfptr = (DNA::IActionVtbl *)&DNA::PropertyData::SetValueAction::`vftable;
  UFG::qString::qString(&this->mOldValue, &value->mData);
  UFG::qString::qString(&this->mNewValue);
  this->mValue = value;
}

// File Line: 420
// RVA: 0x1A41E0
void __fastcall DNA::PropertyData::AddValueAction::~AddValueAction(DNA::PropertyData::AddValueAction *this)
{
  DNA::PropertyData::Value *mValue; // rdi
  UFG::qNode<DNA::IAction,DNA::IAction> *mPrev; // rcx
  UFG::qNode<DNA::IAction,DNA::IAction> *mNext; // rax

  this->vfptr = (DNA::IActionVtbl *)&DNA::PropertyData::AddValueAction::`vftable;
  if ( this->mState == F3_1Pt44_512 )
  {
    mValue = this->mValue;
    if ( mValue )
    {
      DNA::PropertyData::Value::~Value(this->mValue);
      operator delete[](mValue);
    }
  }
  this->vfptr = (DNA::IActionVtbl *)&DNA::IAction::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<DNA::IAction,DNA::IAction>;
  this->mNext = &this->UFG::qNode<DNA::IAction,DNA::IAction>;
}

