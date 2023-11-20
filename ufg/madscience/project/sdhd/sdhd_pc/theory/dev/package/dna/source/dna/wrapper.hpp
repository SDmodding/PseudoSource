// File Line: 168
// RVA: 0x1AB600
void __fastcall DNA::PropertyWrapper::GetValueInternal<unsigned __int64>(DNA::PropertyWrapper *this, unsigned int index, unsigned __int64 *value)
{
  unsigned __int64 *v3; // rdi
  unsigned int v4; // esi
  DNA::PropertyWrapper *v5; // rbx
  __int64 v6; // [rsp+28h] [rbp-20h]
  __int64 v7; // [rsp+30h] [rbp-18h]
  void *mem; // [rsp+38h] [rbp-10h]

  v3 = value;
  v4 = index;
  v5 = this;
  if ( !this->mPropertyBagWrapper->mPropertyBags.size )
  {
LABEL_9:
    DNA::SchemaField::GetDefaultValue(v5->mSchemaField, v3);
    return;
  }
  v6 = 0i64;
  mem = 0i64;
  v7 = 0i64;
  DNA::PropertyBag::GetPropertyInfo(
    *this->mPropertyBagWrapper->mPropertyBags.p,
    this->mSchemaField->mName.mData,
    (DNA::PropertyInfo *)&v6);
  if ( v4 >= HIDWORD(v6) )
  {
    if ( mem )
      operator delete[](mem);
    mem = 0i64;
    v7 = 0i64;
    goto LABEL_9;
  }
  DNA::PropertyBag::Get(*v5->mPropertyBagWrapper->mPropertyBags.p, v5->mSchemaField->mName.mData, v3, v4);
  if ( mem )
    operator delete[](mem);
  mem = 0i64;
  v7 = 0i64;
}

// File Line: 184
// RVA: 0x1AB7C0
void __fastcall DNA::PropertyWrapper::SetValueInternal<long>(DNA::PropertyWrapper *this, unsigned int index, int *value, int *default_value, unsigned int undoId)
{
  int *v5; // r12
  int *v6; // r13
  unsigned int v7; // esi
  DNA::PropertyWrapper *v8; // rbx
  unsigned int v9; // ecx
  __int64 v10; // r14
  __int64 v11; // r15
  DNA::PropertyBag *v12; // rdi
  DNA::PropertyInfo info; // [rsp+38h] [rbp-40h]

  v5 = default_value;
  v6 = value;
  v7 = index;
  v8 = this;
  v9 = this->mPropertyBagWrapper->mPropertyBags.size;
  if ( v9 )
  {
    v10 = 0i64;
    v11 = v9;
    do
    {
      v12 = v8->mPropertyBagWrapper->mPropertyBags.p[v10];
      *(_QWORD *)&info.Type = 0i64;
      info.States.p = 0i64;
      *(_QWORD *)&info.States.size = 0i64;
      DNA::PropertyBag::GetPropertyInfo(v12, v8->mSchemaField->mName.mData, &info);
      while ( v7 >= info.Size )
      {
        DNA::PropertyBag::Append(v12, v8->mSchemaField->mName.mData, *v5, undoId);
        DNA::PropertyBag::GetPropertyInfo(v12, v8->mSchemaField->mName.mData, &info);
      }
      DNA::PropertyBag::Set(v12, v8->mSchemaField->mName.mData, *v6, v7, undoId);
      if ( info.States.p )
        operator delete[](info.States.p);
      info.States.p = 0i64;
      *(_QWORD *)&info.States.size = 0i64;
      ++v10;
      --v11;
    }
    while ( v11 );
  }
}

