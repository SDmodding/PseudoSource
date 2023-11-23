// File Line: 20
// RVA: 0x1469890
__int64 dynamic_initializer_for__DNA::IQueryParser::mParsers__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__DNA::IQueryParser::mParsers__);
}

// File Line: 33
// RVA: 0x1A8300
void __fastcall DNA::IQueryParser::~IQueryParser(DNA::IQueryParser *this)
{
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v1; // rbx
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *mPrev; // rdx
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *mNext; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v4; // rcx
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v5; // rax

  this->vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable;
  v1 = &this->UFG::qNode<DNA::IQueryParser,DNA::IQueryParser>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<DNA::IQueryParser,DNA::IQueryParser>;
  this->mNext = &this->UFG::qNode<DNA::IQueryParser,DNA::IQueryParser>;
  UFG::qString::~qString(&this->mKey);
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 51
// RVA: 0x1A9C50
DNA::IQueryNode *__fastcall DNA::ParseSyntax(const char *syntax)
{
  DNA::IQueryNode *result; // rax
  int v3; // ebx
  int v4; // eax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> **p_mNext; // rbx
  int v6; // ebp
  char dest[72]; // [rsp+20h] [rbp-48h] BYREF

  if ( !*syntax )
    return 0i64;
  result = (DNA::IQueryNode *)UFG::qStringFind(syntax, "(");
  if ( result )
  {
    v3 = (_DWORD)result - (_DWORD)syntax;
    UFG::qMemCopy(dest, syntax, (_DWORD)result - (_DWORD)syntax);
    dest[v3] = 0;
    v4 = UFG::qStringHash32(dest, 0xFFFFFFFF);
    p_mNext = &DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
    v6 = v4;
    if ( &DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext == (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> **)((char *)&DNA::IQueryParser::mParsers - 8) )
      return 0i64;
    while ( 1 )
    {
      if ( *((_DWORD *)p_mNext + 14) == -1 )
        *((_DWORD *)p_mNext + 14) = UFG::qStringHash32((const char *)p_mNext[6], 0xFFFFFFFF);
      if ( *((_DWORD *)p_mNext + 14) == v6 )
        break;
      p_mNext = &p_mNext[2][-1].mNext;
      if ( p_mNext == (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> **)((char *)&DNA::IQueryParser::mParsers - 8) )
        return 0i64;
    }
    if ( !p_mNext )
      return 0i64;
    else
      return (DNA::IQueryNode *)((__int64 (__fastcall *)(UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> **, const char *))(*p_mNext)->mPrev)(
                                  p_mNext,
                                  syntax);
  }
  return result;
}

// File Line: 77
// RVA: 0x1A8730
void __fastcall DNA::CollectArgs(const char *syntax, int keyLength, UFG::qList<UFG::qString,UFG::qString,1,0> *result)
{
  const char *v4; // rbx
  int v5; // edi
  const char *v6; // r15
  UFG::qString *v7; // rax
  UFG::qString *v8; // rax
  UFG::qString *v9; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax

  v4 = &syntax[keyLength + 1];
  v5 = 0;
  v6 = v4;
  do
  {
    if ( *v4 == 40 )
    {
      ++v5;
    }
    else if ( *v4 == 41 && !--v5 )
    {
      v7 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      if ( v7 )
      {
        UFG::qString::qString(v7);
        v9 = v8;
      }
      else
      {
        v9 = 0i64;
      }
      UFG::qString::Set(v9, v6, (_DWORD)v4 - (_DWORD)v6 + 1, 0i64, 0);
      mPrev = result->mNode.mPrev;
      mPrev->mNext = v9;
      v9->mPrev = mPrev;
      v9->mNext = &result->mNode;
      result->mNode.mPrev = v9;
      v6 = v4 + 1;
    }
  }
  while ( *v4++ != 0 );
}

// File Line: 137
// RVA: 0x14693C0
__int64 dynamic_initializer_for__DNA::AllQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *mPrev; // rax

  DNA::AllQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable;
  UFG::qString::qString(&stru_14203D588, "All");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  mPrev = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D578;
  off_14203D578 = mPrev;
  off_14203D580 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D578;
  DNA::AllQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::AllQueryNode::Parser::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__DNA::AllQueryNode::mParser__);
}

// File Line: 140
// RVA: 0x1A9270
UFG::allocator::free_link *__fastcall DNA::AllQueryNode::Parser::Parse(
        DNA::AllQueryNode::Parser *this,
        const char *syntax)
{
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rcx
  UFG::allocator::free_link *v4; // rax

  v2 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  v4 = v2 + 1;
  v4->mNext = v4;
  v4[1].mNext = v4;
  v3->mNext = (UFG::allocator::free_link *)&DNA::IQueryNode::`vftable;
  v3[3].mNext = (UFG::allocator::free_link *)&DNA::AllQueryNode::mParser;
  v3->mNext = (UFG::allocator::free_link *)&DNA::AllQueryNode::`vftable;
  return v3;
}

// File Line: 146
// RVA: 0x1A9D40
void __fastcall DNA::AllQueryNode::Parser::Write(
        DNA::AllQueryNode::Parser *this,
        DNA::IQueryNode *queryNode,
        UFG::qStringBuilder *builder)
{
  UFG::qStringBuilder::operator<<(builder, &this->mKey);
  UFG::qStringBuilder::operator<<(builder, "()");
}

// File Line: 162
// RVA: 0x1A7F00
void __fastcall DNA::PropertyQueryNode::PropertyQueryNode(
        DNA::PropertyQueryNode *this,
        const char *name,
        const char *v)
{
  this->mPrev = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
  this->mNext = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable;
  this->mQueryParser = &DNA::PropertyQueryNode::mParser;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::PropertyQueryNode::`vftable;
  UFG::qString::qString(&this->mPropertyName);
  UFG::qString::qString(&this->mPropertyValue);
  UFG::qString::Set(&this->mPropertyName, name);
  DNA::DataConverter::ToString(&this->mPropertyValue, v);
}

// File Line: 189
// RVA: 0x1A90E0
UFG::qBaseTreeRB *__fastcall DNA::PropertyQueryNode::Match(DNA::PropertyQueryNode *this, DNA::PropertyBag *propertyBag)
{
  UFG::qBaseTreeRB *result; // rax
  DNA::PropertyData *v4; // rdi
  bool v5; // bl
  UFG::qString v; // [rsp+28h] [rbp-30h] BYREF

  result = DNA::PropertyBag::GetProperty(propertyBag, this->mPropertyName.mData);
  v4 = (DNA::PropertyData *)result;
  if ( result )
  {
    UFG::qString::qString(&v);
    DNA::PropertyData::GetRaw(v4, 0, &v);
    v5 = (unsigned int)UFG::qWildcardMatchInsensitive(this->mPropertyValue.mData, v.mData) == 1;
    UFG::qString::~qString(&v);
    return (UFG::qBaseTreeRB *)v5;
  }
  return result;
}

// File Line: 201
// RVA: 0x1469680
__int64 dynamic_initializer_for__DNA::PropertyQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *mPrev; // rax

  DNA::PropertyQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable;
  UFG::qString::qString(&stru_14203D5C8, "Property");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  mPrev = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D5B8;
  off_14203D5B8 = mPrev;
  off_14203D5C0 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D5B8;
  DNA::PropertyQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::PropertyQueryNode::Parser::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__DNA::PropertyQueryNode::mParser__);
}

// File Line: 204
// RVA: 0x1A9770
DNA::IQueryNode *__fastcall DNA::PropertyQueryNode::Parser::Parse(
        DNA::PropertyQueryNode::Parser *this,
        const char *syntax)
{
  __int64 v2; // rdi
  int v3; // ecx
  UFG::qList<UFG::qString,UFG::qString,1,0> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rsi
  UFG::allocator::free_link *v7; // rax
  __int64 v8; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx
  UFG::qList<UFG::qString,UFG::qString,1,0> v15[2]; // [rsp+38h] [rbp-20h] BYREF

  v15[0].mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v15;
  v15[0].mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)v15;
  v2 = 0i64;
  UFG::qTokenize(v15, "(,)", syntax, 0, 0i64, 0);
  v3 = 0;
  mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v15[0].mNode.mNext;
  if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)v15[0].mNode.mNext != v15 )
  {
    do
    {
      ++v3;
      mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)mNext->mNode.mNext;
    }
    while ( mNext != v15 );
    if ( v3 == 3 )
    {
      v5 = v15[0].mNode.mNext->mNext;
      v6 = v5->mNext;
      v7 = UFG::qMalloc(0x70ui64, UFG::gGlobalNewName, 0i64);
      if ( v7 )
      {
        DNA::PropertyQueryNode::PropertyQueryNode(
          (DNA::PropertyQueryNode *)v7,
          (const char *)v5[1].mNext,
          (const char *)v6[1].mNext);
        v2 = v8;
      }
    }
  }
  for ( i = (UFG::qString *)v15[0].mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)v15[0].mNode.mNext != v15;
        i = (UFG::qString *)v15[0].mNode.mNext )
  {
    mPrev = i->mPrev;
    v11 = i->mNext;
    mPrev->mNext = v11;
    v11->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v12 = v15[0].mNode.mPrev;
  v13 = v15[0].mNode.mNext;
  v15[0].mNode.mPrev->mNext = v15[0].mNode.mNext;
  v13->mPrev = v12;
  return (DNA::IQueryNode *)v2;
}

// File Line: 218
// RVA: 0x1A9E70
void __fastcall DNA::PropertyQueryNode::Parser::Write(
        DNA::PropertyQueryNode::Parser *this,
        DNA::IQueryNode *queryNode,
        UFG::qStringBuilder *builder)
{
  UFG::qStringBuilder::operator<<(builder, &this->mKey);
  UFG::qStringBuilder::operator<<(builder, "(");
  UFG::qStringBuilder::operator<<(builder, (UFG::qString *)&queryNode[1]);
  UFG::qStringBuilder::operator<<(builder, ",");
  UFG::qStringBuilder::operator<<(builder, (UFG::qString *)&queryNode[2].UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>);
  UFG::qStringBuilder::operator<<(builder, ")");
}

// File Line: 267
// RVA: 0x1A7FA0
void __fastcall DNA::ReferencedByQueryNode::ReferencedByQueryNode(
        DNA::ReferencedByQueryNode *this,
        DNA::PropertyBagHandle *propertyBags,
        bool recursive)
{
  DNA::PropertyBagHandle *i; // rbp
  unsigned __int64 mUID; // r12
  __int64 size; // r15
  unsigned int v8; // esi
  unsigned int capacity; // ebx
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  unsigned __int64 *v13; // r14
  __int64 j; // r9

  this->mPrev = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
  this->mNext = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable;
  this->mQueryParser = &DNA::ReferencedByQueryNode::mParser;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::ReferencedByQueryNode::`vftable;
  this->mRecursive = recursive;
  *(_QWORD *)&this->mInitialCount = 0i64;
  this->mSourceUIDs.p = 0i64;
  this->mSourceUIDs.capacity = 0;
  this->mReferencedUIDs.p = 0i64;
  *(_QWORD *)&this->mReferencedUIDs.size = 0i64;
  for ( i = (DNA::PropertyBagHandle *)propertyBags->mNext; i != propertyBags; i = (DNA::PropertyBagHandle *)i->mNext )
  {
    if ( DNA::PropertyBagHandle::Get(i) )
    {
      mUID = DNA::PropertyBagHandle::Get(i)->mBaseNode.mUID;
      size = this->mSourceUIDs.size;
      v8 = size + 1;
      capacity = this->mSourceUIDs.capacity;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v10 = 2 * capacity;
        else
          v10 = 1;
        for ( ; v10 < v8; v10 *= 2 )
          ;
        if ( v10 <= 2 )
          v10 = 2;
        if ( v10 - v8 > 0x10000 )
          v10 = size + 65537;
        if ( v10 != (_DWORD)size )
        {
          v11 = 8i64 * v10;
          if ( !is_mul_ok(v10, 8ui64) )
            v11 = -1i64;
          v12 = UFG::qMalloc(v11, "qArray.Add", 0i64);
          v13 = (unsigned __int64 *)v12;
          if ( this->mSourceUIDs.p )
          {
            for ( j = 0i64; (unsigned int)j < this->mSourceUIDs.size; j = (unsigned int)(j + 1) )
              v12[j] = (UFG::allocator::free_link)this->mSourceUIDs.p[j];
            operator delete[](this->mSourceUIDs.p);
          }
          this->mSourceUIDs.p = v13;
          this->mSourceUIDs.capacity = v10;
        }
      }
      this->mSourceUIDs.size = v8;
      this->mSourceUIDs.p[size] = mUID;
    }
  }
  DNA::ReferencedByQueryNode::EvaluateReferences(this);
}

// File Line: 282
// RVA: 0x1A8150
void __fastcall DNA::ReferencedByQueryNode::ReferencedByQueryNode(
        DNA::ReferencedByQueryNode *this,
        DNA::PropertyBag *propertyBag,
        bool recursive)
{
  unsigned __int64 mUID; // r14
  __int64 size; // rbp
  unsigned int v6; // ebx
  unsigned int capacity; // edx
  unsigned int v8; // edx

  this->mPrev = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
  this->mNext = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable;
  this->mQueryParser = &DNA::ReferencedByQueryNode::mParser;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::ReferencedByQueryNode::`vftable;
  this->mRecursive = recursive;
  *(_QWORD *)&this->mInitialCount = 0i64;
  this->mSourceUIDs.p = 0i64;
  this->mSourceUIDs.capacity = 0;
  this->mReferencedUIDs.p = 0i64;
  *(_QWORD *)&this->mReferencedUIDs.size = 0i64;
  mUID = propertyBag->mBaseNode.mUID;
  size = this->mSourceUIDs.size;
  v6 = size + 1;
  capacity = this->mSourceUIDs.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v8 = 2 * capacity;
    else
      v8 = 1;
    for ( ; v8 < v6; v8 *= 2 )
      ;
    if ( v8 <= 2 )
      v8 = 2;
    if ( v8 - v6 > 0x10000 )
      v8 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mSourceUIDs,
      v8,
      "qArray.Add");
  }
  this->mSourceUIDs.size = v6;
  this->mSourceUIDs.p[size] = mUID;
  DNA::ReferencedByQueryNode::EvaluateReferences(this);
}

// File Line: 288
// RVA: 0x1A8880
void __fastcall DNA::ReferencedByQueryNode::EvaluateReferences(DNA::ReferencedByQueryNode *this)
{
  DNA::ReferencedByQueryNode *v1; // r13
  unsigned __int64 v2; // rax
  UFG::allocator::free_link *v3; // rax
  unsigned __int64 *v4; // rbx
  __int64 i; // r9
  __int64 v6; // r8
  unsigned int size; // eax
  __int64 v8; // rcx
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_mSourceUIDs; // rsi
  unsigned __int64 *v10; // rbx
  DNA::Database *v11; // rax
  UFG::qTree64Base *PropertyBag; // rax
  UFG::qTree64Base *v13; // rbx
  UFG::qTree64Base::BaseNode **mNeighbours; // rax
  DNA::SchemaField *mNext; // rcx
  UFG::qBaseTreeRB *Property; // rax
  DNA::PropertyData *v17; // rbx
  unsigned int v18; // r12d
  unsigned int v19; // r13d
  __int64 v20; // r14
  unsigned __int64 mUID; // r15
  unsigned int v22; // eax
  UFG::qReflectInventoryBase **p; // rcx
  unsigned int capacity; // ebx
  unsigned int v25; // edi
  unsigned int v26; // ebx
  unsigned __int64 v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::qReflectInventoryBase **v29; // rbp
  __int64 j; // r9
  __int64 v31; // r8
  UFG::qReflectInventoryBase **v32; // rax
  unsigned int v33; // r15d
  unsigned int v34; // r12d
  __int64 v35; // r14
  DNA::PropertyBag *v36; // rdx
  unsigned int v37; // ecx
  DNA::PropertyBag **v38; // rax
  unsigned int v39; // ebx
  unsigned int v40; // edi
  unsigned int v41; // ebx
  unsigned __int64 v42; // rax
  UFG::allocator::free_link *v43; // rax
  unsigned __int64 *v44; // rbp
  __int64 k; // r9
  __int64 v46; // r8
  unsigned __int64 *v47; // rax
  __int64 v48; // rdi
  unsigned int v49; // ecx
  UFG::qReflectInventoryBase **v50; // rax
  unsigned int v51; // eax
  unsigned int v52; // ebx
  unsigned int v53; // edx
  UFG::qReflectInventoryBase **v54; // rax
  UFG::qBaseTreeRB *m; // r13
  unsigned int v56; // r12d
  unsigned int v57; // ebp
  __int64 v58; // r14
  UFG::qNode<DNA::SchemaField,DNA::SchemaField> *mPrev; // r15
  unsigned int v60; // eax
  UFG::qReflectInventoryBase **v61; // rcx
  unsigned int v62; // ebx
  unsigned int v63; // edi
  unsigned int v64; // ebx
  unsigned __int64 v65; // rax
  UFG::allocator::free_link *v66; // rax
  UFG::qReflectInventoryBase **v67; // rbp
  __int64 n; // r9
  __int64 v69; // r8
  UFG::qReflectInventoryBase **v70; // rax
  UFG::qBaseTreeRB *v71; // [rsp+20h] [rbp-68h]
  UFG::qTree64Base *v72; // [rsp+28h] [rbp-60h]
  DNA::SchemaField *v73; // [rsp+30h] [rbp-58h]
  int v75; // [rsp+98h] [rbp+10h]
  DNA::PropertyBag *v; // [rsp+A0h] [rbp+18h] BYREF
  DNA::SchemaField *v77; // [rsp+A8h] [rbp+20h] BYREF

  v1 = this;
  if ( this->mReferencedUIDs.capacity < 0x100 && this->mReferencedUIDs.size != 256 )
  {
    v2 = 2048i64;
    if ( !is_mul_ok(0x100ui64, 8ui64) )
      v2 = -1i64;
    v3 = UFG::qMalloc(v2, "qArray.Reallocate(Reserve)", 0i64);
    v4 = (unsigned __int64 *)v3;
    if ( v1->mReferencedUIDs.p )
    {
      for ( i = 0i64;
            (unsigned int)i < v1->mReferencedUIDs.size;
            v3[v6] = (UFG::allocator::free_link)v1->mReferencedUIDs.p[v6] )
      {
        v6 = i;
        i = (unsigned int)(i + 1);
      }
      operator delete[](v1->mReferencedUIDs.p);
    }
    v1->mReferencedUIDs.p = v4;
    v1->mReferencedUIDs.capacity = 256;
  }
  size = v1->mSourceUIDs.size;
  v8 = 0i64;
  p_mSourceUIDs = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v1->mSourceUIDs;
  v1->mInitialCount = size;
  v75 = 0;
  if ( size )
  {
    do
    {
      v10 = &v1->mSourceUIDs.p[v8];
      DNA::Database::Instance();
      PropertyBag = DNA::Database::GetPropertyBag(v11, *v10);
      v13 = PropertyBag;
      v72 = PropertyBag;
      if ( PropertyBag )
      {
        if ( DNA::PropertyBag::GetSchemaType((DNA::PropertyBag *)PropertyBag) )
        {
          mNeighbours = DNA::PropertyBag::GetSchemaType((DNA::PropertyBag *)v13)[2].mHead.mNeighbours;
          mNext = (DNA::SchemaField *)mNeighbours[1];
          v73 = (DNA::SchemaField *)mNeighbours;
          v77 = mNext;
          if ( mNext != (DNA::SchemaField *)mNeighbours )
          {
            do
            {
              Property = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v13, mNext->mName.mData);
              v17 = (DNA::PropertyData *)Property;
              v71 = Property;
              if ( Property )
              {
                if ( LODWORD(Property[1].mRoot.mParent) == -915936389 )
                {
                  v18 = 0;
                  v19 = DNA::PropertyData::NumItems((DNA::PropertyData *)Property);
                  if ( v19 )
                  {
                    do
                    {
                      v = 0i64;
                      DNA::PropertyData::Get(v17, v18, (UFG::qTree64Base **)&v);
                      if ( v )
                      {
                        v20 = p_mSourceUIDs->size;
                        mUID = v->mBaseNode.mUID;
                        v22 = 0;
                        if ( !(_DWORD)v20 )
                          goto LABEL_24;
                        p = p_mSourceUIDs->p;
                        while ( (UFG::qReflectInventoryBase *)mUID != *p )
                        {
                          ++v22;
                          ++p;
                          if ( v22 >= (unsigned int)v20 )
                            goto LABEL_24;
                        }
                        if ( v22 == -1 )
                        {
LABEL_24:
                          capacity = p_mSourceUIDs->capacity;
                          v25 = v20 + 1;
                          if ( (int)v20 + 1 > capacity )
                          {
                            if ( capacity )
                              v26 = 2 * capacity;
                            else
                              v26 = 1;
                            for ( ; v26 < v25; v26 *= 2 )
                              ;
                            if ( v26 <= 2 )
                              v26 = 2;
                            if ( v26 - v25 > 0x10000 )
                              v26 = v20 + 65537;
                            if ( v26 != (_DWORD)v20 )
                            {
                              v27 = 8i64 * v26;
                              if ( !is_mul_ok(v26, 8ui64) )
                                v27 = -1i64;
                              v28 = UFG::qMalloc(v27, "qArray.Add", 0i64);
                              v29 = (UFG::qReflectInventoryBase **)v28;
                              if ( p_mSourceUIDs->p )
                              {
                                for ( j = 0i64;
                                      (unsigned int)j < p_mSourceUIDs->size;
                                      v28[v31] = (UFG::allocator::free_link)p_mSourceUIDs->p[v31] )
                                {
                                  v31 = j;
                                  j = (unsigned int)(j + 1);
                                }
                                operator delete[](p_mSourceUIDs->p);
                              }
                              p_mSourceUIDs->p = v29;
                              p_mSourceUIDs->capacity = v26;
                            }
                          }
                          v32 = p_mSourceUIDs->p;
                          v17 = (DNA::PropertyData *)v71;
                          p_mSourceUIDs->size = v25;
                          v32[v20] = (UFG::qReflectInventoryBase *)mUID;
                        }
                      }
                      ++v18;
                    }
                    while ( v18 < v19 );
                  }
                  v1 = this;
                }
                else if ( DNA::SchemaField::GetAnnotation(v77, "HandleNameUID") )
                {
                  v33 = 0;
                  v34 = DNA::PropertyData::NumItems(v17);
                  if ( v34 )
                  {
                    do
                    {
                      v = 0i64;
                      DNA::PropertyData::Get(v17, v33, (unsigned __int64 *)&v);
                      v35 = v1->mReferencedUIDs.size;
                      v36 = v;
                      v37 = 0;
                      if ( !(_DWORD)v35 )
                        goto LABEL_55;
                      v38 = (DNA::PropertyBag **)v1->mReferencedUIDs.p;
                      while ( v != *v38 )
                      {
                        ++v37;
                        ++v38;
                        if ( v37 >= (unsigned int)v35 )
                          goto LABEL_55;
                      }
                      if ( v37 == -1 )
                      {
LABEL_55:
                        v39 = v1->mReferencedUIDs.capacity;
                        v40 = v35 + 1;
                        if ( (int)v35 + 1 > v39 )
                        {
                          if ( v39 )
                            v41 = 2 * v39;
                          else
                            v41 = 1;
                          for ( ; v41 < v40; v41 *= 2 )
                            ;
                          if ( v41 <= 2 )
                            v41 = 2;
                          if ( v41 - v40 > 0x10000 )
                            v41 = v35 + 65537;
                          if ( v41 != (_DWORD)v35 )
                          {
                            v42 = 8i64 * v41;
                            if ( !is_mul_ok(v41, 8ui64) )
                              v42 = -1i64;
                            v43 = UFG::qMalloc(v42, "qArray.Add", 0i64);
                            v44 = (unsigned __int64 *)v43;
                            if ( v1->mReferencedUIDs.p )
                            {
                              for ( k = 0i64;
                                    (unsigned int)k < v1->mReferencedUIDs.size;
                                    v43[v46] = (UFG::allocator::free_link)v1->mReferencedUIDs.p[v46] )
                              {
                                v46 = k;
                                k = (unsigned int)(k + 1);
                              }
                              operator delete[](v1->mReferencedUIDs.p);
                            }
                            v36 = v;
                            v1->mReferencedUIDs.p = v44;
                            v1->mReferencedUIDs.capacity = v41;
                          }
                        }
                        v47 = v1->mReferencedUIDs.p;
                        v1->mReferencedUIDs.size = v40;
                        v47[v35] = (unsigned __int64)v36;
                        v36 = v;
                      }
                      if ( v1->mRecursive )
                      {
                        v48 = p_mSourceUIDs->size;
                        v49 = 0;
                        if ( !(_DWORD)v48 )
                          goto LABEL_81;
                        v50 = p_mSourceUIDs->p;
                        while ( v36 != (DNA::PropertyBag *)*v50 )
                        {
                          ++v49;
                          ++v50;
                          if ( v49 >= (unsigned int)v48 )
                            goto LABEL_81;
                        }
                        if ( v49 == -1 )
                        {
LABEL_81:
                          v51 = p_mSourceUIDs->capacity;
                          v52 = v48 + 1;
                          if ( (int)v48 + 1 > v51 )
                          {
                            v53 = 1;
                            if ( v51 )
                              v53 = 2 * v51;
                            for ( ; v53 < v52; v53 *= 2 )
                              ;
                            if ( v53 <= 2 )
                              v53 = 2;
                            if ( v53 - v52 > 0x10000 )
                              v53 = v48 + 65537;
                            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
                              p_mSourceUIDs,
                              v53,
                              "qArray.Add");
                            v36 = v;
                          }
                          v54 = p_mSourceUIDs->p;
                          p_mSourceUIDs->size = v52;
                          v54[v48] = (UFG::qReflectInventoryBase *)v36;
                        }
                      }
                      v17 = (DNA::PropertyData *)v71;
                      ++v33;
                    }
                    while ( v33 < v34 );
                  }
                }
              }
              v13 = v72;
              mNext = (DNA::SchemaField *)v77->mNext;
              v77 = mNext;
            }
            while ( mNext != v73 );
          }
        }
        else
        {
          for ( m = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v13->mCount);
                m;
                m = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&v13->mCount, &m->mRoot) )
          {
            if ( LODWORD(m[1].mRoot.mParent) == -915936389 )
            {
              v56 = 0;
              v57 = DNA::PropertyData::NumItems((DNA::PropertyData *)m);
              LODWORD(v) = v57;
              if ( v57 )
              {
                do
                {
                  v77 = 0i64;
                  DNA::PropertyData::Get((DNA::PropertyData *)m, v56, (UFG::qTree64Base **)&v77);
                  if ( v77 )
                  {
                    v58 = p_mSourceUIDs->size;
                    mPrev = v77->mPrev;
                    v60 = 0;
                    if ( !(_DWORD)v58 )
                      goto LABEL_104;
                    v61 = p_mSourceUIDs->p;
                    while ( mPrev != (UFG::qNode<DNA::SchemaField,DNA::SchemaField> *)*v61 )
                    {
                      ++v60;
                      ++v61;
                      if ( v60 >= (unsigned int)v58 )
                        goto LABEL_104;
                    }
                    if ( v60 == -1 )
                    {
LABEL_104:
                      v62 = p_mSourceUIDs->capacity;
                      v63 = v58 + 1;
                      if ( (int)v58 + 1 > v62 )
                      {
                        if ( v62 )
                          v64 = 2 * v62;
                        else
                          v64 = 1;
                        for ( ; v64 < v63; v64 *= 2 )
                          ;
                        if ( v64 <= 2 )
                          v64 = 2;
                        if ( v64 - v63 > 0x10000 )
                          v64 = v58 + 65537;
                        if ( v64 != (_DWORD)v58 )
                        {
                          v65 = 8i64 * v64;
                          if ( !is_mul_ok(v64, 8ui64) )
                            v65 = -1i64;
                          v66 = UFG::qMalloc(v65, "qArray.Add", 0i64);
                          v67 = (UFG::qReflectInventoryBase **)v66;
                          if ( p_mSourceUIDs->p )
                          {
                            for ( n = 0i64;
                                  (unsigned int)n < p_mSourceUIDs->size;
                                  v66[v69] = (UFG::allocator::free_link)p_mSourceUIDs->p[v69] )
                            {
                              v69 = n;
                              n = (unsigned int)(n + 1);
                            }
                            operator delete[](p_mSourceUIDs->p);
                          }
                          p_mSourceUIDs->p = v67;
                          v57 = (unsigned int)v;
                          p_mSourceUIDs->capacity = v64;
                        }
                      }
                      v70 = p_mSourceUIDs->p;
                      p_mSourceUIDs->size = v63;
                      v70[v58] = (UFG::qReflectInventoryBase *)mPrev;
                    }
                  }
                  ++v56;
                }
                while ( v56 < v57 );
                v13 = v72;
              }
            }
          }
        }
      }
      v1 = this;
      v8 = (unsigned int)(v75 + 1);
      v75 = v8;
    }
    while ( (unsigned int)v8 < p_mSourceUIDs->size );
  }
}              v70[v58] = (UFG::qReflectInventoryBase *)mPrev;
                    }
                  }
                  ++v56;
                }
  

// File Line: 367
// RVA: 0x1A9160
bool __fastcall DNA::ReferencedByQueryNode::Match(DNA::ReferencedByQueryNode *this, DNA::PropertyBag *propertyBag)
{
  unsigned __int64 mUID; // r8
  unsigned int size; // edx
  unsigned int v4; // eax
  unsigned __int64 *p; // rcx

  mUID = propertyBag->mBaseNode.mUID;
  size = this->mReferencedUIDs.size;
  v4 = 0;
  if ( size )
  {
    p = this->mReferencedUIDs.p;
    while ( mUID != *p )
    {
      ++v4;
      ++p;
      if ( v4 >= size )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v4 = -1;
  }
  return v4 != -1;
}

// File Line: 371
// RVA: 0x1469730
__int64 dynamic_initializer_for__DNA::ReferencedByQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *mPrev; // rax

  DNA::ReferencedByQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable;
  UFG::qString::qString(&stru_14203D608, "ReferencedBy");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  mPrev = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D5F8;
  off_14203D5F8 = mPrev;
  off_14203D600 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D5F8;
  DNA::ReferencedByQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::ReferencedByQueryNode::Parser::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__DNA::ReferencedByQueryNode::mParser__);
}

// File Line: 374
// RVA: 0x1A98A0
DNA::IQueryNode *__fastcall DNA::ReferencedByQueryNode::Parser::Parse(
        DNA::ReferencedByQueryNode::Parser *this,
        const char *syntax)
{
  __int64 v2; // rsi
  int v3; // ecx
  UFG::qList<UFG::qString,UFG::qString,1,0> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v5; // r14
  UFG::qNode<UFG::qString,UFG::qString> *i; // rbx
  UFG::allocator::free_link *v7; // rdi
  unsigned __int64 v8; // rax
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v9; // rax
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v10; // rcx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *mPrev; // rax
  UFG::allocator::free_link *v12; // rbx
  bool v13; // al
  __int64 v14; // rax
  DNA::PropertyBagHandle *j; // rbx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v16; // rdx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v17; // rax
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v18; // rcx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v19; // rax
  UFG::qString *k; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v22; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v23; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v24; // rcx
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+38h] [rbp-28h] BYREF
  DNA::PropertyBagHandle propertyBags; // [rsp+48h] [rbp-18h] BYREF

  list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
  list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
  v2 = 0i64;
  UFG::qTokenize(&list, "(,)", syntax, 0, 0i64, 0);
  v3 = 0;
  mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext;
  if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list )
  {
    do
    {
      ++v3;
      mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)mNext->mNode.mNext;
    }
    while ( mNext != &list );
    if ( v3 > 2 )
    {
      v5 = list.mNode.mNext->mNext;
      propertyBags.mPrev = &propertyBags;
      propertyBags.mNext = &propertyBags;
      for ( i = v5->mNext; i != (UFG::qNode<UFG::qString,UFG::qString> *)&list; i = i->mNext )
      {
        v7 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
        if ( v7 )
        {
          v8 = UFG::qToUInt64((const char *)i[1].mNext, 0i64);
          DNA::PropertyBagHandle::PropertyBagHandle((DNA::PropertyBagHandle *)v7, v8);
          v10 = v9;
        }
        else
        {
          v10 = 0i64;
        }
        mPrev = propertyBags.mPrev;
        propertyBags.mPrev->mNext = v10;
        v10->mPrev = mPrev;
        v10->mNext = &propertyBags;
        propertyBags.mPrev = v10;
      }
      v12 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
      if ( v12 )
      {
        v13 = UFG::qToBool((char *)v5[1].mNext, 0);
        DNA::ReferencedByQueryNode::ReferencedByQueryNode((DNA::ReferencedByQueryNode *)v12, &propertyBags, v13);
        v2 = v14;
      }
      for ( j = (DNA::PropertyBagHandle *)propertyBags.mNext;
            propertyBags.mNext != &propertyBags;
            j = (DNA::PropertyBagHandle *)propertyBags.mNext )
      {
        v16 = j->mPrev;
        v17 = j->mNext;
        v16->mNext = v17;
        v17->mPrev = v16;
        j->mPrev = j;
        j->mNext = j;
        DNA::PropertyBagHandle::~PropertyBagHandle(j);
        operator delete[](j);
      }
      v18 = propertyBags.mPrev;
      v19 = propertyBags.mNext;
      propertyBags.mPrev->mNext = propertyBags.mNext;
      v19->mPrev = v18;
      propertyBags.mPrev = &propertyBags;
      propertyBags.mNext = &propertyBags;
    }
  }
  for ( k = (UFG::qString *)list.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
        k = (UFG::qString *)list.mNode.mNext )
  {
    v21 = k->mPrev;
    v22 = k->mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    k->mPrev = k;
    k->mNext = k;
    UFG::qString::~qString(k);
    operator delete[](k);
  }
  v23 = list.mNode.mPrev;
  v24 = list.mNode.mNext;
  list.mNode.mPrev->mNext = list.mNode.mNext;
  v24->mPrev = v23;
  return (DNA::IQueryNode *)v2;
}

// File Line: 393
// RVA: 0x1A9EE0
void __fastcall DNA::ReferencedByQueryNode::Parser::Write(
        DNA::ReferencedByQueryNode::Parser *this,
        DNA::IQueryNode *queryNode,
        UFG::qStringBuilder *builder)
{
  __int64 i; // rbx

  UFG::qStringBuilder::operator<<(builder, &this->mKey);
  UFG::qStringBuilder::operator<<(builder, "(");
  UFG::qStringBuilder::operator<<(builder, (const bool)queryNode[1].vfptr);
  for ( i = 0i64; (unsigned int)i < HIDWORD(queryNode[1].vfptr); i = (unsigned int)(i + 1) )
  {
    UFG::qStringBuilder::operator<<(builder, ",");
    UFG::qStringBuilder::operator<<(
      builder,
      *((_QWORD *)&queryNode[1].mNext->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>::mPrev + i));
  }
  UFG::qStringBuilder::operator<<(builder, ")");
}

// File Line: 436
// RVA: 0x1A9190
_BOOL8 __fastcall DNA::UsedByQueryNode::Match(DNA::UsedByQueryNode *this, DNA::PropertyBag *propertyBag)
{
  int v3; // eax
  bool v4; // bl
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *mPrev; // rdx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *mNext; // rcx
  DNA::ReferencedByQueryNode v8; // [rsp+30h] [rbp-58h] BYREF

  DNA::ReferencedByQueryNode::ReferencedByQueryNode(&v8, propertyBag, 0);
  v3 = 0;
  if ( v8.mReferencedUIDs.size )
  {
    while ( this->mPropertyBag->mBaseNode.mUID != v8.mReferencedUIDs.p[v3] )
    {
      if ( ++v3 >= v8.mReferencedUIDs.size )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v3 = -1;
  }
  v4 = v3 != -1;
  if ( v8.mReferencedUIDs.p )
    operator delete[](v8.mReferencedUIDs.p);
  v8.mReferencedUIDs.p = 0i64;
  *(_QWORD *)&v8.mReferencedUIDs.size = 0i64;
  if ( v8.mSourceUIDs.p )
    operator delete[](v8.mSourceUIDs.p);
  mPrev = v8.mPrev;
  mNext = v8.mNext;
  v8.mPrev->mNext = v8.mNext;
  mNext->mPrev = mPrev;
  return v4;
}

// File Line: 441
// RVA: 0x14697E0
__int64 dynamic_initializer_for__DNA::UsedByQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *mPrev; // rax

  DNA::UsedByQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable;
  UFG::qString::qString(&stru_14203D648, "UsedBy");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  mPrev = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D638;
  off_14203D638 = mPrev;
  off_14203D640 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D638;
  DNA::UsedByQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::UsedByQueryNode::Parser::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__DNA::UsedByQueryNode::mParser__);
}

// File Line: 444
// RVA: 0x1A9AD0
UFG::allocator::free_link *__fastcall DNA::UsedByQueryNode::Parser::Parse(
        DNA::UsedByQueryNode::Parser *this,
        const char *syntax)
{
  int v2; // ecx
  UFG::qList<UFG::qString,UFG::qString,1,0> *mNext; // rax
  unsigned __int64 v4; // rbx
  DNA::Database *v5; // rax
  UFG::qTree64Base *PropertyBag; // rbx
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rdi
  UFG::allocator::free_link *v9; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rcx
  UFG::qList<UFG::qString,UFG::qString,1,0> v16[2]; // [rsp+38h] [rbp-20h] BYREF

  v16[0].mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v16;
  v16[0].mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)v16;
  UFG::qTokenize(v16, "()", syntax, 0, 0i64, 0);
  v2 = 0;
  mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v16[0].mNode.mNext;
  if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)v16[0].mNode.mNext == v16 )
    goto LABEL_8;
  do
  {
    ++v2;
    mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)mNext->mNode.mNext;
  }
  while ( mNext != v16 );
  if ( v2 == 2
    && (v4 = UFG::qToUInt64((const char *)v16[0].mNode.mPrev[1].mNext, 0i64),
        DNA::Database::Instance(),
        (PropertyBag = DNA::Database::GetPropertyBag(v5, v4)) != 0i64) )
  {
    v7 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    v8 = v7;
    if ( v7 )
    {
      v9 = v7 + 1;
      v9->mNext = v9;
      v9[1].mNext = v9;
      v8->mNext = (UFG::allocator::free_link *)&DNA::IQueryNode::`vftable;
      v8[3].mNext = (UFG::allocator::free_link *)&DNA::UsedByQueryNode::mParser;
      v8->mNext = (UFG::allocator::free_link *)&DNA::UsedByQueryNode::`vftable;
      v8[4].mNext = (UFG::allocator::free_link *)PropertyBag;
    }
    else
    {
      v8 = 0i64;
    }
  }
  else
  {
LABEL_8:
    v8 = 0i64;
  }
  for ( i = (UFG::qString *)v16[0].mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)v16[0].mNode.mNext != v16;
        i = (UFG::qString *)v16[0].mNode.mNext )
  {
    mPrev = i->mPrev;
    v12 = i->mNext;
    mPrev->mNext = v12;
    v12->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v13 = v16[0].mNode.mPrev;
  v14 = v16[0].mNode.mNext;
  v16[0].mNode.mPrev->mNext = v16[0].mNode.mNext;
  v14->mPrev = v13;
  return v8;
}

// File Line: 460
// RVA: 0x1A9F80
void __fastcall DNA::UsedByQueryNode::Parser::Write(
        DNA::UsedByQueryNode::Parser *this,
        DNA::IQueryNode *queryNode,
        UFG::qStringBuilder *builder)
{
  UFG::qStringBuilder::operator<<(builder, &this->mKey);
  UFG::qStringBuilder::operator<<(builder, "(");
  UFG::qStringBuilder::operator<<(builder, (unsigned __int64)queryNode[1].vfptr->Match);
  UFG::qStringBuilder::operator<<(builder, ")");
}

// File Line: 499
// RVA: 0x1A7E90
void __fastcall DNA::DerivedTypeQueryNode::DerivedTypeQueryNode(
        DNA::DerivedTypeQueryNode *this,
        const char *schemaName)
{
  DNA::Database *v4; // rax

  this->mPrev = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
  this->mNext = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable;
  this->mQueryParser = &DNA::DerivedTypeQueryNode::mParser;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::DerivedTypeQueryNode::`vftable;
  DNA::Database::Instance();
  this->mDerivedScemaType = (DNA::SchemaType *)DNA::Database::GetSchema(v4, schemaName);
}

// File Line: 505
// RVA: 0x1A9000
bool __fastcall DNA::DerivedTypeQueryNode::Match(DNA::DerivedTypeQueryNode *this, DNA::PropertyBag *propertyBag)
{
  UFG::qTree64Base *SchemaType; // rax
  DNA::SchemaType *mDerivedScemaType; // rcx
  unsigned __int64 v5; // rbx
  unsigned __int64 mUID; // rdi
  UFG::ReflectionDB *v7; // rax

  SchemaType = DNA::PropertyBag::GetSchemaType(propertyBag);
  if ( SchemaType )
  {
    mDerivedScemaType = this->mDerivedScemaType;
    v5 = *(_QWORD *)SchemaType[3].mCount;
    mUID = mDerivedScemaType->mReflectionType->mBaseNode.mUID;
    v7 = UFG::ReflectionDB::Instance();
    LOBYTE(SchemaType) = UFG::ReflectionDB::IsDerivedFrom(v7, v5, mUID);
  }
  return (char)SchemaType;
}

// File Line: 510
// RVA: 0x1469520
__int64 dynamic_initializer_for__DNA::DerivedTypeQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *mPrev; // rax

  DNA::DerivedTypeQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable;
  UFG::qString::qString(&stru_14203D688, "DerivedType");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  mPrev = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D678;
  off_14203D678 = mPrev;
  off_14203D680 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D678;
  DNA::DerivedTypeQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::DerivedTypeQueryNode::Parser::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__DNA::DerivedTypeQueryNode::mParser__);
}

// File Line: 513
// RVA: 0x1A9490
DNA::IQueryNode *__fastcall DNA::DerivedTypeQueryNode::Parser::Parse(
        DNA::DerivedTypeQueryNode::Parser *this,
        const char *syntax)
{
  __int64 v2; // rdi
  int v3; // ecx
  UFG::qList<UFG::qString,UFG::qString,1,0> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  __int64 v7; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rcx
  UFG::qList<UFG::qString,UFG::qString,1,0> v14[2]; // [rsp+38h] [rbp-20h] BYREF

  v14[0].mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v14;
  v14[0].mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)v14;
  v2 = 0i64;
  UFG::qTokenize(v14, "(,)", syntax, 0, 0i64, 0);
  v3 = 0;
  mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v14[0].mNode.mNext;
  if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)v14[0].mNode.mNext != v14 )
  {
    do
    {
      ++v3;
      mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)mNext->mNode.mNext;
    }
    while ( mNext != v14 );
    if ( v3 == 2 )
    {
      v5 = v14[0].mNode.mNext->mNext;
      v6 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      if ( v6 )
      {
        DNA::DerivedTypeQueryNode::DerivedTypeQueryNode((DNA::DerivedTypeQueryNode *)v6, (const char *)v5[1].mNext);
        v2 = v7;
      }
    }
  }
  for ( i = (UFG::qString *)v14[0].mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)v14[0].mNode.mNext != v14;
        i = (UFG::qString *)v14[0].mNode.mNext )
  {
    mPrev = i->mPrev;
    v10 = i->mNext;
    mPrev->mNext = v10;
    v10->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v11 = v14[0].mNode.mPrev;
  v12 = v14[0].mNode.mNext;
  v14[0].mNode.mPrev->mNext = v14[0].mNode.mNext;
  v12->mPrev = v11;
  return (DNA::IQueryNode *)v2;
}

// File Line: 525
// RVA: 0x1A9D70
void __fastcall DNA::DerivedTypeQueryNode::Parser::Write(
        DNA::DerivedTypeQueryNode::Parser *this,
        DNA::IQueryNode *queryNode,
        UFG::qStringBuilder *builder)
{
  UFG::qStringBuilder::operator<<(builder, &this->mKey);
  UFG::qStringBuilder::operator<<(builder, "(");
  UFG::qStringBuilder::operator<<(builder, (const char *)queryNode[1].vfptr[4].~IQueryNode);
  UFG::qStringBuilder::operator<<(builder, ")");
}

// File Line: 544
// RVA: 0x1A8360
void __fastcall DNA::OrQueryNode::~OrQueryNode(DNA::OrQueryNode *this)
{
  UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *mNodes; // rbx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *mPrev; // rdx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *mNext; // rax
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v5; // rcx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v6; // rax

  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::OrQueryNode::`vftable;
  mNodes = this->mNodes;
  if ( mNodes )
  {
    UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0>::DeleteNodes(mNodes);
    mPrev = mNodes->mNode.mPrev;
    mNext = mNodes->mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mNodes->mNode.mPrev = &mNodes->mNode;
    mNodes->mNode.mNext = &mNodes->mNode;
    operator delete[](mNodes);
  }
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable;
  v5 = this->mPrev;
  v6 = this->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mPrev = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
  this->mNext = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
}

// File Line: 560
// RVA: 0x1A9060
char __fastcall DNA::OrQueryNode::Match(DNA::OrQueryNode *this, DNA::PropertyBag *propertyBag)
{
  UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *mNodes; // rax
  UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *p_mNext; // rbx

  mNodes = this->mNodes;
  p_mNext = (UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *)&mNodes->mNode.mNext[-1].mNext;
  if ( p_mNext == (UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *)&mNodes[-1].mNode.mNext )
    return 0;
  while ( !((unsigned __int64 (__fastcall *)(UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *, DNA::PropertyBag *))p_mNext->mNode.mPrev->mPrev)(
             p_mNext,
             propertyBag) )
  {
    p_mNext = (UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *)&p_mNext[1].mNode.mPrev[-1].mNext;
    if ( p_mNext == (UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *)((char *)this->mNodes - 8) )
      return 0;
  }
  return 1;
}

// File Line: 573
// RVA: 0x14695D0
__int64 dynamic_initializer_for__DNA::OrQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *mPrev; // rax

  DNA::OrQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable;
  UFG::qString::qString(&stru_14203D6C8, "Or");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  mPrev = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D6B8;
  off_14203D6B8 = mPrev;
  off_14203D6C0 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D6B8;
  DNA::OrQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::OrQueryNode::Parser::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__DNA::OrQueryNode::mParser__);
}

// File Line: 576
// RVA: 0x1A95C0
UFG::allocator::free_link *__fastcall DNA::OrQueryNode::Parser::Parse(
        DNA::OrQueryNode::Parser *this,
        const char *syntax)
{
  int v2; // ecx
  UFG::qList<UFG::qString,UFG::qString,1,0> *mNext; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *i; // rdi
  DNA::IQueryNode *v7; // rax
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v8; // rcx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdi
  UFG::allocator::free_link *v12; // rax
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qList<UFG::qString,UFG::qString,1,0> v19[2]; // [rsp+28h] [rbp-20h] BYREF

  v19[0].mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v19;
  v19[0].mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)v19;
  DNA::CollectArgs(syntax, this->mKey.mLength, v19);
  v2 = 0;
  mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v19[0].mNode.mNext;
  if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)v19[0].mNode.mNext == v19 )
    goto LABEL_14;
  do
  {
    ++v2;
    mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)mNext->mNode.mNext;
  }
  while ( mNext != v19 );
  if ( v2 <= 1 )
  {
LABEL_14:
    v11 = 0i64;
  }
  else
  {
    v4 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
    v5 = v4;
    if ( v4 )
    {
      v4->mNext = v4;
      v4[1].mNext = v4;
    }
    else
    {
      v5 = 0i64;
    }
    for ( i = v19[0].mNode.mNext; i != (UFG::qNode<UFG::qString,UFG::qString> *)v19; i = i->mNext )
    {
      v7 = DNA::ParseSyntax((const char *)i[1].mNext);
      if ( v7 )
      {
        v8 = &v7->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
        v9 = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)v5->mNext;
        v9->mNext = v8;
        v8->mPrev = v9;
        v8->mNext = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)v5;
        v5->mNext = (UFG::allocator::free_link *)v8;
      }
    }
    v10 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    v11 = v10;
    if ( v10 )
    {
      v12 = v10 + 1;
      v12->mNext = v12;
      v12[1].mNext = v12;
      v11->mNext = (UFG::allocator::free_link *)&DNA::IQueryNode::`vftable;
      v11[3].mNext = (UFG::allocator::free_link *)&DNA::OrQueryNode::mParser;
      v11->mNext = (UFG::allocator::free_link *)&DNA::OrQueryNode::`vftable;
      v11[4].mNext = v5;
    }
    else
    {
      v11 = 0i64;
    }
  }
  for ( j = (UFG::qString *)v19[0].mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)v19[0].mNode.mNext != v19;
        j = (UFG::qString *)v19[0].mNode.mNext )
  {
    mPrev = j->mPrev;
    v15 = j->mNext;
    mPrev->mNext = v15;
    v15->mPrev = mPrev;
    j->mPrev = j;
    j->mNext = j;
    UFG::qString::~qString(j);
    operator delete[](j);
  }
  v16 = v19[0].mNode.mPrev;
  v17 = v19[0].mNode.mNext;
  v19[0].mNode.mPrev->mNext = v19[0].mNode.mNext;
  v17->mPrev = v16;
  return v11;
}

// File Line: 623
// RVA: 0x1A8230
void __fastcall DNA::AndQueryNode::~AndQueryNode(DNA::AndQueryNode *this)
{
  UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *mNodes; // rbx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *mPrev; // rdx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *mNext; // rax
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v5; // rcx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v6; // rax

  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::AndQueryNode::`vftable;
  mNodes = this->mNodes;
  if ( mNodes )
  {
    UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0>::DeleteNodes(mNodes);
    mPrev = mNodes->mNode.mPrev;
    mNext = mNodes->mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mNodes->mNode.mPrev = &mNodes->mNode;
    mNodes->mNode.mNext = &mNodes->mNode;
    operator delete[](mNodes);
  }
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable;
  v5 = this->mPrev;
  v6 = this->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mPrev = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
  this->mNext = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
}

// File Line: 640
// RVA: 0x1A8F80
char __fastcall DNA::AndQueryNode::Match(DNA::AndQueryNode *this, DNA::PropertyBag *propertyBag)
{
  UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *mNodes; // rax
  UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *p_mNext; // rbx

  mNodes = this->mNodes;
  p_mNext = (UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *)&mNodes->mNode.mNext[-1].mNext;
  if ( p_mNext == (UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *)&mNodes[-1].mNode.mNext )
    return 1;
  while ( ((unsigned __int64 (__fastcall *)(UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *, DNA::PropertyBag *))p_mNext->mNode.mPrev->mPrev)(
            p_mNext,
            propertyBag) )
  {
    p_mNext = (UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *)&p_mNext[1].mNode.mPrev[-1].mNext;
    if ( p_mNext == (UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *)((char *)this->mNodes - 8) )
      return 1;
  }
  return 0;
}

// File Line: 655
// RVA: 0x1469470
__int64 dynamic_initializer_for__DNA::AndQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *mPrev; // rax

  DNA::AndQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable;
  UFG::qString::qString(&stru_14203D708, "And");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  mPrev = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D6F8;
  off_14203D6F8 = mPrev;
  off_14203D700 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D6F8;
  DNA::AndQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::AndQueryNode::Parser::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__DNA::AndQueryNode::mParser__);
}

// File Line: 658
// RVA: 0x1A92E0
UFG::allocator::free_link *__fastcall DNA::AndQueryNode::Parser::Parse(
        DNA::AndQueryNode::Parser *this,
        const char *syntax)
{
  int v2; // ecx
  UFG::qList<UFG::qString,UFG::qString,1,0> *mNext; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *i; // rdi
  DNA::IQueryNode *v7; // rax
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v8; // rcx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdi
  UFG::allocator::free_link *v12; // rax
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qList<UFG::qString,UFG::qString,1,0> v19[2]; // [rsp+28h] [rbp-20h] BYREF

  v19[0].mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v19;
  v19[0].mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)v19;
  DNA::CollectArgs(syntax, this->mKey.mLength, v19);
  v2 = 0;
  mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v19[0].mNode.mNext;
  if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)v19[0].mNode.mNext == v19 )
    goto LABEL_14;
  do
  {
    ++v2;
    mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)mNext->mNode.mNext;
  }
  while ( mNext != v19 );
  if ( v2 <= 1 )
  {
LABEL_14:
    v11 = 0i64;
  }
  else
  {
    v4 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
    v5 = v4;
    if ( v4 )
    {
      v4->mNext = v4;
      v4[1].mNext = v4;
    }
    else
    {
      v5 = 0i64;
    }
    for ( i = v19[0].mNode.mNext; i != (UFG::qNode<UFG::qString,UFG::qString> *)v19; i = i->mNext )
    {
      v7 = DNA::ParseSyntax((const char *)i[1].mNext);
      if ( v7 )
      {
        v8 = &v7->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
        v9 = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)v5->mNext;
        v9->mNext = v8;
        v8->mPrev = v9;
        v8->mNext = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)v5;
        v5->mNext = (UFG::allocator::free_link *)v8;
      }
    }
    v10 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    v11 = v10;
    if ( v10 )
    {
      v12 = v10 + 1;
      v12->mNext = v12;
      v12[1].mNext = v12;
      v11->mNext = (UFG::allocator::free_link *)&DNA::IQueryNode::`vftable;
      v11[3].mNext = (UFG::allocator::free_link *)&DNA::AndQueryNode::mParser;
      v11->mNext = (UFG::allocator::free_link *)&DNA::AndQueryNode::`vftable;
      v11[4].mNext = v5;
    }
    else
    {
      v11 = 0i64;
    }
  }
  for ( j = (UFG::qString *)v19[0].mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)v19[0].mNode.mNext != v19;
        j = (UFG::qString *)v19[0].mNode.mNext )
  {
    mPrev = j->mPrev;
    v15 = j->mNext;
    mPrev->mNext = v15;
    v15->mPrev = mPrev;
    j->mPrev = j;
    j->mNext = j;
    UFG::qString::~qString(j);
    operator delete[](j);
  }
  v16 = v19[0].mNode.mPrev;
  v17 = v19[0].mNode.mNext;
  v19[0].mNode.mPrev->mNext = v19[0].mNode.mNext;
  v17->mPrev = v16;
  return v11;
}

// File Line: 682
// RVA: 0x1A9DD0
void __fastcall DNA::AndQueryNode::Parser::Write(
        DNA::OrQueryNode::Parser *this,
        DNA::IQueryNode *queryNode,
        UFG::qStringBuilder *builder)
{
  DNA::IQueryNodeVtbl *vfptr; // rax
  __int64 v6; // rbx

  UFG::qStringBuilder::operator<<(builder, &this->mKey);
  UFG::qStringBuilder::operator<<(builder, "(");
  vfptr = queryNode[1].vfptr;
  v6 = (__int64)vfptr->~IQueryNode - 8;
  if ( ($3C6D76EB49DCD21B904442384897A5F6 *)v6 != &vfptr[-1].8 )
  {
    do
    {
      (*(void (__fastcall **)(_QWORD, __int64, UFG::qStringBuilder *))(**(_QWORD **)(v6 + 24) + 8i64))(
        *(_QWORD *)(v6 + 24),
        v6,
        builder);
      v6 = *(_QWORD *)(v6 + 16) - 8i64;
    }
    while ( ($3C6D76EB49DCD21B904442384897A5F6 *)v6 != &queryNode[1].vfptr[-1].8 );
  }
  UFG::qStringBuilder::operator<<(builder, ")");
}

// File Line: 759
// RVA: 0x1A8F10
DNA::IQueryNode *__fastcall DNA::Query::FilePath(char *filePath)
{
  char *mData; // rbx
  UFG::allocator::free_link *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  mData = UFG::qCleanupFilepath(&result, filePath, 92)->mData;
  v2 = UFG::qMalloc(0x70ui64, "Query::PropertyQueryNode", 0i64);
  if ( v2 )
  {
    DNA::PropertyQueryNode::PropertyQueryNode((DNA::PropertyQueryNode *)v2, "$FilePath", mData);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  UFG::qString::~qString(&result);
  return (DNA::IQueryNode *)v4;
}

