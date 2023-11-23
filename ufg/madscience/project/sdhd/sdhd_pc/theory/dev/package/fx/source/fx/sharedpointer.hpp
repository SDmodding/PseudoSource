// File Line: 59
// RVA: 0x1C2370
void __fastcall FX::SharedPointer<Render::LightweightFXPosition>::~SharedPointer<Render::LightweightFXPosition>(
        FX::SharedPointer<Render::LightweightFXPosition> *this)
{
  Render::LightweightFXPosition *m_pPointer; // rcx

  if ( this->m_pPointer )
  {
    --this->m_pPointer->mReferenceCount;
    m_pPointer = this->m_pPointer;
    if ( m_pPointer->mReferenceCount <= 0 )
    {
      operator delete[](m_pPointer);
      this->m_pPointer = 0i64;
    }
  }
}

// File Line: 64
// RVA: 0x1D6220
Render::FXOverride *__fastcall FX::SharedPointer<Render::FXOverride>::Set(
        FX::SharedPointer<Render::FXOverride> *this,
        Render::FXOverride *pointer)
{
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v5; // rdi
  char *mTriangleInfo; // rdx
  Render::FXOverride *result; // rax

  m_pPointer = this->m_pPointer;
  if ( pointer == this->m_pPointer )
    return pointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v5 = this->m_pPointer;
    if ( this->m_pPointer->mReferenceCount <= 0 )
    {
      if ( v5 )
      {
        mTriangleInfo = (char *)v5->mTriangleInfo;
        if ( mTriangleInfo )
          UFG::qMemoryPool::Free(v5->mMemoryPool, mTriangleInfo);
        --Render::FXOverride::sNumInstancesInService;
        operator delete[](v5);
      }
      this->m_pPointer = 0i64;
    }
  }
  this->m_pPointer = pointer;
  result = pointer;
  if ( pointer )
    ++pointer->mReferenceCount;
  return result;
}

// File Line: 74
// RVA: 0x1C4A90
FX::SharedPointer<Render::LightweightFXPosition> *__fastcall FX::SharedPointer<Render::LightweightFXPosition>::operator=(
        FX::SharedPointer<Render::LightweightFXPosition> *this,
        Render::LightweightFXPosition *pointer)
{
  Render::LightweightFXPosition *m_pPointer; // rax
  Render::LightweightFXPosition *v5; // rcx
  FX::SharedPointer<Render::LightweightFXPosition> *result; // rax

  m_pPointer = this->m_pPointer;
  if ( pointer == this->m_pPointer )
    return this;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v5 = this->m_pPointer;
    if ( v5->mReferenceCount <= 0 )
    {
      operator delete[](v5);
      this->m_pPointer = 0i64;
    }
  }
  this->m_pPointer = pointer;
  result = this;
  if ( pointer )
    ++pointer->mReferenceCount;
  return result;
}

