// File Line: 301
// RVA: 0x94AE30
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::~HMatrix(Scaleform::Render::MatrixPoolImpl::HMatrix *this)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *v1; // rbx
  bool v2; // zf
  __int64 v3; // rcx

  if ( this->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v1 = this->pHandle->pHeader;
    v2 = v1->RefCount-- == 1;
    if ( v2 )
    {
      v3 = v1->DataPageOffset;
      *(_WORD *)((char *)&v1[1].RefCount + v3 + 2) += 16 * (unsigned __int8)v1->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v1[1].pHandle + v3))[5].pHeader += (unsigned __int8)v1->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v1->pHandle);
      v1->pHandle = 0i64;
    }
  }
}

// File Line: 345
// RVA: 0x981F20
Scaleform::Render::Cxform *__fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::GetCxform(Scaleform::Render::MatrixPoolImpl::HMatrix *this)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *v1; // rdx
  Scaleform::Render::Cxform *result; // rax

  v1 = this->pHandle->pHeader;
  if ( v1->Format & 1 )
    result = (Scaleform::Render::Cxform *)&v1[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v1->Format & 0xF].Offsets[0]
                                            + 1];
  else
    result = &Scaleform::Render::Cxform::Identity;
  return result;
}

