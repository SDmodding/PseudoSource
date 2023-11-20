// File Line: 64
// RVA: 0x9B020
void __fastcall UFG::qReflectArray<UFG::StateMachineNode::FractureElementNode>::~qReflectArray<UFG::StateMachineNode::FractureElementNode>(UFG::qReflectArray<UFG::PhysicsObjectProperties::UserProperty> *this)
{
  UFG::qReflectArray<UFG::PhysicsObjectProperties::UserProperty> *v1; // rdi
  UFG::PhysicsObjectProperties::UserProperty *v2; // rcx
  unsigned int *v3; // rbx

  v1 = this;
  if ( !(this->mData.mFlags & 2) )
  {
    v2 = this->mData.mItems;
    if ( v2 )
    {
      v3 = &v2[-1].mValue;
      `eh vector destructor iterator(v2, 8ui64, v2[-1].mValue, (void (__fastcall *)(void *))_);
      operator delete[](v3);
    }
  }
  v1->mData.mItems = 0i64;
  *(_QWORD *)&v1->mData.mNumItems = 0i64;
}

// File Line: 187
// RVA: 0xB02E0
void __fastcall UFG::qReflectArray<char>::Resize(UFG::qReflectArray<char> *this, unsigned int newSize, const char *reason)
{
  char *v3; // rsi
  unsigned int v4; // edi
  UFG::qReflectArray<char> *v5; // rbx
  char *v6; // rax
  unsigned int v7; // edx
  unsigned int v8; // ecx
  char *v9; // rdx
  __int64 v10; // r8
  __int64 v11; // r9

  v3 = 0i64;
  v4 = newSize;
  v5 = this;
  if ( newSize )
  {
    v6 = UFG::qMalloc(newSize, reason, 0i64);
    v7 = v5->mData.mNumItems;
    v3 = v6;
    if ( v7 )
    {
      v8 = v4;
      if ( v7 < v4 )
        v8 = v5->mData.mNumItems;
      if ( v8 )
      {
        v9 = v6;
        v10 = 0i64;
        v11 = v8;
        do
        {
          *(++v9 - 1) = v5->mData.mItems[++v10 - 1];
          --v11;
        }
        while ( v11 );
      }
    }
  }
  if ( v5->mData.mItems && !(v5->mData.mFlags & 2) )
    operator delete[](v5->mData.mItems);
  v5->mData.mItems = v3;
  v5->mData.mNumItems = v4;
  v5->mData.mFlags = 0;
}

