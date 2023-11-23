// File Line: 168
// RVA: 0x1AB600
void __fastcall DNA::PropertyWrapper::GetValueInternal<unsigned __int64>(
        DNA::PropertyWrapper *this,
        unsigned int index,
        unsigned __int64 *value)
{
  DNA::PropertyInfo v6; // [rsp+28h] [rbp-20h] BYREF

  if ( !this->mPropertyBagWrapper->mPropertyBags.size )
  {
LABEL_9:
    DNA::SchemaField::GetDefaultValue(this->mSchemaField, value);
    return;
  }
  memset(&v6, 0, sizeof(v6));
  DNA::PropertyBag::GetPropertyInfo(*this->mPropertyBagWrapper->mPropertyBags.p, this->mSchemaField->mName.mData, &v6);
  if ( index >= v6.Size )
  {
    if ( v6.States.p )
      operator delete[](v6.States.p);
    v6.States.p = 0i64;
    *(_QWORD *)&v6.States.size = 0i64;
    goto LABEL_9;
  }
  DNA::PropertyBag::Get(*this->mPropertyBagWrapper->mPropertyBags.p, this->mSchemaField->mName.mData, value, index);
  if ( v6.States.p )
    operator delete[](v6.States.p);
  v6.States.p = 0i64;
  *(_QWORD *)&v6.States.size = 0i64;
}

// File Line: 184
// RVA: 0x1AB7C0
void __fastcall DNA::PropertyWrapper::SetValueInternal<long>(
        DNA::PropertyWrapper *this,
        unsigned int index,
        int *value,
        int *default_value,
        unsigned int undoId)
{
  unsigned int size; // ecx
  __int64 v10; // r14
  __int64 v11; // r15
  DNA::PropertyBag *v12; // rdi
  DNA::PropertyInfo info; // [rsp+38h] [rbp-40h] BYREF

  size = this->mPropertyBagWrapper->mPropertyBags.size;
  if ( size )
  {
    v10 = 0i64;
    v11 = size;
    do
    {
      v12 = this->mPropertyBagWrapper->mPropertyBags.p[v10];
      memset(&info, 0, sizeof(info));
      DNA::PropertyBag::GetPropertyInfo(v12, this->mSchemaField->mName.mData, &info);
      while ( index >= info.Size )
      {
        DNA::PropertyBag::Append(v12, this->mSchemaField->mName.mData, *default_value, undoId);
        DNA::PropertyBag::GetPropertyInfo(v12, this->mSchemaField->mName.mData, &info);
      }
      DNA::PropertyBag::Set(v12, this->mSchemaField->mName.mData, *value, index, undoId);
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

