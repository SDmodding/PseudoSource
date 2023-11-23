// File Line: 342
// RVA: 0x8CE510
void __fastcall Scaleform::GFx::XML::DOMStringManager::FreeStringNode(
        Scaleform::GFx::XML::DOMStringManager *this,
        Scaleform::GFx::XML::DOMStringNode *pnode)
{
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *pData; // rdx

  pData = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)pnode->pData;
  if ( pData )
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
    pnode->pData = 0i64;
  }
  pnode->pManager = (Scaleform::GFx::XML::DOMStringManager *)this->pFreeStringNodes;
  this->pFreeStringNodes = pnode;
}

// File Line: 391
// RVA: 0x6DFE40
Scaleform::GFx::XML::DOMString *__fastcall Scaleform::GFx::XML::DOMStringManager::CreateEmptyString(
        Scaleform::GFx::XML::DOMStringManager *this,
        Scaleform::GFx::XML::DOMString *result)
{
  Scaleform::GFx::XML::DOMString::DOMString(result, &this->EmptyStringNode);
  return result;
}

// File Line: 399
// RVA: 0x6E1540
Scaleform::GFx::XML::DOMString *__fastcall Scaleform::GFx::XML::DOMStringManager::CreateString(
        Scaleform::GFx::XML::DOMStringManager *this,
        Scaleform::GFx::XML::DOMString *result,
        const char *pstr,
        unsigned __int64 length)
{
  Scaleform::GFx::XML::DOMStringNode *StringNode; // rax

  StringNode = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(this, pstr, length);
  Scaleform::GFx::XML::DOMString::DOMString(result, StringNode);
  return result;
}

// File Line: 445
// RVA: 0x6E1780
Scaleform::GFx::XML::DOMString *__fastcall Scaleform::GFx::XML::ObjectManager::CreateString(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::XML::DOMString *result,
        const char *str,
        unsigned __int64 len)
{
  Scaleform::GFx::XML::DOMStringManager::CreateString(&this->StringPool, result, str, len);
  return result;
}

// File Line: 454
// RVA: 0x6E2E20
Scaleform::GFx::XML::DOMString *__fastcall Scaleform::GFx::XML::ObjectManager::EmptyString(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::XML::DOMString *result)
{
  Scaleform::GFx::XML::DOMStringManager::CreateEmptyString(&this->StringPool, result);
  return result;
}

