// File Line: 81
// RVA: 0x70FC90
void __fastcall Scaleform::GFx::ASStringNode::Release(Scaleform::GFx::ASStringNode *this)
{
  if ( this->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(this);
}

// File Line: 392
// RVA: 0x6D0AE0
void __fastcall Scaleform::GFx::ASString::~ASString(Scaleform::GFx::ASString *this)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx

  pNode = this->pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 405
// RVA: 0x6DA750
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::AppendChar(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result,
        unsigned int ch)
{
  Scaleform::GFx::ASStringNode *appended; // rax

  appended = Scaleform::GFx::ASConstString::AppendCharNode(this, ch);
  result->pNode = appended;
  ++appended->RefCount;
  return result;
}

// File Line: 423
// RVA: 0x7211C0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::Substring(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result,
        int start,
        int end)
{
  Scaleform::GFx::ASStringNode *v5; // rax

  v5 = Scaleform::GFx::ASConstString::SubstringNode(this, start, end);
  result->pNode = v5;
  ++v5->RefCount;
  return result;
}

// File Line: 426
// RVA: 0x828880
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::TruncateWhitespace(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *v3; // rax

  v3 = Scaleform::GFx::ASConstString::TruncateWhitespaceNode(this);
  result->pNode = v3;
  ++v3->RefCount;
  return result;
}

// File Line: 429
// RVA: 0x722840
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::ToUpper(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *v3; // rax

  v3 = Scaleform::GFx::ASConstString::ToUpperNode(this);
  result->pNode = v3;
  ++v3->RefCount;
  return result;
}

// File Line: 430
// RVA: 0x721710
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::ToLower(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *v3; // rax

  v3 = Scaleform::GFx::ASConstString::ToLowerNode(this);
  result->pNode = v3;
  ++v3->RefCount;
  return result;
}

// File Line: 439
// RVA: 0x6D3450
void __fastcall Scaleform::GFx::ASString::operator=(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *src)
{
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v4; // rcx

  pNode = src->pNode;
  ++src->pNode->RefCount;
  v4 = this->pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->pNode = pNode;
}

// File Line: 482
// RVA: 0x6D3920
bool __fastcall Scaleform::GFx::ASString::operator>(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *str)
{
  return this->pNode != str->pNode && !Scaleform::GFx::ASString::operator<(this, str);
}

// File Line: 494
// RVA: 0x7021F0
int __fastcall Scaleform::GFx::ASString::LocaleCompare_CaseCheck(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *str,
        bool caseSensitive)
{
  const char *pData; // rbx
  unsigned int Length; // eax

  pData = str->pNode->pData;
  Length = Scaleform::GFx::ASConstString::GetLength(str);
  return Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(this, pData, Length, caseSensitive);
}

// File Line: 537
// RVA: 0x6DED50
bool __fastcall Scaleform::GFx::ASString::CompareBuiltIn_CaseCheck(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *str,
        bool caseSensitive)
{
  if ( caseSensitive )
    return this->pNode == str->pNode;
  if ( !str->pNode->pLower )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(str->pNode);
  return this->pNode->pLower == str->pNode->pLower;
}

// File Line: 544
// RVA: 0x6DEDB0
bool __fastcall Scaleform::GFx::ASString::CompareBuiltIn_CaseInsensitive(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *str)
{
  if ( !str->pNode->pLower )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(str->pNode);
  return this->pNode->pLower == str->pNode->pLower;
}

// File Line: 747
// RVA: 0x8CE4B0
void __fastcall Scaleform::GFx::ASStringManager::FreeStringNode(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASStringNode *pnode)
{
  Scaleform::GFx::ASStringManager::TextPage::Entry *pData; // rdx

  pData = (Scaleform::GFx::ASStringManager::TextPage::Entry *)pnode->pData;
  if ( pData )
  {
    if ( (pnode->HashFlags & 0x40000000) == 0 )
    {
      if ( pnode->Size >= 0x10 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      else
      {
        pData->pNextAlloc = this->pFreeTextBuffers;
        this->pFreeTextBuffers = pData;
      }
    }
    pnode->pData = 0i64;
  }
  pnode->pLower = this->pFreeStringNodes;
  this->pFreeStringNodes = pnode;
}

// File Line: 776
// RVA: 0x6DFE00
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateEmptyString(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // rcx

  p_EmptyStringNode = &this->EmptyStringNode;
  result->pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  return result;
}

// File Line: 782
// RVA: 0x6E1460
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateString(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASString *result,
        const char *pstr)
{
  Scaleform::GFx::ASStringNode *StringNode; // rax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this, pstr);
  result->pNode = StringNode;
  ++StringNode->RefCount;
  return result;
}

// File Line: 786
// RVA: 0x6E14A0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateString(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASString *result,
        const char *pstr,
        unsigned __int64 length)
{
  Scaleform::GFx::ASStringNode *StringNode; // rax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this, pstr, length);
  result->pNode = StringNode;
  ++StringNode->RefCount;
  return result;
}

// File Line: 790
// RVA: 0x6E1400
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateString(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASString *result,
        Scaleform::String *str)
{
  Scaleform::GFx::ASStringNode *StringNode; // rax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this,
                 (const char *)((str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                 *(_QWORD *)(str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  result->pNode = StringNode;
  ++StringNode->RefCount;
  return result;
}

// File Line: 794
// RVA: 0x6DF8E0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateConstString(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASString *result,
        const char *pstr,
        unsigned __int64 length,
        unsigned int stringFlags)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // rax

  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(this, pstr, length, stringFlags);
  result->pNode = ConstStringNode;
  ++ConstStringNode->RefCount;
  return result;
}

// File Line: 798
// RVA: 0x6DF880
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateConstString(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASString *result,
        const char *pstr)
{
  unsigned __int64 v5; // r8
  Scaleform::GFx::ASStringNode *ConstStringNode; // rax

  v5 = -1i64;
  do
    ++v5;
  while ( pstr[v5] );
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(this, pstr, v5, 0);
  result->pNode = ConstStringNode;
  ++ConstStringNode->RefCount;
  return result;
}

// File Line: 803
// RVA: 0x6E14F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateString(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASString *result,
        const wchar_t *pwstr,
        __int64 len)
{
  Scaleform::GFx::ASStringNode *StringNode; // rax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this, pwstr, len);
  result->pNode = StringNode;
  ++StringNode->RefCount;
  return result;
}

// File Line: 855
// RVA: 0x76C080
void __fastcall Scaleform::GFx::ASString::operator=<Scaleform::String>(
        Scaleform::GFx::ASString *this,
        Scaleform::StringDH *str)
{
  Scaleform::GFx::ASStringNode *StringNode; // rax
  Scaleform::GFx::ASStringNode *v4; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 (const char *)((str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                 *(_QWORD *)(str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  v4 = StringNode;
  ++StringNode->RefCount;
  pNode = this->pNode;
  if ( this->pNode->RefCount-- == 1 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    this->pNode = v4;
  }
  else
  {
    this->pNode = StringNode;
  }
}

// File Line: 897
// RVA: 0x785790
void __fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::~ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *this)
{
  Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(this->pStringManager, this->Builtins, 0x40u);
}

// File Line: 906
// RVA: 0x7BC620
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *this,
        Scaleform::GFx::ASString *result,
        const char *pstr)
{
  Scaleform::GFx::ASStringManager::CreateConstString(this->pStringManager, result, pstr);
  return result;
}

// File Line: 908
// RVA: 0x6E1250
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *this,
        Scaleform::GFx::ASString *result,
        const char *pstr)
{
  Scaleform::GFx::ASStringManager::CreateString(this->pStringManager, result, pstr);
  return result;
}

// File Line: 909
// RVA: 0x6E12D0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *this,
        Scaleform::GFx::ASString *result,
        const wchar_t *pwstr,
        __int64 len)
{
  Scaleform::GFx::ASStringManager::CreateString(this->pStringManager, result, pwstr, len);
  return result;
}

// File Line: 910
// RVA: 0x6E1290
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *this,
        Scaleform::GFx::ASString *result,
        const char *pstr,
        unsigned __int64 length)
{
  Scaleform::GFx::ASStringManager::CreateString(this->pStringManager, result, pstr, length);
  return result;
}

// File Line: 911
// RVA: 0x6E1210
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *this,
        Scaleform::GFx::ASString *result,
        Scaleform::String *str)
{
  Scaleform::GFx::ASStringManager::CreateString(this->pStringManager, result, str);
  return result;
}

// File Line: 913
// RVA: 0x7BC850
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // rax

  p_EmptyStringNode = &this->pStringManager->EmptyStringNode;
  result->pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  return result;
}

// File Line: 915
// RVA: 0x7BE0F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateNullString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *p_NullStringNode; // rax

  p_NullStringNode = &this->pStringManager->NullStringNode;
  result->pNode = p_NullStringNode;
  ++p_NullStringNode->RefCount;
  return result;
}

// File Line: 960
// RVA: 0x6C5C60
void __fastcall Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>(
        Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *this,
        Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *e)
{
  Scaleform::GFx::ASStringNode *pNode; // rax

  this->NextInChain = e->NextInChain;
  pNode = e->Value.First.pNode;
  this->Value.First.pNode = pNode;
  ++pNode->RefCount;
  Scaleform::GFx::AS2::Value::Value(&this->Value.Second, &e->Value.Second);
}

// File Line: 972
// RVA: 0x6DDAC0
void __fastcall Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>::Clear(
        Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *this)
{
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor> *p_Value; // rdi
  Scaleform::GFx::AS2::Member *p_Second; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx

  p_Value = &this->Value;
  p_Second = &this->Value.Second;
  if ( p_Value->Second.mValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&p_Second->mValue);
  pNode = p_Value->First.pNode;
  if ( p_Value->First.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->NextInChain = -2i64;
}

// File Line: 1005
// RVA: 0x6CFCC0
void __fastcall Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324>::~HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324>(
        Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&this->mHash);
}

// File Line: 1022
// RVA: 0x6CE6E0
void __fastcall Scaleform::GFx::ASStringHashBase<Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,324>>::~ASStringHashBase<Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,324>>(
        Scaleform::GFx::ASStringHashBase<char,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor,324> > *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this);
}

// File Line: 1030
// RVA: 0x6EEBE0
char __fastcall Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324> > *this,
        Scaleform::GFx::ASString *key,
        Scaleform::GFx::AS2::Member *pvalue)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v6; // zf
  signed __int64 v8; // rax
  unsigned __int64 *p_SizeMask; // rbx
  Scaleform::GFx::ASString::NoCaseKey keya; // [rsp+30h] [rbp+8h] BYREF

  pNode = key->pNode;
  v6 = key->pNode->pLower == 0i64;
  keya.pStr = key;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
  if ( !this->mHash.pTable )
    return 0;
  v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this,
         &keya,
         this->mHash.pTable->SizeMask & key->pNode->HashFlags);
  if ( v8 < 0 )
    return 0;
  p_SizeMask = &this->mHash.pTable[3 * v8 + 1].SizeMask;
  if ( !p_SizeMask )
    return 0;
  if ( pvalue )
  {
    Scaleform::GFx::AS2::Value::operator=(&pvalue->mValue, (Scaleform::GFx::AS2::Value *)(p_SizeMask + 1));
    pvalue->mValue.T.PropFlags = *((_BYTE *)p_SizeMask + 9);
  }
  return 1;
}

// File Line: 1041
// RVA: 0x6EEC90
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *this,
        Scaleform::GFx::ASString *key)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v5; // zf
  signed __int64 v6; // rax
  unsigned __int64 *p_SizeMask; // rax
  Scaleform::GFx::ASString::NoCaseKey keya; // [rsp+30h] [rbp+8h] BYREF

  pNode = key->pNode;
  v5 = key->pNode->pLower == 0i64;
  keya.pStr = key;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
  if ( this->mHash.pTable
    && (v6 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
               &this->mHash,
               &keya,
               this->mHash.pTable->SizeMask & key->pNode->HashFlags),
        v6 >= 0)
    && (p_SizeMask = &this->mHash.pTable[3 * v6 + 1].SizeMask) != 0i64 )
  {
    return (Scaleform::GFx::AS2::Value *)(p_SizeMask + 1);
  }
  else
  {
    return 0i64;
  }
}

// File Line: 1072
// RVA: 0x6EA330
Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *__fastcall Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *this,
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *result,
        Scaleform::GFx::ASString *key,
        bool caseSensitive)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  __int64 v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *v11; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::ASString::NoCaseKey keya; // [rsp+48h] [rbp+10h] BYREF

  if ( !caseSensitive )
  {
    pNode = key->pNode;
    keya.pStr = key;
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    if ( this->mHash.pTable )
    {
      v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
             &this->mHash,
             &keya,
             this->mHash.pTable->SizeMask & key->pNode->HashFlags);
      if ( v8 >= 0 )
      {
        v11 = this;
        goto LABEL_11;
      }
    }
LABEL_10:
    v8 = 0i64;
    v11 = 0i64;
    goto LABEL_11;
  }
  pTable = this->mHash.pTable;
  if ( !pTable )
    goto LABEL_10;
  v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
         &this->mHash,
         key,
         pTable->SizeMask & key->pNode->HashFlags);
  if ( v8 < 0 )
    goto LABEL_10;
  v11 = this;
LABEL_11:
  result->pHash = &v11->mHash;
  result->Index = v8;
  return result;
}

// File Line: 1082
// RVA: 0x713300
void __fastcall Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *this,
        Scaleform::GFx::ASString *key,
        Scaleform::GFx::AS2::Value *value,
        bool caseSensitive)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // r9
  unsigned __int64 HashFlags; // r9
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator result; // [rsp+20h] [rbp-18h] BYREF

  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
    this,
    &result,
    key,
    caseSensitive);
  if ( result.pHash && (pTable = result.pHash->pTable) != 0i64 && result.Index <= (signed __int64)pTable->SizeMask )
  {
    Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&pTable[3 * result.Index + 2], value);
  }
  else
  {
    HashFlags = key->pNode->HashFlags;
    result.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)key;
    result.Index = (__int64)value;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &this->mHash,
      this,
      (Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&result,
      HashFlags);
  }
}

