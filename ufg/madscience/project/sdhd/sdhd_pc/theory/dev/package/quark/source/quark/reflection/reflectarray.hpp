// File Line: 64
// RVA: 0x405BB0
void __fastcall UFG::qReflectArray<float>::~qReflectArray<float>(UFG::qReflectArray<char> *this)
{
  UFG::qReflectArray<char> *v1; // rbx

  v1 = this;
  if ( !(this->mData.mFlags & 2) )
    operator delete[](this->mData.mItems);
  v1->mData.mItems = 0i64;
  *(_QWORD *)&v1->mData.mNumItems = 0i64;
}

// File Line: 69
// RVA: 0x155E00
UFG::qReflectArray<UFG::qColour> *__fastcall UFG::qReflectArray<UFG::qColour>::operator=(UFG::qReflectArray<UFG::qColour> *this, UFG::qReflectArray<UFG::qColour> *q)
{
  UFG::qReflectArray<UFG::qColour> *v2; // rdi
  UFG::qReflectArray<UFG::qColour> *v3; // rbx
  unsigned int v4; // er9
  UFG::qColour *v5; // rcx
  signed __int64 v6; // rdx
  _DWORD *v7; // r8

  v2 = q;
  v3 = this;
  if ( this != q )
  {
    UFG::qReflectArray<UFG::qColour>::Resize(this, q->mData.mNumItems, "qReflectArray.Resize");
    v4 = 0;
    if ( v2->mData.mNumItems )
    {
      do
      {
        v5 = v2->mData.mItems;
        v6 = v4++;
        v7 = (_DWORD *)&v3->mData.mItems[v6].r;
        *v7 = LODWORD(v2->mData.mItems[v6].r);
        v7[1] = LODWORD(v5[v6].g);
        v7[2] = LODWORD(v5[v6].b);
        v7[3] = LODWORD(v5[v6].a);
      }
      while ( v4 < v2->mData.mNumItems );
    }
  }
  return v3;
}

// File Line: 187
// RVA: 0x15A9C0
void __fastcall UFG::qReflectArray<UFG::PartTemplateInstance::PartEntry>::Resize(UFG::qReflectArray<UFG::PartTemplateInstance::PartEntry> *this, unsigned int newSize, const char *reason)
{
  unsigned int v3; // er14
  UFG::qReflectArray<UFG::PartTemplateInstance::PartEntry> *v4; // rdi
  signed __int64 v5; // rsi
  signed __int64 v6; // rax
  unsigned __int8 v7; // cf
  unsigned __int64 v8; // rax
  char *v9; // rax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  __int64 v12; // rbx
  __int64 v13; // rbp
  UFG::PartTemplateInstance::PartEntry *v14; // rcx
  unsigned int *v15; // rbx

  v3 = newSize;
  v4 = this;
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
      *(_DWORD *)v9 = v3;
      v5 = (signed __int64)(v9 + 8);
      `eh vector constructor iterator'(
        v9 + 8,
        0x50ui64,
        v3,
        (void (__fastcall *)(void *))UFG::PartTemplateInstance::PartEntry::PartEntry);
    }
    else
    {
      v5 = 0i64;
    }
    v10 = v4->mData.mNumItems;
    if ( v10 )
    {
      v11 = v3;
      if ( v10 < v3 )
        v11 = v4->mData.mNumItems;
      if ( v11 )
      {
        v12 = 0i64;
        v13 = v11;
        do
        {
          UFG::PartTemplateInstance::PartEntry::operator=(
            (UFG::PartTemplateInstance::PartEntry *)(v12 * 80 + v5),
            &v4->mData.mItems[v12]);
          ++v12;
          --v13;
        }
        while ( v13 );
      }
    }
  }
  v14 = v4->mData.mItems;
  if ( v4->mData.mItems && !(v4->mData.mFlags & 2) )
  {
    v15 = &v14[-1].mSpecularValues.mData.mNumItems;
    `eh vector destructor iterator'(
      v14,
      0x50ui64,
      v14[-1].mSpecularValues.mData.mNumItems,
      (void (__fastcall *)(void *))UFG::PartTemplateInstance::PartEntry::~PartEntry);
    operator delete[](v15);
  }
  v4->mData.mItems = (UFG::PartTemplateInstance::PartEntry *)v5;
  v4->mData.mNumItems = v3;
  v4->mData.mFlags = 0;
}

