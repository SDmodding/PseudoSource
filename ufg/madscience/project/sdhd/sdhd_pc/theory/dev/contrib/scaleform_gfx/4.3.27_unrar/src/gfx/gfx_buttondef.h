// File Line: 99
// RVA: 0x8A3590
void __fastcall Scaleform::GFx::ButtonActionBase::~ButtonActionBase(Scaleform::GFx::ButtonActionBase *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ButtonActionBase::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&this->vfptr);
}

// File Line: 130
// RVA: 0x8DD510
Scaleform::Render::Rect<float> *__fastcall Scaleform::Formatter::GetPrevStr(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *t)
{
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  return result;
}

// File Line: 138
// RVA: 0x90B620
void __fastcall Scaleform::GFx::ButtonDef::SetScale9Grid(Scaleform::GFx::ButtonDef *this, Scaleform::Render::Rect<float> *r)
{
  Scaleform::Render::Rect<float> *v2; // rbx
  Scaleform::GFx::ButtonDef *v3; // rdi
  Scaleform::GFx::Scale9Grid *v4; // rdx
  Scaleform::GFx::Scale9Grid *v5; // rax
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  int v12; // [rsp+50h] [rbp+18h]
  Scaleform::GFx::Scale9Grid *v13; // [rsp+58h] [rbp+20h]

  v2 = r;
  v3 = this;
  v4 = this->pScale9Grid;
  if ( v4 )
  {
    v9 = v2->y2;
    v10 = v2->x2;
    v11 = v2->y1;
    v4->Rect.x1 = v2->x1;
    v4->Rect.y1 = v11;
    v4->Rect.x2 = v10;
    v4->Rect.y2 = v9;
  }
  else
  {
    v12 = 258;
    v5 = (Scaleform::GFx::Scale9Grid *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::ButtonDef *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         16i64,
                                         &v12,
                                         -2i64);
    v13 = v5;
    if ( v5 )
    {
      v6 = v2->y2;
      v7 = v2->x2;
      v8 = v2->y1;
      v5->Rect.x1 = v2->x1;
      v5->Rect.y1 = v8;
      v5->Rect.x2 = v7;
      v5->Rect.y2 = v6;
    }
    v3->pScale9Grid = v5;
  }
}

// File Line: 155
// RVA: 0x8DDCD0
signed __int64 __fastcall Scaleform::GFx::ButtonDef::GetResourceTypeCode(Scaleform::GFx::ButtonDef *this)
{
  return 33024i64;
}

