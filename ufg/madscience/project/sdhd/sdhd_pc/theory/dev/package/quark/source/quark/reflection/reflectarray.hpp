// File Line: 64
// RVA: 0x405BB0
void __fastcall UFG::qReflectArray<float>::~qReflectArray<float>(UFG::qReflectArray<char> *this)
{
  if ( (this->mData.mFlags & 2) == 0 )
    operator delete[](this->mData.mItems);
  this->mData.mItems = 0i64;
  *(_QWORD *)&this->mData.mNumItems = 0i64;
}

// File Line: 69
// RVA: 0x155E00
UFG::qReflectArray<UFG::qColour> *__fastcall UFG::qReflectArray<UFG::qColour>::operator=(
        UFG::qReflectArray<UFG::qColour> *this,
        UFG::qReflectArray<UFG::qColour> *q)
{
  unsigned int i; // r9d
  UFG::qColour *mItems; // rcx
  unsigned __int64 v6; // rdx
  UFG::qColour *v7; // r8

  if ( this != q )
  {
    UFG::qReflectArray<UFG::qColour>::Resize(this, q->mData.mNumItems, "qReflectArray.Resize");
    for ( i = 0; i < q->mData.mNumItems; v7->a = mItems[v6].a )
    {
      mItems = q->mData.mItems;
      v6 = i++;
      v7 = &this->mData.mItems[v6];
      v7->r = q->mData.mItems[v6].r;
      v7->g = mItems[v6].g;
      v7->b = mItems[v6].b;
    }
  }
  return this;
}

// File Line: 187
// RVA: 0x15A9C0
void __fastcall UFG::qReflectArray<UFG::PartTemplateInstance::PartEntry>::Resize(
        UFG::qReflectArray<UFG::PartTemplateInstance::PartEntry> *this,
        unsigned int newSize,
        const char *reason)
{
  UFG::PartTemplateInstance::PartEntry *v5; // rsi
  __int64 v6; // rax
  bool v7; // cf
  unsigned __int64 v8; // rax
  char *v9; // rax
  unsigned int mNumItems; // ecx
  unsigned int v11; // eax
  __int64 v12; // rbx
  __int64 v13; // rbp
  UFG::PartTemplateInstance::PartEntry *mItems; // rcx
  unsigned int *p_mNumItems; // rbx

  v5 = 0i64;
  if ( newSize )
  {
    v6 = 80i64 * newSize;
    if ( !is_mul_ok(newSize, 0x50ui64) )
      v6 = -1i64;
    v7 = __CFADD__(v6, 8i64);
    v8 = v6 + 8;
    if ( v7 )
      v8 = -1i64;
    v9 = UFG::qMalloc(v8, reason, 0i64);
    if ( v9 )
    {
      *(_DWORD *)v9 = newSize;
      v5 = (UFG::PartTemplateInstance::PartEntry *)(v9 + 8);
      `eh vector constructor iterator(
        v9 + 8,
        0x50ui64,
        newSize,
        (void (__fastcall *)(void *))UFG::PartTemplateInstance::PartEntry::PartEntry);
    }
    else
    {
      v5 = 0i64;
    }
    mNumItems = this->mData.mNumItems;
    if ( mNumItems )
    {
      v11 = newSize;
      if ( mNumItems < newSize )
        v11 = this->mData.mNumItems;
      if ( v11 )
      {
        v12 = 0i64;
        v13 = v11;
        do
        {
          UFG::PartTemplateInstance::PartEntry::operator=(&v5[v12], &this->mData.mItems[v12]);
          ++v12;
          --v13;
        }
        while ( v13 );
      }
    }
  }
  mItems = this->mData.mItems;
  if ( this->mData.mItems && (this->mData.mFlags & 2) == 0 )
  {
    p_mNumItems = &mItems[-1].mSpecularValues.mData.mNumItems;
    `eh vector destructor iterator(
      mItems,
      0x50ui64,
      mItems[-1].mSpecularValues.mData.mNumItems,
      (void (__fastcall *)(void *))UFG::PartTemplateInstance::PartEntry::~PartEntry);
    operator delete[](p_mNumItems);
  }
  this->mData.mItems = v5;
  this->mData.mNumItems = newSize;
  this->mData.mFlags = 0;
}

