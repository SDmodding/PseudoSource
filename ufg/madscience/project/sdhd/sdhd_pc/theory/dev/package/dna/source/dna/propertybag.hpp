// File Line: 329
// RVA: 0x1A5550
UFG::qString *__fastcall DNA::PropertyData::GetName(DNA::PropertyData *this, UFG::qString *result)
{
  UFG::qString *v2; // rbx

  v2 = result;
  UFG::qString::qString(result, &this->mName);
  return v2;
}

// File Line: 397
// RVA: 0x1A3F90
void __fastcall DNA::PropertyData::SetValueAction::SetValueAction(DNA::PropertyData::SetValueAction *this, DNA::PropertyData::Value *value)
{
  DNA::PropertyData::Value *v2; // rbx
  DNA::PropertyData::SetValueAction *v3; // rdi
  UFG::qNode<DNA::IAction,DNA::IAction> *v4; // rax

  v2 = value;
  v3 = this;
  v4 = (UFG::qNode<DNA::IAction,DNA::IAction> *)&this->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  this->vfptr = (DNA::IActionVtbl *)&DNA::IAction::`vftable';
  this->mIsValid = 1;
  *(_QWORD *)&this->mTypeId = 724266166i64;
  this->vfptr = (DNA::IActionVtbl *)&DNA::PropertyData::SetValueAction::`vftable';
  UFG::qString::qString(&this->mOldValue, &value->mData);
  UFG::qString::qString(&v3->mNewValue);
  v3->mValue = v2;
}

// File Line: 420
// RVA: 0x1A41E0
void __fastcall DNA::PropertyData::AddValueAction::~AddValueAction(DNA::PropertyData::AddValueAction *this)
{
  DNA::PropertyData::AddValueAction *v1; // rbx
  DNA::PropertyData::Value *v2; // rdi
  UFG::qNode<DNA::IAction,DNA::IAction> *v3; // rdx
  UFG::qNode<DNA::IAction,DNA::IAction> *v4; // rcx
  UFG::qNode<DNA::IAction,DNA::IAction> *v5; // rax

  v1 = this;
  this->vfptr = (DNA::IActionVtbl *)&DNA::PropertyData::AddValueAction::`vftable';
  if ( this->mState == 2 )
  {
    v2 = this->mValue;
    if ( v2 )
    {
      DNA::PropertyData::Value::~Value(this->mValue);
      operator delete[](v2);
    }
  }
  v1->vfptr = (DNA::IActionVtbl *)&DNA::IAction::`vftable';
  v3 = (UFG::qNode<DNA::IAction,DNA::IAction> *)&v1->mPrev;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
}

