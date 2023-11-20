// File Line: 102
// RVA: 0x9F8930
void __fastcall Scaleform::Render::TextPrimitiveBundle::unpinLayerBatches(Scaleform::Render::TextPrimitiveBundle *this)
{
  unsigned __int64 v1; // rax
  unsigned __int64 v2; // r10
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v3; // r9
  Scaleform::Render::TextLayerPrimitive *v4; // r9
  unsigned __int64 v5; // rdx
  Scaleform::Render::TreeCacheNode *v6; // r8
  signed __int64 v7; // rax

  v1 = this->Layers.Size;
  v2 = 0i64;
  if ( v1 )
  {
    do
    {
      if ( v1 <= 2 )
        v3 = (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)&this->Layers.8;
      else
        v3 = this->Layers.AD.pData;
      v4 = v3[v2].pObject;
      v5 = 0i64;
      if ( v4->Entries.Data.Size )
      {
        do
        {
          v6 = v4->Entries.Data.Data[v5]->pSourceNode;
          if ( (LODWORD(v6[2].pNext) >> 5) & 1 )
            v7 = (signed __int64)&v6[1].SortParentBounds;
          else
            v7 = 0i64;
          --*(_QWORD *)(v7 + 136);
          ++v5;
        }
        while ( v5 < v4->Entries.Data.Size );
      }
      v1 = this->Layers.Size;
      ++v2;
    }
    while ( v2 < v1 );
  }
}

