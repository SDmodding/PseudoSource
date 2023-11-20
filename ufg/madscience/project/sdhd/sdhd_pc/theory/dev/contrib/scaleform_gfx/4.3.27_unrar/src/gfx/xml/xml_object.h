// File Line: 342
// RVA: 0x8CE510
void __fastcall Scaleform::GFx::XML::DOMStringManager::FreeStringNode(Scaleform::GFx::XML::DOMStringManager *this, Scaleform::GFx::XML::DOMStringNode *pnode)
{
  Scaleform::GFx::XML::DOMStringNode *v2; // rbx
  Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *v3; // rdx
  Scaleform::GFx::XML::DOMStringManager *v4; // rdi

  v2 = pnode;
  v3 = (Scaleform::GFx::XML::DOMStringManager::TextPage::Entry *)pnode->pData;
  v4 = this;
  if ( v3 )
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
    v2->pData = 0i64;
  }
  v2->pManager = (Scaleform::GFx::XML::DOMStringManager *)v4->pFreeStringNodes;
  v4->pFreeStringNodes = v2;
}

// File Line: 391
// RVA: 0x6DFE40
Scaleform::GFx::XML::DOMString *__fastcall Scaleform::GFx::XML::DOMStringManager::CreateEmptyString(Scaleform::GFx::XML::DOMStringManager *this, Scaleform::GFx::XML::DOMString *result)
{
  Scaleform::GFx::XML::DOMString *v2; // rbx

  v2 = result;
  Scaleform::GFx::XML::DOMString::DOMString(result, &this->EmptyStringNode);
  return v2;
}

// File Line: 399
// RVA: 0x6E1540
Scaleform::GFx::XML::DOMString *__fastcall Scaleform::GFx::XML::DOMStringManager::CreateString(Scaleform::GFx::XML::DOMStringManager *this, Scaleform::GFx::XML::DOMString *result, const char *pstr, unsigned __int64 length)
{
  Scaleform::GFx::XML::DOMString *v4; // rbx
  Scaleform::GFx::XML::DOMStringNode *v5; // rax

  v4 = result;
  v5 = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(this, pstr, length);
  Scaleform::GFx::XML::DOMString::DOMString(v4, v5);
  return v4;
}

// File Line: 445
// RVA: 0x6E1780
Scaleform::GFx::XML::DOMString *__fastcall Scaleform::GFx::XML::ObjectManager::CreateString(Scaleform::GFx::XML::ObjectManager *this, Scaleform::GFx::XML::DOMString *result, const char *str, unsigned __int64 len)
{
  Scaleform::GFx::XML::DOMString *v4; // rbx

  v4 = result;
  Scaleform::GFx::XML::DOMStringManager::CreateString(&this->StringPool, result, str, len);
  return v4;
}

// File Line: 454
// RVA: 0x6E2E20
Scaleform::GFx::XML::DOMString *__fastcall Scaleform::GFx::XML::ObjectManager::EmptyString(Scaleform::GFx::XML::ObjectManager *this, Scaleform::GFx::XML::DOMString *result)
{
  Scaleform::GFx::XML::DOMString *v2; // rbx

  v2 = result;
  Scaleform::GFx::XML::DOMStringManager::CreateEmptyString(&this->StringPool, result);
  return v2;
}

