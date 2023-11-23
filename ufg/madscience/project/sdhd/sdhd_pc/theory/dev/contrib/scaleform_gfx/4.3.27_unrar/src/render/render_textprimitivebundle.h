// File Line: 102
// RVA: 0x9F8930
void __fastcall Scaleform::Render::TextPrimitiveBundle::unpinLayerBatches(Scaleform::Render::TextPrimitiveBundle *this)
{
  unsigned __int64 Size; // rax
  unsigned __int64 i; // r10
  _QWORD *p_pData; // r9
  __int64 v4; // r9
  unsigned __int64 j; // rdx
  __int64 v6; // r8
  __int64 v7; // rax

  Size = this->Layers.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    if ( Size <= 2 )
      p_pData = &this->Layers.AD.pData;
    else
      p_pData = &this->Layers.AD.pData->pObject;
    v4 = p_pData[i];
    for ( j = 0i64; j < *(_QWORD *)(v4 + 112); ++j )
    {
      v6 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 104) + 8 * j) + 56i64);
      if ( (*(_DWORD *)(v6 + 240) & 0x20) != 0 )
        v7 = v6 + 208;
      else
        v7 = 0i64;
      --*(_QWORD *)(v7 + 136);
    }
    Size = this->Layers.Size;
  }
}

