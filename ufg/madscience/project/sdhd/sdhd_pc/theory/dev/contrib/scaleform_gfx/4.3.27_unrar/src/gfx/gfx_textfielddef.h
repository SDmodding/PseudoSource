// File Line: 141
// RVA: 0x8DDD30
signed __int64 __fastcall Scaleform::GFx::TextFieldDef::GetResourceTypeCode(Scaleform::GFx::TextFieldDef *this)
{
  return 33536i64;
}

// File Line: 188
// RVA: 0x8A7EE0
void __fastcall Scaleform::GFx::StaticTextRecordList::~StaticTextRecordList(Scaleform::GFx::StaticTextRecordList *this)
{
  Scaleform::GFx::StaticTextRecordList *v1; // rbx

  v1 = this;
  Scaleform::GFx::StaticTextRecordList::Clear(this);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Records.Data.Data);
}

// File Line: 231
// RVA: 0x8D5590
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::StaticTextDef::GetBoundsLocal(Scaleform::GFx::StaticTextDef *this, Scaleform::Render::Rect<float> *result, float __formal)
{
  result->x1 = this->TextRect.x1;
  result->y1 = this->TextRect.y1;
  result->x2 = this->TextRect.x2;
  result->y2 = this->TextRect.y2;
  return result;
}

// File Line: 238
// RVA: 0x8DDD20
signed __int64 __fastcall Scaleform::GFx::StaticTextDef::GetResourceTypeCode(Scaleform::GFx::StaticTextDef *this)
{
  return 33280i64;
}

