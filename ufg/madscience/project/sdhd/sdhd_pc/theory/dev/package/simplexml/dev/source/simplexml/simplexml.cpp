// File Line: 73
// RVA: 0x8A2C0
double __fastcall SimpleXML::XMLNode::ConvertToFloat(
        SimpleXML::XMLNode *this,
        const char *value_string,
        double default_value)
{
  double result; // xmm0_8
  const char *v5; // rax

  if ( !value_string )
    return default_value;
  v5 = UFG::qStringFind(value_string, "#");
  if ( v5 )
    *(_QWORD *)&result = UFG::qToUInt32(v5, LODWORD(default_value));
  else
    *(float *)&result = UFG::qToFloat(value_string, *(float *)&default_value);
  return result;
}

// File Line: 89
// RVA: 0x8ABF0
char *__fastcall SimpleXML::XMLNode::GetName(SimpleXML::XMLNode *this)
{
  pugi::xml_node_struct *root; // rax
  char *result; // rax

  root = this->mData->mNode._root;
  if ( !root )
    return &customCaption;
  result = root->name;
  if ( !result )
    return &customCaption;
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
char __fastcall SimpleXML::XMLNode::GetAttribute(
        SimpleXML::XMLNode *this,
        unsigned int index,
        UFG::qString *attribute_name,
        UFG::qString *attribute_value)
{
  pugi::xml_attribute_struct *first_attribute; // rbx
  const char *name; // rdx
  const char *value; // rdx

  first_attribute = this->mData->mNode._root->first_attribute;
  if ( !first_attribute )
    return 0;
  while ( index )
  {
    first_attribute = first_attribute->next_attribute;
    --index;
    if ( !first_attribute )
      return 0;
  }
  name = first_attribute->name;
  if ( !name )
    name = &customCaption;
  UFG::qString::Set(attribute_name, name);
  value = first_attribute->value;
  if ( !value )
    value = &customCaption;
  UFG::qString::Set(attribute_value, value);
  return 1;
}

// File Line: 135
// RVA: 0x8A850
char *__fastcall SimpleXML::XMLNode::GetAttribute(SimpleXML::XMLNode *this, const char *name)
{
  SimpleXML::XMLNodeData *mData; // rax
  pugi::xml_attribute_struct *i; // r9
  const char *v5; // r8
  char *result; // rax

  mData = this->mData;
  if ( mData->mNode._root )
  {
    for ( i = mData->mNode._root->first_attribute; i; i = i->next_attribute )
    {
      v5 = i->name;
      if ( v5 && !strcmp(name, v5) )
      {
        result = &customCaption;
        if ( i->value )
          return i->value;
        return result;
      }
    }
  }
  return 0i64;
}

// File Line: 143
// RVA: 0x8A7D0
char *__fastcall SimpleXML::XMLNode::GetAttribute(
        SimpleXML::XMLNode *this,
        const char *name,
        const char *default_value)
{
  SimpleXML::XMLNodeData *mData; // rax
  pugi::xml_attribute_struct *i; // r9
  const char *v7; // r8
  char *value; // rcx

  mData = this->mData;
  if ( mData->mNode._root )
  {
    for ( i = mData->mNode._root->first_attribute; i; i = i->next_attribute )
    {
      v7 = i->name;
      if ( v7 && !strcmp(name, v7) )
      {
        value = &customCaption;
        if ( i->value )
          value = i->value;
        if ( !value )
          return (char *)default_value;
        return value;
      }
    }
  }
  return (char *)default_value;
}

// File Line: 149
// RVA: 0x8A750
double __fastcall SimpleXML::XMLNode::GetAttribute(SimpleXML::XMLNode *this, const char *name, double default_value)
{
  pugi::xml_node_struct *root; // r9
  pugi::xml_attribute_struct *i; // r9
  const char *v7; // r8
  const char *value; // rdx
  SimpleXML::XMLNode *v9; // rcx

  root = this->mData->mNode._root;
  if ( root )
  {
    for ( i = root->first_attribute; i; i = i->next_attribute )
    {
      v7 = i->name;
      if ( v7 && !strcmp(name, v7) )
      {
        value = &customCaption;
        v9 = this;
        if ( i->value )
          value = i->value;
        return SimpleXML::XMLNode::ConvertToFloat(v9, value, default_value);
      }
    }
  }
  value = 0i64;
  v9 = this;
  return SimpleXML::XMLNode::ConvertToFloat(v9, value, default_value);
}

// File Line: 155
// RVA: 0x8A670
int __fastcall SimpleXML::XMLNode::GetAttribute(SimpleXML::XMLNode *this, const char *name, int default_value)
{
  SimpleXML::XMLNodeData *mData; // rax
  pugi::xml_attribute_struct *i; // r9
  const char *v7; // r8
  const char *value; // rcx

  mData = this->mData;
  if ( mData->mNode._root )
  {
    for ( i = mData->mNode._root->first_attribute; i; i = i->next_attribute )
    {
      v7 = i->name;
      if ( v7 && !strcmp(name, v7) )
      {
        value = &customCaption;
        if ( i->value )
          value = i->value;
        return UFG::qToInt32(value, 0);
      }
    }
  }
  return default_value;
}

// File Line: 161
// RVA: 0x8A6E0
unsigned int __fastcall SimpleXML::XMLNode::GetAttribute(
        SimpleXML::XMLNode *this,
        const char *name,
        unsigned int default_value)
{
  SimpleXML::XMLNodeData *mData; // rax
  pugi::xml_attribute_struct *i; // r9
  const char *v7; // r8
  const char *value; // rcx

  mData = this->mData;
  if ( mData->mNode._root )
  {
    for ( i = mData->mNode._root->first_attribute; i; i = i->next_attribute )
    {
      v7 = i->name;
      if ( v7 && !strcmp(name, v7) )
      {
        value = &customCaption;
        if ( i->value )
          value = i->value;
        return UFG::qToUInt32(value, 0);
      }
    }
  }
  return default_value;
}

// File Line: 179
// RVA: 0x8A950
char __fastcall SimpleXML::XMLNode::GetAttribute(SimpleXML::XMLNode *this, const char *name, bool default_value)
{
  SimpleXML::XMLNodeData *mData; // rax
  pugi::xml_attribute_struct *i; // r9
  const char *v7; // r8
  const char *value; // rcx

  mData = this->mData;
  if ( mData->mNode._root )
  {
    for ( i = mData->mNode._root->first_attribute; i; i = i->next_attribute )
    {
      v7 = i->name;
      if ( v7 && !strcmp(name, v7) )
      {
        value = &customCaption;
        if ( i->value )
          value = i->value;
        return UFG::qToBool(value, default_value);
      }
    }
  }
  return default_value;
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
char *__fastcall SimpleXML::XMLNode::GetValue(SimpleXML::XMLNode *this)
{
  pugi::xml_node_struct *root; // rax
  pugi::xml_node_struct *first_child; // rax
  char *value; // rcx
  char *result; // rax

  root = this->mData->mNode._root;
  if ( !root )
    return &customCaption;
  first_child = root->first_child;
  if ( !first_child )
    return &customCaption;
  value = first_child->value;
  result = &customCaption;
  if ( value )
    return value;
  return result;
}

// File Line: 207
// RVA: 0x8AE40
double __fastcall SimpleXML::XMLNode::GetValue(SimpleXML::XMLNode *this, double default_value)
{
  pugi::xml_node_struct *root; // rax
  pugi::xml_node_struct *first_child; // rax
  const char *value; // rdx
  const char *v5; // rax

  root = this->mData->mNode._root;
  if ( !root )
    return SimpleXML::XMLNode::ConvertToFloat(this, &customCaption, default_value);
  first_child = root->first_child;
  if ( !first_child )
    return SimpleXML::XMLNode::ConvertToFloat(this, &customCaption, default_value);
  value = first_child->value;
  v5 = &customCaption;
  if ( value )
    v5 = value;
  return SimpleXML::XMLNode::ConvertToFloat(this, v5, default_value);
}

// File Line: 213
// RVA: 0x8ADC0
int __fastcall SimpleXML::XMLNode::GetValue(SimpleXML::XMLNode *this, int default_value)
{
  pugi::xml_node_struct *root; // rax
  pugi::xml_node_struct *first_child; // rax
  const char *value; // rcx
  const char *v5; // rax

  root = this->mData->mNode._root;
  if ( !root )
    return UFG::qToInt32(&customCaption, default_value);
  first_child = root->first_child;
  if ( !first_child )
    return UFG::qToInt32(&customCaption, default_value);
  value = first_child->value;
  v5 = &customCaption;
  if ( value )
    v5 = value;
  return UFG::qToInt32(v5, default_value);
}

// File Line: 219
// RVA: 0x8AE00
unsigned int __fastcall SimpleXML::XMLNode::GetValue(SimpleXML::XMLNode *this, unsigned int default_value)
{
  pugi::xml_node_struct *root; // rax
  pugi::xml_node_struct *first_child; // rax
  const char *value; // rcx
  const char *v5; // rax

  root = this->mData->mNode._root;
  if ( !root )
    return UFG::qToUInt32(&customCaption, default_value);
  first_child = root->first_child;
  if ( !first_child )
    return UFG::qToUInt32(&customCaption, default_value);
  value = first_child->value;
  v5 = &customCaption;
  if ( value )
    v5 = value;
  return UFG::qToUInt32(v5, default_value);
}

// File Line: 237
// RVA: 0x8A9E0
char __fastcall SimpleXML::XMLNode::GetBool(SimpleXML::XMLNode *this, bool default_value)
{
  pugi::xml_node_struct *root; // rax
  pugi::xml_node_struct *first_child; // rax
  const char *value; // rcx
  const char *v5; // rax

  root = this->mData->mNode._root;
  if ( !root )
    return UFG::qToBool(&customCaption, default_value);
  first_child = root->first_child;
  if ( !first_child )
    return UFG::qToBool(&customCaption, default_value);
  value = first_child->value;
  v5 = &customCaption;
  if ( value )
    v5 = value;
  return UFG::qToBool(v5, default_value);
}

// File Line: 256
// RVA: 0x89300
void __fastcall SimpleXML::XMLDocumentData::XMLDocumentData(
        SimpleXML::XMLDocumentData *this,
        unsigned __int64 alloc_params,
        UFG::qMemoryPool *pool)
{
  UFG::qString::qString(&this->mFilename);
  this->mDoc._root = 0i64;
  this->mDoc._filename = 0i64;
  this->mDoc._buffer = 0i64;
  this->mDoc._memory.next = 0i64;
  this->mDoc._memory.size = 0i64;
  this->mDoc._pool = pool;
  this->mDoc._alloc = alloc_params;
  pugi::xml_document::create(&this->mDoc);
  this->mNodes.mNode.mPrev = &this->mNodes.mNode;
  this->mNodes.mNode.mNext = &this->mNodes.mNode;
  this->mPool = pool;
}

// File Line: 260
// RVA: 0x895D0
void __fastcall SimpleXML::XMLDocumentData::~XMLDocumentData(SimpleXML::XMLDocumentData *this)
{
  SimpleXML::XMLDocumentData *mNext; // rbx
  UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *p_mNodes; // rdi
  SimpleXML::XMLDocumentData *v4; // rbp
  void *v5; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rax
  UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *i; // rax
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *v9; // rdx
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *v10; // rcx
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *v11; // rcx
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *v12; // rax

  mNext = (SimpleXML::XMLDocumentData *)this->mNodes.mNode.mNext;
  p_mNodes = &this->mNodes;
  if ( mNext != (SimpleXML::XMLDocumentData *)&this->mNodes )
  {
    do
    {
      v4 = (SimpleXML::XMLDocumentData *)mNext->mFilename.mNext;
      UFG::qMemoryPool::Free(this->mPool, *(void **)&mNext->mFilename.mMagic);
      *(_QWORD *)&mNext->mFilename.mMagic = 0i64;
      v5 = *(void **)&mNext->mFilename.mMagic;
      if ( v5 )
        operator delete[](v5);
      mPrev = mNext->mFilename.mPrev;
      v7 = mNext->mFilename.mNext;
      mPrev->mNext = v7;
      v7->mPrev = mPrev;
      mNext->mFilename.mPrev = &mNext->mFilename;
      mNext->mFilename.mNext = &mNext->mFilename;
      UFG::qMemoryPool::Free(this->mPool, mNext);
      mNext = v4;
    }
    while ( v4 != (SimpleXML::XMLDocumentData *)p_mNodes );
  }
  for ( i = (UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *)p_mNodes->mNode.mNext;
        i != p_mNodes;
        i = (UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *)p_mNodes->mNode.mNext )
  {
    v9 = i->mNode.mPrev;
    v10 = i->mNode.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
  }
  v11 = p_mNodes->mNode.mPrev;
  v12 = p_mNodes->mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  p_mNodes->mNode.mPrev = &p_mNodes->mNode;
  p_mNodes->mNode.mNext = &p_mNodes->mNode;
  pugi::xml_document::free(&this->mDoc);
  UFG::qString::~qString(&this->mFilename);
}

// File Line: 288
// RVA: 0x1457860
__int64 dynamic_initializer_for__SimpleXML::XMLDocumentAsyncParser::mCallbackQueue__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SimpleXML::XMLDocumentAsyncParser::mCallbackQueue__);
}

// File Line: 289
// RVA: 0x1457880
__int64 dynamic_initializer_for__SimpleXML::XMLDocumentAsyncParser::mPendingQueue__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SimpleXML::XMLDocumentAsyncParser::mPendingQueue__);
}

// File Line: 290
// RVA: 0x14578D0
__int64 dynamic_initializer_for__SimpleXML::XMLDocumentAsyncParser::mWorkingQueue__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SimpleXML::XMLDocumentAsyncParser::mWorkingQueue__);
}

// File Line: 292
// RVA: 0x14578A0
__int64 dynamic_initializer_for__SimpleXML::XMLDocumentAsyncParser::mQueueMutex__()
{
  UFG::qMutex::qMutex(&SimpleXML::XMLDocumentAsyncParser::mQueueMutex, "XMLDocumentAsyncParser::mQueueMutex");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SimpleXML::XMLDocumentAsyncParser::mQueueMutex__);
}

// File Line: 316
// RVA: 0x89530
void __fastcall SimpleXML::XMLDocumentAsyncParser::~XMLDocumentAsyncParser(SimpleXML::XMLDocumentAsyncParser *this)
{
  UFG::qThread *mAsyncParsingThread; // rcx
  UFG::qThread *v3; // rdi
  char *mTextBuffer; // rdx
  UFG::qNode<SimpleXML::XMLDocumentAsyncParser,SimpleXML::XMLDocumentAsyncParser> *mPrev; // rcx
  UFG::qNode<SimpleXML::XMLDocumentAsyncParser,SimpleXML::XMLDocumentAsyncParser> *mNext; // rax

  mAsyncParsingThread = this->mAsyncParsingThread;
  if ( mAsyncParsingThread )
  {
    UFG::qThread::WaitForCompletion(mAsyncParsingThread);
    UFG::qThread::Stop(this->mAsyncParsingThread);
    v3 = this->mAsyncParsingThread;
    if ( v3 )
    {
      _((AMD_HD3D *)this->mAsyncParsingThread);
      operator delete[](v3);
    }
    this->mAsyncParsingThread = 0i64;
  }
  mTextBuffer = (char *)this->mTextBuffer;
  if ( mTextBuffer )
  {
    UFG::qMemoryPool::Free(this->mMemoryPool, mTextBuffer);
    this->mTextBuffer = 0i64;
    this->mTextBufferLength = 0;
  }
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 446
// RVA: 0x89280
void __fastcall SimpleXML::XMLDocument::XMLDocument(
        SimpleXML::XMLDocument *this,
        unsigned __int64 alloc_params,
        UFG::qMemoryPool *pool)
{
  char *v5; // rax

  this->mPool = pool;
  if ( !pool )
    pool = UFG::gMainMemoryPool;
  this->mPool = pool;
  v5 = UFG::qMemoryPool::Allocate(this->mPool, 0x8078ui64, "XMLDocument.mData", alloc_params, 1u);
  if ( v5 )
    SimpleXML::XMLDocumentData::XMLDocumentData((SimpleXML::XMLDocumentData *)v5, alloc_params, this->mPool);
  this->mData = (SimpleXML::XMLDocumentData *)v5;
}

// File Line: 455
// RVA: 0x89500
void __fastcall SimpleXML::XMLDocument::~XMLDocument(SimpleXML::XMLDocument *this)
{
  SimpleXML::XMLDocumentData::~XMLDocumentData(this->mData);
  UFG::qMemoryPool::Free(this->mPool, this->mData);
}

// File Line: 676
// RVA: 0x8AEC0
SimpleXML::XMLDocument *__fastcall SimpleXML::XMLDocument::Open(
        const char *filename,
        unsigned __int64 alloc_params,
        UFG::qMemoryPool *pool)
{
  char *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  UFG::qString *Directory; // rax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  UFG::qString *v14; // rax
  UFG::qString *p_result; // rcx
  UFG::qString *v16; // rax
  UFG::qString *v17; // rax
  UFG::qString result; // [rsp+38h] [rbp-80h] BYREF
  UFG::qString v19; // [rsp+60h] [rbp-58h] BYREF
  UFG::qString v20; // [rsp+88h] [rbp-30h] BYREF

  v6 = UFG::qMalloc(0x10ui64, "XMLDocument.xml_doc", alloc_params);
  if ( v6 )
  {
    SimpleXML::XMLDocument::XMLDocument((SimpleXML::XMLDocument *)v6, alloc_params, pool);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( !v8 )
  {
    Directory = UFG::qGetDirectory(&result);
    UFG::qPrintf(
      "ERROR: SimpleXML::Open() - Insufficient memory to open file!\n       file = %s\n       dir  = %s\n",
      filename,
      Directory->mData);
    UFG::qString::~qString(&result);
    return 0i64;
  }
  UFG::qString::Set(*(UFG::qString **)v8, filename);
  v11 = pugi::xml_document::load_file((pugi::xml_document *)(*(_QWORD *)v8 + 40i64), filename, 0xB4u, 0i64, 0i64) - 1;
  if ( !v11 )
  {
    v17 = UFG::qGetDirectory(&v20);
    UFG::qPrintf(
      "ERROR: SimpleXML::Open() - File does not exist!\n       file = %s\n       dir  = %s\n",
      filename,
      v17->mData);
    p_result = &v20;
    goto LABEL_14;
  }
  v12 = v11 - 1;
  if ( !v12 )
  {
    v16 = UFG::qGetDirectory(&v19);
    UFG::qPrintf(
      "ERROR: SimpleXML::Open() - File could not be read!\n       file = %s\n       dir  = %s\n",
      filename,
      v16->mData);
    p_result = &v19;
    goto LABEL_14;
  }
  v13 = v12 - 1;
  if ( !v13 )
  {
    v14 = UFG::qGetDirectory(&result);
    UFG::qPrintf(
      "ERROR: SimpleXML::Open() - No memory to load file!\n       file = %s\n       dir  = %s\n",
      filename,
      v14->mData);
    p_result = &result;
LABEL_14:
    UFG::qString::~qString(p_result);
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
  char *v4; // rax
  UFG::qMemoryPool **v5; // rbx
  char *v6; // rax

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
  if ( pugi::xml_document::load((pugi::xml_document *)(*v5)->mDataBuffer, text_buffer, length, 0xB4u) == LOAD_OK )
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
SimpleXML::XMLNode *__fastcall SimpleXML::XMLDocument::GetNode(
        SimpleXML::XMLDocument *this,
        const char *name,
        SimpleXML::XMLNode *prev_node)
{
  pugi::xml_node_struct *root; // rbx
  pugi::xml_node_struct *first_child; // rbx
  const char *v7; // r8
  const char *v8; // r8
  char *v10; // rax
  char *v11; // rdi
  UFG::qMemoryPool *mPool; // rcx
  char *v13; // rax
  UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *p_mNodes; // rdx
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *mPrev; // rcx

  if ( !prev_node )
  {
    root = this->mData->mDoc._root;
    if ( name )
    {
      if ( root )
      {
        first_child = root->first_child;
        if ( first_child )
        {
          do
          {
            v7 = first_child->name;
            if ( v7 && !strcmp(name, v7) )
              break;
            first_child = first_child->next_sibling;
          }
          while ( first_child );
          goto LABEL_20;
        }
      }
    }
    else if ( root )
    {
      first_child = root->first_child;
      goto LABEL_20;
    }
LABEL_17:
    first_child = 0i64;
    goto LABEL_20;
  }
  first_child = prev_node->mData->mNode._root;
  if ( name )
  {
    if ( !first_child )
      goto LABEL_20;
    first_child = first_child->next_sibling;
    if ( !first_child )
      goto LABEL_17;
    while ( 1 )
    {
      v8 = first_child->name;
      if ( v8 )
      {
        if ( !strcmp(name, v8) )
          break;
      }
      first_child = first_child->next_sibling;
      if ( !first_child )
        goto LABEL_17;
    }
  }
  else if ( first_child )
  {
    first_child = first_child->next_sibling;
  }
LABEL_20:
  if ( !first_child )
    return 0i64;
  v10 = UFG::qMemoryPool::Allocate(this->mPool, 0x18ui64, "XMLNode", 1ui64, 1u);
  v11 = v10;
  if ( v10 )
  {
    mPool = this->mPool;
    *(_QWORD *)v10 = v10;
    *((_QWORD *)v10 + 1) = v10;
    v13 = UFG::qMemoryPool::Allocate(mPool, 8ui64, "XMLNodeData", 0i64, 1u);
    if ( v13 )
      *(_QWORD *)v13 = 0i64;
    *((_QWORD *)v11 + 2) = v13;
  }
  else
  {
    v11 = 0i64;
  }
  **((_QWORD **)v11 + 2) = first_child;
  p_mNodes = &this->mData->mNodes;
  mPrev = p_mNodes->mNode.mPrev;
  mPrev->mNext = (UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *)v11;
  *(_QWORD *)v11 = mPrev;
  *((_QWORD *)v11 + 1) = p_mNodes;
  p_mNodes->mNode.mPrev = (UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *)v11;
  return (SimpleXML::XMLNode *)v11;
}

// File Line: 863
// RVA: 0x8AA40
SimpleXML::XMLNode *__fastcall SimpleXML::XMLDocument::GetChildNode(
        SimpleXML::XMLDocument *this,
        const char *name,
        SimpleXML::XMLNode *prev_node)
{
  pugi::xml_node_struct *root; // rbx
  pugi::xml_node_struct *i; // rbx
  const char *v7; // r8
  const char *v8; // r8
  char *v10; // rax
  char *v11; // rdi
  UFG::qMemoryPool *mPool; // rcx
  char *v13; // rax
  UFG::qList<SimpleXML::XMLNode,SimpleXML::XMLNode,0,0> *p_mNodes; // rdx
  UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *mPrev; // rcx

  if ( !prev_node )
  {
    root = this->mData->mDoc._root;
    if ( name )
    {
      if ( root )
      {
        for ( i = root->first_child; i; i = i->next_sibling )
        {
          v7 = i->name;
          if ( v7 )
          {
            if ( !strcmp(name, v7) )
              goto LABEL_19;
          }
        }
      }
LABEL_18:
      i = 0i64;
      goto LABEL_19;
    }
LABEL_16:
    if ( root )
    {
      i = root->first_child;
      goto LABEL_19;
    }
    goto LABEL_18;
  }
  root = prev_node->mData->mNode._root;
  if ( !name )
    goto LABEL_16;
  if ( !root )
    goto LABEL_18;
  i = root->first_child;
  if ( !i )
    goto LABEL_18;
  while ( 1 )
  {
    v8 = i->name;
    if ( v8 )
    {
      if ( !strcmp(name, v8) )
        break;
    }
    i = i->next_sibling;
    if ( !i )
      goto LABEL_18;
  }
LABEL_19:
  if ( !i )
    return 0i64;
  v10 = UFG::qMemoryPool::Allocate(this->mPool, 0x18ui64, "XMLDocument.GetChildNode", 1ui64, 1u);
  v11 = v10;
  if ( v10 )
  {
    mPool = this->mPool;
    *(_QWORD *)v10 = v10;
    *((_QWORD *)v10 + 1) = v10;
    v13 = UFG::qMemoryPool::Allocate(mPool, 8ui64, "XMLNodeData", 0i64, 1u);
    if ( v13 )
      *(_QWORD *)v13 = 0i64;
    *((_QWORD *)v11 + 2) = v13;
  }
  else
  {
    v11 = 0i64;
  }
  **((_QWORD **)v11 + 2) = i;
  p_mNodes = &this->mData->mNodes;
  mPrev = p_mNodes->mNode.mPrev;
  mPrev->mNext = (UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *)v11;
  *(_QWORD *)v11 = mPrev;
  *((_QWORD *)v11 + 1) = p_mNodes;
  p_mNodes->mNode.mPrev = (UFG::qNode<SimpleXML::XMLNode,SimpleXML::XMLNode> *)v11;
  return (SimpleXML::XMLNode *)v11;
}

// File Line: 976
// RVA: 0x8B3F0
void __fastcall SimpleXML::XMLWriterData::Write(SimpleXML::XMLWriterData *this, const char *text, unsigned int count)
{
  __int64 v4; // rbp
  unsigned int v6; // r14d
  unsigned int mTextBufferSize; // eax
  unsigned int v8; // esi
  unsigned int v9; // edx
  char *v10; // rdi
  __int64 v11; // rdi
  __int64 v12; // r15
  const char *v13; // rbp
  unsigned int v14; // esi
  unsigned int v15; // edi
  char *v16; // rcx
  char *mWriteBufferPtr; // rdx
  unsigned int mWriteBufferPos; // eax

  v4 = count;
  v6 = UFG::qStringLength(text);
  if ( this->mTextBuffer )
  {
    mTextBufferSize = this->mTextBufferSize;
    v8 = mTextBufferSize;
    v9 = v4 * v6 + this->mTextBufferPos + 1;
    if ( v9 > mTextBufferSize )
    {
      do
        v8 *= 2;
      while ( v9 > v8 );
    }
    if ( v8 > mTextBufferSize )
    {
      v10 = UFG::qMalloc(v8, "XMLWriter.Write", 1ui64);
      UFG::qMemCopy(v10, this->mTextBuffer, this->mTextBufferPos);
      v10[this->mTextBufferPos] = 0;
      operator delete[](this->mTextBuffer);
      this->mTextBuffer = v10;
      this->mTextBufferSize = v8;
    }
    if ( (int)v4 > 0 )
    {
      v11 = v4;
      do
      {
        UFG::qMemCopy(&this->mTextBuffer[this->mTextBufferPos], text, v6);
        this->mTextBufferPos += v6;
        this->mTextBuffer[this->mTextBufferPos] = 0;
        --v11;
      }
      while ( v11 );
    }
  }
  else if ( this->mFile && (int)v4 > 0 )
  {
    v12 = v4;
    do
    {
      v13 = text;
      v14 = v6;
      if ( v6 )
      {
        while ( 1 )
        {
          v15 = this->mWriteBufferSizeBytes - this->mWriteBufferPos;
          v16 = &this->mWriteBufferPtr[this->mWriteBufferPos];
          if ( v14 <= v15 )
            break;
          UFG::qMemCopy(v16, v13, v15);
          this->mWriteBufferPos += v15;
          mWriteBufferPtr = this->mWriteBufferPtr;
          v14 -= v15;
          v13 += v15;
          mWriteBufferPos = this->mWriteBufferPos;
          if ( mWriteBufferPtr )
          {
            if ( mWriteBufferPos )
              UFG::qWrite(this->mFile, mWriteBufferPtr, mWriteBufferPos, 0i64, QSEEK_CUR, 0i64);
            this->mWriteBufferPos = 0;
          }
          if ( !v14 )
            goto LABEL_22;
        }
        UFG::qMemCopy(v16, v13, v14);
        this->mWriteBufferPos += v14;
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
  SimpleXML::XMLWriterData::State mState; // eax

  mState = this->mState;
  if ( mState == STATE_QUEUED )
  {
    SimpleXML::XMLWriterData::Write(this, "/>", 1);
    this->mState = STATE_WAITING;
  }
  else
  {
    if ( mState == STATE_NONE )
      SimpleXML::XMLWriterData::Write(this, "\t", this->mIndent);
    SimpleXML::XMLWriterData::Write(this, "</", 1);
    SimpleXML::XMLWriterData::Write(this, name, 1);
    SimpleXML::XMLWriterData::Write(this, ">", 1);
  }
}

// File Line: 1104
// RVA: 0x89390
void __fastcall SimpleXML::XMLWriter::XMLWriter(SimpleXML::XMLWriter *this)
{
  char *v2; // rax

  v2 = UFG::qMalloc(0x40ui64, "XMLWriter.mData", 0i64);
  if ( v2 )
  {
    *((_QWORD *)v2 + 6) = v2 + 48;
    *((_QWORD *)v2 + 7) = v2 + 48;
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
  this->mData = (SimpleXML::XMLWriterData *)v2;
  UFG::qStringCopy(this->mReplacementMap[0].mNaturalString, 0x7FFFFFFF, "&", -1);
  UFG::qStringCopy(this->mReplacementMap[1].mNaturalString, 0x7FFFFFFF, "<", -1);
  UFG::qStringCopy(this->mReplacementMap[2].mNaturalString, 0x7FFFFFFF, ">", -1);
  UFG::qStringCopy(this->mReplacementMap[3].mNaturalString, 0x7FFFFFFF, "\"", -1);
  UFG::qStringCopy(this->mReplacementMap[4].mNaturalString, 0x7FFFFFFF, "", -1);
  UFG::qStringCopy(this->mReplacementMap[0].mReplacementString, 0x7FFFFFFF, "&amp;", -1);
  UFG::qStringCopy(this->mReplacementMap[1].mReplacementString, 0x7FFFFFFF, "&lt;", -1);
  UFG::qStringCopy(this->mReplacementMap[2].mReplacementString, 0x7FFFFFFF, "&gt;", -1);
  UFG::qStringCopy(this->mReplacementMap[3].mReplacementString, 0x7FFFFFFF, "&quot;", -1);
  UFG::qStringCopy(this->mReplacementMap[4].mReplacementString, 0x7FFFFFFF, "&apos;", -1);
}

// File Line: 1127
// RVA: 0x8A340
UFG::qFile *__fastcall SimpleXML::XMLWriter::Create(const char *filename, bool includeHeader, unsigned int bufferSize)
{
  unsigned __int64 v3; // rsi
  UFG::qFile *result; // rax
  SimpleXML::XMLWriter *v6; // rbx
  char *v7; // rax
  SimpleXML::XMLWriterData **v8; // rax
  SimpleXML::XMLWriterData **v9; // rdi
  SimpleXML::XMLWriterData *v10; // rbx

  v3 = bufferSize;
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
    (*v9)->mWriteBufferPtr = UFG::qMalloc(v3, "XMLWriter.mWriteBuffer", 0i64);
    (*v9)->mWriteBufferSizeBytes = v3;
    (*v9)->mWriteBufferPos = 0;
    (*v9)->mFile = (UFG::qFile *)v6;
    if ( includeHeader )
    {
      v10 = *v9;
      SimpleXML::XMLWriterData::Write(*v9, "<?xml version=\"1.0\"?>\n", 1);
      SimpleXML::XMLWriterData::Write(v10, "\n", 1);
    }
    return (UFG::qFile *)v9;
  }
  return result;
}

// File Line: 1152
// RVA: 0x8A430
SimpleXML::XMLWriter *__fastcall SimpleXML::XMLWriter::CreateBuffer(unsigned int text_buffer_size, bool includeHeader)
{
  unsigned __int64 v3; // rbx
  char *v4; // rax
  SimpleXML::XMLWriterData **v5; // rax
  SimpleXML::XMLWriterData **v6; // rdi
  SimpleXML::XMLWriterData *v7; // rbx

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
  if ( includeHeader )
  {
    v7 = *v6;
    SimpleXML::XMLWriterData::Write(*v6, "<?xml version=\"1.0\"?>\n", 1);
    SimpleXML::XMLWriterData::Write(v7, "\n", 1);
  }
  return (SimpleXML::XMLWriter *)v6;
}

// File Line: 1169
// RVA: 0x89DF0
__int64 __fastcall SimpleXML::XMLWriter::Close(SimpleXML::XMLWriter *writer)
{
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  const char *mNext; // rsi
  UFG::qString *v4; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rax
  SimpleXML::XMLWriterData *mData; // rbx
  SimpleXML::XMLWriterData::State mState; // eax
  SimpleXML::XMLWriterData *v9; // rbx
  char *mWriteBufferPtr; // rdx
  unsigned int mWriteBufferPos; // eax
  SimpleXML::XMLWriterData *v12; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *v13; // r8
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rdx

  for ( ; writer->mData->mOpenNodes.mNode.mNext != &writer->mData->mOpenNodes.mNode; writer->mData->mState = STATE_NONE )
  {
    mPrev = writer->mData->mOpenNodes.mNode.mPrev;
    mNext = (const char *)mPrev[1].mNext;
    v4 = (UFG::qString *)mPrev;
    v5 = mPrev->mPrev;
    v6 = mPrev->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = v4;
    v4->mNext = v4;
    UFG::qString::~qString(v4);
    operator delete[](v4);
    --writer->mData->mIndent;
    mData = writer->mData;
    mState = writer->mData->mState;
    if ( mState == STATE_QUEUED )
    {
      SimpleXML::XMLWriterData::Write(writer->mData, "/>", 1);
      mData->mState = STATE_WAITING;
    }
    else
    {
      if ( mState == STATE_NONE )
        SimpleXML::XMLWriterData::Write(writer->mData, "\t", mData->mIndent);
      SimpleXML::XMLWriterData::Write(mData, "</", 1);
      SimpleXML::XMLWriterData::Write(mData, mNext, 1);
      SimpleXML::XMLWriterData::Write(mData, ">", 1);
    }
    SimpleXML::XMLWriterData::Write(writer->mData, "\n", 1);
  }
  v9 = writer->mData;
  if ( writer->mData->mWriteBufferPtr )
  {
    mWriteBufferPtr = v9->mWriteBufferPtr;
    if ( mWriteBufferPtr )
    {
      mWriteBufferPos = v9->mWriteBufferPos;
      if ( mWriteBufferPos )
        UFG::qWrite(v9->mFile, mWriteBufferPtr, mWriteBufferPos, 0i64, QSEEK_CUR, 0i64);
      v9->mWriteBufferPos = 0;
    }
    operator delete[](writer->mData->mWriteBufferPtr);
  }
  UFG::qClose(writer->mData->mFile);
  v12 = writer->mData;
  if ( writer->mData )
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
  operator delete[](writer);
  return 1i64;
}

// File Line: 1201
// RVA: 0x89FC0
const char *__fastcall SimpleXML::XMLWriter::CloseBuffer(SimpleXML::XMLWriterData ***writer, unsigned int *buffer_size)
{
  SimpleXML::XMLWriterData **v4; // rsi
  UFG::qString *mPrev; // rcx
  const char *mData; // rbp
  UFG::qString *v7; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  SimpleXML::XMLWriterData *v10; // rbx
  SimpleXML::XMLWriterData::State mState; // eax
  SimpleXML::XMLWriterData *v12; // rcx
  const char *mTextBuffer; // rbp
  UFG::qList<UFG::qString,UFG::qString,1,0> **v14; // r14
  UFG::qList<UFG::qString,UFG::qString,1,0> *v15; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *v16; // r8
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rdx
  const char *result; // rax

  for ( ;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)(**writer)->mOpenNodes.mNode.mNext != &(**writer)->mOpenNodes;
        (*v4)->mState = STATE_NONE )
  {
    v4 = *writer;
    mPrev = (UFG::qString *)(**writer)->mOpenNodes.mNode.mPrev;
    mData = mPrev->mData;
    v7 = mPrev;
    v8 = mPrev->mPrev;
    mNext = mPrev->mNext;
    v8->mNext = mNext;
    mNext->mPrev = v8;
    mPrev->mPrev = mPrev;
    mPrev->mNext = mPrev;
    UFG::qString::~qString(mPrev);
    operator delete[](v7);
    --(*v4)->mIndent;
    v10 = *v4;
    mState = (*v4)->mState;
    if ( mState == STATE_QUEUED )
    {
      SimpleXML::XMLWriterData::Write(*v4, "/>", 1);
      v10->mState = STATE_WAITING;
    }
    else
    {
      if ( mState == STATE_NONE )
        SimpleXML::XMLWriterData::Write(*v4, "\t", v10->mIndent);
      SimpleXML::XMLWriterData::Write(v10, "</", 1);
      SimpleXML::XMLWriterData::Write(v10, mData, 1);
      SimpleXML::XMLWriterData::Write(v10, ">", 1);
    }
    SimpleXML::XMLWriterData::Write(*v4, "\n", 1);
  }
  v12 = **writer;
  mTextBuffer = v12->mTextBuffer;
  if ( buffer_size )
    *buffer_size = v12->mTextBufferPos;
  v14 = (UFG::qList<UFG::qString,UFG::qString,1,0> **)*writer;
  if ( *writer )
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
  result = mTextBuffer;
  *writer = 0i64;
  return result;
}

// File Line: 1287
// RVA: 0x8A170
__int64 __fastcall SimpleXML::XMLWriter::CloseBufferAndWriteToFile(SimpleXML::XMLWriter *this, const char *filename)
{
  unsigned __int8 v3; // bl
  char *v4; // rbp
  UFG::qFile *v5; // rax
  UFG::qFile *v6; // rdi
  unsigned int buffer_size; // [rsp+40h] [rbp+8h] BYREF
  SimpleXML::XMLWriter *writer; // [rsp+50h] [rbp+18h] BYREF

  writer = this;
  v3 = 0;
  buffer_size = 0;
  v4 = (char *)SimpleXML::XMLWriter::CloseBuffer((SimpleXML::XMLWriterData ***)&writer, &buffer_size);
  if ( v4 )
  {
    if ( filename )
    {
      if ( *filename )
      {
        if ( buffer_size )
        {
          v5 = UFG::qOpen(filename, QACCESS_WRITE, 1);
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
  SimpleXML::XMLWriterData *mData; // rbx

  mData = this->mData;
  if ( this->mData->mState == STATE_QUEUED )
  {
    SimpleXML::XMLWriterData::Write(this->mData, ">", 1);
    mData->mState = STATE_WAITING;
    SimpleXML::XMLWriterData::Write(this->mData, "\n", 1);
  }
  SimpleXML::XMLWriterData::Write(this->mData, "\t", this->mData->mIndent);
  SimpleXML::XMLWriterData::Write(this->mData, "<!--", 1);
  SimpleXML::XMLWriterData::Write(this->mData, text, 1);
  SimpleXML::XMLWriterData::Write(this->mData, "-->", 1);
  SimpleXML::XMLWriterData::Write(this->mData, "\n", 1);
  this->mData->mState = STATE_NONE;
}

// File Line: 1384
// RVA: 0x89CF0
void __fastcall SimpleXML::XMLWriter::BeginNode(SimpleXML::XMLWriter *this, const char *name)
{
  SimpleXML::XMLWriterData *mData; // rdi
  char *v5; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v6; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rdx
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_mOpenNodes; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax

  mData = this->mData;
  if ( this->mData->mState == STATE_QUEUED )
  {
    SimpleXML::XMLWriterData::Write(this->mData, ">", 1);
    mData->mState = STATE_WAITING;
    SimpleXML::XMLWriterData::Write(this->mData, "\n", 1);
  }
  SimpleXML::XMLWriterData::Write(this->mData, "\t", this->mData->mIndent);
  SimpleXML::XMLWriterData::Write(this->mData, "<", 1);
  SimpleXML::XMLWriterData::Write(this->mData, name, 1);
  v5 = UFG::qMalloc(0x28ui64, "XMLWriter.BeginNode", 0i64);
  if ( v5 )
  {
    UFG::qString::qString((UFG::qString *)v5, name);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  p_mOpenNodes = &this->mData->mOpenNodes;
  mPrev = p_mOpenNodes->mNode.mPrev;
  mPrev->mNext = v7;
  v7->mPrev = mPrev;
  v7->mNext = &p_mOpenNodes->mNode;
  p_mOpenNodes->mNode.mPrev = v7;
  ++this->mData->mIndent;
  this->mData->mState = STATE_QUEUED;
}

// File Line: 1407
// RVA: 0x8A4F0
void __fastcall SimpleXML::XMLWriter::EndNode(SimpleXML::XMLWriter *this, const char *name)
{
  UFG::qString *mPrev; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // r8
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax

  mPrev = (UFG::qString *)this->mData->mOpenNodes.mNode.mPrev;
  v5 = mPrev->mPrev;
  mNext = mPrev->mNext;
  v5->mNext = mNext;
  mNext->mPrev = v5;
  mPrev->mPrev = mPrev;
  mPrev->mNext = mPrev;
  UFG::qString::~qString(mPrev);
  operator delete[](mPrev);
  --this->mData->mIndent;
  SimpleXML::XMLWriterData::CloseNode(this->mData, name);
  SimpleXML::XMLWriterData::Write(this->mData, "\n", 1);
  this->mData->mState = STATE_NONE;
}

// File Line: 1431
// RVA: 0x896F0
void __fastcall SimpleXML::XMLWriter::AddAttribute(
        SimpleXML::XMLWriter *this,
        const char *name,
        const char *val,
        bool replaceSpecialCharacters)
{
  SimpleXML::XMLReplacementMap *mReplacementMap; // rbx
  __int64 v9; // rdi
  char *mData; // rbp
  SimpleXML::XMLWriterData *v11; // rbx
  unsigned int v12; // eax
  unsigned int v13; // esi
  unsigned int mTextBufferSize; // edx
  unsigned int v15; // r14d
  unsigned int v16; // ecx
  char *v17; // rdi
  unsigned int v18; // edi
  char *v19; // rcx
  unsigned int mWriteBufferPos; // eax
  char *mWriteBufferPtr; // rdx
  UFG::qString v22; // [rsp+38h] [rbp-70h] BYREF
  UFG::qString v23; // [rsp+60h] [rbp-48h] BYREF

  SimpleXML::XMLWriterData::Write(this->mData, " ", 1);
  SimpleXML::XMLWriterData::Write(this->mData, name, 1);
  SimpleXML::XMLWriterData::Write(this->mData, "=\"", 1);
  if ( replaceSpecialCharacters )
  {
    UFG::qString::qString(&v22, val);
    UFG::qString::qString(&v23, name);
    mReplacementMap = this->mReplacementMap;
    v9 = 5i64;
    do
    {
      UFG::qString::ReplaceString(&v22, mReplacementMap->mNaturalString, mReplacementMap->mReplacementString, 0);
      ++mReplacementMap;
      --v9;
    }
    while ( v9 );
    mData = v22.mData;
    v11 = this->mData;
    v12 = UFG::qStringLength(v22.mData);
    v13 = v12;
    if ( v11->mTextBuffer )
    {
      mTextBufferSize = v11->mTextBufferSize;
      v15 = mTextBufferSize;
      v16 = v12 + v11->mTextBufferPos + 1;
      if ( v16 > mTextBufferSize )
      {
        do
          v15 *= 2;
        while ( v16 > v15 );
      }
      if ( v15 > mTextBufferSize )
      {
        v17 = UFG::qMalloc(v15, "XMLWriter.Write", 1ui64);
        UFG::qMemCopy(v17, v11->mTextBuffer, v11->mTextBufferPos);
        v17[v11->mTextBufferPos] = 0;
        operator delete[](v11->mTextBuffer);
        v11->mTextBuffer = v17;
        v11->mTextBufferSize = v15;
      }
      UFG::qMemCopy(&v11->mTextBuffer[v11->mTextBufferPos], mData, v13);
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
        UFG::qMemCopy(v19, mData, v18);
        mData += v18;
        v13 -= v18;
        v11->mWriteBufferPos += v18;
        mWriteBufferPos = v11->mWriteBufferPos;
        mWriteBufferPtr = v11->mWriteBufferPtr;
        if ( mWriteBufferPtr )
        {
          if ( mWriteBufferPos )
            UFG::qWrite(v11->mFile, mWriteBufferPtr, mWriteBufferPos, 0i64, QSEEK_CUR, 0i64);
          v11->mWriteBufferPos = 0;
        }
        if ( !v13 )
          goto LABEL_20;
      }
      UFG::qMemCopy(v19, mData, v13);
      v11->mWriteBufferPos += v13;
    }
LABEL_20:
    UFG::qString::~qString(&v23);
    UFG::qString::~qString(&v22);
  }
  else
  {
    SimpleXML::XMLWriterData::Write(this->mData, val, 1);
  }
  SimpleXML::XMLWriterData::Write(this->mData, "\"", 1);
}

// File Line: 1479
// RVA: 0x89990
void __fastcall SimpleXML::XMLWriter::AddAttribute(SimpleXML::XMLWriter *this, const char *name, float val)
{
  UFG::qString v5; // [rsp+28h] [rbp-40h] BYREF

  UFG::qString::qString(&v5);
  UFG::qString::Format(&v5, "%.7f#%08X", val, val);
  SimpleXML::XMLWriter::AddAttribute(this, name, v5.mData, 1);
  UFG::qString::~qString(&v5);
}

// File Line: 1494
// RVA: 0x89920
void __fastcall SimpleXML::XMLWriter::AddAttribute(SimpleXML::XMLWriter *this, const char *name, unsigned int val)
{
  UFG::qString v6; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::qString(&v6);
  UFG::qString::Format(&v6, "%u", val);
  SimpleXML::XMLWriter::AddAttribute(this, name, v6.mData, 1);
  UFG::qString::~qString(&v6);
}

// File Line: 1506
// RVA: 0x89A20
void __fastcall SimpleXML::XMLWriter::AddAttribute(SimpleXML::XMLWriter *this, const char *name, unsigned __int64 val)
{
  UFG::qString *v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  v5 = UFG::qToHex(&result, val);
  SimpleXML::XMLWriter::AddAttribute(this, name, v5->mData, 1);
  UFG::qString::~qString(&result);
}

// File Line: 1512
// RVA: 0x89C20
void __fastcall SimpleXML::XMLWriter::AddValue(
        SimpleXML::XMLWriter *this,
        const char *val,
        bool replaceSpecialCharacters)
{
  SimpleXML::XMLWriterData *mData; // rbx
  SimpleXML::XMLReplacementMap *mReplacementMap; // rbx
  __int64 v8; // rdi
  UFG::qString v9; // [rsp+28h] [rbp-30h] BYREF

  mData = this->mData;
  if ( this->mData->mState == STATE_QUEUED )
  {
    SimpleXML::XMLWriterData::Write(this->mData, ">", 1);
    mData->mState = STATE_WAITING;
  }
  if ( replaceSpecialCharacters )
  {
    UFG::qString::qString(&v9, val);
    mReplacementMap = this->mReplacementMap;
    v8 = 5i64;
    do
    {
      UFG::qString::ReplaceString(&v9, mReplacementMap->mNaturalString, mReplacementMap->mReplacementString, 0);
      ++mReplacementMap;
      --v8;
    }
    while ( v8 );
    SimpleXML::XMLWriterData::Write(this->mData, v9.mData, 1);
    UFG::qString::~qString(&v9);
  }
  else
  {
    SimpleXML::XMLWriterData::Write(this->mData, val, 1);
  }
}

// File Line: 1536
// RVA: 0x89BA0
void __fastcall SimpleXML::XMLWriter::AddValue(SimpleXML::XMLWriter *this, float val)
{
  UFG::qString v3; // [rsp+28h] [rbp-40h] BYREF

  UFG::qString::qString(&v3);
  UFG::qString::Format(&v3, "%.7f#%08X", val, val);
  SimpleXML::XMLWriter::AddValue(this, v3.mData, 1);
  UFG::qString::~qString(&v3);
}

// File Line: 1544
// RVA: 0x89B40
void __fastcall SimpleXML::XMLWriter::AddValue(SimpleXML::XMLWriter *this, unsigned int val)
{
  UFG::qString v4; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::qString(&v4);
  UFG::qString::Format(&v4, "%d", val);
  SimpleXML::XMLWriter::AddValue(this, v4.mData, 1);
  UFG::qString::~qString(&v4);
}

