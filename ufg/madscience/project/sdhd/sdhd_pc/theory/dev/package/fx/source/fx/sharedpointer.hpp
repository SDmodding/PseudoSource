// File Line: 59
// RVA: 0x1C2370
void __fastcall FX::SharedPointer<Render::LightweightFXPosition>::~SharedPointer<Render::LightweightFXPosition>(FX::SharedPointer<Render::LightweightFXPosition> *this)
{
  FX::SharedPointer<Render::LightweightFXPosition> *v1; // rbx
  Render::LightweightFXPosition *v2; // rcx

  v1 = this;
  if ( this->m_pPointer )
  {
    --this->m_pPointer->mReferenceCount;
    v2 = this->m_pPointer;
    if ( v2->mReferenceCount <= 0 )
    {
      operator delete[](v2);
      v1->m_pPointer = 0i64;
    }
  }
}

// File Line: 64
// RVA: 0x1D6220
Render::FXOverride *__fastcall FX::SharedPointer<Render::FXOverride>::Set(FX::SharedPointer<Render::FXOverride> *this, Render::FXOverride *pointer)
{
  Render::FXOverride *v2; // rax
  Render::FXOverride *v3; // rbx
  FX::SharedPointer<Render::FXOverride> *v4; // rsi
  Render::FXOverride *v5; // rdi
  Render::FXOverride::PrecalculatedTriangle *v6; // rdx
  Render::FXOverride *result; // rax

  v2 = this->m_pPointer;
  v3 = pointer;
  v4 = this;
  if ( pointer == this->m_pPointer )
    return pointer;
  if ( v2 )
  {
    --v2->mReferenceCount;
    v5 = this->m_pPointer;
    if ( this->m_pPointer->mReferenceCount <= 0 )
    {
      if ( v5 )
      {
        v6 = v5->mTriangleInfo;
        if ( v6 )
          UFG::qMemoryPool::Free(v5->mMemoryPool, v6);
        --Render::FXOverride::sNumInstancesInService;
        operator delete[](v5);
      }
      v4->m_pPointer = 0i64;
    }
  }
  v4->m_pPointer = v3;
  result = v3;
  if ( v3 )
    ++v3->mReferenceCount;
  return result;
}

// File Line: 74
// RVA: 0x1C4A90
FX::SharedPointer<Render::LightweightFXPosition> *__fastcall FX::SharedPointer<Render::LightweightFXPosition>::operator=(FX::SharedPointer<Render::LightweightFXPosition> *this, Render::LightweightFXPosition *pointer)
{
  Render::LightweightFXPosition *v2; // rax
  Render::LightweightFXPosition *v3; // rdi
  FX::SharedPointer<Render::LightweightFXPosition> *v4; // rbx
  Render::LightweightFXPosition *v5; // rcx
  FX::SharedPointer<Render::LightweightFXPosition> *result; // rax

  v2 = this->m_pPointer;
  v3 = pointer;
  v4 = this;
  if ( pointer == this->m_pPointer )
    return this;
  if ( v2 )
  {
    --v2->mReferenceCount;
    v5 = this->m_pPointer;
    if ( v5->mReferenceCount <= 0 )
    {
      operator delete[](v5);
      v4->m_pPointer = 0i64;
    }
  }
  v4->m_pPointer = v3;
  result = v4;
  if ( v3 )
    ++v3->mReferenceCount;
  return result;
}

