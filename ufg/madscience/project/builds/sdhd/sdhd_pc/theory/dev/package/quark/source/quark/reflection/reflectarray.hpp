// File Line: 64
// RVA: 0x9B020
void __fastcall UFG::qReflectArray<UFG::StateMachineNode::FractureElementNode>::~qReflectArray<UFG::StateMachineNode::FractureElementNode>(
        UFG::qReflectArray<UFG::PhysicsObjectProperties::UserProperty> *this)
{
  UFG::PhysicsObjectProperties::UserProperty *mItems; // rcx
  unsigned int *p_mValue; // rbx

  if ( (this->mData.mFlags & 2) == 0 )
  {
    mItems = this->mData.mItems;
    if ( mItems )
    {
      p_mValue = &mItems[-1].mValue;
      `eh vector destructor iterator(mItems, 8ui64, mItems[-1].mValue, (void (__fastcall *)(void *))_);
      operator delete[](p_mValue);
    }
  }
  this->mData.mItems = 0i64;
  *(_QWORD *)&this->mData.mNumItems = 0i64;
}

// File Line: 187
// RVA: 0xB02E0
void __fastcall UFG::qReflectArray<char>::Resize(
        UFG::qReflectArray<char> *this,
        unsigned int newSize,
        const char *reason)
{
  char *v3; // rsi
  char *v6; // rax
  unsigned int mNumItems; // edx
  unsigned int v8; // ecx
  char *v9; // rdx
  __int64 v10; // r8
  __int64 v11; // r9

  v3 = 0i64;
  if ( newSize )
  {
    v6 = UFG::qMalloc(newSize, reason, 0i64);
    mNumItems = this->mData.mNumItems;
    v3 = v6;
    if ( mNumItems )
    {
      v8 = newSize;
      if ( mNumItems < newSize )
        v8 = this->mData.mNumItems;
      if ( v8 )
      {
        v9 = v6;
        v10 = 0i64;
        v11 = v8;
        do
        {
          *v9++ = this->mData.mItems[v10++];
          --v11;
        }
        while ( v11 );
      }
    }
  }
  if ( this->mData.mItems && (this->mData.mFlags & 2) == 0 )
    operator delete[](this->mData.mItems);
  this->mData.mItems = v3;
  this->mData.mNumItems = newSize;
  this->mData.mFlags = 0;
}

