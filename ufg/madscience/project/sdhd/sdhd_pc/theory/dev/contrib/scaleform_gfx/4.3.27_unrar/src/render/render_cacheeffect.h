// File Line: 50
// RVA: 0x949000
void __fastcall Scaleform::Render::CacheEffect::~CacheEffect(Scaleform::Render::CacheEffect *this)
{
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
}

// File Line: 156
// RVA: 0x980740
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::MaskEffect::GetBoundsMatrix(
        Scaleform::Render::MaskEffect *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax

  pHandle = this->BoundsMatrix.pHandle;
  result->pHandle = pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
  return result;
}

// File Line: 182
// RVA: 0x9806A0
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::BlendModeEffect::GetBoundsMatrix(
        Scaleform::Render::BlendModeEffect *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax

  pHandle = this->BoundsMatrix.pHandle;
  result->pHandle = pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
  return result;
}

// File Line: 186
// RVA: 0x98B830
Scaleform::Render::TreeCacheNode *__fastcall Scaleform::Render::ViewMatrix3DEffect::GetSourceNode(
        Scaleform::Render::ViewMatrix3DEffect *this)
{
  return this->StartEntry.pSourceNode;
}

// File Line: 204
// RVA: 0x9806F0
Scaleform::Render::MatrixPoolImpl::HMatrix *__fastcall Scaleform::Render::FilterEffect::GetBoundsMatrix(
        Scaleform::Render::FilterEffect *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax

  pHandle = this->BoundsMatrix.pHandle;
  result->pHandle = pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
  return result;
}

