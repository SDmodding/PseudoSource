// File Line: 27
// RVA: 0x14577D0
__int64 dynamic_initializer_for__Json::Value::null__()
{
  *((_DWORD *)&Json::Value::null + 2) &= 0xFFFFFE00;
  return atexit(dynamic_atexit_destructor_for__Json::Value::null__);
}

// File Line: 61
// RVA: 0x84360
void __fastcall Json::ValueAllocator::~ValueAllocator(Json::ValueAllocator *this)
{
  this->vfptr = (Json::ValueAllocatorVtbl *)&Json::ValueAllocator::`vftable;
}

// File Line: 72
// RVA: 0x84A80
char *__fastcall Json::DefaultValueAllocator::makeMemberName(Json::DefaultValueAllocator *this, const char *memberName)
{
  return (char *)this->vfptr->duplicateStringValue((Json::ValueAllocator *)this, memberName, 0xFFFFFFFF);
}

// File Line: 83
// RVA: 0x84580
char *__fastcall Json::DefaultValueAllocator::duplicateStringValue(Json::DefaultValueAllocator *this, const char *value, unsigned int length)
{
  signed __int64 v3; // rbx
  const char *v4; // rsi
  void *v5; // rdi

  LODWORD(v3) = length;
  v4 = value;
  if ( length == -1 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( value[v3] );
  }
  v3 = (unsigned int)v3;
  v5 = malloc((unsigned int)(v3 + 1));
  memmove(v5, v4, (unsigned int)v3);
  *((_BYTE *)v5 + v3) = 0;
  return (char *)v5;
}

// File Line: 97
// RVA: 0x84A90
void __fastcall Json::DefaultValueAllocator::releaseStringValue(Json::DefaultValueAllocator *this, char *value)
{
  if ( value )
    free(value);
}

// File Line: 104
// RVA: 0x84AA0
Json::ValueAllocator **__fastcall Json::valueAllocator()
{
  if ( !(_S1_13 & 1) )
  {
    _S1_13 |= 1u;
    defaultAllocator.vfptr = (Json::ValueAllocatorVtbl *)&Json::DefaultValueAllocator::`vftable;
    atexit(Json::valueAllocator_::_2_::_dynamic_atexit_destructor_for__defaultAllocator__);
  }
  return &valueAllocator;
}

// File Line: 115
// RVA: 0x14577F0
__int64 Json::_dynamic_initializer_for__dummyValueAllocatorInitializer__()
{
  __int64 result; // rax

  result = _S1_13;
  if ( !(_S1_13 & 1) )
  {
    _S1_13 = result | 1;
    defaultAllocator.vfptr = (Json::ValueAllocatorVtbl *)&Json::DefaultValueAllocator::`vftable;
    result = atexit(Json::valueAllocator_::_2_::_dynamic_atexit_destructor_for__defaultAllocator__);
  }
  return result;
}

// File Line: 149
// RVA: 0x84240
void __fastcall Json::Value::CommentInfo::~CommentInfo(Json::Value::CommentInfo *this)
{
  Json::Value::CommentInfo *v1; // rbx

  v1 = this;
  if ( this->comment_ )
  {
    if ( !(_S1_13 & 1) )
    {
      _S1_13 |= 1u;
      defaultAllocator.vfptr = (Json::ValueAllocatorVtbl *)&Json::DefaultValueAllocator::`vftable;
      atexit(Json::valueAllocator_::_2_::_dynamic_atexit_destructor_for__defaultAllocator__);
    }
    valueAllocator->vfptr->releaseStringValue(valueAllocator, v1->comment_);
  }
}

// File Line: 202
// RVA: 0x84200
void __fastcall Json::Value::CZString::~CZString(Json::Value::CZString *this)
{
  Json::Value::CZString *v1; // rbx
  Json::ValueAllocator **v2; // rax

  v1 = this;
  if ( this->cstr_ )
  {
    if ( this->index_ == 1 )
    {
      v2 = Json::valueAllocator();
      (*v2)->vfptr->releaseMemberName(*v2, (char *)v1->cstr_);
    }
  }
}

// File Line: 478
// RVA: 0x842B0
void __fastcall Json::Value::~Value(Json::Value *this)
{
  Json::Value *v1; // rbx
  int v2; // eax
  long double v3; // rdi
  Json::ValueAllocator **v4; // rax
  Json::Value::CommentInfo *v5; // rcx
  Json::Value::CommentInfo *v6; // rbx
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<Json::Value::CZString const ,Json::Value> > > > result; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = *((char *)this + 8);
  if ( v2 == 4 )
  {
    if ( *((_DWORD *)this + 2) & 0x100 )
    {
      v4 = Json::valueAllocator();
      (*v4)->vfptr->releaseStringValue(*v4, *(char **)&v1->value_.real_);
    }
  }
  else if ( (unsigned int)(v2 - 6) <= 1 )
  {
    v3 = this->value_.real_;
    if ( *(_QWORD *)&this->value_.real_ )
    {
      std::_Tree<std::_Tmap_traits<Json::Value::CZString,Json::Value,std::less<Json::Value::CZString>,std::allocator<std::pair<Json::Value::CZString const,Json::Value>>,0>>::erase(
        *(std::_Tree<std::_Tmap_traits<Json::Value::CZString,Json::Value,std::less<Json::Value::CZString>,std::allocator<std::pair<Json::Value::CZString const ,Json::Value> >,0> > **)&v3,
        &result,
        (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<Json::Value::CZString const ,Json::Value> > > >)(**(std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<Json::Value::CZString const ,Json::Value> > > > ***)&v3)->_Ptr,
        (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<Json::Value::CZString const ,Json::Value> > > >)(*(std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<Json::Value::CZString const ,Json::Value> > > > **)&v3)->_Ptr);
      Illusion::ShaderParam::operator delete(**(void ***)&v3);
      Illusion::ShaderParam::operator delete(*(void **)&v3);
    }
  }
  v5 = v1->comments_;
  if ( v5 )
  {
    v6 = v5 - 1;
    `eh vector destructor iterator(
      v5,
      8ui64,
      (int)v5[-1].comment_,
      (void (__fastcall *)(void *))Json::Value::CommentInfo::~CommentInfo);
    Illusion::ShaderParam::operator delete(v6);
  }
}

