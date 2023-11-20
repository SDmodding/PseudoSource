// File Line: 81
// RVA: 0x70FC90
void __fastcall Scaleform::GFx::ASStringNode::Release(Scaleform::GFx::ASStringNode *this)
{
  bool v1; // zf

  v1 = this->RefCount-- == 1;
  JUMPOUT(v1, Scaleform::GFx::ASStringNode::ReleaseNode);
}

// File Line: 392
// RVA: 0x6D0AE0
void __fastcall Scaleform::GFx::ASString::~ASString(Scaleform::GFx::ASString *this)
{
  Scaleform::GFx::ASStringNode *v1; // rcx
  bool v2; // zf

  v1 = this->pNode;
  v2 = v1->RefCount-- == 1;
  JUMPOUT(v2, Scaleform::GFx::ASStringNode::ReleaseNode);
}

// File Line: 405
// RVA: 0x6DA750
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::AppendChar(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *result, unsigned int ch)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rax

  v3 = result;
  v4 = Scaleform::GFx::ASConstString::AppendCharNode((Scaleform::GFx::ASConstString *)&this->pNode, ch);
  v3->pNode = v4;
  ++v4->RefCount;
  return v3;
}

// File Line: 423
// RVA: 0x7211C0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::Substring(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *result, int start, int end)
{
  Scaleform::GFx::ASString *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rax

  v4 = result;
  v5 = Scaleform::GFx::ASConstString::SubstringNode((Scaleform::GFx::ASConstString *)&this->pNode, start, end);
  v4->pNode = v5;
  ++v5->RefCount;
  return v4;
}

// File Line: 426
// RVA: 0x828880
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::TruncateWhitespace(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::ASStringNode *v3; // rax

  v2 = result;
  v3 = Scaleform::GFx::ASConstString::TruncateWhitespaceNode((Scaleform::GFx::ASConstString *)&this->pNode);
  v2->pNode = v3;
  ++v3->RefCount;
  return v2;
}

// File Line: 429
// RVA: 0x722840
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::ToUpper(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::ASStringNode *v3; // rax

  v2 = result;
  v3 = Scaleform::GFx::ASConstString::ToUpperNode((Scaleform::GFx::ASConstString *)&this->pNode);
  v2->pNode = v3;
  ++v3->RefCount;
  return v2;
}

// File Line: 430
// RVA: 0x721710
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::ToLower(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::ASStringNode *v3; // rax

  v2 = result;
  v3 = Scaleform::GFx::ASConstString::ToLowerNode((Scaleform::GFx::ASConstString *)&this->pNode);
  v2->pNode = v3;
  ++v3->RefCount;
  return v2;
}

// File Line: 439
// RVA: 0x6D3450
void __fastcall Scaleform::GFx::ASString::operator=(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *src)
{
  Scaleform::GFx::ASStringNode *v2; // rbx
  Scaleform::GFx::ASString *v3; // rdi
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf

  v2 = src->pNode;
  v3 = this;
  ++v2->RefCount;
  v4 = this->pNode;
  v5 = v4->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v3->pNode = v2;
}

// File Line: 482
// RVA: 0x6D3920
bool __fastcall Scaleform::GFx::ASString::operator>(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *str)
{
  bool result; // al

  if ( this->pNode == str->pNode )
    result = 0;
  else
    result = Scaleform::GFx::ASString::operator<(this, str) == 0;
  return result;
}

// File Line: 494
// RVA: 0x7021F0
int __fastcall Scaleform::GFx::ASString::LocaleCompare_CaseCheck(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *str, bool caseSensitive)
{
  Scaleform::GFx::ASString *v3; // rsi
  const char *v4; // rbx
  bool v5; // di
  unsigned int v6; // eax

  v3 = this;
  v4 = str->pNode->pData;
  v5 = caseSensitive;
  v6 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&str->pNode);
  return Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck((Scaleform::GFx::ASConstString *)&v3->pNode, v4, v6, v5);
}

// File Line: 537
// RVA: 0x6DED50
bool __fastcall Scaleform::GFx::ASString::CompareBuiltIn_CaseCheck(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *str, bool caseSensitive)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::ASString *v4; // rdi

  v3 = str;
  v4 = this;
  if ( caseSensitive )
    return this->pNode == str->pNode;
  if ( !str->pNode->pLower )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(str->pNode);
  return v4->pNode->pLower == v3->pNode->pLower;
}

// File Line: 544
// RVA: 0x6DEDB0
bool __fastcall Scaleform::GFx::ASString::CompareBuiltIn_CaseInsensitive(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::ASString *v3; // rbx

  v2 = this;
  v3 = str;
  if ( !str->pNode->pLower )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(str->pNode);
  return v2->pNode->pLower == v3->pNode->pLower;
}

// File Line: 747
// RVA: 0x8CE4B0
void __fastcall Scaleform::GFx::ASStringManager::FreeStringNode(Scaleform::GFx::ASStringManager *this, Scaleform::GFx::ASStringNode *pnode)
{
  Scaleform::GFx::ASStringNode *v2; // rbx
  Scaleform::GFx::ASStringManager::TextPage::Entry *v3; // rdx
  Scaleform::GFx::ASStringManager *v4; // rdi

  v2 = pnode;
  v3 = (Scaleform::GFx::ASStringManager::TextPage::Entry *)pnode->pData;
  v4 = this;
  if ( v3 )
  {
    if ( !(v2->HashFlags & 0x40000000) )
    {
      if ( v2->Size >= 0x10 )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      }
      else
      {
        v3->pNextAlloc = this->pFreeTextBuffers;
        this->pFreeTextBuffers = v3;
      }
    }
    v2->pData = 0i64;
  }
  v2->pLower = v4->pFreeStringNodes;
  v4->pFreeStringNodes = v2;
}

// File Line: 776
// RVA: 0x6DFE00
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateEmptyString(Scaleform::GFx::ASStringManager *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *v2; // rcx

  v2 = &this->EmptyStringNode;
  result->pNode = v2;
  ++v2->RefCount;
  return result;
}

// File Line: 782
// RVA: 0x6E1460
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateString(Scaleform::GFx::ASStringManager *this, Scaleform::GFx::ASString *result, const char *pstr)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rax

  v3 = result;
  v4 = Scaleform::GFx::ASStringManager::CreateStringNode(this, pstr);
  v3->pNode = v4;
  ++v4->RefCount;
  return v3;
}

// File Line: 786
// RVA: 0x6E14A0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateString(Scaleform::GFx::ASStringManager *this, Scaleform::GFx::ASString *result, const char *pstr, unsigned __int64 length)
{
  Scaleform::GFx::ASString *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rax

  v4 = result;
  v5 = Scaleform::GFx::ASStringManager::CreateStringNode(this, pstr, length);
  v4->pNode = v5;
  ++v5->RefCount;
  return v4;
}

// File Line: 790
// RVA: 0x6E1400
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateString(Scaleform::GFx::ASStringManager *this, Scaleform::GFx::ASString *result, Scaleform::String *str)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rax

  v3 = result;
  v4 = Scaleform::GFx::ASStringManager::CreateStringNode(
         this,
         (const char *)((str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
         *(_QWORD *)(str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  v3->pNode = v4;
  ++v4->RefCount;
  return v3;
}

// File Line: 794
// RVA: 0x6DF8E0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateConstString(Scaleform::GFx::ASStringManager *this, Scaleform::GFx::ASString *result, const char *pstr, unsigned __int64 length, unsigned int stringFlags)
{
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // rax

  v5 = result;
  v6 = Scaleform::GFx::ASStringManager::CreateConstStringNode(this, pstr, length, stringFlags);
  v5->pNode = v6;
  ++v6->RefCount;
  return v5;
}

// File Line: 798
// RVA: 0x6DF880
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateConstString(Scaleform::GFx::ASStringManager *this, Scaleform::GFx::ASString *result, const char *pstr)
{
  const char *v3; // rax
  Scaleform::GFx::ASString *v4; // rbx
  unsigned __int64 v5; // r8
  Scaleform::GFx::ASStringNode *v6; // rax

  v3 = pstr;
  v4 = result;
  v5 = -1i64;
  do
    ++v5;
  while ( v3[v5] );
  v6 = Scaleform::GFx::ASStringManager::CreateConstStringNode(this, v3, v5, 0);
  v4->pNode = v6;
  ++v6->RefCount;
  return v4;
}

// File Line: 803
// RVA: 0x6E14F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringManager::CreateString(Scaleform::GFx::ASStringManager *this, Scaleform::GFx::ASString *result, const wchar_t *pwstr, __int64 len)
{
  Scaleform::GFx::ASString *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rax

  v4 = result;
  v5 = Scaleform::GFx::ASStringManager::CreateStringNode(this, pwstr, len);
  v4->pNode = v5;
  ++v5->RefCount;
  return v4;
}

// File Line: 855
// RVA: 0x76C080
void __fastcall Scaleform::GFx::ASString::operator=<Scaleform::String>(Scaleform::GFx::ASString *this, Scaleform::StringDH *str)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::ASStringNode *v3; // rax
  Scaleform::GFx::ASStringNode *v4; // rdi
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf

  v2 = this;
  v3 = Scaleform::GFx::ASStringManager::CreateStringNode(
         this->pNode->pManager,
         (const char *)((str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
         *(_QWORD *)(str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  v4 = v3;
  ++v3->RefCount;
  v5 = v2->pNode;
  v6 = v2->pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    v2->pNode = v4;
  }
  else
  {
    v2->pNode = v3;
  }
}

// File Line: 897
// RVA: 0x785790
void __fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::~ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *this)
{
  Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(this->pStringManager, this->Builtins, 0x40u);
}

// File Line: 906
// RVA: 0x7BC620
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *this, Scaleform::GFx::ASString *result, const char *pstr)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  Scaleform::GFx::ASStringManager::CreateConstString(this->pStringManager, result, pstr);
  return v3;
}

// File Line: 908
// RVA: 0x6E1250
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *this, Scaleform::GFx::ASString *result, const char *pstr)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  Scaleform::GFx::ASStringManager::CreateString(this->pStringManager, result, pstr);
  return v3;
}

// File Line: 909
// RVA: 0x6E12D0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *this, Scaleform::GFx::ASString *result, const wchar_t *pwstr, __int64 len)
{
  Scaleform::GFx::ASString *v4; // rbx

  v4 = result;
  Scaleform::GFx::ASStringManager::CreateString(this->pStringManager, result, pwstr, len);
  return v4;
}

// File Line: 910
// RVA: 0x6E1290
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *this, Scaleform::GFx::ASString *result, const char *pstr, unsigned __int64 length)
{
  Scaleform::GFx::ASString *v4; // rbx

  v4 = result;
  Scaleform::GFx::ASStringManager::CreateString(this->pStringManager, result, pstr, length);
  return v4;
}

// File Line: 911
// RVA: 0x6E1210
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *this, Scaleform::GFx::ASString *result, Scaleform::String *str)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  Scaleform::GFx::ASStringManager::CreateString(this->pStringManager, result, str);
  return v3;
}

// File Line: 913
// RVA: 0x7BC850
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *v2; // rax

  v2 = &this->pStringManager->EmptyStringNode;
  result->pNode = v2;
  ++v2->RefCount;
  return result;
}

// File Line: 915
// RVA: 0x7BE0F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateNullString(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *v2; // rax

  v2 = &this->pStringManager->NullStringNode;
  result->pNode = v2;
  ++v2->RefCount;
  return result;
}

// File Line: 960
// RVA: 0x6C5C60
void __fastcall Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>(Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *this, Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *e)
{
  Scaleform::GFx::ASStringNode *v2; // rax

  this->NextInChain = e->NextInChain;
  v2 = e->Value.First.pNode;
  this->Value.First.pNode = v2;
  ++v2->RefCount;
  Scaleform::GFx::AS2::Value::Value(&this->Value.Second, &e->Value.Second);
}

// File Line: 972
// RVA: 0x6DDAC0
void __fastcall Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>::Clear(Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *this)
{
  Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *v1; // rbx
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor> *v2; // rdi
  Scaleform::GFx::AS2::Value *v3; // rcx
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf

  v1 = this;
  v2 = &this->Value;
  v3 = &this->Value.Second.mValue;
  if ( v2->Second.mValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v3);
  v4 = v2->First.pNode;
  v5 = v2->First.pNode->RefCount == 1;
  --v4->RefCount;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v1->NextInChain = -2i64;
}

// File Line: 1005
// RVA: 0x6CFCC0
void __fastcall Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324>::~HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324>(Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->mHash.pTable);
}

// File Line: 1022
// RVA: 0x6CE6E0
void __fastcall Scaleform::GFx::ASStringHashBase<Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,324>>::~ASStringHashBase<Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,324>>(Scaleform::GFx::ASStringHashBase<char,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor,324> > *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this);
}

// File Line: 1030
// RVA: 0x6EEBE0
char __fastcall Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324> > *this, Scaleform::GFx::ASString *key, Scaleform::GFx::AS2::Member *pvalue)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rcx
  Scaleform::GFx::AS2::Member *v5; // rdi
  bool v6; // zf
  Scaleform::GFx::ASString *v7; // rsi
  signed __int64 v8; // rax
  signed __int64 v9; // rbx
  Scaleform::GFx::ASString::NoCaseKey keya; // [rsp+30h] [rbp+8h]

  v3 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this;
  v4 = key->pNode;
  v5 = pvalue;
  v6 = key->pNode->pLower == 0i64;
  v7 = key;
  keya.pStr = key;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v4);
  if ( !v3->pTable )
    return 0;
  v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
         v3,
         &keya,
         v3->pTable->SizeMask & v7->pNode->HashFlags);
  if ( v8 < 0 )
    return 0;
  v9 = (signed __int64)&v3->pTable[3 * v8 + 1].SizeMask;
  if ( !v9 )
    return 0;
  if ( v5 )
  {
    Scaleform::GFx::AS2::Value::operator=(&v5->mValue, (Scaleform::GFx::AS2::Value *)(v9 + 8), (__int64)v5);
    v5->mValue.T.PropFlags = *(_BYTE *)(v9 + 9);
  }
  return 1;
}

// File Line: 1041
// RVA: 0x6EEC90
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *this, Scaleform::GFx::ASString *key)
{
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *v2; // rbx
  Scaleform::GFx::ASStringNode *v3; // rcx
  Scaleform::GFx::ASString *v4; // rdi
  bool v5; // zf
  signed __int64 v6; // rax
  signed __int64 v7; // rax
  Scaleform::GFx::AS2::Value *result; // rax
  Scaleform::GFx::ASString::NoCaseKey keya; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = key->pNode;
  v4 = key;
  v5 = key->pNode->pLower == 0i64;
  keya.pStr = key;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v3);
  if ( v2->mHash.pTable
    && (v6 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
               (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v2->mHash.pTable,
               &keya,
               v2->mHash.pTable->SizeMask & v4->pNode->HashFlags),
        v6 >= 0)
    && (v7 = (signed __int64)&v2->mHash.pTable[3 * v6 + 1].SizeMask) != 0 )
  {
    result = (Scaleform::GFx::AS2::Value *)(v7 + 8);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 1072
// RVA: 0x6EA330
Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *__fastcall Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *this, Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *result, Scaleform::GFx::ASString *key, bool caseSensitive)
{
  Scaleform::GFx::ASString *v4; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *v5; // rsi
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *v6; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v7; // rcx
  signed __int64 v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *v11; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::ASString::NoCaseKey keya; // [rsp+48h] [rbp+10h]

  v4 = key;
  v5 = result;
  v6 = this;
  if ( !caseSensitive )
  {
    v9 = key->pNode;
    keya.pStr = key;
    if ( !v9->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v9);
    if ( v6->mHash.pTable )
    {
      v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
             (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v6->mHash.pTable,
             &keya,
             v6->mHash.pTable->SizeMask & v4->pNode->HashFlags);
      if ( v8 >= 0 )
      {
        v11 = v6;
        goto LABEL_11;
      }
    }
LABEL_10:
    v8 = 0i64;
    v11 = 0i64;
    goto LABEL_11;
  }
  v7 = this->mHash.pTable;
  if ( !v7 )
    goto LABEL_10;
  v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v6->mHash.pTable,
         key,
         v7->SizeMask & key->pNode->HashFlags);
  if ( v8 < 0 )
    goto LABEL_10;
  v11 = v6;
LABEL_11:
  v5->pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v11->mHash.pTable;
  v5->Index = v8;
  return v5;
}

// File Line: 1082
// RVA: 0x713300
void __fastcall Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *this, Scaleform::GFx::ASString *key, Scaleform::GFx::AS2::Value *value, bool caseSensitive)
{
  Scaleform::GFx::AS2::Value *v4; // rsi
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *v6; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v7; // r9
  unsigned __int64 v8; // r9
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator result; // [rsp+20h] [rbp-18h]

  v4 = value;
  v5 = key;
  v6 = this;
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
    this,
    &result,
    key,
    caseSensitive);
  if ( result.pHash && (v7 = result.pHash->pTable) != 0i64 && result.Index <= (signed __int64)v7->SizeMask )
  {
    Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&v7[3 * result.Index + 2], v4, (__int64)v6);
  }
  else
  {
    v8 = v5->pNode->HashFlags;
    result.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v5;
    result.Index = (__int64)v4;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v6->mHash.pTable,
      v6,
      (Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&result,
      v8);
  }
}

