// File Line: 99
// RVA: 0x8A3590
void __fastcall Scaleform::GFx::ButtonActionBase::~ButtonActionBase(Scaleform::GFx::ButtonActionBase *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ButtonActionBase::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 130
// RVA: 0x8DD510
Scaleform::Render::Rect<float> *__fastcall Scaleform::Formatter::GetPrevStr(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *t)
{
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  return result;
}

// File Line: 138
// RVA: 0x90B620
void __fastcall Scaleform::GFx::ButtonDef::SetScale9Grid(
        Scaleform::GFx::ButtonDef *this,
        Scaleform::Render::Rect<float> *r)
{
  Scaleform::GFx::Scale9Grid *pScale9Grid; // rdx
  __int64 v5; // rax
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm0_4
  int v12; // [rsp+50h] [rbp+18h] BYREF
  __int64 v13; // [rsp+58h] [rbp+20h]

  pScale9Grid = this->pScale9Grid;
  if ( pScale9Grid )
  {
    y2 = r->y2;
    x2 = r->x2;
    y1 = r->y1;
    pScale9Grid->Rect.x1 = r->x1;
    pScale9Grid->Rect.y1 = y1;
    pScale9Grid->Rect.x2 = x2;
    pScale9Grid->Rect.y2 = y2;
  }
  else
  {
    v12 = 258;
    v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ButtonDef *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
           Scaleform::Memory::pGlobalHeap,
           this,
           16i64,
           &v12,
           -2i64);
    v13 = v5;
    if ( v5 )
    {
      v6 = r->y2;
      v7 = r->x2;
      v8 = r->y1;
      *(float *)v5 = r->x1;
      *(float *)(v5 + 4) = v8;
      *(float *)(v5 + 8) = v7;
      *(float *)(v5 + 12) = v6;
    }
    this->pScale9Grid = (Scaleform::GFx::Scale9Grid *)v5;
  }
}

// File Line: 155
// RVA: 0x8DDCD0
__int64 __fastcall Scaleform::GFx::ButtonDef::GetResourceTypeCode(Scaleform::GFx::ButtonDef *this)
{
  return 33024i64;
}

