// File Line: 20
// RVA: 0x1469890
__int64 dynamic_initializer_for__DNA::IQueryParser::mParsers__()
{
  return atexit(dynamic_atexit_destructor_for__DNA::IQueryParser::mParsers__);
}

// File Line: 33
// RVA: 0x1A8300
void __fastcall DNA::IQueryParser::~IQueryParser(DNA::IQueryParser *this)
{
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v1; // rbx
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v2; // rdx
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v3; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v4; // rcx
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v5; // rax

  this->vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable';
  v1 = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = this->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
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
  const char *v1; // rdi
  DNA::IQueryNode *result; // rax
  int v3; // ebx
  int v4; // eax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> **v5; // rbx
  int v6; // ebp
  char dest[72]; // [rsp+20h] [rbp-48h]

  v1 = syntax;
  if ( !*syntax )
    return 0i64;
  result = (DNA::IQueryNode *)UFG::qStringFind(syntax, "(");
  if ( result )
  {
    v3 = (_DWORD)result - (_DWORD)v1;
    UFG::qMemCopy(dest, v1, (_DWORD)result - (_DWORD)v1);
    dest[v3] = 0;
    v4 = UFG::qStringHash32(dest, 0xFFFFFFFF);
    v5 = &DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
    v6 = v4;
    if ( &DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext == (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> **)((char *)&DNA::IQueryParser::mParsers - 8) )
      goto LABEL_9;
    while ( 1 )
    {
      if ( *((_DWORD *)v5 + 14) == -1 )
        *((_DWORD *)v5 + 14) = UFG::qStringHash32((const char *)v5[6], 0xFFFFFFFF);
      if ( *((_DWORD *)v5 + 14) == v6 )
        break;
      v5 = &v5[2][-1].mNext;
      if ( v5 == (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> **)((char *)&DNA::IQueryParser::mParsers - 8) )
        goto LABEL_9;
    }
    if ( v5 )
      result = (DNA::IQueryNode *)((__int64 (__fastcall *)(UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> **, const char *))(*v5)->mPrev)(
                                    v5,
                                    v1);
    else
LABEL_9:
      result = 0i64;
  }
  return result;
}

// File Line: 77
// RVA: 0x1A8730
void __fastcall DNA::CollectArgs(const char *syntax, int keyLength, UFG::qList<UFG::qString,UFG::qString,1,0> *result)
{
  UFG::qList<UFG::qString,UFG::qString,1,0> *v3; // r14
  const char *v4; // rbx
  int v5; // edi
  const char *v6; // r15
  UFG::qString *v7; // rax
  UFG::qString *v8; // rax
  UFG::qString *v9; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rax
  bool v11; // al

  v3 = result;
  v4 = &syntax[keyLength + 1];
  v5 = 0;
  v6 = &syntax[keyLength + 1];
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
      v10 = v3->mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v9->mPrev;
      v9->mPrev = v10;
      v9->mNext = &v3->mNode;
      v3->mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v9->mPrev;
      v6 = v4 + 1;
    }
    v11 = *v4++ != 0;
  }
  while ( v11 );
}

// File Line: 137
// RVA: 0x14693C0
__int64 dynamic_initializer_for__DNA::AllQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v1; // rax

  DNA::AllQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable';
  UFG::qString::qString(&stru_14203D588, "All");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  v1 = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D578;
  off_14203D578 = v1;
  off_14203D580 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D578;
  DNA::AllQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::AllQueryNode::Parser::`vftable';
  return atexit(dynamic_atexit_destructor_for__DNA::AllQueryNode::mParser__);
}

// File Line: 140
// RVA: 0x1A9270
UFG::allocator::free_link *__fastcall DNA::AllQueryNode::Parser::Parse(DNA::AllQueryNode::Parser *this, const char *syntax)
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
  v3->mNext = (UFG::allocator::free_link *)&DNA::IQueryNode::`vftable';
  v3[3].mNext = (UFG::allocator::free_link *)&DNA::AllQueryNode::mParser;
  v3->mNext = (UFG::allocator::free_link *)&DNA::AllQueryNode::`vftable';
  return v3;
}

// File Line: 146
// RVA: 0x1A9D40
void __fastcall DNA::AllQueryNode::Parser::Write(DNA::AllQueryNode::Parser *this, DNA::IQueryNode *queryNode, UFG::qStringBuilder *builder)
{
  UFG::qStringBuilder *v3; // rbx

  v3 = builder;
  UFG::qStringBuilder::operator<<(builder, &this->mKey);
  UFG::qStringBuilder::operator<<(v3, "()");
}

// File Line: 162
// RVA: 0x1A7F00
void __fastcall DNA::PropertyQueryNode::PropertyQueryNode(DNA::PropertyQueryNode *this, const char *name, const char *v)
{
  const char *v3; // rbp
  const char *v4; // rsi
  DNA::PropertyQueryNode *v5; // r14
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v6; // rax

  v3 = v;
  v4 = name;
  v5 = this;
  v6 = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)&this->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable';
  this->mQueryParser = (DNA::IQueryParser *)&DNA::PropertyQueryNode::mParser;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::PropertyQueryNode::`vftable';
  UFG::qString::qString(&this->mPropertyName);
  UFG::qString::qString(&v5->mPropertyValue);
  UFG::qString::Set(&v5->mPropertyName, v4);
  DNA::DataConverter::ToString(&v5->mPropertyValue, v3);
}

// File Line: 189
// RVA: 0x1A90E0
UFG::qBaseTreeRB *__fastcall DNA::PropertyQueryNode::Match(DNA::PropertyQueryNode *this, DNA::PropertyBag *propertyBag)
{
  DNA::PropertyQueryNode *v2; // rbx
  UFG::qBaseTreeRB *result; // rax
  DNA::PropertyData *v4; // rdi
  bool v5; // bl
  UFG::qString v; // [rsp+28h] [rbp-30h]

  v2 = this;
  result = DNA::PropertyBag::GetProperty(propertyBag, this->mPropertyName.mData);
  v4 = (DNA::PropertyData *)result;
  if ( result )
  {
    UFG::qString::qString(&v);
    DNA::PropertyData::GetRaw(v4, 0, &v);
    v5 = (unsigned int)UFG::qWildcardMatchInsensitive(v2->mPropertyValue.mData, v.mData) == 1;
    UFG::qString::~qString(&v);
    result = (UFG::qBaseTreeRB *)v5;
  }
  return result;
}

// File Line: 201
// RVA: 0x1469680
__int64 dynamic_initializer_for__DNA::PropertyQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v1; // rax

  DNA::PropertyQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable';
  UFG::qString::qString(&stru_14203D5C8, "Property");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  v1 = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D5B8;
  off_14203D5B8 = v1;
  off_14203D5C0 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D5B8;
  DNA::PropertyQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::PropertyQueryNode::Parser::`vftable';
  return atexit(dynamic_atexit_destructor_for__DNA::PropertyQueryNode::mParser__);
}

// File Line: 204
// RVA: 0x1A9770
DNA::IQueryNode *__fastcall DNA::PropertyQueryNode::Parser::Parse(DNA::PropertyQueryNode::Parser *this, const char *syntax)
{
  __int64 v2; // rdi
  int v3; // ecx
  __int64 *v4; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rsi
  UFG::allocator::free_link *v7; // rax
  __int64 v8; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rax
  __int64 *v12; // rdx
  UFG::qString *v13; // rcx
  __int64 *v15; // [rsp+38h] [rbp-20h]
  UFG::qString *v16; // [rsp+40h] [rbp-18h]

  v15 = (__int64 *)&v15;
  v16 = (UFG::qString *)&v15;
  v2 = 0i64;
  UFG::qTokenize((UFG::qList<UFG::qString,UFG::qString,1,0> *)&v15, "(,)", syntax, 0, 0i64, 0);
  v3 = 0;
  v4 = (__int64 *)v16;
  if ( v16 != (UFG::qString *)&v15 )
  {
    do
    {
      ++v3;
      v4 = (__int64 *)v4[1];
    }
    while ( v4 != (__int64 *)&v15 );
    if ( v3 == 3 )
    {
      v5 = v16->mNext;
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
  for ( i = v16; v16 != (UFG::qString *)&v15; i = v16 )
  {
    v10 = i->mPrev;
    v11 = i->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v12 = v15;
  v13 = v16;
  v15[1] = (__int64)v16;
  v13->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v12;
  return (DNA::IQueryNode *)v2;
}

// File Line: 218
// RVA: 0x1A9E70
void __fastcall DNA::PropertyQueryNode::Parser::Write(DNA::PropertyQueryNode::Parser *this, DNA::IQueryNode *queryNode, UFG::qStringBuilder *builder)
{
  DNA::IQueryNode *v3; // rbx
  UFG::qStringBuilder *v4; // rdi

  v3 = queryNode;
  v4 = builder;
  UFG::qStringBuilder::operator<<(builder, &this->mKey);
  UFG::qStringBuilder::operator<<(v4, "(");
  UFG::qStringBuilder::operator<<(v4, (UFG::qString *)&v3[1]);
  UFG::qStringBuilder::operator<<(v4, ",");
  UFG::qStringBuilder::operator<<(v4, (UFG::qString *)&v3[2].mPrev);
  UFG::qStringBuilder::operator<<(v4, ")");
}

// File Line: 267
// RVA: 0x1A7FA0
void __fastcall DNA::ReferencedByQueryNode::ReferencedByQueryNode(DNA::ReferencedByQueryNode *this, UFG::qList<DNA::PropertyBagHandle,DNA::PropertyBagHandle,1,0> *propertyBags, bool recursive)
{
  UFG::qList<DNA::PropertyBagHandle,DNA::PropertyBagHandle,1,0> *v3; // r13
  DNA::ReferencedByQueryNode *v4; // rdi
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v5; // rax
  DNA::PropertyBagHandle *v6; // rbp
  unsigned __int64 v7; // r12
  __int64 v8; // r15
  unsigned int v9; // esi
  unsigned int v10; // ebx
  unsigned int v11; // ebx
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  unsigned __int64 *v14; // r14
  __int64 v15; // r9

  v3 = propertyBags;
  v4 = this;
  v5 = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)&this->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable';
  this->mQueryParser = (DNA::IQueryParser *)&DNA::ReferencedByQueryNode::mParser;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::ReferencedByQueryNode::`vftable';
  this->mRecursive = recursive;
  *(_QWORD *)&this->mInitialCount = 0i64;
  this->mSourceUIDs.p = 0i64;
  this->mSourceUIDs.capacity = 0;
  this->mReferencedUIDs.p = 0i64;
  *(_QWORD *)&this->mReferencedUIDs.size = 0i64;
  v6 = (DNA::PropertyBagHandle *)propertyBags->mNode.mNext;
  if ( v6 != (DNA::PropertyBagHandle *)propertyBags )
  {
    do
    {
      if ( DNA::PropertyBagHandle::Get(v6) )
      {
        v7 = DNA::PropertyBagHandle::Get(v6)->mBaseNode.mUID;
        v8 = v4->mSourceUIDs.size;
        v9 = v8 + 1;
        v10 = v4->mSourceUIDs.capacity;
        if ( (signed int)v8 + 1 > v10 )
        {
          if ( v10 )
            v11 = 2 * v10;
          else
            v11 = 1;
          for ( ; v11 < v9; v11 *= 2 )
            ;
          if ( v11 <= 2 )
            v11 = 2;
          if ( v11 - v9 > 0x10000 )
            v11 = v8 + 65537;
          if ( v11 != (_DWORD)v8 )
          {
            v12 = 8i64 * v11;
            if ( !is_mul_ok(v11, 8ui64) )
              v12 = -1i64;
            v13 = UFG::qMalloc(v12, "qArray.Add", 0i64);
            v14 = (unsigned __int64 *)v13;
            if ( v4->mSourceUIDs.p )
            {
              v15 = 0i64;
              if ( v4->mSourceUIDs.size )
              {
                do
                {
                  v13[v15] = (UFG::allocator::free_link)v4->mSourceUIDs.p[v15];
                  v15 = (unsigned int)(v15 + 1);
                }
                while ( (unsigned int)v15 < v4->mSourceUIDs.size );
              }
              operator delete[](v4->mSourceUIDs.p);
            }
            v4->mSourceUIDs.p = v14;
            v4->mSourceUIDs.capacity = v11;
          }
        }
        v4->mSourceUIDs.size = v9;
        v4->mSourceUIDs.p[v8] = v7;
      }
      v6 = (DNA::PropertyBagHandle *)v6->mNext;
    }
    while ( v6 != (DNA::PropertyBagHandle *)v3 );
  }
  DNA::ReferencedByQueryNode::EvaluateReferences(v4);
}

// File Line: 282
// RVA: 0x1A8150
void __fastcall DNA::ReferencedByQueryNode::ReferencedByQueryNode(DNA::ReferencedByQueryNode *this, DNA::PropertyBag *propertyBag, bool recursive)
{
  DNA::ReferencedByQueryNode *v3; // rdi
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v4; // rax
  unsigned __int64 v5; // r14
  __int64 v6; // rbp
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int v9; // edx

  v3 = this;
  v4 = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)&this->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable';
  this->mQueryParser = (DNA::IQueryParser *)&DNA::ReferencedByQueryNode::mParser;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::ReferencedByQueryNode::`vftable';
  this->mRecursive = recursive;
  *(_QWORD *)&this->mInitialCount = 0i64;
  this->mSourceUIDs.p = 0i64;
  this->mSourceUIDs.capacity = 0;
  this->mReferencedUIDs.p = 0i64;
  *(_QWORD *)&this->mReferencedUIDs.size = 0i64;
  v5 = propertyBag->mBaseNode.mUID;
  v6 = this->mSourceUIDs.size;
  v7 = v6 + 1;
  v8 = this->mSourceUIDs.capacity;
  if ( (signed int)v6 + 1 > v8 )
  {
    if ( v8 )
      v9 = 2 * v8;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 <= 2 )
      v9 = 2;
    if ( v9 - v7 > 0x10000 )
      v9 = v6 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mSourceUIDs,
      v9,
      "qArray.Add");
  }
  v3->mSourceUIDs.size = v7;
  v3->mSourceUIDs.p[v6] = v5;
  DNA::ReferencedByQueryNode::EvaluateReferences(v3);
}

// File Line: 288
// RVA: 0x1A8880
void __fastcall DNA::ReferencedByQueryNode::EvaluateReferences(DNA::ReferencedByQueryNode *this)
{
  DNA::ReferencedByQueryNode *v1; // r13
  unsigned __int64 v2; // rax
  UFG::allocator::free_link *v3; // rax
  unsigned __int64 *v4; // rbx
  signed __int64 v5; // r9
  signed __int64 v6; // r8
  unsigned int v7; // eax
  __int64 v8; // rcx
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v9; // rsi
  unsigned __int64 *v10; // rbx
  DNA::Database *v11; // rax
  UFG::qTree64Base *v12; // rax
  UFG::qTree64Base *v13; // rbx
  UFG::qTree64Base::BaseNode **v14; // rax
  DNA::SchemaField *v15; // rcx
  UFG::qBaseTreeRB *v16; // rax
  DNA::PropertyData *v17; // rbx
  unsigned int v18; // er12
  unsigned int v19; // er13
  __int64 v20; // r14
  unsigned __int64 v21; // r15
  unsigned int v22; // eax
  UFG::qReflectInventoryBase **v23; // rcx
  unsigned int v24; // ebx
  unsigned int v25; // edi
  unsigned int v26; // ebx
  unsigned __int64 v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::qReflectInventoryBase **v29; // rbp
  signed __int64 v30; // r9
  signed __int64 v31; // r8
  UFG::qReflectInventoryBase **v32; // rax
  unsigned int v33; // er15
  unsigned int v34; // er12
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
  signed __int64 v45; // r9
  signed __int64 v46; // r8
  unsigned __int64 *v47; // rax
  __int64 v48; // rdi
  unsigned int v49; // ecx
  UFG::qReflectInventoryBase **v50; // rax
  unsigned int v51; // eax
  unsigned int v52; // ebx
  unsigned int v53; // edx
  UFG::qReflectInventoryBase **v54; // rax
  UFG::qBaseTreeRB *i; // r13
  unsigned int v56; // er12
  unsigned int v57; // ebp
  __int64 v58; // r14
  UFG::qNode<DNA::SchemaField,DNA::SchemaField> *v59; // r15
  unsigned int v60; // eax
  UFG::qReflectInventoryBase **v61; // rcx
  unsigned int v62; // ebx
  unsigned int v63; // edi
  unsigned int v64; // ebx
  unsigned __int64 v65; // rax
  UFG::allocator::free_link *v66; // rax
  UFG::qReflectInventoryBase **v67; // rbp
  signed __int64 v68; // r9
  signed __int64 v69; // r8
  UFG::qReflectInventoryBase **v70; // rax
  UFG::qBaseTreeRB *v71; // [rsp+20h] [rbp-68h]
  UFG::qTree64Base *v72; // [rsp+28h] [rbp-60h]
  DNA::SchemaField *v73; // [rsp+30h] [rbp-58h]
  DNA::ReferencedByQueryNode *v74; // [rsp+90h] [rbp+8h]
  int v75; // [rsp+98h] [rbp+10h]
  DNA::PropertyBag *v; // [rsp+A0h] [rbp+18h]
  DNA::SchemaField *v77; // [rsp+A8h] [rbp+20h]

  v74 = this;
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
      v5 = 0i64;
      if ( v1->mReferencedUIDs.size )
      {
        do
        {
          v6 = v5;
          v5 = (unsigned int)(v5 + 1);
          v3[v6] = (UFG::allocator::free_link)v1->mReferencedUIDs.p[v6];
        }
        while ( (unsigned int)v5 < v1->mReferencedUIDs.size );
      }
      operator delete[](v1->mReferencedUIDs.p);
    }
    v1->mReferencedUIDs.p = v4;
    v1->mReferencedUIDs.capacity = 256;
  }
  v7 = v1->mSourceUIDs.size;
  v8 = 0i64;
  v9 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v1->mSourceUIDs;
  v1->mInitialCount = v7;
  v75 = 0;
  if ( v7 )
  {
    do
    {
      v10 = &v1->mSourceUIDs.p[v8];
      DNA::Database::Instance();
      v12 = DNA::Database::GetPropertyBag(v11, *v10);
      v13 = v12;
      v72 = v12;
      if ( v12 )
      {
        if ( DNA::PropertyBag::GetSchemaType((DNA::PropertyBag *)v12) )
        {
          v14 = DNA::PropertyBag::GetSchemaType((DNA::PropertyBag *)v13)[2].mHead.mNeighbours;
          v15 = (DNA::SchemaField *)v14[1];
          v73 = (DNA::SchemaField *)v14;
          v77 = v15;
          if ( v15 != (DNA::SchemaField *)v14 )
          {
            do
            {
              v16 = DNA::PropertyBag::GetProperty((DNA::PropertyBag *)v13, v15->mName.mData);
              v17 = (DNA::PropertyData *)v16;
              v71 = v16;
              if ( v16 )
              {
                if ( LODWORD(v16[1].mRoot.mParent) == -915936389 )
                {
                  v18 = 0;
                  v19 = DNA::PropertyData::NumItems((DNA::PropertyData *)v16);
                  if ( v19 )
                  {
                    do
                    {
                      v = 0i64;
                      DNA::PropertyData::Get(v17, v18, &v);
                      if ( v )
                      {
                        v20 = v9->size;
                        v21 = v->mBaseNode.mUID;
                        v22 = 0;
                        if ( !(_DWORD)v20 )
                          goto LABEL_24;
                        v23 = v9->p;
                        while ( (UFG::qReflectInventoryBase *)v21 != *v23 )
                        {
                          ++v22;
                          ++v23;
                          if ( v22 >= (unsigned int)v20 )
                            goto LABEL_24;
                        }
                        if ( v22 == -1 )
                        {
LABEL_24:
                          v24 = v9->capacity;
                          v25 = v20 + 1;
                          if ( (signed int)v20 + 1 > v24 )
                          {
                            if ( v24 )
                              v26 = 2 * v24;
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
                              if ( v9->p )
                              {
                                v30 = 0i64;
                                if ( v9->size )
                                {
                                  do
                                  {
                                    v31 = v30;
                                    v30 = (unsigned int)(v30 + 1);
                                    v28[v31] = (UFG::allocator::free_link)v9->p[v31];
                                  }
                                  while ( (unsigned int)v30 < v9->size );
                                }
                                operator delete[](v9->p);
                              }
                              v9->p = v29;
                              v9->capacity = v26;
                            }
                          }
                          v32 = v9->p;
                          v17 = (DNA::PropertyData *)v71;
                          v9->size = v25;
                          v32[v20] = (UFG::qReflectInventoryBase *)v21;
                        }
                      }
                      ++v18;
                    }
                    while ( v18 < v19 );
                  }
                  v1 = v74;
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
                        if ( (signed int)v35 + 1 > v39 )
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
                              v45 = 0i64;
                              if ( v1->mReferencedUIDs.size )
                              {
                                do
                                {
                                  v46 = v45;
                                  v45 = (unsigned int)(v45 + 1);
                                  v43[v46] = (UFG::allocator::free_link)v1->mReferencedUIDs.p[v46];
                                }
                                while ( (unsigned int)v45 < v1->mReferencedUIDs.size );
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
                      if ( v1->mRecursive == 1 )
                      {
                        v48 = v9->size;
                        v49 = 0;
                        if ( !(_DWORD)v48 )
                          goto LABEL_81;
                        v50 = v9->p;
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
                          v51 = v9->capacity;
                          v52 = v48 + 1;
                          if ( (signed int)v48 + 1 > v51 )
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
                            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v9, v53, "qArray.Add");
                            v36 = v;
                          }
                          v54 = v9->p;
                          v9->size = v52;
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
              v15 = (DNA::SchemaField *)v77->mNext;
              v77 = v15;
            }
            while ( v15 != v73 );
          }
        }
        else
        {
          for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v13->mCount);
                i;
                i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&v13->mCount, &i->mRoot) )
          {
            if ( LODWORD(i[1].mRoot.mParent) == -915936389 )
            {
              v56 = 0;
              v57 = DNA::PropertyData::NumItems((DNA::PropertyData *)i);
              LODWORD(v) = v57;
              if ( v57 )
              {
                do
                {
                  v77 = 0i64;
                  DNA::PropertyData::Get((DNA::PropertyData *)i, v56, (DNA::PropertyBag **)&v77);
                  if ( v77 )
                  {
                    v58 = v9->size;
                    v59 = v77->mPrev;
                    v60 = 0;
                    if ( !(_DWORD)v58 )
                      goto LABEL_104;
                    v61 = v9->p;
                    while ( v59 != (UFG::qNode<DNA::SchemaField,DNA::SchemaField> *)*v61 )
                    {
                      ++v60;
                      ++v61;
                      if ( v60 >= (unsigned int)v58 )
                        goto LABEL_104;
                    }
                    if ( v60 == -1 )
                    {
LABEL_104:
                      v62 = v9->capacity;
                      v63 = v58 + 1;
                      if ( (signed int)v58 + 1 > v62 )
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
                          if ( v9->p )
                          {
                            v68 = 0i64;
                            if ( v9->size )
                            {
                              do
                              {
                                v69 = v68;
                                v68 = (unsigned int)(v68 + 1);
                                v66[v69] = (UFG::allocator::free_link)v9->p[v69];
                              }
                              while ( (unsigned int)v68 < v9->size );
                            }
                            operator delete[](v9->p);
                          }
                          v9->p = v67;
                          v57 = (unsigned int)v;
                          v9->capacity = v64;
                        }
                      }
                      v70 = v9->p;
                      v9->size = v63;
                      v70[v58] = (UFG::qReflectInventoryBase *)v59;
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
      v1 = v74;
      v8 = (unsigned int)(v75 + 1);
      v75 = v8;
    }
    while ( (unsigned int)v8 < v9->size );
  }
}    v9->size = v63;
                      v70[v58] = (UFG:

// File Line: 367
// RVA: 0x1A9160
bool __fastcall DNA::ReferencedByQueryNode::Match(DNA::ReferencedByQueryNode *this, DNA::PropertyBag *propertyBag)
{
  unsigned __int64 v2; // r8
  unsigned int v3; // edx
  unsigned int v4; // eax
  unsigned __int64 *v5; // rcx

  v2 = propertyBag->mBaseNode.mUID;
  v3 = this->mReferencedUIDs.size;
  v4 = 0;
  if ( v3 )
  {
    v5 = this->mReferencedUIDs.p;
    while ( v2 != *v5 )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
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
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v1; // rax

  DNA::ReferencedByQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable';
  UFG::qString::qString(&stru_14203D608, "ReferencedBy");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  v1 = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D5F8;
  off_14203D5F8 = v1;
  off_14203D600 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D5F8;
  DNA::ReferencedByQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::ReferencedByQueryNode::Parser::`vftable';
  return atexit(dynamic_atexit_destructor_for__DNA::ReferencedByQueryNode::mParser__);
}

// File Line: 374
// RVA: 0x1A98A0
DNA::IQueryNode *__fastcall DNA::ReferencedByQueryNode::Parser::Parse(DNA::ReferencedByQueryNode::Parser *this, const char *syntax)
{
  __int64 v2; // rsi
  signed int v3; // ecx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v4; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v5; // r14
  UFG::qNode<UFG::qString,UFG::qString> *i; // rbx
  UFG::allocator::free_link *v7; // rdi
  unsigned __int64 v8; // rax
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v9; // rax
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v10; // rcx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v11; // rax
  UFG::allocator::free_link *v12; // rbx
  char v13; // al
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
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+38h] [rbp-28h]
  UFG::qList<DNA::PropertyBagHandle,DNA::PropertyBagHandle,1,0> propertyBags; // [rsp+48h] [rbp-18h]

  list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
  list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
  v2 = 0i64;
  UFG::qTokenize(&list, "(,)", syntax, 0, 0i64, 0);
  v3 = 0;
  v4 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext;
  if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list )
  {
    do
    {
      ++v3;
      v4 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v4->mNode.mNext;
    }
    while ( v4 != &list );
    if ( v3 > 2 )
    {
      v5 = list.mNode.mNext->mNext;
      propertyBags.mNode.mPrev = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&propertyBags;
      propertyBags.mNode.mNext = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&propertyBags;
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
        v11 = propertyBags.mNode.mPrev;
        propertyBags.mNode.mPrev->mNext = v10;
        v10->mPrev = v11;
        v10->mNext = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&propertyBags;
        propertyBags.mNode.mPrev = v10;
      }
      v12 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
      if ( v12 )
      {
        v13 = UFG::qToBool((const char *)v5[1].mNext, 0);
        DNA::ReferencedByQueryNode::ReferencedByQueryNode((DNA::ReferencedByQueryNode *)v12, &propertyBags, v13);
        v2 = v14;
      }
      for ( j = (DNA::PropertyBagHandle *)propertyBags.mNode.mNext;
            (UFG::qList<DNA::PropertyBagHandle,DNA::PropertyBagHandle,1,0> *)propertyBags.mNode.mNext != &propertyBags;
            j = (DNA::PropertyBagHandle *)propertyBags.mNode.mNext )
      {
        v16 = j->mPrev;
        v17 = j->mNext;
        v16->mNext = v17;
        v17->mPrev = v16;
        j->mPrev = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&j->mPrev;
        j->mNext = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&j->mPrev;
        DNA::PropertyBagHandle::~PropertyBagHandle(j);
        operator delete[](j);
      }
      v18 = propertyBags.mNode.mPrev;
      v19 = propertyBags.mNode.mNext;
      propertyBags.mNode.mPrev->mNext = propertyBags.mNode.mNext;
      v19->mPrev = v18;
      propertyBags.mNode.mPrev = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&propertyBags;
      propertyBags.mNode.mNext = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&propertyBags;
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
    k->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&k->mPrev;
    k->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&k->mPrev;
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
void __fastcall DNA::ReferencedByQueryNode::Parser::Write(DNA::ReferencedByQueryNode::Parser *this, DNA::IQueryNode *queryNode, UFG::qStringBuilder *builder)
{
  DNA::IQueryNode *v3; // rsi
  UFG::qStringBuilder *v4; // rdi
  __int64 v5; // rbx

  v3 = queryNode;
  v4 = builder;
  UFG::qStringBuilder::operator<<(builder, &this->mKey);
  UFG::qStringBuilder::operator<<(v4, "(");
  UFG::qStringBuilder::operator<<(v4, (const bool)v3[1].vfptr);
  v5 = 0i64;
  if ( HIDWORD(v3[1].vfptr) )
  {
    do
    {
      UFG::qStringBuilder::operator<<(v4, ",");
      UFG::qStringBuilder::operator<<(v4, *((_QWORD *)&v3[1].mNext->mPrev + v5));
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < HIDWORD(v3[1].vfptr) );
  }
  UFG::qStringBuilder::operator<<(v4, ")");
}

// File Line: 436
// RVA: 0x1A9190
_BOOL8 __fastcall DNA::UsedByQueryNode::Match(DNA::UsedByQueryNode *this, DNA::PropertyBag *propertyBag)
{
  DNA::UsedByQueryNode *v2; // rbx
  signed int v3; // eax
  bool v4; // bl
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v5; // rdx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v6; // rcx
  DNA::ReferencedByQueryNode v8; // [rsp+30h] [rbp-58h]

  v2 = this;
  DNA::ReferencedByQueryNode::ReferencedByQueryNode(&v8, propertyBag, 0);
  v3 = 0;
  if ( v8.mReferencedUIDs.size )
  {
    while ( v2->mPropertyBag->mBaseNode.mUID != v8.mReferencedUIDs.p[v3] )
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
  v5 = v8.mPrev;
  v6 = v8.mNext;
  v8.mPrev->mNext = v8.mNext;
  v6->mPrev = v5;
  return v4;
}

// File Line: 441
// RVA: 0x14697E0
__int64 dynamic_initializer_for__DNA::UsedByQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v1; // rax

  DNA::UsedByQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable';
  UFG::qString::qString(&stru_14203D648, "UsedBy");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  v1 = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D638;
  off_14203D638 = v1;
  off_14203D640 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D638;
  DNA::UsedByQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::UsedByQueryNode::Parser::`vftable';
  return atexit(dynamic_atexit_destructor_for__DNA::UsedByQueryNode::mParser__);
}

// File Line: 444
// RVA: 0x1A9AD0
UFG::allocator::free_link *__fastcall DNA::UsedByQueryNode::Parser::Parse(DNA::UsedByQueryNode::Parser *this, const char *syntax)
{
  int v2; // ecx
  __int64 *v3; // rax
  unsigned __int64 v4; // rbx
  DNA::Database *v5; // rax
  UFG::qTree64Base *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rdi
  UFG::allocator::free_link *v9; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rax
  __int64 *v13; // rdx
  UFG::qString *v14; // rcx
  __int64 *v16; // [rsp+38h] [rbp-20h]
  UFG::qString *v17; // [rsp+40h] [rbp-18h]

  v16 = (__int64 *)&v16;
  v17 = (UFG::qString *)&v16;
  UFG::qTokenize((UFG::qList<UFG::qString,UFG::qString,1,0> *)&v16, "()", syntax, 0, 0i64, 0);
  v2 = 0;
  v3 = (__int64 *)v17;
  if ( v17 == (UFG::qString *)&v16 )
    goto LABEL_15;
  do
  {
    ++v2;
    v3 = (__int64 *)v3[1];
  }
  while ( v3 != (__int64 *)&v16 );
  if ( v2 == 2
    && (v4 = UFG::qToUInt64((const char *)v16[3], 0i64),
        DNA::Database::Instance(),
        (v6 = DNA::Database::GetPropertyBag(v5, v4)) != 0i64) )
  {
    v7 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    v8 = v7;
    if ( v7 )
    {
      v9 = v7 + 1;
      v9->mNext = v9;
      v9[1].mNext = v9;
      v8->mNext = (UFG::allocator::free_link *)&DNA::IQueryNode::`vftable';
      v8[3].mNext = (UFG::allocator::free_link *)&DNA::UsedByQueryNode::mParser;
      v8->mNext = (UFG::allocator::free_link *)&DNA::UsedByQueryNode::`vftable';
      v8[4].mNext = (UFG::allocator::free_link *)v6;
    }
    else
    {
      v8 = 0i64;
    }
  }
  else
  {
LABEL_15:
    v8 = 0i64;
  }
  for ( i = v17; v17 != (UFG::qString *)&v16; i = v17 )
  {
    v11 = i->mPrev;
    v12 = i->mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v13 = v16;
  v14 = v17;
  v16[1] = (__int64)v17;
  v14->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v13;
  return v8;
}

// File Line: 460
// RVA: 0x1A9F80
void __fastcall DNA::UsedByQueryNode::Parser::Write(DNA::UsedByQueryNode::Parser *this, DNA::IQueryNode *queryNode, UFG::qStringBuilder *builder)
{
  DNA::IQueryNode *v3; // rbx
  UFG::qStringBuilder *v4; // rdi

  v3 = queryNode;
  v4 = builder;
  UFG::qStringBuilder::operator<<(builder, &this->mKey);
  UFG::qStringBuilder::operator<<(v4, "(");
  UFG::qStringBuilder::operator<<(v4, (const unsigned __int64)v3[1].vfptr->Match);
  UFG::qStringBuilder::operator<<(v4, ")");
}

// File Line: 499
// RVA: 0x1A7E90
void __fastcall DNA::DerivedTypeQueryNode::DerivedTypeQueryNode(DNA::DerivedTypeQueryNode *this, const char *schemaName)
{
  const char *v2; // rbx
  DNA::DerivedTypeQueryNode *v3; // rdi
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v4; // rax
  DNA::Database *v5; // rax

  v2 = schemaName;
  v3 = this;
  v4 = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)&this->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable';
  this->mQueryParser = (DNA::IQueryParser *)&DNA::DerivedTypeQueryNode::mParser;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::DerivedTypeQueryNode::`vftable';
  DNA::Database::Instance();
  v3->mDerivedScemaType = (DNA::SchemaType *)DNA::Database::GetSchema(v5, v2);
}

// File Line: 505
// RVA: 0x1A9000
bool __fastcall DNA::DerivedTypeQueryNode::Match(DNA::DerivedTypeQueryNode *this, DNA::PropertyBag *propertyBag)
{
  DNA::DerivedTypeQueryNode *v2; // rbx
  UFG::qTree64Base *v3; // rax
  DNA::SchemaType *v4; // rcx
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rdi
  UFG::ReflectionDB *v7; // rax

  v2 = this;
  v3 = DNA::PropertyBag::GetSchemaType(propertyBag);
  if ( v3 )
  {
    v4 = v2->mDerivedScemaType;
    v5 = *(_QWORD *)v3[3].mCount;
    v6 = v4->mReflectionType->mBaseNode.mUID;
    v7 = UFG::ReflectionDB::Instance();
    LOBYTE(v3) = UFG::ReflectionDB::IsDerivedFrom(v7, v5, v6);
  }
  return (char)v3;
}

// File Line: 510
// RVA: 0x1469520
__int64 dynamic_initializer_for__DNA::DerivedTypeQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v1; // rax

  DNA::DerivedTypeQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable';
  UFG::qString::qString(&stru_14203D688, "DerivedType");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  v1 = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D678;
  off_14203D678 = v1;
  off_14203D680 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D678;
  DNA::DerivedTypeQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::DerivedTypeQueryNode::Parser::`vftable';
  return atexit(dynamic_atexit_destructor_for__DNA::DerivedTypeQueryNode::mParser__);
}

// File Line: 513
// RVA: 0x1A9490
DNA::IQueryNode *__fastcall DNA::DerivedTypeQueryNode::Parser::Parse(DNA::DerivedTypeQueryNode::Parser *this, const char *syntax)
{
  __int64 v2; // rdi
  int v3; // ecx
  __int64 *v4; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  __int64 v7; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rax
  __int64 *v11; // rdx
  UFG::qString *v12; // rcx
  __int64 *v14; // [rsp+38h] [rbp-20h]
  UFG::qString *v15; // [rsp+40h] [rbp-18h]

  v14 = (__int64 *)&v14;
  v15 = (UFG::qString *)&v14;
  v2 = 0i64;
  UFG::qTokenize((UFG::qList<UFG::qString,UFG::qString,1,0> *)&v14, "(,)", syntax, 0, 0i64, 0);
  v3 = 0;
  v4 = (__int64 *)v15;
  if ( v15 != (UFG::qString *)&v14 )
  {
    do
    {
      ++v3;
      v4 = (__int64 *)v4[1];
    }
    while ( v4 != (__int64 *)&v14 );
    if ( v3 == 2 )
    {
      v5 = v15->mNext;
      v6 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      if ( v6 )
      {
        DNA::DerivedTypeQueryNode::DerivedTypeQueryNode((DNA::DerivedTypeQueryNode *)v6, (const char *)v5[1].mNext);
        v2 = v7;
      }
    }
  }
  for ( i = v15; v15 != (UFG::qString *)&v14; i = v15 )
  {
    v9 = i->mPrev;
    v10 = i->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v11 = v14;
  v12 = v15;
  v14[1] = (__int64)v15;
  v12->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v11;
  return (DNA::IQueryNode *)v2;
}

// File Line: 525
// RVA: 0x1A9D70
void __fastcall DNA::DerivedTypeQueryNode::Parser::Write(DNA::DerivedTypeQueryNode::Parser *this, DNA::IQueryNode *queryNode, UFG::qStringBuilder *builder)
{
  DNA::IQueryNode *v3; // rbx
  UFG::qStringBuilder *v4; // rdi

  v3 = queryNode;
  v4 = builder;
  UFG::qStringBuilder::operator<<(builder, &this->mKey);
  UFG::qStringBuilder::operator<<(v4, "(");
  UFG::qStringBuilder::operator<<(v4, (const char *)v3[1].vfptr[4].~IQueryNode);
  UFG::qStringBuilder::operator<<(v4, ")");
}

// File Line: 544
// RVA: 0x1A8360
void __fastcall DNA::OrQueryNode::~OrQueryNode(DNA::OrQueryNode *this)
{
  DNA::OrQueryNode *v1; // rdi
  UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *v2; // rbx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v3; // rdx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v4; // rax
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v5; // rdx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v6; // rcx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v7; // rax

  v1 = this;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::OrQueryNode::`vftable';
  v2 = this->mNodes;
  if ( v2 )
  {
    UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0>::DeleteNodes(v2);
    v3 = v2->mNode.mPrev;
    v4 = v2->mNode.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mNode.mPrev = &v2->mNode;
    v2->mNode.mNext = &v2->mNode;
    operator delete[](v2);
  }
  v1->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable';
  v5 = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
}

// File Line: 560
// RVA: 0x1A9060
char __fastcall DNA::OrQueryNode::Match(DNA::OrQueryNode *this, DNA::PropertyBag *propertyBag)
{
  UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *v2; // rax
  DNA::PropertyBag *v3; // rsi
  DNA::OrQueryNode *v4; // rdi
  signed __int64 v5; // rbx

  v2 = this->mNodes;
  v3 = propertyBag;
  v4 = this;
  v5 = (signed __int64)&v2->mNode.mNext[-1].mNext;
  if ( (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> **)v5 == &v2[-1].mNode.mNext )
    return 0;
  while ( !(**(unsigned __int8 (__fastcall ***)(signed __int64, DNA::PropertyBag *))v5)(v5, v3) )
  {
    v5 = *(_QWORD *)(v5 + 16) - 8i64;
    if ( (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> **)v5 == &v4->mNodes[-1].mNode.mNext )
      return 0;
  }
  return 1;
}

// File Line: 573
// RVA: 0x14695D0
__int64 dynamic_initializer_for__DNA::OrQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v1; // rax

  DNA::OrQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable';
  UFG::qString::qString(&stru_14203D6C8, "Or");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  v1 = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D6B8;
  off_14203D6B8 = v1;
  off_14203D6C0 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D6B8;
  DNA::OrQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::OrQueryNode::Parser::`vftable';
  return atexit(dynamic_atexit_destructor_for__DNA::OrQueryNode::mParser__);
}

// File Line: 576
// RVA: 0x1A95C0
UFG::allocator::free_link *__fastcall DNA::OrQueryNode::Parser::Parse(DNA::OrQueryNode::Parser *this, const char *syntax)
{
  signed int v2; // ecx
  __int64 *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  UFG::qString *i; // rdi
  DNA::IQueryNode *v7; // rax
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v8; // rcx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdi
  UFG::allocator::free_link *v12; // rax
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  __int64 *v16; // rdx
  UFG::qString *v17; // rcx
  __int64 *v19; // [rsp+28h] [rbp-20h]
  UFG::qString *v20; // [rsp+30h] [rbp-18h]

  v19 = (__int64 *)&v19;
  v20 = (UFG::qString *)&v19;
  DNA::CollectArgs(syntax, this->mKey.mLength, (UFG::qList<UFG::qString,UFG::qString,1,0> *)&v19);
  v2 = 0;
  v3 = (__int64 *)v20;
  if ( v20 == (UFG::qString *)&v19 )
    goto LABEL_21;
  do
  {
    ++v2;
    v3 = (__int64 *)v3[1];
  }
  while ( v3 != (__int64 *)&v19 );
  if ( v2 <= 1 )
  {
LABEL_21:
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
    for ( i = v20; i != (UFG::qString *)&v19; i = (UFG::qString *)i->mNext )
    {
      v7 = DNA::ParseSyntax(i->mData);
      if ( v7 )
      {
        v8 = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)&v7->mPrev;
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
      v11->mNext = (UFG::allocator::free_link *)&DNA::IQueryNode::`vftable';
      v11[3].mNext = (UFG::allocator::free_link *)&DNA::OrQueryNode::mParser;
      v11->mNext = (UFG::allocator::free_link *)&DNA::OrQueryNode::`vftable';
      v11[4].mNext = v5;
    }
    else
    {
      v11 = 0i64;
    }
  }
  for ( j = v20; v20 != (UFG::qString *)&v19; j = v20 )
  {
    v14 = j->mPrev;
    v15 = j->mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    j->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
    j->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
    UFG::qString::~qString(j);
    operator delete[](j);
  }
  v16 = v19;
  v17 = v20;
  v19[1] = (__int64)v20;
  v17->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v16;
  return v11;
}

// File Line: 623
// RVA: 0x1A8230
void __fastcall DNA::AndQueryNode::~AndQueryNode(DNA::AndQueryNode *this)
{
  DNA::AndQueryNode *v1; // rdi
  UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *v2; // rbx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v3; // rdx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v4; // rax
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v5; // rdx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v6; // rcx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v7; // rax

  v1 = this;
  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::AndQueryNode::`vftable';
  v2 = this->mNodes;
  if ( v2 )
  {
    UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0>::DeleteNodes(v2);
    v3 = v2->mNode.mPrev;
    v4 = v2->mNode.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mNode.mPrev = &v2->mNode;
    v2->mNode.mNext = &v2->mNode;
    operator delete[](v2);
  }
  v1->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable';
  v5 = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
}

// File Line: 640
// RVA: 0x1A8F80
char __fastcall DNA::AndQueryNode::Match(DNA::AndQueryNode *this, DNA::PropertyBag *propertyBag)
{
  UFG::qList<DNA::IQueryNode,DNA::IQueryNode,1,0> *v2; // rax
  DNA::PropertyBag *v3; // rsi
  DNA::AndQueryNode *v4; // rdi
  signed __int64 v5; // rbx

  v2 = this->mNodes;
  v3 = propertyBag;
  v4 = this;
  v5 = (signed __int64)&v2->mNode.mNext[-1].mNext;
  if ( (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> **)v5 == &v2[-1].mNode.mNext )
    return 1;
  while ( (**(unsigned __int8 (__fastcall ***)(signed __int64, DNA::PropertyBag *))v5)(v5, v3) )
  {
    v5 = *(_QWORD *)(v5 + 16) - 8i64;
    if ( (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> **)v5 == &v4->mNodes[-1].mNode.mNext )
      return 1;
  }
  return 0;
}

// File Line: 655
// RVA: 0x1469470
__int64 dynamic_initializer_for__DNA::AndQueryNode::mParser__()
{
  UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *i; // rax
  UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *v1; // rax

  DNA::AndQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::IQueryParser::`vftable';
  UFG::qString::qString(&stru_14203D708, "And");
  for ( i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&DNA::IQueryParser::mParsers.mNode.mNext[-1].mNext;
        i != (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)((char *)&DNA::IQueryParser::mParsers - 8);
        i = (UFG::qList<DNA::IQueryParser,DNA::IQueryParser,1,0> *)&i[1].mNode.mPrev[-1].mNext )
  {
    ;
  }
  v1 = DNA::IQueryParser::mParsers.mNode.mPrev;
  DNA::IQueryParser::mParsers.mNode.mPrev->mNext = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D6F8;
  off_14203D6F8 = v1;
  off_14203D700 = (void **)&DNA::IQueryParser::mParsers;
  DNA::IQueryParser::mParsers.mNode.mPrev = (UFG::qNode<DNA::IQueryParser,DNA::IQueryParser> *)&off_14203D6F8;
  DNA::AndQueryNode::mParser.vfptr = (DNA::IQueryParserVtbl *)&DNA::AndQueryNode::Parser::`vftable';
  return atexit(dynamic_atexit_destructor_for__DNA::AndQueryNode::mParser__);
}

// File Line: 658
// RVA: 0x1A92E0
UFG::allocator::free_link *__fastcall DNA::AndQueryNode::Parser::Parse(DNA::AndQueryNode::Parser *this, const char *syntax)
{
  signed int v2; // ecx
  __int64 *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  UFG::qString *i; // rdi
  DNA::IQueryNode *v7; // rax
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v8; // rcx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdi
  UFG::allocator::free_link *v12; // rax
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  __int64 *v16; // rdx
  UFG::qString *v17; // rcx
  __int64 *v19; // [rsp+28h] [rbp-20h]
  UFG::qString *v20; // [rsp+30h] [rbp-18h]

  v19 = (__int64 *)&v19;
  v20 = (UFG::qString *)&v19;
  DNA::CollectArgs(syntax, this->mKey.mLength, (UFG::qList<UFG::qString,UFG::qString,1,0> *)&v19);
  v2 = 0;
  v3 = (__int64 *)v20;
  if ( v20 == (UFG::qString *)&v19 )
    goto LABEL_21;
  do
  {
    ++v2;
    v3 = (__int64 *)v3[1];
  }
  while ( v3 != (__int64 *)&v19 );
  if ( v2 <= 1 )
  {
LABEL_21:
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
    for ( i = v20; i != (UFG::qString *)&v19; i = (UFG::qString *)i->mNext )
    {
      v7 = DNA::ParseSyntax(i->mData);
      if ( v7 )
      {
        v8 = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)&v7->mPrev;
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
      v11->mNext = (UFG::allocator::free_link *)&DNA::IQueryNode::`vftable';
      v11[3].mNext = (UFG::allocator::free_link *)&DNA::AndQueryNode::mParser;
      v11->mNext = (UFG::allocator::free_link *)&DNA::AndQueryNode::`vftable';
      v11[4].mNext = v5;
    }
    else
    {
      v11 = 0i64;
    }
  }
  for ( j = v20; v20 != (UFG::qString *)&v19; j = v20 )
  {
    v14 = j->mPrev;
    v15 = j->mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    j->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
    j->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
    UFG::qString::~qString(j);
    operator delete[](j);
  }
  v16 = v19;
  v17 = v20;
  v19[1] = (__int64)v20;
  v17->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v16;
  return v11;
}

// File Line: 682
// RVA: 0x1A9DD0
void __fastcall DNA::AndQueryNode::Parser::Write(DNA::OrQueryNode::Parser *this, DNA::IQueryNode *queryNode, UFG::qStringBuilder *builder)
{
  DNA::IQueryNode *v3; // rsi
  UFG::qStringBuilder *v4; // rdi
  DNA::IQueryNodeVtbl *v5; // rax
  signed __int64 v6; // rbx

  v3 = queryNode;
  v4 = builder;
  UFG::qStringBuilder::operator<<(builder, &this->mKey);
  UFG::qStringBuilder::operator<<(v4, "(");
  v5 = v3[1].vfptr;
  v6 = (signed __int64)v5->~IQueryNode - 8;
  if ( ($3C6D76EB49DCD21B904442384897A5F6 *)v6 != &v5[-1].8 )
  {
    do
    {
      (*(void (__fastcall **)(_QWORD, signed __int64, UFG::qStringBuilder *))(**(_QWORD **)(v6 + 24) + 8i64))(
        *(_QWORD *)(v6 + 24),
        v6,
        v4);
      v6 = *(_QWORD *)(v6 + 16) - 8i64;
    }
    while ( ($3C6D76EB49DCD21B904442384897A5F6 *)v6 != &v3[1].vfptr[-1].8 );
  }
  UFG::qStringBuilder::operator<<(v4, ")");
}

// File Line: 759
// RVA: 0x1A8F10
DNA::IQueryNode *__fastcall DNA::Query::FilePath(const char *filePath)
{
  char *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v1 = UFG::qCleanupFilepath(&result, filePath, 92)->mData;
  v2 = UFG::qMalloc(0x70ui64, "Query::PropertyQueryNode", 0i64);
  if ( v2 )
  {
    DNA::PropertyQueryNode::PropertyQueryNode((DNA::PropertyQueryNode *)v2, "$FilePath", v1);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  UFG::qString::~qString(&result);
  return (DNA::IQueryNode *)v4;
}

