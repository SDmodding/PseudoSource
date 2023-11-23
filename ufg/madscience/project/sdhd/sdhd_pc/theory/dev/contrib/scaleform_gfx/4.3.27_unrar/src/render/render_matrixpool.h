// File Line: 301
// RVA: 0x94AE30
void __fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::~HMatrix(Scaleform::Render::MatrixPoolImpl::HMatrix *this)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx

  if ( this->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    pHeader = this->pHandle->pHeader;
    if ( pHeader->RefCount-- == 1 )
    {
      DataPageOffset = pHeader->DataPageOffset;
      *(_WORD *)((char *)&pHeader[1].RefCount + DataPageOffset + 2) += 16 * (unsigned __int8)pHeader->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)pHeader->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
      pHeader->pHandle = 0i64;
    }
  }
}

// File Line: 345
// RVA: 0x981F20
Scaleform::Render::Cxform *__fastcall Scaleform::Render::MatrixPoolImpl::HMatrix::GetCxform(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rdx

  pHeader = this->pHandle->pHeader;
  if ( (pHeader->Format & 1) != 0 )
    return (Scaleform::Render::Cxform *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[0]
                                               + 1];
  else
    return &Scaleform::Render::Cxform::Identity;
}

