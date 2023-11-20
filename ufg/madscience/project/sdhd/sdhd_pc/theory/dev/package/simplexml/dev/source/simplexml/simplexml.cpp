// File Line: 73
// RVA: 0x8A2C0
void __fastcall SimpleXML::XMLNode::ConvertToFloat(SimpleXML::XMLNode *this, const char *value_string, float default_value)
{
  const char *v3; // rbx
  const char *v4; // rax

  v3 = value_string;
  if ( value_string )
  {
    v4 = UFG::qStringFind(value_string, "#");
    if ( v4 )
      UFG::qToUInt32(v4, LODWORD(default_value));
    else
      UFG::qToFloat(v3, default_value);
  }
}

// File Line: 89
// RVA: 0x8ABF0
char *__fastcall SimpleXML::XMLNode::GetName(SimpleXML::XMLNode *this)
{
  pugi::xml_node_struct *v1; // rax
  char *result; // rax

  v1 = this->mData->mNode._root;
  if ( !v1 || (result = v1->name) == 0i64 )
    result = &customWorldMapCaption;
  return result;
}

// File Line: 110
// RVA: 0x8A9C0
__int64 __fastcall SimpleXML::XMLNode::GetAttributeCount(SimpleXML::XMLNode *this)
{
  __int64 result; // rax
  pugi::xml_attribute_struct *i; // rcx

  result = 0i64;
  for ( i = this->mData->mNode._root->first_attribute; i; result = (unsigned int)(result + 1) )
    i = i->next_attribute;
  return result;
}

// File Line: 120
// RVA: 0x8A8C0
char __fastcall SimpleXML::XMLNode::GetAttribute(SimpleXML::XMLNode *this, unsigned int index, UFG::qString *attribute_name, UFG::qString *attribute_value)
{
  UFG::qString *v4; // rdi
  pugi::xml_attribute_struct *v5; // rbx
  const char *v7; // rdx
  const char *v8; // rdx

  v4 = attribute_value;
  v5 = this->mData->mNode._root->first_attribute;
  if ( !v5 )
    return 0;
  while ( index )
  {
    v5 = v5->next_attribute;
    --index;
    if ( !v5 )
      return 0;
  }
  if ( !v5 || (v7 = v5->name) == 0i64 )
    v7 = &customWorldMapCaption;
  UFG::qString::Set(attribute_name, v7);
  if ( !v5 || (v8 = v5->value) == 0i64 )
    v8 = &customWorldMapCaption;
  UFG::qString::Set(v4, v8);
  return 1;
}

// File Line: 135
// RVA: 0x8A850
char *__fastcall SimpleXML::XMLNode::GetAttribute(SimpleXML::XMLNode *this, const char *name)
{
  SimpleXML::XMLNodeData *v2; // rax
  const char *v3; // r10
  pugi::xml_attribute_struct *i; // r9
  char *v5; // r8
  const char *v6; // rax
  signed __int64 v7; // r8
  int v8; // ecx
  int v9; // edx
  char *result; // rax

  v2 = this->mData;
  v3 = name;
  if ( v2->mNode._root )
  {
    for ( i = v2->mNode._root->first_attribute; i; i = i->next_attribute )
    {
      v5 = i->name;
      if ( v5 )
      {
        v6 = v3;
        v7 = v5 - v3;
        do
        {
          v8 = (unsigned __int8)v6[v7];
          v9 = *(unsigned __int8 *)v6 - v8;
          if ( *(unsigned __int8 *)v6 != v8 )
            break;
          ++v6;
        }
        while ( v8 );
        if ( !v9 )
        {
          result = &customWorldMapCaption;
          if ( i->value )
            result = i->value;
          return result;
        }
      }
    }
  }
  return 0i64;
}

// File Line: 143
// RVA: 0x8A7D0
char *__fastcall SimpleXML::XMLNode::GetAttribute(SimpleXML::XMLNode *this, const char *name, const char *default_value)
{
  SimpleXML::XMLNodeData *v3; // rax
  const char *v4; // r11
  const char *v5; // r10
  pugi::xml_attribute_struct *i; // r9
  char *v7; // r8
  const char *v8; // rax
  signed __int64 v9; // r8
  int v10; // ecx
  int v11; // edx
  char *v12; // rcx

  v3 = this->mData;
  v4 = default_value;
  v5 = name;
  if ( v3->mNode._root )
  {
    for ( i = v3->mNode._root->first_attribute; i; i = i->next_attribute )
    {
      v7 = i->name;
      if ( v7 )
      {
        v8 = v5;
        v9 = v7 - v5;
        do
        {
          v10 = (unsigned __int8)v8[v9];
          v11 = *(unsigned __int8 *)v8 - v10;
          if ( *(unsigned __int8 *)v8 != v10 )
            break;
          ++v8;
        }
        while ( v10 );
        if ( !v11 )
        {
          v12 = &customWorldMapCaption;
          if ( i->value )
            v12 = i->value;
          if ( !v12 )
            v12 = (char *)v4;
          return v12;
        }
      }
    }
  }
  return (char *)v4;
}

// File Line: 149
// RVA: 0x8A750
void __fastcall SimpleXML::XMLNode::GetAttribute(SimpleXML::XMLNode *this, const char *name, float default_value)
{
  const char *v3; // r10
  SimpleXML::XMLNode *v4; // r11
  pugi::xml_node_struct *v5; // r9
  pugi::xml_attribute_struct *i; // r9
  char *v7; // r8
  const char *v8; // rax
  signed __int64 v9; // r8
  int v10; // ecx
  int v11; // edx
  const char *v12; // rdx

  v3 = name;
  v4 = this;
  v5 = this->mData->mNode._root;
  if ( v5 )
  {
    for ( i = v5->first_attribute; i; i = i->next_attribute )
    {
      v7 = i->name;
      if ( v7 )
      {
        v8 = v3;
        v9 = v7 - v3;
        do
        {
          v10 = (unsigned __int8)v8[v9];
          v11 = *(unsigned __int8 *)v8 - v10;
          if ( *(unsigned __int8 *)v8 != v10 )
            break;
          ++v8;
        }
        while ( v10 );
        if ( !v11 )
        {
          v12 = &customWorldMapCaption;
          if ( i->value )
            v12 = i->value;
          SimpleXML::XMLNode::ConvertToFloat(v4, v12, default_value);
          return;
        }
      }
    }
  }
  SimpleXML::XMLNode::ConvertToFloat(v4, 0i64, default_value);
}

// File Line: 155
// RVA: 0x8A670
int __fastcall SimpleXML::XMLNode::GetAttribute(SimpleXML::XMLNode *this, const char *name, int default_value)
{
  SimpleXML::XMLNodeData *v3; // rax
  int v4; // er11
  const char *v5; // r10
  pugi::xml_attribute_struct *i; // r9
  char *v7; // r8
  const char *v8; // rax
  signed __int64 v9; // r8
  int v10; // ecx
  int v11; // edx
  const char *v12; // rcx

  v3 = this->mData;
  v4 = default_value;
  v5 = name;
  if ( v3->mNode._root )
  {
    for ( i = v3->mNode._root->first_attribute; i; i = i->next_attribute )
    {
      v7 = i->name;
      if ( v7 )
      {
        v8 = v5;
        v9 = v7 - v5;
        do
        {
          v10 = (unsigned __int8)v8[v9];
          v11 = *(unsigned __int8 *)v8 - v10;
          if ( *(unsigned __int8 *)v8 != v10 )
            break;
          ++v8;
        }
        while ( v10 );
        if ( !v11 )
        {
          v12 = &customWorldMapCaption;
          if ( i->value )
            v12 = i->value;
          return UFG::qToInt32(v12, 0);
        }
      }
    }
  }
  return v4;
}

// File Line: 161
// RVA: 0x8A6E0
unsigned int __fastcall SimpleXML::XMLNode::GetAttribute(SimpleXML::XMLNode *this, const char *name, unsigned int default_value)
{
  SimpleXML::XMLNodeData *v3; // rax
  unsigned int v4; // er11
  const char *v5; // r10
  pugi::xml_attribute_struct *i; // r9
  char *v7; // r8
  const char *v8; // rax
  signed __int64 v9; // r8
  int v10; // ecx
  int v11; // edx
  const char *v12; // rcx

  v3 = this->mData;
  v4 = default_value;
  v5 = name;
  if ( v3->mNode._root )
  {
    for ( i = v3->mNode._root->first_attribute; i; i = i->next_attribute )
    {
      v7 = i->name;
      if ( v7 )
      {
        v8 = v5;
        v9 = v7 - v5;
        do
        {
          v10 = (unsigned __int8)v8[v9];
          v11 = *(unsigned __int8 *)v8 - v10;
          if ( *(unsigned __int8 *)v8 != v10 )
            break;
          ++v8;
        }
        while ( v10 );
        if ( !v11 )
        {
          v12 = &customWorldMapCaption;
          if ( i->value )
            v12 = i->value;
          return UFG::qToUInt32(v12, 0);
        }
      }
    }
  }
  return v4;
}

// File Line: 179
// RVA: 0x8A950
char __fastcall SimpleXML::XMLNode::GetAttribute(SimpleXML::XMLNode *this, const char *name, bool default_value)
{
  SimpleXML::XMLNodeData *v3; // rax
  bool v4; // r11
  const char *v5; // r10
  pugi::xml_attribute_struct *i; // r9
  char *v7; // r8
  const char *v8; // rax
  signed __int64 v9; // r8
  int v10; // ecx
  int v11; // edx
  const char *v12; // rcx

  v3 = this->mData;
  v4 = default_value;
  v5 = name;
  if ( v3->mNode._root )
  {
    for ( i = v3->mNode._root->first_attribute; i; i = i->next_attribute )
    {
      v7 = i->name;
      if ( v7 )
      {
        v8 = v5;
        v9 = v7 - v5;
        do
        {
          v10 = (unsigned __int8)v8[v9];
          v11 = *(unsigned __int8 *)v8 - v10;
          if ( *(unsigned __int8 *)v8 != v10 )
            break;
          ++v8;
        }
        while ( v10 );
        if ( !v11 )
        {
          v12 = &customWorldMapCaption;
          if ( i->value )
            v12 = i->value;
          return UFG::qToBool(v12, v4);
        }
      }
    }
  }
  return v4;
}

// File Line: 185
// RVA: 0x8AA20
__int64 __fastcall SimpleXML::XMLNode::GetChildCount(SimpleXML::XMLNode *this)
{
  __int64 result; // rax
  pugi::xml_node_struct *i; // rcx

  result = 0i64;
  for ( i = this->mData->mNode._root->first_child; i; result = (unsigned int)(result + 1) )
    i = i->next_sibling;
  return result;
}

// File Line: 199
// RVA: 0x8AE90
const char *__fastcall SimpleXML::XMLNode::GetValue(SimpleXML::XMLNode *this)
{
  pugi::xml_node_struct *v1; // rax
  pugi::xml_node_struct *v2; // rax
  const char *v3; // rcx
  const char *result; // rax

  v1 = this->mData->mNode._root;
  if ( !v1 )
    return &customWorldMapCaption;
  v2 = v1->first_child;
  if ( !v2 )
    return &customWorldMapCaption;
  v3 = v2->value;
  result = &customWorldMapCaption;
  if ( v3 )
    result = v3;
  return result;
}

// File Line: 207
// RVA: 0x8AE40
void __fastcall SimpleXML::XMLNode::GetValue(SimpleXML::XMLNode *this, float default_value)
{
  pugi::xml_node_struct *v2; // rax
  pugi::xml_node_struct *v3; // rax
  const char *v4; // rdx
  const char *v5; // rax

  v2 = this->mData->mNode._root;
  if ( v2 && (v3 = v2->first_child) != 0i64 )
  {
    v4 = v3->value;
    v5 = &customWorldMapCaption;
    if ( v4 )
      v5 = v4;
    SimpleXML::XMLNode::ConvertToFloat(this, v5, default_value);
  }
  else
  {
    SimpleXML::XMLNode::ConvertToFloat(this, &customWorldMapCaption, default_value);
  }
}

// File Line: 213
// RVA: 0x8ADC0
int __fastcall SimpleXML::XMLNode::GetValue(SimpleXML::XMLNode *this, int default_value)
{
  pugi::xml_node_struct *v2; // rax
  pugi::xml_node_struct *v3; // rax
  const char *v4; // rcx
  const char *v5; // rax

  v2 = this->mData->mNode._root;
  if ( !v2 )
    return UFG::qToInt32(&customWorldMapCaption, default_value);
  v3 = v2->first_child;
  if ( !v3 )
    return UFG::qToInt32(&customWorldMapCaption, default_value);
  v4 = v3->value;
  v5 = &customWorldMapCaption;
  if ( v4 )
    v5 = v4;
  return UFG::qToInt32(v5, default_value);
}

// File Line: 219
// RVA: 0x8AE00
unsigned int __fastcall SimpleXML::XMLNode::GetValue(SimpleXML::XMLNode *this, unsigned int default_value)
{
  pugi::xml_node_struct *v2; // rax
  pugi::xml_node_struct *v3; // rax
  const char *v4; // rcx
  const char *v5; // rax

  v2 = this->mData->mNode._root;
  if ( !v2 )
    return UFG::qToUInt32(&customWorldMapCaption, default_value);
  v3 = v2->first_child;
  if ( !v3 )
    return UFG::qToUInt32(&customWorldMapCaption, default_value);
  v4 = v3->value;
  v5 = &customWorldMapCaption;
  if ( v4 )
    v5 = v4;
  return UFG::qToUInt32(v5, default_value);
}

// File Line: 237
// RVA: 0x8A9E0
char __fastcall SimpleXML::XMLNode::GetBool(SimpleXML::XMLNode *this, bool default_value)
{
  pugi::xml_node_struct *v2; // rax
  pugi::xml_node_struct *v3; // rax
  const char *v4; // rcx
  const char *v5; // rax

  v2 = this->mData->mNode._root;
  if ( !v2 )
    return UFG::qToBool(&customWorldMapCaption, default_value);
  v3 = v2->first_child;
  if ( !v3 )
    return UFG::qToBool(&customWorldMapCaption, default_value);
  v4 = v3->value;
  v5 = &customWorldMapCaption;
  if ( v4 )
    v5 = v4;
  return UFG::qToBool(v5, default_value);
}

// File Line: 256
// RVA: 0x89300
void __fastcall SimpleXML::XMLDocumentData::XMLDocumentData(SimpleXML::XMLDocumentData *this, unsigned __int64 alloc_params, UFG::qMemoryPool *pool)
{
  UFG::qMemoryPool *v3; // rdi
  unsigned __int64 v4; // rbx
  SimpleXML::XMLDocumentData *v5; // rsi
  pugi::xml_document *v6; // rcx
  UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *v7; // [rsp+48h] [rbp+10h]

  v3 = pool;
  v4 = alloc_params;
  v5 = this;
  UFG::qString::qString(&this->mFilename);
  v6 = &v5->mDoc;
  v6->_root = 0i64;
  v6->_filename = 0i64;
  v6->_buffer = 0i64;
  v6->_memory.next = 0i64;
  v6->_memory.size = 0i64;
  v6->_pool = v3;
  v6->_alloc = v4;
  pugi::xml_document::create(&v5->mDoc);
  v7 = &v5->mNodes;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v5->mPool = v3;
}

// File Line: 260
// RVA: 0x895D0
void __fastcall SimpleXML::XMLDocumentData::~XMLDocumentData(SimpleXML::XMLDocumentData *this)
{
  SimpleXML::XMLDocumentData *v1; // rsi
  SimpleXML::XMLDocumentData *v2; // rbx
  UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *v3; // rdi
  SimpleXML::XMLDocumentData *v4; // rbp
  void *v5; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rax
  UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *i; // rax
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *v9; // rdx
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *v10; // rcx
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *v11; // rcx
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *v12; // rax

  v1 = this;
  v2 = (SimpleXML::XMLDocumentData *)this->mNodes.mNode.mNext;
  v3 = &this->mNodes;
  if ( v2 != (SimpleXML::XMLDocumentData *)&this->mNodes )
  {
    do
    {
      v4 = (SimpleXML::XMLDocumentData *)v2->mFilename.mNext;
      UFG::qMemoryPool::Free(v1->mPool, *(void **)&v2->mFilename.mMagic);
      *(_QWORD *)&v2->mFilename.mMagic = 0i64;
      v5 = *(void **)&v2->mFilename.mMagic;
      if ( v5 )
        operator delete[](v5);
      v6 = v2->mFilename.mPrev;
      v7 = v2->mFilename.mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v2->mFilename.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mFilename.mPrev;
      v2->mFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mFilename.mPrev;
      UFG::qMemoryPool::Free(v1->mPool, v2);
      v2 = v4;
    }
    while ( v4 != (SimpleXML::XMLDocumentData *)v3 );
  }
  for ( i = (UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *)v3->mNode.mNext;
        i != v3;
        i = (UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *)v3->mNode.mNext )
  {
    v9 = i->mNode.mPrev;
    v10 = i->mNode.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
  }
  v11 = v3->mNode.mPrev;
  v12 = v3->mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  pugi::xml_document::free(&v1->mDoc);
  UFG::qString::~qString(&v1->mFilename);
}

// File Line: 288
// RVA: 0x1457860
__int64 dynamic_initializer_for__SimpleXML::XMLDocumentAsyncParser::mCallbackQueue__()
{
  return atexit(dynamic_atexit_destructor_for__SimpleXML::XMLDocumentAsyncParser::mCallbackQueue__);
}

// File Line: 289
// RVA: 0x1457880
__int64 dynamic_initializer_for__SimpleXML::XMLDocumentAsyncParser::mPendingQueue__()
{
  return atexit(dynamic_atexit_destructor_for__SimpleXML::XMLDocumentAsyncParser::mPendingQueue__);
}

// File Line: 290
// RVA: 0x14578D0
__int64 dynamic_initializer_for__SimpleXML::XMLDocumentAsyncParser::mWorkingQueue__()
{
  return atexit(dynamic_atexit_destructor_for__SimpleXML::XMLDocumentAsyncParser::mWorkingQueue__);
}

// File Line: 292
// RVA: 0x14578A0
__int64 dynamic_initializer_for__SimpleXML::XMLDocumentAsyncParser::mQueueMutex__()
{
  UFG::qMutex::qMutex(&SimpleXML::XMLDocumentAsyncParser::mQueueMutex, "XMLDocumentAsyncParser::mQueueMutex");
  return atexit(dynamic_atexit_destructor_for__SimpleXML::XMLDocumentAsyncParser::mQueueMutex__);
}

// File Line: 316
// RVA: 0x89530
void __fastcall SimpleXML::XMLDocumentAsyncParser::~XMLDocumentAsyncParser(SimpleXML::XMLDocumentAsyncParser *this)
{
  SimpleXML::XMLDocumentAsyncParser *v1; // rbx
  UFG::qThread *v2; // rcx
  UFG::qThread *v3; // rdi
  char *v4; // rdx
  UFG::qNode<SimpleXML::XMLDocumentAsyncParser,SimpleXML::XMLDocumentAsyncParser> *v5; // rcx
  UFG::qNode<SimpleXML::XMLDocumentAsyncParser,SimpleXML::XMLDocumentAsyncParser> *v6; // rax

  v1 = this;
  v2 = this->mAsyncParsingThread;
  if ( v2 )
  {
    UFG::qThread::WaitForCompletion(v2);
    UFG::qThread::Stop(v1->mAsyncParsingThread);
    v3 = v1->mAsyncParsingThread;
    if ( v3 )
    {
      _((AMD_HD3D *)v1->mAsyncParsingThread);
      operator delete[](v3);
    }
    v1->mAsyncParsingThread = 0i64;
  }
  v4 = (char *)v1->mTextBuffer;
  if ( v4 )
  {
    UFG::qMemoryPool::Free(v1->mMemoryPool, v4);
    v1->mTextBuffer = 0i64;
    v1->mTextBufferLength = 0;
  }
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mPrev = (UFG::qNode<SimpleXML::XMLDocumentAsyncParser,SimpleXML::XMLDocumentAsyncParser> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<SimpleXML::XMLDocumentAsyncParser,SimpleXML::XMLDocumentAsyncParser> *)&v1->mPrev;
}

// File Line: 446
// RVA: 0x89280
void __fastcall SimpleXML::XMLDocument::XMLDocument(SimpleXML::XMLDocument *this, unsigned __int64 alloc_params, UFG::qMemoryPool *pool)
{
  unsigned __int64 v3; // rdi
  SimpleXML::XMLDocument *v4; // rbx
  char *v5; // rax

  v3 = alloc_params;
  v4 = this;
  this->mPool = pool;
  if ( !pool )
    pool = UFG::gMainMemoryPool;
  this->mPool = pool;
  v5 = UFG::qMemoryPool::Allocate(this->mPool, 0x8078ui64, "XMLDocument.mData", alloc_params, 1u);
  if ( v5 )
    SimpleXML::XMLDocumentData::XMLDocumentData((SimpleXML::XMLDocumentData *)v5, v3, v4->mPool);
  v4->mData = (SimpleXML::XMLDocumentData *)v5;
}

// File Line: 455
// RVA: 0x89500
void __fastcall SimpleXML::XMLDocument::~XMLDocument(SimpleXML::XMLDocument *this)
{
  SimpleXML::XMLDocument *v1; // rbx

  v1 = this;
  SimpleXML::XMLDocumentData::~XMLDocumentData(this->mData);
  UFG::qMemoryPool::Free(v1->mPool, v1->mData);
}

// File Line: 676
// RVA: 0x8AEC0
SimpleXML::XMLDocument *__fastcall SimpleXML::XMLDocument::Open(const char *filename, unsigned __int64 alloc_params, UFG::qMemoryPool *pool)
{
  UFG::qMemoryPool *v3; // rsi
  unsigned __int64 v4; // rbx
  const char *v5; // rdi
  char *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  UFG::qString *v9; // rax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  UFG::qString *v14; // rax
  UFG::qString *v15; // rcx
  UFG::qString *v16; // rax
  UFG::qString *v17; // rax
  UFG::qString result; // [rsp+38h] [rbp-80h]
  UFG::qString v19; // [rsp+60h] [rbp-58h]
  UFG::qString v20; // [rsp+88h] [rbp-30h]

  v3 = pool;
  v4 = alloc_params;
  v5 = filename;
  v6 = UFG::qMalloc(0x10ui64, "XMLDocument.xml_doc", alloc_params);
  if ( v6 )
  {
    SimpleXML::XMLDocument::XMLDocument((SimpleXML::XMLDocument *)v6, v4, v3);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( !v8 )
  {
    v9 = UFG::qGetDirectory(&result);
    UFG::qPrintf(
      "ERROR: SimpleXML::Open() - Insufficient memory to open file!\n       file = '%s'\n       dir  = '%s'\n",
      v5,
      v9->mData);
    UFG::qString::~qString(&result);
    return 0i64;
  }
  UFG::qString::Set(*(UFG::qString **)v8, v5);
  v11 = (unsigned __int64)pugi::xml_document::load_file(
                            (pugi::xml_document *)(*(_QWORD *)v8 + 40i64),
                            v5,
                            0xB4u,
                            0i64,
                            0i64)
      - 1;
  if ( !v11 )
  {
    v17 = UFG::qGetDirectory(&v20);
    UFG::qPrintf(
      "ERROR: SimpleXML::Open() - File does not exist!\n       file = '%s'\n       dir  = '%s'\n",
      v5,
      v17->mData);
    v15 = &v20;
    goto LABEL_14;
  }
  v12 = v11 - 1;
  if ( !v12 )
  {
    v16 = UFG::qGetDirectory(&v19);
    UFG::qPrintf(
      "ERROR: SimpleXML::Open() - File could not be read!\n       file = '%s'\n       dir  = '%s'\n",
      v5,
      v16->mData);
    v15 = &v19;
    goto LABEL_14;
  }
  v13 = v12 - 1;
  if ( !v13 )
  {
    v14 = UFG::qGetDirectory(&result);
    UFG::qPrintf(
      "ERROR: SimpleXML::Open() - No memory to load file!\n       file = '%s'\n       dir  = '%s'\n",
      v5,
      v14->mData);
    v15 = &result;
LABEL_14:
    UFG::qString::~qString(v15);
LABEL_15:
    SimpleXML::XMLDocumentData::~XMLDocumentData(*(SimpleXML::XMLDocumentData **)v8);
    UFG::qMemoryPool::Free(*(UFG::qMemoryPool **)(v8 + 8), *(void **)v8);
    operator delete[]((void *)v8);
    return 0i64;
  }
  if ( v13 == 1 )
    goto LABEL_15;
  return (SimpleXML::XMLDocument *)v8;
}

// File Line: 738
// RVA: 0x8B050
UFG::qMemoryPool **__fastcall SimpleXML::XMLDocument::OpenBuffer(const char *text_buffer, int length)
{
  int v2; // edi
  const char *v3; // rsi
  char *v4; // rax
  UFG::qMemoryPool **v5; // rbx
  char *v6; // rax

  v2 = length;
  v3 = text_buffer;
  v4 = UFG::qMalloc(0x10ui64, "XMLDocument.OpenBuffer", 0i64);
  v5 = (UFG::qMemoryPool **)v4;
  if ( v4 )
  {
    *((_QWORD *)v4 + 1) = 0i64;
    *((_QWORD *)v4 + 1) = UFG::gMainMemoryPool;
    v6 = UFG::qMemoryPool::Allocate(UFG::gMainMemoryPool, 0x8078ui64, "XMLDocument.mData", 1ui64, 1u);
    if ( v6 )
      SimpleXML::XMLDocumentData::XMLDocumentData((SimpleXML::XMLDocumentData *)v6, 1ui64, v5[1]);
    *v5 = (UFG::qMemoryPool *)v6;
  }
  else
  {
    v5 = 0i64;
  }
  if ( pugi::xml_document::load((pugi::xml_document *)(*v5)->mDataBuffer, v3, v2, 0xB4u) == LOAD_OK )
    return v5;
  SimpleXML::XMLDocumentData::~XMLDocumentData((SimpleXML::XMLDocumentData *)*v5);
  UFG::qMemoryPool::Free(v5[1], *v5);
  operator delete[](v5);
  return 0i64;
}

// File Line: 755
// RVA: 0x8ABE0
char *__fastcall SimpleXML::XMLDocument::GetFilename(SimpleXML::XMLDocument *this)
{
  return this->mData->mFilename.mData;
}

// File Line: 760
// RVA: 0x8AC10
SimpleXML::XMLNode *__fastcall SimpleXML::XMLDocument::GetNode(SimpleXML::XMLDocument *this, const char *name, SimpleXML::XMLNode *prev_node)
{
  const char *v3; // r9
  SimpleXML::XMLDocument *v4; // rsi
  pugi::xml_node_struct *v5; // rbx
  pugi::xml_node_struct *v6; // rbx
  char *v7; // r8
  const char *v8; // rax
  signed __int64 v9; // r8
  int v10; // ecx
  int v11; // edx
  char *v12; // r8
  const char *v13; // rax
  signed __int64 v14; // r8
  int v15; // ecx
  int v16; // edx
  char *v18; // rax
  char *v19; // rdi
  UFG::qMemoryPool *v20; // rcx
  char *v21; // rax
  UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *v22; // rdx
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *v23; // rcx

  v3 = name;
  v4 = this;
  if ( !prev_node )
  {
    v5 = this->mData->mDoc._root;
    if ( name )
    {
      if ( v5 )
      {
        v6 = v5->first_child;
        if ( v6 )
        {
          do
          {
            v7 = v6->name;
            if ( v7 )
            {
              v8 = v3;
              v9 = v7 - v3;
              do
              {
                v10 = (unsigned __int8)v8[v9];
                v11 = *(unsigned __int8 *)v8 - v10;
                if ( *(unsigned __int8 *)v8 != v10 )
                  break;
                ++v8;
              }
              while ( v10 );
              if ( !v11 )
                break;
            }
            v6 = v6->next_sibling;
          }
          while ( v6 );
          goto LABEL_26;
        }
      }
    }
    else if ( v5 )
    {
      v6 = v5->first_child;
      goto LABEL_26;
    }
LABEL_23:
    v6 = 0i64;
    goto LABEL_26;
  }
  v6 = prev_node->mData->mNode._root;
  if ( name )
  {
    if ( !v6 )
      goto LABEL_26;
    v6 = v6->next_sibling;
    if ( !v6 )
      goto LABEL_23;
    while ( 1 )
    {
      v12 = v6->name;
      if ( v12 )
      {
        v13 = v3;
        v14 = v12 - v3;
        do
        {
          v15 = (unsigned __int8)v13[v14];
          v16 = *(unsigned __int8 *)v13 - v15;
          if ( *(unsigned __int8 *)v13 != v15 )
            break;
          ++v13;
        }
        while ( v15 );
        if ( !v16 )
          break;
      }
      v6 = v6->next_sibling;
      if ( !v6 )
        goto LABEL_23;
    }
  }
  else if ( v6 )
  {
    v6 = v6->next_sibling;
  }
LABEL_26:
  if ( !v6 )
    return 0i64;
  v18 = UFG::qMemoryPool::Allocate(v4->mPool, 0x18ui64, "XMLNode", 1ui64, 1u);
  v19 = v18;
  if ( v18 )
  {
    v20 = v4->mPool;
    *(_QWORD *)v18 = v18;
    *((_QWORD *)v18 + 1) = v18;
    v21 = UFG::qMemoryPool::Allocate(v20, 8ui64, "XMLNodeData", 0i64, 1u);
    if ( v21 )
      *(_QWORD *)v21 = 0i64;
    *((_QWORD *)v19 + 2) = v21;
  }
  else
  {
    v19 = 0i64;
  }
  **((_QWORD **)v19 + 2) = v6;
  v22 = &v4->mData->mNodes;
  v23 = v22->mNode.mPrev;
  v23->mNext = (UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *)v19;
  *(_QWORD *)v19 = v23;
  *((_QWORD *)v19 + 1) = v22;
  v22->mNode.mPrev = (UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *)v19;
  return (SimpleXML::XMLNode *)v19;
}

// File Line: 863
// RVA: 0x8AA40
SimpleXML::XMLNode *__fastcall SimpleXML::XMLDocument::GetChildNode(SimpleXML::XMLDocument *this, const char *name, SimpleXML::XMLNode *prev_node)
{
  const char *v3; // r9
  SimpleXML::XMLDocument *v4; // rsi
  pugi::xml_node_struct *v5; // rbx
  pugi::xml_node_struct *i; // rbx
  char *v7; // r8
  const char *v8; // rax
  signed __int64 v9; // r8
  int v10; // ecx
  int v11; // edx
  char *v12; // r8
  const char *v13; // rax
  signed __int64 v14; // r8
  int v15; // ecx
  int v16; // edx
  char *v18; // rax
  char *v19; // rdi
  UFG::qMemoryPool *v20; // rcx
  char *v21; // rax
  UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *v22; // rdx
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *v23; // rcx

  v3 = name;
  v4 = this;
  if ( !prev_node )
  {
    v5 = this->mData->mDoc._root;
    if ( name )
    {
      if ( v5 )
      {
        for ( i = v5->first_child; i; i = i->next_sibling )
        {
          v7 = i->name;
          if ( v7 )
          {
            v8 = v3;
            v9 = v7 - v3;
            do
            {
              v10 = (unsigned __int8)v8[v9];
              v11 = *(unsigned __int8 *)v8 - v10;
              if ( *(unsigned __int8 *)v8 != v10 )
                break;
              ++v8;
            }
            while ( v10 );
            if ( !v11 )
              goto LABEL_25;
          }
        }
      }
LABEL_24:
      i = 0i64;
      goto LABEL_25;
    }
LABEL_22:
    if ( v5 )
    {
      i = v5->first_child;
      goto LABEL_25;
    }
    goto LABEL_24;
  }
  v5 = prev_node->mData->mNode._root;
  if ( !name )
    goto LABEL_22;
  if ( !v5 )
    goto LABEL_24;
  i = v5->first_child;
  if ( !i )
    goto LABEL_24;
  while ( 1 )
  {
    v12 = i->name;
    if ( v12 )
    {
      v13 = v3;
      v14 = v12 - v3;
      do
      {
        v15 = (unsigned __int8)v13[v14];
        v16 = *(unsigned __int8 *)v13 - v15;
        if ( *(unsigned __int8 *)v13 != v15 )
          break;
        ++v13;
      }
      while ( v15 );
      if ( !v16 )
        break;
    }
    i = i->next_sibling;
    if ( !i )
      goto LABEL_24;
  }
LABEL_25:
  if ( !i )
    return 0i64;
  v18 = UFG::qMemoryPool::Allocate(v4->mPool, 0x18ui64, "XMLDocument.GetChildNode", 1ui64, 1u);
  v19 = v18;
  if ( v18 )
  {
    v20 = v4->mPool;
    *(_QWORD *)v18 = v18;
    *((_QWORD *)v18 + 1) = v18;
    v21 = UFG::qMemoryPool::Allocate(v20, 8ui64, "XMLNodeData", 0i64, 1u);
    if ( v21 )
      *(_QWORD *)v21 = 0i64;
    *((_QWORD *)v19 + 2) = v21;
  }
  else
  {
    v19 = 0i64;
  }
  **((_QWORD **)v19 + 2) = i;
  v22 = &v4->mData->mNodes;
  v23 = v22->mNode.mPrev;
  v23->mNext = (UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *)v19;
  *(_QWORD *)v19 = v23;
  *((_QWORD *)v19 + 1) = v22;
  v22->mNode.mPrev = (UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *)v19;
  return (SimpleXML::XMLNode *)v19;
}

// File Line: 976
// RVA: 0x8B3F0
void __fastcall SimpleXML::XMLWriterData::Write(SimpleXML::XMLWriterData *this, const char *text, int count)
{
  SimpleXML::XMLWriterData *v3; // rbx
  __int64 v4; // rbp
  const char *v5; // r12
  unsigned int v6; // er14
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // edx
  char *v10; // rdi
  __int64 v11; // rdi
  __int64 v12; // r15
  const char *v13; // rbp
  unsigned int v14; // esi
  unsigned int v15; // edi
  char *v16; // rcx
  char *v17; // rdx
  unsigned int v18; // eax

  v3 = this;
  v4 = (unsigned int)count;
  v5 = text;
  v6 = UFG::qStringLength(text);
  if ( v3->mTextBuffer )
  {
    v7 = v3->mTextBufferSize;
    v8 = v7;
    v9 = v4 * v6 + v3->mTextBufferPos + 1;
    if ( v9 > v7 )
    {
      do
        v8 *= 2;
      while ( v9 > v8 );
    }
    if ( v8 > v7 )
    {
      v10 = UFG::qMalloc(v8, "XMLWriter.Write", 1ui64);
      UFG::qMemCopy(v10, v3->mTextBuffer, v3->mTextBufferPos);
      v10[v3->mTextBufferPos] = 0;
      operator delete[](v3->mTextBuffer);
      v3->mTextBuffer = v10;
      v3->mTextBufferSize = v8;
    }
    if ( (signed int)v4 > 0 )
    {
      v11 = v4;
      do
      {
        UFG::qMemCopy(&v3->mTextBuffer[v3->mTextBufferPos], v5, v6);
        v3->mTextBufferPos += v6;
        v3->mTextBuffer[v3->mTextBufferPos] = 0;
        --v11;
      }
      while ( v11 );
    }
  }
  else if ( v3->mFile && (signed int)v4 > 0 )
  {
    v12 = v4;
    do
    {
      v13 = v5;
      v14 = v6;
      if ( v6 )
      {
        while ( 1 )
        {
          v15 = v3->mWriteBufferSizeBytes - v3->mWriteBufferPos;
          v16 = &v3->mWriteBufferPtr[v3->mWriteBufferPos];
          if ( v14 <= v15 )
            break;
          UFG::qMemCopy(v16, v13, v15);
          v3->mWriteBufferPos += v15;
          v17 = v3->mWriteBufferPtr;
          v14 -= v15;
          v13 += v15;
          v18 = v3->mWriteBufferPos;
          if ( v17 )
          {
            if ( v18 )
              UFG::qWrite(v3->mFile, v17, v18, 0i64, QSEEK_CUR, 0i64);
            v3->mWriteBufferPos = 0;
          }
          if ( !v14 )
            goto LABEL_22;
        }
        UFG::qMemCopy(v16, v13, v14);
        v3->mWriteBufferPos += v14;
      }
LABEL_22:
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 1073
// RVA: 0x8A220
void __fastcall SimpleXML::XMLWriterData::CloseNode(SimpleXML::XMLWriterData *this, const char *name)
{
  SimpleXML::XMLWriterData::State v2; // eax
  const char *v3; // rdi
  SimpleXML::XMLWriterData *v4; // rbx

  v2 = this->mState;
  v3 = name;
  v4 = this;
  if ( v2 == 1 )
  {
    SimpleXML::XMLWriterData::Write(this, "/>", 1);
    v4->mState = 2;
  }
  else
  {
    if ( v2 == STATE_NONE )
      SimpleXML::XMLWriterData::Write(this, "\t", this->mIndent);
    SimpleXML::XMLWriterData::Write(v4, "</", 1);
    SimpleXML::XMLWriterData::Write(v4, v3, 1);
    SimpleXML::XMLWriterData::Write(v4, ">", 1);
  }
}

// File Line: 1104
// RVA: 0x89390
void __fastcall SimpleXML::XMLWriter::XMLWriter(SimpleXML::XMLWriter *this)
{
  SimpleXML::XMLWriter *v1; // rbx
  char *v2; // rax
  _QWORD *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = UFG::qMalloc(0x40ui64, "XMLWriter.mData", 0i64);
  if ( v2 )
  {
    v3 = v2 + 48;
    *v3 = v3;
    v3[1] = v3;
    *(_QWORD *)v2 = 0i64;
    *((_QWORD *)v2 + 3) = 0i64;
    *((_QWORD *)v2 + 2) = 0i64;
    *((_QWORD *)v2 + 1) = 0i64;
    *((_QWORD *)v2 + 4) = 0i64;
    *((_QWORD *)v2 + 5) = 0i64;
  }
  else
  {
    v2 = 0i64;
  }
  v1->mData = (SimpleXML::XMLWriterData *)v2;
  UFG::qStringCopy((char *)v1->mReplacementMap, 0x7FFFFFFF, "&", -1);
  UFG::qStringCopy(v1->mReplacementMap[1].mNaturalString, 0x7FFFFFFF, "<", -1);
  UFG::qStringCopy(v1->mReplacementMap[2].mNaturalString, 0x7FFFFFFF, ">", -1);
  UFG::qStringCopy(v1->mReplacementMap[3].mNaturalString, 0x7FFFFFFF, "\"", -1);
  UFG::qStringCopy(v1->mReplacementMap[4].mNaturalString, 0x7FFFFFFF, "'", -1);
  UFG::qStringCopy(v1->mReplacementMap[0].mReplacementString, 0x7FFFFFFF, "&amp;", -1);
  UFG::qStringCopy(v1->mReplacementMap[1].mReplacementString, 0x7FFFFFFF, "&lt;", -1);
  UFG::qStringCopy(v1->mReplacementMap[2].mReplacementString, 0x7FFFFFFF, "&gt;", -1);
  UFG::qStringCopy(v1->mReplacementMap[3].mReplacementString, 0x7FFFFFFF, "&quot;", -1);
  UFG::qStringCopy(v1->mReplacementMap[4].mReplacementString, 0x7FFFFFFF, "&apos;", -1);
}

// File Line: 1127
// RVA: 0x8A340
UFG::qFile *__fastcall SimpleXML::XMLWriter::Create(const char *filename, bool includeHeader, unsigned int bufferSize)
{
  unsigned __int64 v3; // rsi
  bool v4; // bp
  UFG::qFile *result; // rax
  SimpleXML::XMLWriter *v6; // rbx
  char *v7; // rax
  SimpleXML::XMLWriter *v8; // rax
  SimpleXML::XMLWriter *v9; // rdi
  SimpleXML::XMLWriterData *v10; // rbx

  v3 = bufferSize;
  v4 = includeHeader;
  result = UFG::qOpen(filename, QACCESS_WRITE_SEQUENTIAL, 1);
  v6 = (SimpleXML::XMLWriter *)result;
  if ( result )
  {
    v7 = UFG::qMalloc(0x58ui64, "XMLWriter.Create", 0i64);
    if ( v7 )
    {
      SimpleXML::XMLWriter::XMLWriter((SimpleXML::XMLWriter *)v7);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    v9->mData->mWriteBufferPtr = UFG::qMalloc(v3, "XMLWriter.mWriteBuffer", 0i64);
    v9->mData->mWriteBufferSizeBytes = v3;
    v9->mData->mWriteBufferPos = 0;
    v9->mData->mFile = (UFG::qFile *)v6;
    if ( v4 )
    {
      v10 = v9->mData;
      SimpleXML::XMLWriterData::Write(v9->mData, "<?xml version=\"1.0\"?>\n", 1);
      SimpleXML::XMLWriterData::Write(v10, "\n", 1);
    }
    result = (UFG::qFile *)v9;
  }
  return result;
}

// File Line: 1152
// RVA: 0x8A430
SimpleXML::XMLWriterData **__fastcall SimpleXML::XMLWriter::CreateBuffer(unsigned int text_buffer_size, bool includeHeader)
{
  bool v2; // si
  unsigned __int64 v3; // rbx
  char *v4; // rax
  SimpleXML::XMLWriterData **v5; // rax
  SimpleXML::XMLWriterData **v6; // rdi
  SimpleXML::XMLWriterData *v7; // rbx

  v2 = includeHeader;
  v3 = text_buffer_size;
  v4 = UFG::qMalloc(0x58ui64, "XMLWriter.CreateBuffer", 0i64);
  if ( v4 )
  {
    SimpleXML::XMLWriter::XMLWriter((SimpleXML::XMLWriter *)v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  (*v6)->mTextBuffer = UFG::qMalloc(v3, "XMLWriter.mTextBuffer", 1ui64);
  (*v6)->mTextBufferSize = v3;
  if ( v2 )
  {
    v7 = *v6;
    SimpleXML::XMLWriterData::Write(*v6, "<?xml version=\"1.0\"?>\n", 1);
    SimpleXML::XMLWriterData::Write(v7, "\n", 1);
  }
  return v6;
}

// File Line: 1169
// RVA: 0x89DF0
signed __int64 __fastcall SimpleXML::XMLWriter::Close(SimpleXML::XMLWriter *writer)
{
  SimpleXML::XMLWriter *i; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v2; // rax
  const char *v3; // rsi
  UFG::qString *v4; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rax
  SimpleXML::XMLWriterData *v7; // rbx
  SimpleXML::XMLWriterData::State v8; // eax
  SimpleXML::XMLWriterData *v9; // rbx
  char *v10; // rdx
  unsigned int v11; // eax
  SimpleXML::XMLWriterData *v12; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *v13; // r8
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rdx

  for ( i = writer; i->mData->mOpenNodes.mNode.mNext != &i->mData->mOpenNodes.mNode; i->mData->mState = 0 )
  {
    v2 = i->mData->mOpenNodes.mNode.mPrev;
    v3 = (const char *)v2[1].mNext;
    v4 = (UFG::qString *)i->mData->mOpenNodes.mNode.mPrev;
    v5 = v2->mPrev;
    v6 = v2->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v4->mPrev;
    UFG::qString::~qString(v4);
    operator delete[](v4);
    --i->mData->mIndent;
    v7 = i->mData;
    v8 = i->mData->mState;
    if ( v8 == 1 )
    {
      SimpleXML::XMLWriterData::Write(i->mData, "/>", 1);
      v7->mState = 2;
    }
    else
    {
      if ( v8 == STATE_NONE )
        SimpleXML::XMLWriterData::Write(i->mData, "\t", v7->mIndent);
      SimpleXML::XMLWriterData::Write(v7, "</", 1);
      SimpleXML::XMLWriterData::Write(v7, v3, 1);
      SimpleXML::XMLWriterData::Write(v7, ">", 1);
    }
    SimpleXML::XMLWriterData::Write(i->mData, "\n", 1);
  }
  v9 = i->mData;
  if ( i->mData->mWriteBufferPtr )
  {
    v10 = v9->mWriteBufferPtr;
    if ( v10 )
    {
      v11 = v9->mWriteBufferPos;
      if ( v11 )
        UFG::qWrite(v9->mFile, v10, v11, 0i64, QSEEK_CUR, 0i64);
      v9->mWriteBufferPos = 0;
    }
    operator delete[](i->mData->mWriteBufferPtr);
  }
  UFG::qClose(i->mData->mFile);
  v12 = i->mData;
  if ( i->mData )
  {
    UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&v12->mOpenNodes);
    v13 = v12->mOpenNodes.mNode.mPrev;
    v14 = v12->mOpenNodes.mNode.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mOpenNodes.mNode.mPrev = &v12->mOpenNodes.mNode;
    v12->mOpenNodes.mNode.mNext = &v12->mOpenNodes.mNode;
    operator delete[](v12);
  }
  operator delete[](i);
  return 1i64;
}

// File Line: 1201
// RVA: 0x89FC0
const char *__fastcall SimpleXML::XMLWriter::CloseBuffer(SimpleXML::XMLWriter **writer, unsigned int *buffer_size)
{
  unsigned int *v2; // r14
  SimpleXML::XMLWriter **i; // rdi
  SimpleXML::XMLWriterData **v4; // rsi
  UFG::qString *v5; // rcx
  const char *v6; // rbp
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  SimpleXML::XMLWriterData *v10; // rbx
  SimpleXML::XMLWriterData::State v11; // eax
  SimpleXML::XMLWriterData *v12; // rcx
  const char *v13; // rbp
  UFG::qList<UFG::qString,UFG::qString,1,0> **v14; // r14
  UFG::qList<UFG::qString,UFG::qString,1,0> *v15; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *v16; // r8
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rdx
  const char *result; // rax

  v2 = buffer_size;
  for ( i = writer; (*i)->mData->mOpenNodes.mNode.mNext != &(*i)->mData->mOpenNodes.mNode; (*v4)->mState = 0 )
  {
    v4 = (SimpleXML::XMLWriterData **)*i;
    v5 = (UFG::qString *)(*i)->mData->mOpenNodes.mNode.mPrev;
    v6 = v5->mData;
    v7 = (*i)->mData->mOpenNodes.mNode.mPrev;
    v8 = v5->mPrev;
    v9 = v5->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v5->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v5->mPrev;
    UFG::qString::~qString(v5);
    operator delete[](v7);
    --(*v4)->mIndent;
    v10 = *v4;
    v11 = (*v4)->mState;
    if ( v11 == 1 )
    {
      SimpleXML::XMLWriterData::Write(*v4, "/>", 1);
      v10->mState = 2;
    }
    else
    {
      if ( v11 == STATE_NONE )
        SimpleXML::XMLWriterData::Write(*v4, "\t", v10->mIndent);
      SimpleXML::XMLWriterData::Write(v10, "</", 1);
      SimpleXML::XMLWriterData::Write(v10, v6, 1);
      SimpleXML::XMLWriterData::Write(v10, ">", 1);
    }
    SimpleXML::XMLWriterData::Write(*v4, "\n", 1);
  }
  v12 = (*i)->mData;
  v13 = v12->mTextBuffer;
  if ( v2 )
    *v2 = v12->mTextBufferPos;
  v14 = (UFG::qList<UFG::qString,UFG::qString,1,0> **)*i;
  if ( *i )
  {
    v15 = *v14;
    if ( *v14 )
    {
      UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(v15 + 3);
      v16 = v15[3].mNode.mPrev;
      v17 = v15[3].mNode.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15[3].mNode.mPrev = &v15[3].mNode;
      v15[3].mNode.mNext = &v15[3].mNode;
      operator delete[](v15);
    }
    operator delete[](v14);
  }
  result = v13;
  *i = 0i64;
  return result;
}

// File Line: 1287
// RVA: 0x8A170
__int64 __fastcall SimpleXML::XMLWriter::CloseBufferAndWriteToFile(SimpleXML::XMLWriter *this, const char *filename)
{
  const char *v2; // rdi
  unsigned __int8 v3; // bl
  char *v4; // rbp
  UFG::qFile *v5; // rax
  UFG::qFile *v6; // rdi
  unsigned int buffer_size; // [rsp+40h] [rbp+8h]
  SimpleXML::XMLWriter *writer; // [rsp+50h] [rbp+18h]

  v2 = filename;
  writer = this;
  v3 = 0;
  buffer_size = 0;
  v4 = (char *)SimpleXML::XMLWriter::CloseBuffer(&writer, &buffer_size);
  if ( v4 )
  {
    if ( v2 )
    {
      if ( *v2 )
      {
        if ( buffer_size )
        {
          v5 = UFG::qOpen(v2, QACCESS_WRITE, 1);
          v6 = v5;
          if ( v5 )
          {
            UFG::qWrite(v5, v4, buffer_size, 0i64, QSEEK_CUR, 0i64);
            UFG::qClose(v6);
            v3 = 1;
          }
        }
      }
    }
    operator delete[](v4);
  }
  return v3;
}

// File Line: 1339
// RVA: 0x89A70
void __fastcall SimpleXML::XMLWriter::AddComment(SimpleXML::XMLWriter *this, const char *text)
{
  SimpleXML::XMLWriterData *v2; // rbx
  const char *v3; // rsi
  SimpleXML::XMLWriter *v4; // rdi

  v2 = this->mData;
  v3 = text;
  v4 = this;
  if ( this->mData->mState == 1 )
  {
    SimpleXML::XMLWriterData::Write(this->mData, ">", 1);
    v2->mState = 2;
    SimpleXML::XMLWriterData::Write(v4->mData, "\n", 1);
  }
  SimpleXML::XMLWriterData::Write(v4->mData, "\t", v4->mData->mIndent);
  SimpleXML::XMLWriterData::Write(v4->mData, "<!--", 1);
  SimpleXML::XMLWriterData::Write(v4->mData, v3, 1);
  SimpleXML::XMLWriterData::Write(v4->mData, "-->", 1);
  SimpleXML::XMLWriterData::Write(v4->mData, "\n", 1);
  v4->mData->mState = 0;
}

// File Line: 1384
// RVA: 0x89CF0
void __fastcall SimpleXML::XMLWriter::BeginNode(SimpleXML::XMLWriter *this, const char *name)
{
  const char *v2; // rsi
  SimpleXML::XMLWriter *v3; // rbx
  SimpleXML::XMLWriterData *v4; // rdi
  char *v5; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rdx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v8; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax

  v2 = name;
  v3 = this;
  v4 = this->mData;
  if ( this->mData->mState == 1 )
  {
    SimpleXML::XMLWriterData::Write(this->mData, ">", 1);
    v4->mState = 2;
    SimpleXML::XMLWriterData::Write(v3->mData, "\n", 1);
  }
  SimpleXML::XMLWriterData::Write(v3->mData, "\t", v3->mData->mIndent);
  SimpleXML::XMLWriterData::Write(v3->mData, "<", 1);
  SimpleXML::XMLWriterData::Write(v3->mData, v2, 1);
  v5 = UFG::qMalloc(0x28ui64, "XMLWriter.BeginNode", 0i64);
  if ( v5 )
  {
    UFG::qString::qString((UFG::qString *)v5, v2);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = &v3->mData->mOpenNodes;
  v9 = v8->mNode.mPrev;
  v9->mNext = v7;
  v7->mPrev = v9;
  v7->mNext = &v8->mNode;
  v8->mNode.mPrev = v7;
  ++v3->mData->mIndent;
  v3->mData->mState = 1;
}

// File Line: 1407
// RVA: 0x8A4F0
void __fastcall SimpleXML::XMLWriter::EndNode(SimpleXML::XMLWriter *this, const char *name)
{
  SimpleXML::XMLWriter *v2; // rsi
  const char *v3; // rdi
  UFG::qString *v4; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // r8
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rax

  v2 = this;
  v3 = name;
  v4 = (UFG::qString *)this->mData->mOpenNodes.mNode.mPrev;
  v5 = v4->mPrev;
  v6 = v4->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v4->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v4->mPrev;
  UFG::qString::~qString(v4);
  operator delete[](v4);
  --v2->mData->mIndent;
  SimpleXML::XMLWriterData::CloseNode(v2->mData, v3);
  SimpleXML::XMLWriterData::Write(v2->mData, "\n", 1);
  v2->mData->mState = 0;
}

// File Line: 1431
// RVA: 0x896F0
void __fastcall SimpleXML::XMLWriter::AddAttribute(SimpleXML::XMLWriter *this, const char *name, const char *val, bool replaceSpecialCharacters)
{
  bool v4; // bl
  const char *v5; // rdi
  const char *v6; // rsi
  SimpleXML::XMLWriter *v7; // r15
  const char *v8; // rbx
  signed __int64 v9; // rdi
  char *v10; // rbp
  SimpleXML::XMLWriterData *v11; // rbx
  unsigned int v12; // eax
  unsigned int v13; // esi
  unsigned int v14; // edx
  unsigned int v15; // er14
  unsigned int v16; // ecx
  char *v17; // rdi
  unsigned int v18; // edi
  char *v19; // rcx
  unsigned int v20; // eax
  char *v21; // rdx
  UFG::qString v22; // [rsp+38h] [rbp-70h]
  UFG::qString v23; // [rsp+60h] [rbp-48h]

  v4 = replaceSpecialCharacters;
  v5 = val;
  v6 = name;
  v7 = this;
  SimpleXML::XMLWriterData::Write(this->mData, " ", 1);
  SimpleXML::XMLWriterData::Write(v7->mData, v6, 1);
  SimpleXML::XMLWriterData::Write(v7->mData, "=\"", 1);
  if ( v4 == 1 )
  {
    UFG::qString::qString(&v22, v5);
    UFG::qString::qString(&v23, v6);
    v8 = (const char *)v7->mReplacementMap;
    v9 = 5i64;
    do
    {
      UFG::qString::ReplaceString(&v22, v8, v8 + 8, 0);
      v8 += 16;
      --v9;
    }
    while ( v9 );
    v10 = v22.mData;
    v11 = v7->mData;
    v12 = UFG::qStringLength(v22.mData);
    v13 = v12;
    if ( v11->mTextBuffer )
    {
      v14 = v11->mTextBufferSize;
      v15 = v14;
      v16 = v12 + v11->mTextBufferPos + 1;
      if ( v16 > v14 )
      {
        do
          v15 *= 2;
        while ( v16 > v15 );
      }
      if ( v15 > v14 )
      {
        v17 = UFG::qMalloc(v15, "XMLWriter.Write", 1ui64);
        UFG::qMemCopy(v17, v11->mTextBuffer, v11->mTextBufferPos);
        v17[v11->mTextBufferPos] = 0;
        operator delete[](v11->mTextBuffer);
        v11->mTextBuffer = v17;
        v11->mTextBufferSize = v15;
      }
      UFG::qMemCopy(&v11->mTextBuffer[v11->mTextBufferPos], v10, v13);
      v11->mTextBufferPos += v13;
      v11->mTextBuffer[v11->mTextBufferPos] = 0;
    }
    else if ( v11->mFile && v12 )
    {
      while ( 1 )
      {
        v18 = v11->mWriteBufferSizeBytes - v11->mWriteBufferPos;
        v19 = &v11->mWriteBufferPtr[v11->mWriteBufferPos];
        if ( v13 <= v18 )
          break;
        UFG::qMemCopy(v19, v10, v18);
        v10 += v18;
        v13 -= v18;
        v11->mWriteBufferPos += v18;
        v20 = v11->mWriteBufferPos;
        v21 = v11->mWriteBufferPtr;
        if ( v21 )
        {
          if ( v20 )
            UFG::qWrite(v11->mFile, v21, v20, 0i64, QSEEK_CUR, 0i64);
          v11->mWriteBufferPos = 0;
        }
        if ( !v13 )
          goto LABEL_20;
      }
      UFG::qMemCopy(v19, v10, v13);
      v11->mWriteBufferPos += v13;
    }
LABEL_20:
    UFG::qString::~qString(&v23);
    UFG::qString::~qString(&v22);
  }
  else
  {
    SimpleXML::XMLWriterData::Write(v7->mData, v5, 1);
  }
  SimpleXML::XMLWriterData::Write(v7->mData, "\"", 1);
}

// File Line: 1479
// RVA: 0x89990
void __fastcall SimpleXML::XMLWriter::AddAttribute(SimpleXML::XMLWriter *this, const char *name, float val)
{
  const char *v3; // rbx
  SimpleXML::XMLWriter *v4; // rdi
  UFG::qString v5; // [rsp+28h] [rbp-40h]

  v3 = name;
  v4 = this;
  UFG::qString::qString(&v5);
  UFG::qString::Format(&v5, "%.7f#%08X", val, val, -2i64);
  SimpleXML::XMLWriter::AddAttribute(v4, v3, v5.mData, 1);
  UFG::qString::~qString(&v5);
}

// File Line: 1494
// RVA: 0x89920
void __fastcall SimpleXML::XMLWriter::AddAttribute(SimpleXML::XMLWriter *this, const char *name, unsigned int val)
{
  unsigned int v3; // ebx
  const char *v4; // rdi
  SimpleXML::XMLWriter *v5; // rsi
  UFG::qString v6; // [rsp+28h] [rbp-30h]

  v3 = val;
  v4 = name;
  v5 = this;
  UFG::qString::qString(&v6);
  UFG::qString::Format(&v6, "%u", v3);
  SimpleXML::XMLWriter::AddAttribute(v5, v4, v6.mData, 1);
  UFG::qString::~qString(&v6);
}

// File Line: 1506
// RVA: 0x89A20
void __fastcall SimpleXML::XMLWriter::AddAttribute(SimpleXML::XMLWriter *this, const char *name, unsigned __int64 val)
{
  const char *v3; // rbx
  SimpleXML::XMLWriter *v4; // rdi
  UFG::qString *v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v3 = name;
  v4 = this;
  v5 = UFG::qToHex(&result, val);
  SimpleXML::XMLWriter::AddAttribute(v4, v3, v5->mData, 1);
  UFG::qString::~qString(&result);
}

// File Line: 1512
// RVA: 0x89C20
void __fastcall SimpleXML::XMLWriter::AddValue(SimpleXML::XMLWriter *this, const char *val, bool replaceSpecialCharacters)
{
  bool v3; // bp
  const char *v4; // rdi
  SimpleXML::XMLWriter *v5; // rsi
  SimpleXML::XMLWriterData *v6; // rbx
  const char *v7; // rbx
  signed __int64 v8; // rdi
  UFG::qString v9; // [rsp+28h] [rbp-30h]

  v3 = replaceSpecialCharacters;
  v4 = val;
  v5 = this;
  v6 = this->mData;
  if ( this->mData->mState == 1 )
  {
    SimpleXML::XMLWriterData::Write(this->mData, ">", 1);
    v6->mState = 2;
  }
  if ( v3 == 1 )
  {
    UFG::qString::qString(&v9, v4);
    v7 = (const char *)v5->mReplacementMap;
    v8 = 5i64;
    do
    {
      UFG::qString::ReplaceString(&v9, v7, v7 + 8, 0);
      v7 += 16;
      --v8;
    }
    while ( v8 );
    SimpleXML::XMLWriterData::Write(v5->mData, v9.mData, 1);
    UFG::qString::~qString(&v9);
  }
  else
  {
    SimpleXML::XMLWriterData::Write(v5->mData, v4, 1);
  }
}

// File Line: 1536
// RVA: 0x89BA0
void __fastcall SimpleXML::XMLWriter::AddValue(SimpleXML::XMLWriter *this, float val)
{
  SimpleXML::XMLWriter *v2; // rbx
  UFG::qString v3; // [rsp+28h] [rbp-40h]

  v2 = this;
  UFG::qString::qString(&v3);
  UFG::qString::Format(&v3, "%.7f#%08X", val, val, -2i64);
  SimpleXML::XMLWriter::AddValue(v2, v3.mData, 1);
  UFG::qString::~qString(&v3);
}

// File Line: 1544
// RVA: 0x89B40
void __fastcall SimpleXML::XMLWriter::AddValue(SimpleXML::XMLWriter *this, unsigned int val)
{
  unsigned int v2; // ebx
  SimpleXML::XMLWriter *v3; // rdi
  UFG::qString v4; // [rsp+28h] [rbp-30h]

  v2 = val;
  v3 = this;
  UFG::qString::qString(&v4);
  UFG::qString::Format(&v4, "%d", v2);
  SimpleXML::XMLWriter::AddValue(v3, v4.mData, 1);
  UFG::qString::~qString(&v4);
}

