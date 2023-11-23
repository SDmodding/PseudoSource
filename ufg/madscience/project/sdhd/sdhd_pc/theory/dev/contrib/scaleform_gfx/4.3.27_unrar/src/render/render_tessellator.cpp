// File Line: 86
// RVA: 0x945A00
void __fastcall Scaleform::Render::Tessellator::Tessellator(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::LinearHeap *heap1,
        Scaleform::Render::LinearHeap *heap2)
{
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::Tessellator::`vftable;
  this->pHeap1 = heap1;
  this->pHeap2 = heap2;
  *(_QWORD *)&this->FillRule = 0i64;
  *(_DWORD *)&this->HasEpsilon = 0x10000;
  this->VertexLimit = 65534;
  this->ComplexFlags.pHeap = heap2;
  this->ComplexFlags.Size = 0i64;
  this->ComplexFlags.Array = 0i64;
  this->MaxStyle = 0;
  this->Paths.pHeap = heap1;
  this->Paths.Size = 0i64;
  this->Paths.NumPages = 0i64;
  this->Paths.MaxPages = 0i64;
  this->Paths.Pages = 0i64;
  this->SrcVertices.pHeap = heap1;
  this->SrcVertices.Size = 0i64;
  this->SrcVertices.NumPages = 0i64;
  this->SrcVertices.MaxPages = 0i64;
  this->SrcVertices.Pages = 0i64;
  this->LastVertex = 0;
  this->Edges.pHeap = heap1;
  this->Edges.Size = 0i64;
  this->Edges.NumPages = 0i64;
  this->Edges.MaxPages = 0i64;
  this->Edges.Pages = 0i64;
  this->MonoChains.pHeap = heap1;
  this->MonoChains.Size = 0i64;
  this->MonoChains.NumPages = 0i64;
  this->MonoChains.MaxPages = 0i64;
  this->MonoChains.Pages = 0i64;
  this->MonoChainsSorted.pHeap = heap1;
  this->MonoChainsSorted.Size = 0i64;
  this->MonoChainsSorted.Array = 0i64;
  this->Scanbeams.pHeap = heap1;
  this->Scanbeams.Size = 0i64;
  this->Scanbeams.NumPages = 0i64;
  this->Scanbeams.MaxPages = 0i64;
  this->Scanbeams.Pages = 0i64;
  this->ActiveChains.pHeap = heap1;
  this->ActiveChains.Size = 0i64;
  this->ActiveChains.NumPages = 0i64;
  this->ActiveChains.MaxPages = 0i64;
  this->ActiveChains.Pages = 0i64;
  this->InteriorChains.pHeap = heap1;
  this->InteriorChains.Size = 0i64;
  this->InteriorChains.NumPages = 0i64;
  this->InteriorChains.MaxPages = 0i64;
  this->InteriorChains.Pages = 0i64;
  this->ValidChains.pHeap = heap1;
  this->ValidChains.Size = 0i64;
  this->ValidChains.NumPages = 0i64;
  this->ValidChains.MaxPages = 0i64;
  this->ValidChains.Pages = 0i64;
  this->InteriorOrder.pHeap = heap1;
  this->InteriorOrder.Size = 0i64;
  this->InteriorOrder.NumPages = 0i64;
  this->InteriorOrder.MaxPages = 0i64;
  this->InteriorOrder.Pages = 0i64;
  this->Intersections.pHeap = heap1;
  this->Intersections.Size = 0i64;
  this->Intersections.NumPages = 0i64;
  this->Intersections.MaxPages = 0i64;
  this->Intersections.Pages = 0i64;
  this->StyleCounts.pHeap = heap1;
  this->StyleCounts.Size = 0i64;
  this->StyleCounts.Array = 0i64;
  this->LastX = -1.0e30;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  this->ChainsBelow.pHeap = heap1;
  this->ChainsBelow.Size = 0i64;
  this->ChainsBelow.NumPages = 0i64;
  this->ChainsBelow.MaxPages = 0i64;
  this->ChainsBelow.Pages = 0i64;
  this->ChainsAbove.pHeap = heap1;
  this->ChainsAbove.Size = 0i64;
  this->ChainsAbove.NumPages = 0i64;
  this->ChainsAbove.MaxPages = 0i64;
  this->ChainsAbove.Pages = 0i64;
  this->BaseLines.pHeap = heap1;
  this->BaseLines.Size = 0i64;
  this->BaseLines.NumPages = 0i64;
  this->BaseLines.MaxPages = 0i64;
  this->BaseLines.Pages = 0i64;
  this->PendingEnds.pHeap = heap1;
  this->PendingEnds.Size = 0i64;
  this->PendingEnds.NumPages = 0i64;
  this->PendingEnds.MaxPages = 0i64;
  this->PendingEnds.Pages = 0i64;
  this->Monotones.pHeap = heap2;
  this->Monotones.Size = 0i64;
  this->Monotones.NumPages = 0i64;
  this->Monotones.MaxPages = 0i64;
  this->Monotones.Pages = 0i64;
  this->MonoVertices.pHeap = heap2;
  this->MonoVertices.Size = 0i64;
  this->MonoVertices.NumPages = 0i64;
  this->MonoVertices.MaxPages = 0i64;
  this->MonoVertices.Pages = 0i64;
  this->MeshVertices.pHeap = heap2;
  this->MeshVertices.Size = 0i64;
  this->MeshVertices.NumPages = 0i64;
  this->MeshVertices.MaxPages = 0i64;
  this->MeshVertices.Pages = 0i64;
  this->StyleMatrix.pHeap = heap2;
  this->StyleMatrix.Size = 0i64;
  this->StyleMatrix.Array = 0i64;
  this->Meshes.pHeap = heap2;
  this->Meshes.Size = 0i64;
  this->Meshes.NumPages = 0i64;
  this->Meshes.MaxPages = 0i64;
  this->Meshes.Pages = 0i64;
  this->MeshTriangles.pHeap = heap1;
  this->MeshTriangles.Arrays = 0i64;
  this->MeshTriangles.NumArrays = 0i64;
  this->MeshTriangles.MaxArrays = 0i64;
  this->MonoStyle = 0;
  this->MeshIdx = -1;
  this->FactorOneFlag = 0;
  this->EdgeAAWidth = 0.5;
  this->EdgeAAFlag = 1;
  this->IntersectionEpsilon = 0.0099999998;
  this->LeftChain.pHeap = heap1;
  this->LeftChain.Size = 0i64;
  this->LeftChain.NumPages = 0i64;
  this->LeftChain.MaxPages = 0i64;
  this->LeftChain.Pages = 0i64;
  this->RightChain.pHeap = heap1;
  this->RightChain.Size = 0i64;
  this->RightChain.NumPages = 0i64;
  this->RightChain.MaxPages = 0i64;
  this->RightChain.Pages = 0i64;
  this->TmpEdgeFan.pHeap = heap1;
  this->TmpEdgeFan.Size = 0i64;
  this->TmpEdgeFan.NumPages = 0i64;
  this->TmpEdgeFan.MaxPages = 0i64;
  this->TmpEdgeFan.Pages = 0i64;
  this->EdgeFans.pHeap = heap1;
  this->EdgeFans.Size = 0i64;
  this->EdgeFans.Array = 0i64;
  this->StartFan.pHeap = heap1;
  this->StartFan.Size = 0i64;
  this->StartFan.NumPages = 0i64;
  this->StartFan.MaxPages = 0i64;
  this->StartFan.Pages = 0i64;
  this->EndFan.pHeap = heap1;
  this->EndFan.Size = 0i64;
  this->EndFan.NumPages = 0i64;
  this->EndFan.MaxPages = 0i64;
  this->EndFan.Pages = 0i64;
  this->OuterEdges.pHeap = heap1;
  this->OuterEdges.Size = 0i64;
  this->OuterEdges.NumPages = 0i64;
  this->OuterEdges.MaxPages = 0i64;
  this->OuterEdges.Pages = 0i64;
  this->StrokerEdges.pHeap = heap1;
  this->StrokerEdges.Size = 0i64;
  this->StrokerEdges.NumPages = 0i64;
  this->StrokerEdges.MaxPages = 0i64;
  this->StrokerEdges.Pages = 0i64;
  this->MonoStack.pHeap = heap1;
  this->MonoStack.Size = 0i64;
  this->MonoStack.NumPages = 0i64;
  this->MonoStack.MaxPages = 0i64;
  this->MonoStack.Pages = 0i64;
  this->InnerQuads.pHeap = heap1;
  this->InnerQuads.Size = 0i64;
  this->InnerQuads.NumPages = 0i64;
  this->InnerQuads.MaxPages = 0i64;
  this->InnerQuads.Pages = 0i64;
  this->StarVertices.pHeap = heap1;
  this->StarVertices.Size = 0i64;
  this->StarVertices.NumPages = 0i64;
  this->StarVertices.MaxPages = 0i64;
  this->StarVertices.Pages = 0i64;
  this->FakeVar = 0;
}

// File Line: 90
// RVA: 0x95FB60
void __fastcall Scaleform::Render::Tessellator::Clear(Scaleform::Render::Tessellator *this)
{
  this->LastX = -1.0e30;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  this->LastVertex = 0;
  this->HasComplexFill = 0;
  this->MaxStyle = 0;
  this->ComplexFlags.Size = 0i64;
  this->ComplexFlags.Array = 0i64;
  this->Paths.MaxPages = 0i64;
  this->Paths.NumPages = 0i64;
  this->Paths.Size = 0i64;
  this->Paths.Pages = 0i64;
  this->SrcVertices.MaxPages = 0i64;
  this->SrcVertices.NumPages = 0i64;
  this->SrcVertices.Size = 0i64;
  this->SrcVertices.Pages = 0i64;
  this->Edges.MaxPages = 0i64;
  this->Edges.NumPages = 0i64;
  this->Edges.Size = 0i64;
  this->Edges.Pages = 0i64;
  this->MonoChains.MaxPages = 0i64;
  this->MonoChains.NumPages = 0i64;
  this->MonoChains.Size = 0i64;
  this->MonoChains.Pages = 0i64;
  this->MonoChainsSorted.Size = 0i64;
  this->MonoChainsSorted.Array = 0i64;
  this->Scanbeams.MaxPages = 0i64;
  this->Scanbeams.NumPages = 0i64;
  this->Scanbeams.Size = 0i64;
  this->Scanbeams.Pages = 0i64;
  this->ActiveChains.MaxPages = 0i64;
  this->ActiveChains.NumPages = 0i64;
  this->ActiveChains.Size = 0i64;
  this->ActiveChains.Pages = 0i64;
  this->InteriorChains.MaxPages = 0i64;
  this->InteriorChains.NumPages = 0i64;
  this->InteriorChains.Size = 0i64;
  this->InteriorChains.Pages = 0i64;
  this->ValidChains.MaxPages = 0i64;
  this->ValidChains.NumPages = 0i64;
  this->ValidChains.Size = 0i64;
  this->ValidChains.Pages = 0i64;
  this->InteriorOrder.MaxPages = 0i64;
  this->InteriorOrder.NumPages = 0i64;
  this->InteriorOrder.Size = 0i64;
  this->InteriorOrder.Pages = 0i64;
  this->Intersections.MaxPages = 0i64;
  this->Intersections.NumPages = 0i64;
  this->Intersections.Size = 0i64;
  this->Intersections.Pages = 0i64;
  this->StyleCounts.Size = 0i64;
  this->StyleCounts.Array = 0i64;
  this->ChainsBelow.MaxPages = 0i64;
  this->ChainsBelow.NumPages = 0i64;
  this->ChainsBelow.Size = 0i64;
  this->ChainsBelow.Pages = 0i64;
  this->ChainsAbove.MaxPages = 0i64;
  this->ChainsAbove.NumPages = 0i64;
  this->ChainsAbove.Size = 0i64;
  this->ChainsAbove.Pages = 0i64;
  this->BaseLines.MaxPages = 0i64;
  this->BaseLines.NumPages = 0i64;
  this->BaseLines.Size = 0i64;
  this->BaseLines.Pages = 0i64;
  this->PendingEnds.MaxPages = 0i64;
  this->PendingEnds.NumPages = 0i64;
  this->PendingEnds.Size = 0i64;
  this->PendingEnds.Pages = 0i64;
  this->Monotones.MaxPages = 0i64;
  this->Monotones.NumPages = 0i64;
  this->Monotones.Size = 0i64;
  this->Monotones.Pages = 0i64;
  this->MonoVertices.MaxPages = 0i64;
  this->MonoVertices.NumPages = 0i64;
  this->MonoVertices.Size = 0i64;
  this->MonoVertices.Pages = 0i64;
  this->MeshVertices.MaxPages = 0i64;
  this->MeshVertices.NumPages = 0i64;
  this->MeshVertices.Size = 0i64;
  this->MeshVertices.Pages = 0i64;
  this->StyleMatrix.Size = 0i64;
  this->StyleMatrix.Array = 0i64;
  this->Meshes.MaxPages = 0i64;
  this->Meshes.NumPages = 0i64;
  this->Meshes.Size = 0i64;
  this->Meshes.Pages = 0i64;
  this->MeshTriangles.Arrays = 0i64;
  this->MeshTriangles.MaxArrays = 0i64;
  this->MeshTriangles.NumArrays = 0i64;
  this->LeftChain.MaxPages = 0i64;
  this->LeftChain.NumPages = 0i64;
  this->LeftChain.Size = 0i64;
  this->LeftChain.Pages = 0i64;
  this->RightChain.MaxPages = 0i64;
  this->RightChain.NumPages = 0i64;
  this->RightChain.Size = 0i64;
  this->RightChain.Pages = 0i64;
  this->TmpEdgeFan.MaxPages = 0i64;
  this->TmpEdgeFan.NumPages = 0i64;
  this->TmpEdgeFan.Size = 0i64;
  this->TmpEdgeFan.Pages = 0i64;
  this->EdgeFans.Size = 0i64;
  this->EdgeFans.Array = 0i64;
  this->StartFan.MaxPages = 0i64;
  this->StartFan.NumPages = 0i64;
  this->StartFan.Size = 0i64;
  this->StartFan.Pages = 0i64;
  this->EndFan.MaxPages = 0i64;
  this->EndFan.NumPages = 0i64;
  this->EndFan.Size = 0i64;
  this->EndFan.Pages = 0i64;
  this->OuterEdges.MaxPages = 0i64;
  this->OuterEdges.NumPages = 0i64;
  this->OuterEdges.Size = 0i64;
  this->OuterEdges.Pages = 0i64;
  this->StrokerEdges.MaxPages = 0i64;
  this->StrokerEdges.NumPages = 0i64;
  this->StrokerEdges.Size = 0i64;
  this->StrokerEdges.Pages = 0i64;
  this->MonoStack.MaxPages = 0i64;
  this->MonoStack.NumPages = 0i64;
  this->MonoStack.Size = 0i64;
  this->MonoStack.Pages = 0i64;
  this->InnerQuads.MaxPages = 0i64;
  this->InnerQuads.NumPages = 0i64;
  this->InnerQuads.Size = 0i64;
  this->InnerQuads.Pages = 0i64;
  this->StarVertices.MaxPages = 0i64;
  this->StarVertices.NumPages = 0i64;
  this->StarVertices.Size = 0i64;
  this->StarVertices.Pages = 0i64;
  Scaleform::Render::LinearHeap::ClearAndRelease(this->pHeap1);
  Scaleform::Render::LinearHeap::ClearAndRelease(this->pHeap2);
}

// File Line: 147
// RVA: 0x9D5BD0
void __fastcall Scaleform::Render::Tessellator::clearHeap1(Scaleform::Render::Tessellator *this)
{
  unsigned __int64 v1; // rax
  Scaleform::Render::LinearHeap *pHeap1; // r9
  __int64 v3; // r8

  v1 = 0i64;
  this->Paths.MaxPages = 0i64;
  this->Paths.NumPages = 0i64;
  this->Paths.Size = 0i64;
  this->Paths.Pages = 0i64;
  this->SrcVertices.MaxPages = 0i64;
  this->SrcVertices.NumPages = 0i64;
  this->SrcVertices.Size = 0i64;
  this->SrcVertices.Pages = 0i64;
  this->Edges.MaxPages = 0i64;
  this->Edges.NumPages = 0i64;
  this->Edges.Size = 0i64;
  this->Edges.Pages = 0i64;
  this->MonoChains.MaxPages = 0i64;
  this->MonoChains.NumPages = 0i64;
  this->MonoChains.Size = 0i64;
  this->MonoChains.Pages = 0i64;
  this->MonoChainsSorted.Size = 0i64;
  this->MonoChainsSorted.Array = 0i64;
  this->Scanbeams.MaxPages = 0i64;
  this->Scanbeams.NumPages = 0i64;
  this->Scanbeams.Size = 0i64;
  this->Scanbeams.Pages = 0i64;
  this->ActiveChains.MaxPages = 0i64;
  this->ActiveChains.NumPages = 0i64;
  this->ActiveChains.Size = 0i64;
  this->ActiveChains.Pages = 0i64;
  this->InteriorChains.MaxPages = 0i64;
  this->InteriorChains.NumPages = 0i64;
  this->InteriorChains.Size = 0i64;
  this->InteriorChains.Pages = 0i64;
  this->ValidChains.MaxPages = 0i64;
  this->ValidChains.NumPages = 0i64;
  this->ValidChains.Size = 0i64;
  this->ValidChains.Pages = 0i64;
  this->InteriorOrder.MaxPages = 0i64;
  this->InteriorOrder.NumPages = 0i64;
  this->InteriorOrder.Size = 0i64;
  this->InteriorOrder.Pages = 0i64;
  this->Intersections.MaxPages = 0i64;
  this->Intersections.NumPages = 0i64;
  this->Intersections.Size = 0i64;
  this->Intersections.Pages = 0i64;
  this->StyleCounts.Size = 0i64;
  this->StyleCounts.Array = 0i64;
  this->ChainsBelow.MaxPages = 0i64;
  this->ChainsBelow.NumPages = 0i64;
  this->ChainsBelow.Size = 0i64;
  this->ChainsBelow.Pages = 0i64;
  this->ChainsAbove.MaxPages = 0i64;
  this->ChainsAbove.NumPages = 0i64;
  this->ChainsAbove.Size = 0i64;
  this->ChainsAbove.Pages = 0i64;
  this->BaseLines.MaxPages = 0i64;
  this->BaseLines.NumPages = 0i64;
  this->BaseLines.Size = 0i64;
  this->BaseLines.Pages = 0i64;
  this->PendingEnds.MaxPages = 0i64;
  this->PendingEnds.NumPages = 0i64;
  this->PendingEnds.Size = 0i64;
  this->PendingEnds.Pages = 0i64;
  this->MeshTriangles.Arrays = 0i64;
  this->MeshTriangles.MaxArrays = 0i64;
  this->MeshTriangles.NumArrays = 0i64;
  this->LeftChain.MaxPages = 0i64;
  this->LeftChain.NumPages = 0i64;
  this->LeftChain.Size = 0i64;
  this->LeftChain.Pages = 0i64;
  this->RightChain.MaxPages = 0i64;
  this->RightChain.NumPages = 0i64;
  this->RightChain.Size = 0i64;
  this->RightChain.Pages = 0i64;
  this->EdgeFans.Size = 0i64;
  this->EdgeFans.Array = 0i64;
  this->StartFan.MaxPages = 0i64;
  this->StartFan.NumPages = 0i64;
  this->StartFan.Size = 0i64;
  this->StartFan.Pages = 0i64;
  this->TmpEdgeFan.MaxPages = 0i64;
  this->TmpEdgeFan.NumPages = 0i64;
  this->TmpEdgeFan.Size = 0i64;
  this->TmpEdgeFan.Pages = 0i64;
  this->EndFan.MaxPages = 0i64;
  this->EndFan.NumPages = 0i64;
  this->EndFan.Size = 0i64;
  this->EndFan.Pages = 0i64;
  this->OuterEdges.MaxPages = 0i64;
  this->OuterEdges.NumPages = 0i64;
  this->OuterEdges.Size = 0i64;
  this->OuterEdges.Pages = 0i64;
  this->StrokerEdges.MaxPages = 0i64;
  this->StrokerEdges.NumPages = 0i64;
  this->StrokerEdges.Size = 0i64;
  this->StrokerEdges.Pages = 0i64;
  this->MonoStack.MaxPages = 0i64;
  this->MonoStack.NumPages = 0i64;
  this->MonoStack.Size = 0i64;
  this->MonoStack.Pages = 0i64;
  this->InnerQuads.MaxPages = 0i64;
  this->InnerQuads.NumPages = 0i64;
  this->InnerQuads.Size = 0i64;
  this->InnerQuads.Pages = 0i64;
  this->StarVertices.MaxPages = 0i64;
  this->StarVertices.NumPages = 0i64;
  this->StarVertices.Size = 0i64;
  this->StarVertices.Pages = 0i64;
  pHeap1 = this->pHeap1;
  if ( pHeap1->MaxPages )
  {
    v3 = 0i64;
    do
    {
      ++v1;
      ++v3;
      pHeap1->pPagePool[v3 - 1].pFree = pHeap1->pPagePool[v3 - 1].pStart;
    }
    while ( v1 < pHeap1->MaxPages );
  }
  pHeap1->pLastPage = pHeap1->pPagePool;
}ap

// File Line: 247
// RVA: 0x9D6230
bool __fastcall Scaleform::Render::Tessellator::cmpEdgeAA(
        Scaleform::Render::Tessellator::TmpEdgeAAType *a,
        Scaleform::Render::Tessellator::TmpEdgeAAType *b)
{
  float slope; // xmm0_4
  float v3; // xmm1_4

  slope = a->slope;
  v3 = b->slope;
  if ( slope == v3 )
    return a->style < b->style;
  else
    return v3 > slope;
}

// File Line: 255
// RVA: 0x9D62C0
bool __fastcall Scaleform::Render::Tessellator::cmpOuterEdges(
        Scaleform::Render::Tessellator::OuterEdgeType *a,
        Scaleform::Render::Tessellator::OuterEdgeType *b)
{
  Scaleform::Render::Tessellator::EdgeAAType *edge; // r8
  Scaleform::Render::Tessellator::EdgeAAType *v3; // r9
  Scaleform::Render::Tessellator::MonoVertexType *cntVer; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v5; // rdx
  bool v6; // cf

  edge = a->edge;
  v3 = b->edge;
  cntVer = a->edge->cntVer;
  v5 = b->edge->cntVer;
  v6 = cntVer < v5;
  if ( cntVer == v5 )
    return edge->rayVer < v3->rayVer;
  return v6;
}

// File Line: 263
// RVA: 0x9D6320
_BOOL8 __fastcall Scaleform::Render::Tessellator::cmpStrokerEdges(
        Scaleform::Render::Tessellator::StrokerEdgeType *a,
        Scaleform::Render::Tessellator::StrokerEdgeType *b)
{
  unsigned int v2; // r8d
  unsigned int v3; // r9d

  v2 = a->node1 & 0xFFFFFFF;
  v3 = b->node1 & 0xFFFFFFF;
  if ( v2 == v3 )
    return (a->node2 & 0xFFFFFFF) < (b->node2 & 0xFFFFFFF);
  else
    return v2 < v3;
}

// File Line: 309
// RVA: 0x9CF930
void __fastcall Scaleform::Render::Tessellator::buildEdgeList(
        Scaleform::Render::Tessellator *this,
        unsigned int start,
        unsigned int numEdges,
        int step,
        unsigned int leftStyle,
        unsigned int rightStyle)
{
  __int16 v6; // di
  __int16 v7; // si
  unsigned __int64 Size_low; // r13
  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *p_Edges; // rbx
  __int64 v13; // rsi
  Scaleform::Render::Tessellator::SrcVertexType **Pages; // rcx
  char v15; // r8
  Scaleform::Render::Tessellator::SrcVertexType *v16; // rdx
  unsigned __int64 v17; // rdi
  Scaleform::Render::Tessellator::SrcVertexType *v18; // rcx
  Scaleform::Render::Tessellator::EdgeType **v19; // rax
  __int64 v20; // r10
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType,4,16> *p_MonoChains; // r15
  Scaleform::Render::Tessellator::EdgeType *v22; // r9
  float slope; // xmm8_4
  unsigned __int64 v24; // rbx
  unsigned __int64 lower; // rcx
  __int64 v26; // r8
  __int64 v27; // rdx
  float v28; // xmm6_4
  float v29; // xmm7_4
  Scaleform::Render::Tessellator::MonoChainType *v30; // rcx
  __int64 v31; // rdx
  __int64 v32; // [rsp+8h] [rbp-39h]
  int v33; // [rsp+1Ch] [rbp-25h]
  int v34; // [rsp+20h] [rbp-21h]
  Scaleform::Render::VertexBasic v35; // [rsp+98h] [rbp+57h]
  __int16 v36; // [rsp+B8h] [rbp+77h]
  __int16 v37; // [rsp+C0h] [rbp+7Fh]

  Size_low = LODWORD(this->Edges.Size);
  if ( numEdges )
  {
    v36 = v7;
    p_Edges = (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->Edges;
    v37 = v6;
    v13 = numEdges;
    do
    {
      Pages = this->SrcVertices.Pages;
      v15 = start;
      LODWORD(v35.x) = start;
      v16 = Pages[(unsigned __int64)start >> 4];
      start += step;
      v17 = p_Edges->Size >> 4;
      v18 = Pages[(unsigned __int64)start >> 4];
      v35.y = (float)(v18[start & 0xF].x - v16[v15 & 0xF].x) / (float)(v18[start & 0xF].y - v16[v15 & 0xF].y);
      if ( v17 >= p_Edges->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(p_Edges, v17);
      p_Edges->Pages[v17][p_Edges->Size & 0xF] = v35;
      ++p_Edges->Size;
      --v13;
    }
    while ( v13 );
  }
  v19 = this->Edges.Pages;
  v20 = Size_low & 0xF;
  p_MonoChains = &this->MonoChains;
  LODWORD(v32) = Size_low;
  v22 = v19[Size_low >> 4];
  slope = v22[v20].slope;
  v24 = p_MonoChains->Size >> 4;
  lower = v22[v20].lower;
  v26 = lower & 0xF;
  v33 = (unsigned __int16)step;
  v27 = *(_QWORD *)(p_MonoChains[-2].MaxPages + 8 * (lower >> 4));
  HIDWORD(v32) = LODWORD(p_MonoChains[-1].Size) - 1;
  v28 = *(float *)(v27 + 8 * v26 + 4);
  v29 = *(float *)(v27 + 8 * v26);
  LOWORD(v34) = v36;
  HIWORD(v34) = v37;
  if ( v24 >= p_MonoChains->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType,4,16>::allocPage(p_MonoChains, v24);
  v30 = p_MonoChains->Pages[v24];
  v31 = p_MonoChains->Size & 0xF;
  *(_QWORD *)&v30[v31].edge = v32;
  v30[v31].ySort = v28;
  v30[v31].xb = v29;
  v30[v31].xt = slope;
  *(_DWORD *)&v30[v31].dir = v33;
  *(_DWORD *)&v30[v31].leftStyle = v34;
  *(_DWORD *)&v30[v31].leftBelow = 0;
  *(_DWORD *)&v30[v31].rightBelow = 0;
  v30[v31].posIntr = -1;
  v30[v31].posScan = 0;
  ++p_MonoChains->Size;
}

// File Line: 344
// RVA: 0x9CA0B0
void __fastcall Scaleform::Render::Tessellator::addStyle(
        Scaleform::Render::Tessellator *this,
        unsigned int style,
        bool complex)
{
  unsigned __int64 v3; // r15
  unsigned __int64 Size; // rsi
  unsigned __int64 v7; // rsi
  void *v8; // rbp
  unsigned int *Array; // rdx
  unsigned __int64 v10; // r8

  if ( style )
  {
    v3 = style;
    if ( 32 * this->ComplexFlags.Size <= style )
    {
      do
      {
        Size = this->ComplexFlags.Size;
        if ( Size )
          v7 = 2 * Size;
        else
          v7 = 8i64;
        if ( v7 > this->ComplexFlags.Size )
        {
          v8 = Scaleform::Render::LinearHeap::Alloc(this->ComplexFlags.pHeap, 4 * v7);
          memset(v8, 0, 4 * v7);
          Array = this->ComplexFlags.Array;
          if ( Array )
          {
            v10 = this->ComplexFlags.Size;
            if ( v10 )
              memmove(v8, Array, 4 * v10);
          }
          this->ComplexFlags.Array = (unsigned int *)v8;
        }
        this->ComplexFlags.Size = v7;
      }
      while ( 32 * v7 <= v3 );
    }
    if ( complex )
    {
      this->ComplexFlags.Array[(unsigned __int64)(unsigned int)v3 >> 5] |= 1 << (v3 & 0x1F);
      this->HasComplexFill = 1;
    }
    if ( this->MaxStyle < (unsigned int)v3 )
      this->MaxStyle = v3;
  }
}

// File Line: 367
// RVA: 0x961650
void __fastcall Scaleform::Render::Tessellator::ClosePath(Scaleform::Render::Tessellator *this)
{
  unsigned int LastVertex; // r8d
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::SrcVertexType,4,16> *p_SrcVertices; // rbx
  unsigned __int64 Size; // rsi
  Scaleform::Render::Tessellator::SrcVertexType **Pages; // r10
  unsigned __int64 v5; // rsi
  __int64 v6; // rdi
  Scaleform::Render::Tessellator::SrcVertexType *v7; // r14

  LastVertex = this->LastVertex;
  if ( this->SrcVertices.Size > LastVertex + 2 )
  {
    p_SrcVertices = &this->SrcVertices;
    Size = this->SrcVertices.Size;
    Pages = this->SrcVertices.Pages;
    if ( Pages[(Size - 1) >> 4][((_BYTE)Size - 1) & 0xF].x != Pages[(unsigned __int64)LastVertex >> 4][LastVertex & 0xF].x
      || Pages[(Size - 1) >> 4][((_BYTE)Size - 1) & 0xF].y != Pages[(unsigned __int64)LastVertex >> 4][LastVertex & 0xF].y )
    {
      v5 = Size >> 4;
      v6 = LastVertex & 0xF;
      v7 = Pages[(unsigned __int64)LastVertex >> 4];
      if ( v5 >= this->SrcVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)p_SrcVertices,
          v5);
      p_SrcVertices->Pages[v5][p_SrcVertices->Size & 0xF] = v7[v6];
      ++p_SrcVertices->Size;
    }
  }
}

// File Line: 381
// RVA: 0x979250
void __fastcall Scaleform::Render::Tessellator::FinalizePath(
        Scaleform::Render::Tessellator *this,
        unsigned int leftStyle,
        unsigned int rightStyle,
        bool leftComplex,
        bool rightComplex)
{
  unsigned __int64 LastVertex; // rdx
  unsigned int v7; // esi
  bool v9; // bp
  unsigned int v10; // r12d
  unsigned __int64 v11; // r14
  int v12; // r15d
  Scaleform::Render::Tessellator::PathType *v13; // rax
  __int64 v14; // rcx

  LastVertex = this->LastVertex;
  v7 = rightStyle;
  if ( this->SrcVertices.Size < (unsigned int)(LastVertex + 2) || leftStyle == rightStyle )
  {
    if ( LastVertex < this->SrcVertices.Size )
      this->SrcVertices.Size = LastVertex;
  }
  else
  {
    if ( this->StrokerMode )
    {
      if ( (leftStyle == 0) == (rightStyle == 0) )
      {
        if ( LastVertex < this->SrcVertices.Size )
          this->SrcVertices.Size = LastVertex;
        return;
      }
      leftStyle = leftStyle != 0;
      v7 = rightStyle != 0;
      v9 = 0;
      leftComplex = 0;
    }
    else
    {
      v9 = rightComplex;
    }
    Scaleform::Render::Tessellator::addStyle(this, leftStyle, leftComplex);
    Scaleform::Render::Tessellator::addStyle(this, v7, v9);
    v10 = this->LastVertex;
    v11 = this->Paths.Size >> 4;
    v12 = LODWORD(this->SrcVertices.Size) - 1;
    if ( v11 >= this->Paths.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4> *)&this->Paths,
        this->Paths.Size >> 4);
    v13 = this->Paths.Pages[v11];
    v14 = this->Paths.Size & 0xF;
    v13[v14].start = v10;
    v13[v14].end = v12;
    v13[v14].leftStyle = leftStyle;
    v13[v14].rightStyle = v7;
    ++this->Paths.Size;
    this->LastVertex = this->SrcVertices.Size;
  }
}

// File Line: 435
// RVA: 0x9DF530
void __fastcall Scaleform::Render::Tessellator::decomposePath(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::PathType *path)
{
  signed int start; // edi
  signed int end; // esi
  Scaleform::Render::Tessellator::SrcVertexType **Pages; // r11
  float y; // xmm0_4
  signed int v8; // r9d
  unsigned int v9; // ebx
  int i; // r10d
  signed int v11; // edi
  signed int v12; // r11d
  Scaleform::Render::Tessellator::SrcVertexType **v13; // rsi
  signed int v14; // r9d
  float v15; // xmm0_4
  __int64 v16; // rcx
  Scaleform::Render::Tessellator::SrcVertexType *v17; // rax
  unsigned int v18; // ebx
  int j; // r10d

  start = path->start;
  end = path->end;
  if ( (signed int)path->start < end )
  {
    do
    {
      Pages = this->SrcVertices.Pages;
      y = Pages[(unsigned __int64)start >> 4][start & 0xF].y;
      if ( start > (signed int)path->start )
      {
        if ( y <= Pages[(unsigned __int64)(start - 1) >> 4][(start - 1) & 0xF].y )
        {
          v8 = start + 1;
          if ( y < Pages[(unsigned __int64)(start + 1) >> 4][(start + 1) & 0xF].y )
          {
LABEL_7:
            v9 = 1;
            for ( i = v8 + 1;
                  v8 < end && Pages[(unsigned __int64)i >> 4][i & 0xF].y > Pages[(unsigned __int64)v8 >> 4][v8 & 0xF].y;
                  ++i )
            {
              ++v9;
              ++v8;
            }
            Scaleform::Render::Tessellator::buildEdgeList(this, start, v9, 1, path->leftStyle, path->rightStyle);
            start = v9 + start - 1;
          }
        }
      }
      else
      {
        v8 = start + 1;
        if ( y < Pages[(unsigned __int64)(start + 1) >> 4][(start + 1) & 0xF].y )
          goto LABEL_7;
      }
      end = path->end;
      ++start;
    }
    while ( start < end );
  }
  v11 = path->end;
  v12 = path->start;
  while ( v11 > (signed int)path->start )
  {
    v13 = this->SrcVertices.Pages;
    v14 = v11 - 1;
    v15 = v13[(unsigned __int64)v11 >> 4][v11 & 0xF].y;
    v16 = (v11 - 1) & 0xF;
    v17 = v13[(unsigned __int64)(v11 - 1) >> 4];
    if ( v11 < (signed int)path->end )
    {
      if ( v15 < v17[v16].y && v15 <= v13[(unsigned __int64)(v11 + 1) >> 4][(v11 + 1) & 0xF].y )
      {
LABEL_19:
        v18 = 1;
        for ( j = v11 - 2;
              v14 > v12 && v13[(unsigned __int64)j >> 4][j & 0xF].y > v13[(unsigned __int64)v14 >> 4][v14 & 0xF].y;
              --j )
        {
          ++v18;
          --v14;
        }
        Scaleform::Render::Tessellator::buildEdgeList(this, v11, v18, -1, path->leftStyle, path->rightStyle);
        v11 += 1 - v18;
      }
    }
    else if ( v15 < v17[v16].y )
    {
      goto LABEL_19;
    }
    v12 = path->start;
    --v11;
  }
}

// File Line: 512
// RVA: 0x9EBD70
void __fastcall Scaleform::Render::Tessellator::perceiveStyles(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8> *aet)
{
  unsigned __int16 v4; // r11
  unsigned __int64 i; // r9
  Scaleform::Render::Tessellator::MonoChainType *v6; // r8
  __int64 rightStyle; // r10
  __int64 leftStyle; // rcx
  int *Array; // rax
  unsigned __int64 Size; // rax
  int *v11; // rdx
  unsigned __int16 v12; // ax

  memset(this->StyleCounts.Array, 0, 4 * this->StyleCounts.Size);
  v4 = 0;
  for ( i = 0i64; i < aet->Size; ++i )
  {
    v6 = aet->Pages[i >> 4][i & 0xF];
    v6->flags &= ~4u;
    if ( (v6->flags & 2) == 0 )
    {
      rightStyle = v6->rightStyle;
      leftStyle = v6->leftStyle;
      Array = this->StyleCounts.Array;
      if ( this->FillRule )
      {
        Array[leftStyle] ^= 1u;
        this->StyleCounts.Array[rightStyle] ^= 1u;
      }
      else
      {
        Array[leftStyle] += v6->dir;
        this->StyleCounts.Array[rightStyle] -= v6->dir;
      }
      Size = this->StyleCounts.Size;
      if ( Size )
      {
        v11 = &this->StyleCounts.Array[Size - 1];
        while ( !*v11 )
        {
          --v11;
          if ( !--Size )
            goto LABEL_10;
        }
        v12 = Size - 1;
      }
      else
      {
LABEL_10:
        v12 = 0;
      }
      v6->rightAbove = v12;
      v6->leftAbove = v4;
      if ( v4 != v12 )
        v6->flags |= 4u;
      v4 = v12;
    }
  }
}

// File Line: 535
// RVA: 0x9F2270
void __fastcall Scaleform::Render::Tessellator::setupIntersections(Scaleform::Render::Tessellator *this)
{
  unsigned __int64 v1; // rdi
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *p_InteriorChains; // rbp
  Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *p_InteriorOrder; // rbx
  unsigned __int64 v5; // r8
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rsi
  Scaleform::Render::Tessellator::MonoChainType **v8; // r15
  unsigned __int64 v9; // rsi

  v1 = 0i64;
  this->InteriorChains.Size = 0i64;
  this->InteriorOrder.Size = 0i64;
  if ( this->ActiveChains.Size )
  {
    p_InteriorChains = (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *)&this->InteriorChains;
    p_InteriorOrder = (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->InteriorOrder;
    do
    {
      v5 = v1 >> 4;
      v6 = v1 & 0xF;
      this->ActiveChains.Pages[v5][v6]->posIntr = v1;
      v7 = p_InteriorChains->Size >> 4;
      v8 = &this->ActiveChains.Pages[v5][v6];
      if ( v7 >= p_InteriorChains->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8>::allocPage(
          p_InteriorChains,
          p_InteriorChains->Size >> 4);
      p_InteriorChains->Pages[v7][p_InteriorChains->Size & 0xF] = (Scaleform::Render::Tessellator::MonoVertexType *)*v8;
      ++p_InteriorChains->Size;
      v9 = p_InteriorOrder->Size >> 4;
      if ( v9 >= p_InteriorOrder->NumPages )
        Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(p_InteriorOrder, p_InteriorOrder->Size >> 4);
      p_InteriorOrder->Pages[v9][p_InteriorOrder->Size & 0xF] = (Scaleform::Render::GlyphFitter::VertexType)v1;
      ++p_InteriorOrder->Size;
      ++v1;
    }
    while ( v1 < this->ActiveChains.Size );
  }
}

// File Line: 556
// RVA: 0x9EAE70
__int64 __fastcall Scaleform::Render::Tessellator::nextScanbeam(
        Scaleform::Render::Tessellator *this,
        float yb,
        float yt,
        unsigned int startMc,
        unsigned int numMc)
{
  float y; // xmm7_4
  unsigned int v6; // r13d
  unsigned int v8; // ebp
  __int64 v9; // r12
  unsigned __int64 v10; // r14
  Scaleform::Render::Tessellator::MonoChainType *v11; // rbx
  unsigned int edge; // r10d
  int dir; // r15d
  Scaleform::Render::Tessellator::SrcVertexType **Pages; // rsi
  __int64 v15; // r9
  Scaleform::Render::Tessellator::EdgeType *v16; // r11
  unsigned __int64 v17; // rax
  __int64 v18; // r9
  Scaleform::Render::Tessellator::EdgeType *v19; // r10
  Scaleform::Render::Tessellator::SrcVertexType **v20; // rcx
  unsigned int lower; // edx
  Scaleform::Render::Tessellator::SrcVertexType *v22; // r11
  __int64 v23; // r8
  float x; // xmm0_4
  __int64 v25; // r8
  Scaleform::Render::Tessellator::SrcVertexType *v26; // rdx
  unsigned __int64 v27; // rbp
  unsigned int *v28; // rax
  float xt; // eax
  __int64 v30; // rdx
  Scaleform::Render::Tessellator::SrcVertexType *v31; // rcx
  float v32; // xmm0_4
  __int64 v33; // r8
  Scaleform::Render::Tessellator::SrcVertexType *v34; // rdx
  unsigned __int64 v35; // rsi
  __int64 v36; // r14
  __int64 v37; // rbp
  Scaleform::Render::Tessellator::MonoChainType *v38; // r10
  unsigned __int64 v39; // rcx
  __int64 v40; // r9
  Scaleform::Render::Tessellator::EdgeType *v41; // r11
  Scaleform::Render::Tessellator::SrcVertexType **v42; // rcx
  unsigned int v43; // edx
  Scaleform::Render::Tessellator::SrcVertexType *v44; // rsi
  __int64 v45; // r8
  float v46; // xmm0_4
  __int64 v47; // r8
  Scaleform::Render::Tessellator::SrcVertexType *v48; // rdx
  unsigned __int64 v49; // rsi
  unsigned __int64 Size; // r10
  __int64 v51; // rbx
  unsigned __int64 v52; // r11
  int v53; // r12d
  unsigned __int64 v54; // rsi
  Scaleform::Render::Tessellator::MonoChainType ***v55; // r9
  Scaleform::Render::Tessellator::MonoChainType *v56; // rdx
  float xb; // xmm1_4
  Scaleform::Render::Tessellator::MonoChainType *v58; // r8
  float v59; // xmm0_4
  bool v60; // al
  Scaleform::Render::Tessellator::MonoChainType **v61; // rcx
  Scaleform::Render::Tessellator::MonoChainType *v62; // rax
  unsigned int v63; // r15d
  unsigned __int64 v64; // r14
  unsigned __int64 i; // rsi
  unsigned __int64 v66; // rbp
  __int64 v67; // r13
  unsigned __int64 v68; // r9
  unsigned int **v69; // rdx
  Scaleform::Render::Tessellator::MonoChainType ***v70; // r8
  __int64 v71; // r14
  unsigned __int64 v72; // r12
  unsigned __int64 v73; // r15
  unsigned __int64 v74; // rax
  Scaleform::Render::Tessellator::MonoChainType *v75; // rbx
  unsigned __int64 v76; // rax
  Scaleform::Render::Tessellator::MonoChainType *v77; // rsi
  float v78; // xmm1_4
  float v79; // xmm6_4
  float v80; // xmm0_4
  float v81; // xmm6_4
  unsigned __int64 v82; // rsi
  unsigned __int64 MaxPages; // rdx
  Scaleform::Render::LinearHeap *pHeap; // rcx
  void *v85; // rbx
  unsigned __int64 v86; // rax
  __int64 v87; // rdx
  Scaleform::Render::Tessellator::IntersectionType *v88; // rax
  unsigned int **v89; // rcx
  Scaleform::Render::Tessellator::MonoChainType ***v90; // rdx
  unsigned __int64 v91; // rax
  __int64 v92; // r10
  Scaleform::Render::Tessellator::MonoChainType **v93; // r8
  unsigned __int64 v94; // rax
  __int64 v95; // r9
  Scaleform::Render::Tessellator::MonoChainType **v96; // rdx
  Scaleform::Render::Tessellator::MonoChainType *v97; // rcx
  unsigned __int64 v98; // rdx
  unsigned __int64 v99; // r8
  Scaleform::Render::Tessellator::IntersectionType *v100; // rcx
  __int64 v102; // [rsp+20h] [rbp-A8h]
  unsigned int posIntr; // [rsp+30h] [rbp-98h]
  unsigned int v104; // [rsp+34h] [rbp-94h]
  __int64 v105; // [rsp+D0h] [rbp+8h]
  unsigned int v106; // [rsp+D8h] [rbp+10h]

  y = yb;
  v6 = numMc;
  v8 = numMc != 0;
  v9 = startMc;
  this->ValidChains.Size = 0i64;
  v106 = v8;
  v10 = 0i64;
  if ( this->ActiveChains.Size )
  {
    do
    {
      v11 = this->ActiveChains.Pages[v10 >> 4][v10 & 0xF];
      v11->flags &= ~8u;
      edge = v11->edge;
      dir = v11->dir;
      Pages = this->SrcVertices.Pages;
      v15 = v11->edge & 0xF;
      v16 = this->Edges.Pages[(unsigned __int64)v11->edge >> 4];
      v17 = dir + v16[v15].lower;
      if ( yb == Pages[v17 >> 4][v17 & 0xF].y )
      {
        if ( edge >= v11->end )
        {
          xt = v11->xt;
          v8 |= 2u;
          v11->flags |= 2u;
          v11->flags |= 8u;
          v11->xb = xt;
          v106 = v8;
        }
        else
        {
          v11->edge = edge + 1;
          v18 = ((_BYTE)edge + 1) & 0xF;
          v19 = this->Edges.Pages[(unsigned __int64)(edge + 1) >> 4];
          v20 = this->SrcVertices.Pages;
          lower = v19[v18].lower;
          v22 = v20[(unsigned __int64)(lower + dir) >> 4];
          v23 = ((_BYTE)lower + (_BYTE)dir) & 0xF;
          v11->xb = v20[(unsigned __int64)lower >> 4][lower & 0xF].x;
          if ( yt == v22[v23].y )
          {
            x = v22[v23].x;
          }
          else
          {
            v25 = v19[v18].lower & 0xF;
            v26 = this->SrcVertices.Pages[(unsigned __int64)v19[v18].lower >> 4];
            x = (float)((float)(yt - v26[v25].y) * v19[v18].slope) + v26[v25].x;
          }
          v11->xt = x;
          v27 = this->ValidChains.Size >> 4;
          if ( v27 >= this->ValidChains.NumPages )
            Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->ValidChains,
              this->ValidChains.Size >> 4);
          v28 = this->ValidChains.Pages[v27];
          v8 = v106;
          v28[this->ValidChains.Size & 0xF] = v10;
          ++this->ValidChains.Size;
          v11->flags |= 8u;
        }
      }
      else
      {
        v30 = ((_BYTE)dir + LOBYTE(v16[v15].lower)) & 0xF;
        v31 = Pages[(unsigned __int64)(unsigned int)v17 >> 4];
        v11->xb = v11->xt;
        if ( yt == v31[v30].y )
        {
          v32 = v31[v30].x;
        }
        else
        {
          v33 = v16[v15].lower & 0xF;
          v34 = this->SrcVertices.Pages[(unsigned __int64)v16[v15].lower >> 4];
          v32 = (float)((float)(yt - v34[v33].y) * v16[v15].slope) + v34[v33].x;
        }
        v11->xt = v32;
        v35 = this->ValidChains.Size >> 4;
        if ( v35 >= this->ValidChains.NumPages )
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->ValidChains,
            this->ValidChains.Size >> 4);
        this->ValidChains.Pages[v35][this->ValidChains.Size & 0xF] = v10;
        ++this->ValidChains.Size;
      }
      ++v10;
    }
    while ( v10 < this->ActiveChains.Size );
    v6 = numMc;
  }
  if ( v6 )
  {
    v36 = v9;
    v37 = v6;
    do
    {
      v38 = this->MonoChainsSorted.Array[v36];
      v39 = v38->edge;
      v40 = v39 & 0xF;
      v41 = this->Edges.Pages[v39 >> 4];
      v42 = this->SrcVertices.Pages;
      v43 = v41[v40].lower;
      v44 = v42[(unsigned __int64)(v43 + v38->dir) >> 4];
      v45 = ((_BYTE)v43 + (unsigned __int8)v38->dir) & 0xF;
      *(float *)&v42 = v42[(unsigned __int64)v43 >> 4][v43 & 0xF].x;
      v38->flags = 8;
      LODWORD(v38->xb) = (_DWORD)v42;
      if ( yt == v44[v45].y )
      {
        v46 = v44[v45].x;
      }
      else
      {
        v47 = v41[v40].lower & 0xF;
        v48 = this->SrcVertices.Pages[(unsigned __int64)v41[v40].lower >> 4];
        v46 = (float)((float)(yt - v48[v47].y) * v41[v40].slope) + v48[v47].x;
      }
      v38->xt = v46;
      v49 = this->ActiveChains.Size >> 4;
      if ( v49 >= this->ActiveChains.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *)&this->ActiveChains,
          this->ActiveChains.Size >> 4);
      ++v36;
      this->ActiveChains.Pages[v49][this->ActiveChains.Size & 0xF] = 0i64;
      ++this->ActiveChains.Size;
      --v37;
    }
    while ( v37 );
    Size = this->ActiveChains.Size;
    LODWORD(v51) = v9 + numMc;
    v52 = Size - v6;
    v53 = -(int)v9;
    v54 = v52 - 1;
    do
    {
      if ( !v52
        || ((v55 = this->ActiveChains.Pages,
             v56 = this->MonoChainsSorted.Array[(unsigned int)(v51 - 1)],
             xb = v56->xb,
             v58 = v55[v54 >> 4][v54 & 0xF],
             v59 = v58->xb,
             v59 == xb)
          ? (v60 = v58->xt < v56->xt)
          : (v60 = xb > v59),
            v60) )
      {
        --Size;
        v51 = (unsigned int)(v51 - 1);
        v61 = this->ActiveChains.Pages[Size >> 4];
        v62 = this->MonoChainsSorted.Array[v51];
      }
      else
      {
        --v52;
        --Size;
        --v54;
        v61 = v55[Size >> 4];
        v62 = v55[v52 >> 4][v52 & 0xF];
      }
      v61[Size & 0xF] = v62;
    }
    while ( v53 + (_DWORD)v51 );
  }
  v63 = v106;
  v64 = 0i64;
  this->Intersections.Size = 0i64;
  if ( (v106 & 1) != 0 )
  {
    this->ValidChains.Size = 0i64;
    for ( i = 0i64; i < this->ActiveChains.Size; ++i )
    {
      if ( (this->ActiveChains.Pages[i >> 4][i & 0xF]->flags & 2) == 0 )
      {
        v66 = this->ValidChains.Size >> 4;
        if ( v66 >= this->ValidChains.NumPages )
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->ValidChains,
            this->ValidChains.Size >> 4);
        this->ValidChains.Pages[v66][this->ValidChains.Size & 0xF] = i;
        ++this->ValidChains.Size;
      }
    }
  }
  if ( this->ValidChains.Size > 1 )
  {
    v67 = 0i64;
    v102 = 0i64;
    do
    {
      if ( v67 >= 0 )
      {
        v68 = v67 + 1;
        v105 = v67 + 1;
        do
        {
          v69 = this->ValidChains.Pages;
          v70 = this->ActiveChains.Pages;
          v71 = v67 & 0xF;
          v72 = v68 & 0xF;
          v73 = v68 >> 4;
          v74 = v69[(unsigned __int64)v67 >> 4][v71];
          v75 = v70[v74 >> 4][v74 & 0xF];
          v76 = v69[v68 >> 4][v72];
          v77 = v70[v76 >> 4][v76 & 0xF];
          if ( v77->xt >= v75->xt )
            break;
          if ( !this->Intersections.Size )
            Scaleform::Render::Tessellator::setupIntersections(this);
          v78 = v77->xb;
          posIntr = v75->posIntr;
          v79 = v75->xb;
          v104 = v77->posIntr;
          v80 = (float)((float)(v77->xt - v78) - v75->xt) + v79;
          if ( v80 != 0.0 )
          {
            v81 = (float)((float)((float)(v79 - v78) * (float)(yt - y)) / v80) + y;
            if ( v81 >= y )
              continue;
          }
          v81 = y;
          if ( v81 > yt )
            v81 = yt;
          v82 = this->Intersections.Size >> 4;
          if ( v82 >= this->Intersections.NumPages )
          {
            MaxPages = this->Intersections.MaxPages;
            if ( v82 >= MaxPages )
            {
              pHeap = this->Intersections.pHeap;
              if ( this->Intersections.Pages )
              {
                v85 = Scaleform::Render::LinearHeap::Alloc(pHeap, 16 * MaxPages);
                memmove(v85, this->Intersections.Pages, 8 * this->Intersections.NumPages);
                v86 = this->Intersections.MaxPages;
                this->Intersections.Pages = (Scaleform::Render::Tessellator::IntersectionType **)v85;
                this->Intersections.MaxPages = 2 * v86;
              }
              else
              {
                this->Intersections.MaxPages = 4i64;
                this->Intersections.Pages = (Scaleform::Render::Tessellator::IntersectionType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                                   pHeap,
                                                                                                   0x20ui64);
              }
            }
            this->Intersections.Pages[v82] = (Scaleform::Render::Tessellator::IntersectionType *)Scaleform::Render::LinearHeap::Alloc(
                                                                                                   this->Intersections.pHeap,
                                                                                                   0xC0ui64);
            ++this->Intersections.NumPages;
          }
          v87 = this->Intersections.Size & 0xF;
          v88 = this->Intersections.Pages[v82];
          v88[v87].pos1 = posIntr;
          v88[v87].pos2 = v104;
          v88[v87].y = v81;
          ++this->Intersections.Size;
          v89 = this->ValidChains.Pages;
          v90 = this->ActiveChains.Pages;
          v91 = v89[v73][v72];
          v92 = v91 & 0xF;
          v93 = v90[v91 >> 4];
          v94 = v89[(unsigned __int64)v67 >> 4][v71];
          v95 = v94 & 0xF;
          v96 = v90[v94 >> 4];
          v97 = v96[v95];
          v96[v95] = v93[v92];
          v68 = v105 - 1;
          --v67;
          v93[v92] = v97;
          --v105;
        }
        while ( v67 >= 0 );
        v67 = v102;
      }
      v102 = ++v67;
    }
    while ( v67 + 1 < this->ValidChains.Size );
    v63 = v106;
    v64 = 0i64;
  }
  if ( this->Intersections.Size > 1 )
  {
    Scaleform::Alg::InsertionSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::IntersectionType,4,4>,bool (*)(Scaleform::Render::Tessellator::IntersectionType const &,Scaleform::Render::Tessellator::IntersectionType const &)>(
      &this->Intersections,
      0i64,
      this->Intersections.Size,
      (bool (__fastcall *)(Scaleform::Render::Tessellator::IntersectionType *, Scaleform::Render::Tessellator::IntersectionType *))UFG::SectionChooser::fnSectionStreamPriority);
    if ( this->HasEpsilon )
    {
      if ( this->Intersections.Size )
      {
        do
        {
          v98 = v64 >> 4;
          v99 = v64 & 0xF;
          v100 = this->Intersections.Pages[v64 >> 4];
          if ( (float)(v100[v64 & 0xF].y - y) < (float)(COERCE_FLOAT(LODWORD(y) & _xmm) * this->Epsilon) )
            v100[v64 & 0xF].y = y;
          ++v64;
          y = this->Intersections.Pages[v98][v99].y;
        }
        while ( v64 < this->Intersections.Size );
      }
    }
  }
  return v63;
}

// File Line: 763
// RVA: 0x9C6BE0
__int64 __fastcall Scaleform::Render::Tessellator::addEventVertex(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::MonoChainType *mc,
        float yb,
        bool enforceFlag)
{
  unsigned __int64 edge; // r8
  __int64 v5; // r10
  Scaleform::Render::Tessellator::EdgeType *v7; // r11
  unsigned __int16 flags; // cx
  unsigned int lower; // edx
  Scaleform::Render::Tessellator::SrcVertexType **Pages; // r8
  Scaleform::Render::Tessellator::SrcVertexType *v11; // rcx
  __int64 v12; // rdx
  float x; // xmm6_4
  float y; // xmm7_4
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *p_MeshVertices; // rdi
  unsigned __int64 v16; // rsi
  __int64 v17; // rdx
  Scaleform::Render::TessVertex *v18; // rax
  unsigned int v20; // r8d
  Scaleform::Render::Tessellator::SrcVertexType **v21; // r9
  unsigned __int64 v22; // rax
  __int64 v23; // r8
  Scaleform::Render::Tessellator::SrcVertexType *v24; // rcx
  Scaleform::Render::Tessellator::SrcVertexType *v25; // rcx
  float v26; // xmm7_4
  unsigned __int64 v27; // rsi

  edge = mc->edge;
  v5 = edge & 0xF;
  v7 = this->Edges.Pages[edge >> 4];
  if ( !enforceFlag )
  {
    flags = mc->flags;
    if ( (flags & 0x10) == 0 && mc->leftBelow == mc->leftAbove && mc->rightBelow == mc->rightAbove )
    {
      if ( (flags & 8) == 0 )
        return 0xFFFFFFFFi64;
      lower = v7[v5].lower;
      Pages = this->SrcVertices.Pages;
      if ( yb != Pages[(unsigned __int64)lower >> 4][lower & 0xF].y )
        return 0xFFFFFFFFi64;
      v11 = Pages[(unsigned __int64)lower >> 4];
LABEL_8:
      v12 = lower & 0xF;
      x = v11[v12].x;
      if ( x > this->LastX )
      {
        this->LastX = x;
        y = v11[v12].y;
LABEL_10:
        p_MeshVertices = &this->MeshVertices;
        v16 = this->MeshVertices.Size >> 4;
        if ( v16 >= this->MeshVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
            &this->MeshVertices,
            this->MeshVertices.Size >> 4);
        v17 = this->MeshVertices.Size & 0xF;
        v18 = this->MeshVertices.Pages[v16];
        v18[v17].x = x;
        v18[v17].y = y;
LABEL_24:
        v18[v17].Idx = -1;
        *(_DWORD *)v18[v17].Styles = -1;
        *(_DWORD *)&v18[v17].Flags = 2;
        ++p_MeshVertices->Size;
        return (unsigned int)(LODWORD(this->MeshVertices.Size) - 1);
      }
      return (unsigned int)(LODWORD(this->MeshVertices.Size) - 1);
    }
  }
  v20 = v7[v5].lower;
  v21 = this->SrcVertices.Pages;
  if ( yb != v21[(unsigned __int64)v20 >> 4][v20 & 0xF].y )
  {
    if ( (mc->flags & 2) == 0 || (lower = v20 + mc->dir, yb != v21[(unsigned __int64)lower >> 4][lower & 0xF].y) )
    {
      v25 = v21[(unsigned __int64)v7[v5].lower >> 4];
      v26 = (float)((float)(yb - v25[v20 & 0xF].y) * v7[v5].slope) + v25[v20 & 0xF].x;
      if ( (float)(v26 - this->LastX) > (float)(COERCE_FLOAT(LODWORD(yb) & _xmm) * this->Epsilon) )
      {
        p_MeshVertices = &this->MeshVertices;
        this->LastX = v26;
        v27 = this->MeshVertices.Size >> 4;
        if ( v27 >= this->MeshVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(&this->MeshVertices, v27);
        v17 = this->MeshVertices.Size & 0xF;
        v18 = this->MeshVertices.Pages[v27];
        v18[v17].x = v26;
        v18[v17].y = yb;
        goto LABEL_24;
      }
      return (unsigned int)(LODWORD(this->MeshVertices.Size) - 1);
    }
    v11 = v21[(unsigned __int64)lower >> 4];
    goto LABEL_8;
  }
  v22 = v20;
  v23 = v20 & 0xF;
  v24 = v21[v22 >> 4];
  x = v24[v23].x;
  if ( x > this->LastX )
  {
    this->LastX = x;
    y = v24[v23].y;
    goto LABEL_10;
  }
  return (unsigned int)(LODWORD(this->MeshVertices.Size) - 1);
}

// File Line: 893
// RVA: 0x9F03F0
void __fastcall Scaleform::Render::Tessellator::removeLastMonoVertex(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::MonotoneType *m)
{
  unsigned int lastIdx; // ecx
  unsigned __int64 Size; // rax
  unsigned __int64 prevIdx1; // rcx
  unsigned int prevIdx2; // eax

  lastIdx = m->d.m.lastIdx;
  if ( lastIdx != -1 )
  {
    if ( lastIdx == LODWORD(this->MonoVertices.Size) - 1 )
    {
      Size = this->MonoVertices.Size;
      if ( Size )
        this->MonoVertices.Size = Size - 1;
    }
    prevIdx1 = m->d.m.prevIdx1;
    prevIdx2 = m->d.m.prevIdx2;
    m->d.m.prevIdx2 = -1;
    m->d.m.lastIdx = prevIdx1;
    m->d.m.prevIdx1 = prevIdx2;
    if ( (_DWORD)prevIdx1 == -1 )
      m->start = 0i64;
    else
      this->MonoVertices.Pages[prevIdx1 >> 4][prevIdx1 & 0xF].next = 0i64;
  }
}

// File Line: 952
// RVA: 0x9F3640
Scaleform::Render::Tessellator::MonotoneType *__fastcall Scaleform::Render::Tessellator::startMonotone(
        Scaleform::Render::Tessellator *this,
        unsigned int style)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16> *p_Monotones; // rbx
  unsigned __int64 v3; // rdi
  Scaleform::Render::Tessellator::MonotoneType *v4; // rdx
  __int64 v6; // [rsp+30h] [rbp-18h]

  p_Monotones = &this->Monotones;
  LODWORD(v6) = -1;
  HIDWORD(v6) = style;
  v3 = this->Monotones.Size >> 4;
  if ( v3 >= this->Monotones.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16>::allocPage(&this->Monotones, v3);
  v4 = &p_Monotones->Pages[v3][p_Monotones->Size & 0xF];
  v4->start = 0i64;
  *(_QWORD *)&v4->d.m.lastIdx = -1i64;
  *(_QWORD *)&v4->d.t.meshIdx = v6;
  v4->lowerBase = 0i64;
  ++p_Monotones->Size;
  return &p_Monotones->Pages[(p_Monotones->Size - 1) >> 4][((unsigned int)p_Monotones->Size - 1) & 0xF];
}

// File Line: 961
// RVA: 0x9F36F0
void __fastcall Scaleform::Render::Tessellator::startMonotone(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        signed int vertex)
{
  Scaleform::Render::Tessellator::MonoChainType *chain; // rax
  unsigned __int16 rightAbove; // cx
  Scaleform::Render::Tessellator::MonotoneType *started; // rax
  Scaleform::Render::Tessellator::MonotoneType *v9; // rsi
  Scaleform::Render::Tessellator::BaseLineType *lowerBase; // r8
  unsigned __int64 v11; // rbp
  Scaleform::Render::Tessellator::MonoVertexType *v12; // rcx
  __int64 v13; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v14; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v15; // rbp
  unsigned __int64 v16; // rbx
  Scaleform::Render::Tessellator::MonoVertexType *v17; // rcx
  __int64 v18; // rdx
  __int64 v19; // [rsp+20h] [rbp-18h]

  chain = scan->chain;
  scan->monotone = 0i64;
  rightAbove = chain->rightAbove;
  if ( rightAbove )
  {
    started = Scaleform::Render::Tessellator::startMonotone(this, rightAbove);
    v9 = started;
    scan->monotone = started;
    if ( started )
    {
      lowerBase = started->lowerBase;
      if ( lowerBase )
      {
        if ( this->MeshVertices.Pages[(unsigned __int64)(vertex & 0xFFFFFFF) >> 4][vertex & 0xF].y == lowerBase->y )
        {
          lowerBase->vertexRight = vertex & 0xFFFFFFF;
        }
        else if ( vertex >= 0 )
        {
          Scaleform::Render::Tessellator::connectPendingToRight(this, scan, vertex);
        }
        else
        {
          Scaleform::Render::Tessellator::connectPendingToLeft(this, scan, vertex);
        }
      }
      else
      {
        LODWORD(v19) = vertex;
        HIDWORD(v19) = vertex;
        if ( started->start )
        {
          v15 = &this->MonoVertices.Pages[(unsigned __int64)started->d.m.lastIdx >> 4][started->d.m.lastIdx & 0xF];
          if ( v15->srcVer == vertex )
            return;
          v16 = this->MonoVertices.Size >> 4;
          if ( v16 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v17 = this->MonoVertices.Pages[v16];
          v18 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v17[v18].srcVer = v19;
          v17[v18].next = 0i64;
          v15->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          v9->d.m.prevIdx2 = v9->d.m.prevIdx1;
          v9->d.m.prevIdx1 = v9->d.m.lastIdx;
        }
        else
        {
          v11 = this->MonoVertices.Size >> 4;
          if ( v11 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v12 = this->MonoVertices.Pages[v11];
          v13 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v12[v13].srcVer = v19;
          v12[v13].next = 0i64;
          v14 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v9->d.t.numTriangles = -1i64;
          v9->start = v14;
        }
        v9->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
      }
    }
  }
}

// File Line: 994
// RVA: 0x9F0520
void __fastcall Scaleform::Render::Tessellator::replaceMonotone(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        unsigned int style)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // rax

  if ( style )
  {
    monotone = scan->monotone;
    if ( monotone )
    {
      if ( monotone->style != style )
      {
        if ( monotone->start )
        {
          *Scaleform::Render::Tessellator::startMonotone(this, style) = *scan->monotone;
          monotone = scan->monotone;
          monotone->start = 0i64;
          *(_QWORD *)&monotone->d.m.lastIdx = -1i64;
          monotone->d.m.prevIdx2 = -1;
          monotone->lowerBase = 0i64;
        }
      }
      monotone->style = style;
    }
    else
    {
      scan->monotone = Scaleform::Render::Tessellator::startMonotone(this, style);
    }
  }
}

// File Line: 1018
// RVA: 0x9C8960
void __fastcall Scaleform::Render::Tessellator::addPendingEnd(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *dst,
        Scaleform::Render::Tessellator::ScanChainType *pending,
        float y)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // rsi
  Scaleform::Render::Tessellator::MonoChainType *chain; // rax
  unsigned int leftBelow; // ecx
  float v9; // eax
  Scaleform::Render::Tessellator::MonotoneType *v10; // r14
  unsigned __int64 Size; // rdi
  unsigned __int64 v12; // rdi
  Scaleform::Render::Tessellator::PendingEndType *v13; // rcx
  __int64 v14; // rdx
  Scaleform::Render::Tessellator::BaseLineType val; // [rsp+20h] [rbp-28h] BYREF

  if ( dst )
  {
    monotone = dst->monotone;
    if ( monotone )
    {
      if ( monotone->style )
      {
        if ( !monotone->lowerBase )
        {
          chain = pending->chain;
          val.y = y;
          val.vertexRight = -1;
          leftBelow = chain->leftBelow;
          val.vertexLeft = dst->vertex;
          LODWORD(chain) = this->PendingEnds.Size;
          val.styleLeft = leftBelow;
          val.numChains = 0;
          val.leftAbove = -1;
          val.firstChain = (unsigned int)chain;
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4>::PushBack(
            &this->BaseLines,
            &val);
          monotone->lowerBase = &this->BaseLines.Pages[(this->BaseLines.Size - 1) >> 4][(LODWORD(this->BaseLines.Size)
                                                                                       - 1) & 0xF];
        }
        v9 = *(float *)&pending->vertex;
        v10 = pending->monotone;
        Size = this->PendingEnds.Size;
        val.y = v9;
        v12 = Size >> 4;
        if ( v12 >= this->PendingEnds.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4>::allocPage(
            &this->PendingEnds,
            v12);
        v13 = this->PendingEnds.Pages[v12];
        v14 = this->PendingEnds.Size & 0xF;
        *(_QWORD *)&v13[v14].vertex = *(_QWORD *)&val.y;
        v13[v14].monotone = v10;
        ++this->PendingEnds.Size;
        ++monotone->lowerBase->numChains;
      }
    }
  }
}

// File Line: 1097
// RVA: 0x9D7260
void __fastcall Scaleform::Render::Tessellator::connectPendingToLeft(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        unsigned int targetVertex)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // rax
  unsigned int style; // r11d
  Scaleform::Render::Tessellator::BaseLineType *lowerBase; // r8
  unsigned int firstChain; // r13d
  int vertexLeft; // r14d
  int numChains; // r15d
  Scaleform::Render::Tessellator::ScanChainType *v11; // r10
  int vertex; // r12d
  Scaleform::Render::Tessellator::PendingEndType *v13; // rax
  char v14; // r8
  int *v15; // rdi
  Scaleform::Render::Tessellator::MonotoneType *v16; // r14
  unsigned __int64 v17; // rsi
  Scaleform::Render::Tessellator::MonoVertexType *v18; // rdx
  __int64 v19; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v20; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v21; // rdi
  unsigned __int64 v22; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v23; // rdx
  __int64 v24; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v25; // rdi
  unsigned __int64 v26; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v27; // rdx
  __int64 v28; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v29; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v30; // rsi
  unsigned __int64 v31; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v32; // rdx
  __int64 v33; // rcx
  unsigned __int64 v34; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v35; // rdx
  __int64 v36; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v37; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v38; // rsi
  unsigned __int64 v39; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v40; // rdx
  __int64 v41; // rcx
  Scaleform::Render::Tessellator::MonotoneType *started; // rax
  Scaleform::Render::Tessellator::MonotoneType *v43; // rsi
  unsigned int v44; // r14d
  unsigned __int64 v45; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v46; // rdx
  __int64 v47; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v48; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v49; // r15
  unsigned __int64 v50; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v51; // rdx
  __int64 v52; // rcx
  unsigned __int64 v53; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v54; // rdx
  __int64 v55; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v56; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v57; // r14
  unsigned __int64 v58; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v59; // rdx
  __int64 v60; // rcx
  __int64 v61; // rdi
  unsigned __int64 v62; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v63; // rdx
  __int64 v64; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v65; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v66; // rsi
  unsigned __int64 v67; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v68; // rdx
  __int64 v69; // rcx
  unsigned __int64 v70; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v71; // rdx
  __int64 v72; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v73; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v74; // rsi
  unsigned __int64 v75; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v76; // rdx
  __int64 v77; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v78; // rsi
  unsigned __int64 v79; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v80; // rdx
  __int64 v81; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v82; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v83; // rdi
  unsigned __int64 v84; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v85; // rdx
  __int64 v86; // rcx
  Scaleform::Render::Tessellator::PendingEndType **Pages; // rdx
  unsigned __int64 v88; // rax
  __int64 v89; // rdi
  unsigned __int64 v90; // rax
  unsigned __int64 Size; // rax
  unsigned int v92; // [rsp+20h] [rbp-D0h]
  int vertexRight; // [rsp+28h] [rbp-C8h]
  __int64 v94; // [rsp+30h] [rbp-C0h]
  __int64 v95; // [rsp+40h] [rbp-B0h]
  __int64 v96; // [rsp+50h] [rbp-A0h]
  __int64 v97; // [rsp+60h] [rbp-90h]
  Scaleform::Render::Tessellator::BaseLineType *v98; // [rsp+70h] [rbp-80h]
  __int64 v99; // [rsp+78h] [rbp-78h]
  __int64 v100; // [rsp+78h] [rbp-78h]
  __int64 v101; // [rsp+88h] [rbp-68h]
  __int64 v102; // [rsp+98h] [rbp-58h]
  int v103; // [rsp+A8h] [rbp-48h] BYREF
  Scaleform::Render::Tessellator::MonotoneType *v104; // [rsp+B0h] [rbp-40h]
  int vars0; // [rsp+110h] [rbp+20h]
  Scaleform::Render::Tessellator::ScanChainType *retaddr; // [rsp+118h] [rbp+28h]
  unsigned int v107; // [rsp+120h] [rbp+30h]
  unsigned int v108; // [rsp+128h] [rbp+38h]

  monotone = scan->monotone;
  style = monotone->style;
  lowerBase = monotone->lowerBase;
  monotone->lowerBase = 0i64;
  firstChain = lowerBase->firstChain;
  vertexLeft = lowerBase->vertexLeft;
  numChains = lowerBase->numChains;
  v104 = scan->monotone;
  v11 = scan;
  vertexRight = lowerBase->vertexRight;
  v98 = lowerBase;
  v108 = style;
  v13 = this->PendingEnds.Pages[(unsigned __int64)firstChain >> 4];
  v103 = vertexLeft;
  v92 = firstChain;
  vertex = v13[firstChain & 0xF].vertex;
  LODWORD(v13) = lowerBase->styleLeft;
  vars0 = numChains;
  v14 = 1;
  v15 = &v103;
  while ( 1 )
  {
    if ( vertexLeft == vertex )
      goto LABEL_84;
    if ( v14 )
    {
      v16 = v11->monotone;
      LODWORD(v96) = vertex;
      HIDWORD(v96) = vertex;
      if ( v16->start )
      {
        v21 = &this->MonoVertices.Pages[(unsigned __int64)v16->d.m.lastIdx >> 4][v16->d.m.lastIdx & 0xF];
        if ( v21->srcVer == vertex )
          goto LABEL_13;
        v22 = this->MonoVertices.Size >> 4;
        if ( v22 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
          targetVertex = v107;
          v11 = retaddr;
        }
        v23 = this->MonoVertices.Pages[v22];
        numChains = vars0;
        v24 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v23[v24].srcVer = v96;
        v23[v24].next = 0i64;
        v21->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v16->d.m.prevIdx2 = v16->d.m.prevIdx1;
        v16->d.m.prevIdx1 = v16->d.m.lastIdx;
      }
      else
      {
        v17 = this->MonoVertices.Size >> 4;
        if ( v17 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
          targetVertex = v107;
          v11 = retaddr;
        }
        v18 = this->MonoVertices.Pages[v17];
        v19 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v18[v19].srcVer = v96;
        v18[v19].next = 0i64;
        v20 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v16->d.t.numTriangles = -1i64;
        v16->start = v20;
      }
      v16->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_13:
      v25 = v11->monotone;
      if ( targetVertex == -1 )
        goto LABEL_84;
      LODWORD(v99) = targetVertex | 0x80000000;
      HIDWORD(v99) = targetVertex | 0x80000000;
      if ( v25->start )
      {
        v30 = &this->MonoVertices.Pages[(unsigned __int64)v25->d.m.lastIdx >> 4][v25->d.m.lastIdx & 0xF];
        if ( v30->srcVer == (targetVertex | 0x80000000) )
          goto LABEL_23;
        v31 = this->MonoVertices.Size >> 4;
        if ( v31 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
          targetVertex = v107;
        }
        v32 = this->MonoVertices.Pages[v31];
        v33 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v32[v33].srcVer = v99;
        v32[v33].next = 0i64;
        v30->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v25->d.m.prevIdx2 = v25->d.m.prevIdx1;
        v25->d.m.prevIdx1 = v25->d.m.lastIdx;
      }
      else
      {
        v26 = this->MonoVertices.Size >> 4;
        if ( v26 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
          targetVertex = v107;
        }
        v27 = this->MonoVertices.Pages[v26];
        v28 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v27[v28].srcVer = v99;
        v27[v28].next = 0i64;
        v29 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v25->d.t.numTriangles = -1i64;
        v25->start = v29;
      }
      v25->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_23:
      LODWORD(v94) = targetVertex & 0x7FFFFFFF;
      HIDWORD(v94) = targetVertex & 0x7FFFFFFF;
      if ( v25->start )
      {
        v38 = &this->MonoVertices.Pages[(unsigned __int64)v25->d.m.lastIdx >> 4][v25->d.m.lastIdx & 0xF];
        if ( v38->srcVer != (targetVertex & 0x7FFFFFFF) )
        {
          v39 = this->MonoVertices.Size >> 4;
          if ( v39 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
            targetVertex = v107;
          }
          v40 = this->MonoVertices.Pages[v39];
          v41 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v40[v41].srcVer = v94;
          v40[v41].next = 0i64;
          v38->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          v25->d.m.prevIdx2 = v25->d.m.prevIdx1;
          v25->d.m.prevIdx1 = v25->d.m.lastIdx;
          v25->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
        }
      }
      else
      {
        v34 = this->MonoVertices.Size >> 4;
        if ( v34 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
          targetVertex = v107;
        }
        v35 = this->MonoVertices.Pages[v34];
        v36 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v35[v36].srcVer = v94;
        v35[v36].next = 0i64;
        v37 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v25->d.t.numTriangles = -1i64;
        v25->start = v37;
        v25->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
      }
      goto LABEL_83;
    }
    if ( (_DWORD)v13 != style || !*((_QWORD *)v15 + 1) )
    {
      started = Scaleform::Render::Tessellator::startMonotone(this, style);
      v43 = started;
      *((_QWORD *)v15 + 1) = started;
      if ( vertexLeft == -1 )
        goto LABEL_43;
      v44 = vertexLeft | 0x80000000;
      LODWORD(v102) = v44;
      HIDWORD(v102) = v44;
      if ( started->start )
      {
        v49 = &this->MonoVertices.Pages[(unsigned __int64)started->d.m.lastIdx >> 4][started->d.m.lastIdx & 0xF];
        if ( v49->srcVer == v44 )
          goto LABEL_43;
        v50 = this->MonoVertices.Size >> 4;
        if ( v50 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v51 = this->MonoVertices.Pages[v50];
        v52 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v51[v52].srcVer = v102;
        v51[v52].next = 0i64;
        v49->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v43->d.m.prevIdx2 = v43->d.m.prevIdx1;
        v43->d.m.prevIdx1 = v43->d.m.lastIdx;
      }
      else
      {
        v45 = this->MonoVertices.Size >> 4;
        if ( v45 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v46 = this->MonoVertices.Pages[v45];
        v47 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v46[v47].srcVer = v102;
        v46[v47].next = 0i64;
        v48 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v43->d.t.numTriangles = -1i64;
        v43->start = v48;
      }
      v43->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_43:
      if ( vertex != -1 )
      {
        LODWORD(v95) = vertex & 0x7FFFFFFF;
        HIDWORD(v95) = vertex & 0x7FFFFFFF;
        if ( !v43->start )
        {
          v53 = this->MonoVertices.Size >> 4;
          if ( v53 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v54 = this->MonoVertices.Pages[v53];
          v55 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v54[v55].srcVer = v95;
          v54[v55].next = 0i64;
          v56 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v43->d.t.numTriangles = -1i64;
          v43->start = v56;
LABEL_52:
          v43->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          goto LABEL_53;
        }
        v57 = &this->MonoVertices.Pages[(unsigned __int64)v43->d.m.lastIdx >> 4][v43->d.m.lastIdx & 0xF];
        if ( v57->srcVer != (vertex & 0x7FFFFFFF) )
        {
          v58 = this->MonoVertices.Size >> 4;
          if ( v58 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v59 = this->MonoVertices.Pages[v58];
          v60 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v59[v60].srcVer = v95;
          v59[v60].next = 0i64;
          v57->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          v43->d.m.prevIdx2 = v43->d.m.prevIdx1;
          v43->d.m.prevIdx1 = v43->d.m.lastIdx;
          goto LABEL_52;
        }
      }
LABEL_53:
      v11 = retaddr;
      targetVertex = v107;
    }
    if ( !vars0 )
    {
      v78 = (Scaleform::Render::Tessellator::MonotoneType *)*((_QWORD *)v15 + 1);
      v11->monotone = v78;
      LODWORD(v101) = targetVertex | 0x80000000;
      HIDWORD(v101) = targetVertex | 0x80000000;
      if ( v78->start )
      {
        v83 = &this->MonoVertices.Pages[(unsigned __int64)v78->d.m.lastIdx >> 4][v78->d.m.lastIdx & 0xF];
        if ( v83->srcVer == (targetVertex | 0x80000000) )
          goto LABEL_82;
        v84 = this->MonoVertices.Size >> 4;
        if ( v84 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
          targetVertex = v107;
        }
        v85 = this->MonoVertices.Pages[v84];
        v86 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v85[v86].srcVer = v101;
        v85[v86].next = 0i64;
        v83->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v78->d.m.prevIdx2 = v78->d.m.prevIdx1;
        v78->d.m.prevIdx1 = v78->d.m.lastIdx;
      }
      else
      {
        v79 = this->MonoVertices.Size >> 4;
        if ( v79 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
          targetVertex = v107;
        }
        v80 = this->MonoVertices.Pages[v79];
        v81 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v80[v81].srcVer = v101;
        v80[v81].next = 0i64;
        v82 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v78->d.t.numTriangles = -1i64;
        v78->start = v82;
      }
      v78->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
      goto LABEL_82;
    }
    v61 = *((_QWORD *)v15 + 1);
    if ( targetVertex != -1 )
    {
      LODWORD(v97) = targetVertex | 0x80000000;
      HIDWORD(v97) = targetVertex | 0x80000000;
      if ( *(_QWORD *)v61 )
      {
        v66 = &this->MonoVertices.Pages[(unsigned __int64)*(unsigned int *)(v61 + 8) >> 4][*(_DWORD *)(v61 + 8) & 0xF];
        if ( v66->srcVer == (targetVertex | 0x80000000) )
          goto LABEL_65;
        v67 = this->MonoVertices.Size >> 4;
        if ( v67 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
          targetVertex = v107;
        }
        v68 = this->MonoVertices.Pages[v67];
        v69 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v68[v69].srcVer = v97;
        v68[v69].next = 0i64;
        v66->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_DWORD *)(v61 + 16) = *(_DWORD *)(v61 + 12);
        *(_DWORD *)(v61 + 12) = *(_DWORD *)(v61 + 8);
      }
      else
      {
        v62 = this->MonoVertices.Size >> 4;
        if ( v62 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
          targetVertex = v107;
        }
        v63 = this->MonoVertices.Pages[v62];
        v64 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v63[v64].srcVer = v97;
        v63[v64].next = 0i64;
        v65 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)(v61 + 12) = -1i64;
        *(_QWORD *)v61 = v65;
      }
      *(_DWORD *)(v61 + 8) = LODWORD(this->MonoVertices.Size) - 1;
LABEL_65:
      LODWORD(v100) = targetVertex & 0x7FFFFFFF;
      HIDWORD(v100) = targetVertex & 0x7FFFFFFF;
      if ( *(_QWORD *)v61 )
      {
        v74 = &this->MonoVertices.Pages[(unsigned __int64)*(unsigned int *)(v61 + 8) >> 4][*(_DWORD *)(v61 + 8) & 0xF];
        if ( v74->srcVer != (targetVertex & 0x7FFFFFFF) )
        {
          v75 = this->MonoVertices.Size >> 4;
          if ( v75 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
            targetVertex = v107;
          }
          v76 = this->MonoVertices.Pages[v75];
          v77 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v76[v77].srcVer = v100;
          v76[v77].next = 0i64;
          v74->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_DWORD *)(v61 + 16) = *(_DWORD *)(v61 + 12);
          *(_DWORD *)(v61 + 12) = *(_DWORD *)(v61 + 8);
          *(_DWORD *)(v61 + 8) = LODWORD(this->MonoVertices.Size) - 1;
        }
      }
      else
      {
        v70 = this->MonoVertices.Size >> 4;
        if ( v70 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
          targetVertex = v107;
        }
        v71 = this->MonoVertices.Pages[v70];
        v72 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v71[v72].srcVer = v100;
        v71[v72].next = 0i64;
        v73 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)(v61 + 12) = -1i64;
        *(_QWORD *)v61 = v73;
        *(_DWORD *)(v61 + 8) = LODWORD(this->MonoVertices.Size) - 1;
      }
    }
LABEL_82:
    firstChain = v92;
LABEL_83:
    numChains = vars0;
LABEL_84:
    v14 = 0;
    if ( !numChains )
      break;
    Pages = this->PendingEnds.Pages;
    --numChains;
    v88 = firstChain;
    v89 = firstChain++ & 0xF;
    vars0 = numChains;
    v15 = (int *)&Pages[v88 >> 4][v89];
    vertexLeft = vertex;
    v92 = firstChain;
    if ( numChains )
      vertex = Pages[(unsigned __int64)firstChain >> 4][firstChain & 0xF].vertex;
    else
      vertex = vertexRight;
    v13 = (Scaleform::Render::Tessellator::PendingEndType *)*((_QWORD *)v15 + 1);
    v11 = retaddr;
    style = v108;
    if ( v13 )
      LODWORD(v13) = *(&v13[1].vertex + 1);
  }
  if ( v98 == &this->BaseLines.Pages[(this->BaseLines.Size - 1) >> 4][(LODWORD(this->BaseLines.Size) - 1) & 0xF] )
  {
    v90 = v98->firstChain;
    if ( v90 < this->PendingEnds.Size )
      this->PendingEnds.Size = v90;
    Size = this->BaseLines.Size;
    if ( Size )
      this->BaseLines.Size = Size - 1;
  }
}

// File Line: 1147
// RVA: 0x9D7E70
void __fastcall Scaleform::Render::Tessellator::connectPendingToRight(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        unsigned int targetVertex)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // rax
  Scaleform::Render::Tessellator::BaseLineType *lowerBase; // rdx
  unsigned int v7; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v8; // r14
  unsigned int vertex; // r12d
  unsigned __int64 v10; // rsi
  Scaleform::Render::Tessellator::MonoVertexType *v11; // rdx
  __int64 v12; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v13; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v14; // rdi
  unsigned __int64 v15; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v16; // rdx
  __int64 v17; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v18; // rsi
  unsigned __int64 v19; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v20; // rdx
  __int64 v21; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v22; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v23; // rdi
  unsigned __int64 v24; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v25; // rdx
  __int64 v26; // rcx
  unsigned int v27; // r9d
  unsigned int v28; // ecx
  Scaleform::Render::Tessellator::PendingEndType **Pages; // rdx
  unsigned __int64 v30; // rax
  __int64 v31; // rsi
  __int64 v32; // rsi
  unsigned int v33; // r14d
  __int64 v34; // rax
  int v35; // ecx
  Scaleform::Render::Tessellator::MonotoneType *started; // rax
  Scaleform::Render::Tessellator::MonotoneType *v37; // rdi
  unsigned int v38; // r14d
  unsigned __int64 v39; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v40; // rdx
  __int64 v41; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v42; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v43; // r15
  unsigned __int64 v44; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v45; // rdx
  __int64 v46; // rcx
  unsigned __int64 v47; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v48; // rdx
  __int64 v49; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v50; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v51; // r14
  unsigned __int64 v52; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v53; // rdx
  __int64 v54; // rcx
  __int64 v55; // rdi
  unsigned __int64 v56; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v57; // rdx
  __int64 v58; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v59; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v60; // rsi
  unsigned __int64 v61; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v62; // rdx
  __int64 v63; // rcx
  unsigned __int64 v64; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v65; // rdx
  __int64 v66; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v67; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v68; // rsi
  unsigned __int64 v69; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v70; // rdx
  __int64 v71; // rcx
  unsigned __int64 v72; // rax
  unsigned __int64 Size; // rax
  unsigned int firstChain; // [rsp+10h] [rbp-49h]
  Scaleform::Render::Tessellator::BaseLineType *v75; // [rsp+18h] [rbp-41h]
  __int64 v76; // [rsp+20h] [rbp-39h]
  __int64 v77; // [rsp+20h] [rbp-39h]
  __int64 v78; // [rsp+20h] [rbp-39h]
  __int64 v79; // [rsp+30h] [rbp-29h]
  __int64 v80; // [rsp+40h] [rbp-19h]
  __int64 v81; // [rsp+50h] [rbp-9h]
  unsigned int numChains; // [rsp+C0h] [rbp+67h]
  void *retaddr; // [rsp+C8h] [rbp+6Fh]
  unsigned int v84; // [rsp+D0h] [rbp+77h]
  unsigned int style; // [rsp+D8h] [rbp+7Fh]

  monotone = scan->monotone;
  lowerBase = monotone->lowerBase;
  v7 = monotone->style;
  monotone->lowerBase = 0i64;
  v8 = scan->monotone;
  style = v7;
  numChains = lowerBase->numChains;
  LODWORD(retaddr) = lowerBase->vertexRight;
  v75 = lowerBase;
  firstChain = lowerBase->firstChain;
  vertex = this->PendingEnds.Pages[(unsigned __int64)firstChain >> 4][firstChain & 0xF].vertex;
  LODWORD(v76) = vertex;
  HIDWORD(v76) = vertex;
  if ( !v8->start )
  {
    v10 = this->MonoVertices.Size >> 4;
    if ( v10 >= this->MonoVertices.NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
        this->MonoVertices.Size >> 4);
      targetVertex = v84;
    }
    v11 = this->MonoVertices.Pages[v10];
    v12 = this->MonoVertices.Size & 0xF;
    *(_QWORD *)&v11[v12].srcVer = v76;
    v11[v12].next = 0i64;
    v13 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
    *(_QWORD *)&v8->d.t.numTriangles = -1i64;
    v8->start = v13;
LABEL_9:
    v8->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
    goto LABEL_10;
  }
  v14 = &this->MonoVertices.Pages[(unsigned __int64)v8->d.m.lastIdx >> 4][v8->d.m.lastIdx & 0xF];
  if ( v14->srcVer != vertex )
  {
    v15 = this->MonoVertices.Size >> 4;
    if ( v15 >= this->MonoVertices.NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
        this->MonoVertices.Size >> 4);
      targetVertex = v84;
    }
    v16 = this->MonoVertices.Pages[v15];
    v17 = this->MonoVertices.Size & 0xF;
    *(_QWORD *)&v16[v17].srcVer = v76;
    v16[v17].next = 0i64;
    v14->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
    v8->d.m.prevIdx2 = v8->d.m.prevIdx1;
    v8->d.m.prevIdx1 = v8->d.m.lastIdx;
    goto LABEL_9;
  }
LABEL_10:
  v18 = scan->monotone;
  LODWORD(v77) = targetVertex;
  HIDWORD(v77) = targetVertex;
  if ( v18->start )
  {
    v23 = &this->MonoVertices.Pages[(unsigned __int64)v18->d.m.lastIdx >> 4][v18->d.m.lastIdx & 0xF];
    if ( v23->srcVer != targetVertex )
    {
      v24 = this->MonoVertices.Size >> 4;
      if ( v24 >= this->MonoVertices.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
          this->MonoVertices.Size >> 4);
        targetVertex = v84;
      }
      v25 = this->MonoVertices.Pages[v24];
      v26 = this->MonoVertices.Size & 0xF;
      *(_QWORD *)&v25[v26].srcVer = v77;
      v25[v26].next = 0i64;
      v23->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
      v18->d.m.prevIdx2 = v18->d.m.prevIdx1;
      v18->d.m.prevIdx1 = v18->d.m.lastIdx;
      v18->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
    }
  }
  else
  {
    v19 = this->MonoVertices.Size >> 4;
    if ( v19 >= this->MonoVertices.NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
        this->MonoVertices.Size >> 4);
      targetVertex = v84;
    }
    v20 = this->MonoVertices.Pages[v19];
    v21 = this->MonoVertices.Size & 0xF;
    *(_QWORD *)&v20[v21].srcVer = v77;
    v20[v21].next = 0i64;
    v22 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
    *(_QWORD *)&v18->d.t.numTriangles = -1i64;
    v18->start = v22;
    v18->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
  }
LABEL_18:
  v27 = firstChain;
  while ( 1 )
  {
    v28 = numChains;
    if ( !numChains )
      break;
    Pages = this->PendingEnds.Pages;
    v30 = v27;
    v31 = v27++ & 0xF;
    --numChains;
    v32 = (__int64)&Pages[v30 >> 4][v31];
    v33 = vertex;
    firstChain = v27;
    if ( v28 == 1 )
      vertex = (unsigned int)retaddr;
    else
      vertex = Pages[(unsigned __int64)v27 >> 4][v27 & 0xF].vertex;
    v34 = *(_QWORD *)(v32 + 8);
    if ( v34 )
      v35 = *(_DWORD *)(v34 + 20);
    else
      v35 = 0;
    if ( v33 != vertex )
    {
      if ( v35 != style || !v34 )
      {
        started = Scaleform::Render::Tessellator::startMonotone(this, style);
        v37 = started;
        *(_QWORD *)(v32 + 8) = started;
        if ( v33 != -1 )
        {
          v38 = v33 | 0x80000000;
          LODWORD(v78) = v38;
          HIDWORD(v78) = v38;
          if ( !started->start )
          {
            v39 = this->MonoVertices.Size >> 4;
            if ( v39 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v40 = this->MonoVertices.Pages[v39];
            v41 = this->MonoVertices.Size & 0xF;
            *(_QWORD *)&v40[v41].srcVer = v78;
            v40[v41].next = 0i64;
            v42 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
            *(_QWORD *)&v37->d.t.numTriangles = -1i64;
            v37->start = v42;
            goto LABEL_38;
          }
          v43 = &this->MonoVertices.Pages[(unsigned __int64)started->d.m.lastIdx >> 4][started->d.m.lastIdx & 0xF];
          if ( v43->srcVer != v38 )
          {
            v44 = this->MonoVertices.Size >> 4;
            if ( v44 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v45 = this->MonoVertices.Pages[v44];
            v46 = this->MonoVertices.Size & 0xF;
            *(_QWORD *)&v45[v46].srcVer = v78;
            v45[v46].next = 0i64;
            v43->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
            v37->d.m.prevIdx2 = v37->d.m.prevIdx1;
            v37->d.m.prevIdx1 = v37->d.m.lastIdx;
LABEL_38:
            v37->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          }
        }
        if ( vertex != -1 )
        {
          LODWORD(v79) = vertex & 0x7FFFFFFF;
          HIDWORD(v79) = vertex & 0x7FFFFFFF;
          if ( v37->start )
          {
            v51 = &this->MonoVertices.Pages[(unsigned __int64)v37->d.m.lastIdx >> 4][v37->d.m.lastIdx & 0xF];
            if ( v51->srcVer != (vertex & 0x7FFFFFFF) )
            {
              v52 = this->MonoVertices.Size >> 4;
              if ( v52 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v53 = this->MonoVertices.Pages[v52];
              v54 = this->MonoVertices.Size & 0xF;
              *(_QWORD *)&v53[v54].srcVer = v79;
              v53[v54].next = 0i64;
              v51->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
              v37->d.m.prevIdx2 = v37->d.m.prevIdx1;
              v37->d.m.prevIdx1 = v37->d.m.lastIdx;
              v37->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
            }
          }
          else
          {
            v47 = this->MonoVertices.Size >> 4;
            if ( v47 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v48 = this->MonoVertices.Pages[v47];
            v49 = this->MonoVertices.Size & 0xF;
            *(_QWORD *)&v48[v49].srcVer = v79;
            v48[v49].next = 0i64;
            v50 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
            *(_QWORD *)&v37->d.t.numTriangles = -1i64;
            v37->start = v50;
            v37->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          }
        }
        v27 = firstChain;
        targetVertex = v84;
      }
      v55 = *(_QWORD *)(v32 + 8);
      if ( targetVertex != -1 )
      {
        LODWORD(v80) = targetVertex | 0x80000000;
        HIDWORD(v80) = targetVertex | 0x80000000;
        if ( !*(_QWORD *)v55 )
        {
          v56 = this->MonoVertices.Size >> 4;
          if ( v56 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
            targetVertex = v84;
          }
          v57 = this->MonoVertices.Pages[v56];
          v58 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v57[v58].srcVer = v80;
          v57[v58].next = 0i64;
          v59 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)(v55 + 12) = -1i64;
          *(_QWORD *)v55 = v59;
LABEL_58:
          *(_DWORD *)(v55 + 8) = LODWORD(this->MonoVertices.Size) - 1;
          goto LABEL_59;
        }
        v60 = &this->MonoVertices.Pages[(unsigned __int64)*(unsigned int *)(v55 + 8) >> 4][*(_DWORD *)(v55 + 8) & 0xF];
        if ( v60->srcVer != (targetVertex | 0x80000000) )
        {
          v61 = this->MonoVertices.Size >> 4;
          if ( v61 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
            targetVertex = v84;
          }
          v62 = this->MonoVertices.Pages[v61];
          v63 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v62[v63].srcVer = v80;
          v62[v63].next = 0i64;
          v60->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_DWORD *)(v55 + 16) = *(_DWORD *)(v55 + 12);
          *(_DWORD *)(v55 + 12) = *(_DWORD *)(v55 + 8);
          goto LABEL_58;
        }
LABEL_59:
        LODWORD(v81) = targetVertex & 0x7FFFFFFF;
        HIDWORD(v81) = targetVertex & 0x7FFFFFFF;
        if ( !*(_QWORD *)v55 )
        {
          v64 = this->MonoVertices.Size >> 4;
          if ( v64 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
            targetVertex = v84;
          }
          v65 = this->MonoVertices.Pages[v64];
          v66 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v65[v66].srcVer = v81;
          v65[v66].next = 0i64;
          v67 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)(v55 + 12) = -1i64;
          *(_QWORD *)v55 = v67;
          *(_DWORD *)(v55 + 8) = LODWORD(this->MonoVertices.Size) - 1;
          goto LABEL_18;
        }
        v27 = firstChain;
        v68 = &this->MonoVertices.Pages[(unsigned __int64)*(unsigned int *)(v55 + 8) >> 4][*(_DWORD *)(v55 + 8) & 0xF];
        if ( v68->srcVer != (targetVertex & 0x7FFFFFFF) )
        {
          v69 = this->MonoVertices.Size >> 4;
          if ( v69 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
            targetVertex = v84;
          }
          v70 = this->MonoVertices.Pages[v69];
          v71 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v70[v71].srcVer = v81;
          v70[v71].next = 0i64;
          v68->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_DWORD *)(v55 + 16) = *(_DWORD *)(v55 + 12);
          *(_DWORD *)(v55 + 12) = *(_DWORD *)(v55 + 8);
          *(_DWORD *)(v55 + 8) = LODWORD(this->MonoVertices.Size) - 1;
          goto LABEL_18;
        }
      }
    }
  }
  if ( v75 == &this->BaseLines.Pages[(this->BaseLines.Size - 1) >> 4][(LODWORD(this->BaseLines.Size) - 1) & 0xF] )
  {
    v72 = v75->firstChain;
    if ( v72 < this->PendingEnds.Size )
      this->PendingEnds.Size = v72;
    Size = this->BaseLines.Size;
    if ( Size )
      this->BaseLines.Size = Size - 1;
  }
}

// File Line: 1183
// RVA: 0x9D8A50
void __fastcall Scaleform::Render::Tessellator::connectStartingToLeft(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        Scaleform::Render::Tessellator::BaseLineType *upperBase,
        unsigned int targetVertex)
{
  unsigned __int64 leftAbove; // rax
  unsigned int v5; // esi
  Scaleform::Render::Tessellator::ScanChainType *v6; // r14
  unsigned int numChains; // edi
  unsigned int vertexLeft; // r15d
  unsigned int vertex; // r12d
  Scaleform::Render::Tessellator::MonotoneType *started; // rax
  Scaleform::Render::Tessellator::MonotoneType *monotone; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v13; // r13
  Scaleform::Render::Tessellator::BaseLineType *lowerBase; // rcx
  unsigned int v15; // edx
  Scaleform::Render::Tessellator::MonotoneType *v16; // rcx
  unsigned int rightAbove; // eax
  Scaleform::Render::Tessellator::MonotoneType *v18; // rdi
  unsigned int v19; // edx
  unsigned __int64 v20; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v21; // rdx
  __int64 v22; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v23; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v24; // rsi
  unsigned __int64 v25; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v26; // rdx
  __int64 v27; // rcx
  unsigned __int64 v28; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v29; // rdx
  __int64 v30; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v31; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v32; // rsi
  unsigned __int64 v33; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v34; // rdx
  __int64 v35; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v36; // rdi
  unsigned __int64 v37; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v38; // rdx
  __int64 v39; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v40; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v41; // rsi
  unsigned __int64 v42; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v43; // rdx
  __int64 v44; // rcx
  unsigned __int64 v45; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v46; // rdx
  __int64 v47; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v48; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v49; // rsi
  unsigned __int64 v50; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v51; // rdx
  __int64 v52; // rcx
  unsigned __int64 v53; // rsi
  Scaleform::Render::Tessellator::MonoVertexType *v54; // rdx
  __int64 v55; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v56; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v57; // rdi
  unsigned __int64 v58; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v59; // rdx
  __int64 v60; // rcx
  unsigned __int64 v61; // rsi
  Scaleform::Render::Tessellator::MonoVertexType *v62; // rdx
  __int64 v63; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v64; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v65; // rdi
  unsigned __int64 v66; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v67; // rdx
  __int64 v68; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v69; // rdi
  unsigned int v70; // r15d
  unsigned __int64 v71; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v72; // rdx
  __int64 v73; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v74; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v75; // rsi
  unsigned __int64 v76; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v77; // rdx
  __int64 v78; // rcx
  unsigned __int64 v79; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v80; // rdx
  __int64 v81; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v82; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v83; // rsi
  unsigned __int64 v84; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v85; // rdx
  __int64 v86; // rcx
  Scaleform::Render::Tessellator::ScanChainType **Pages; // rdx
  unsigned int v88; // esi
  unsigned __int64 v89; // rax
  __int64 v90; // rcx
  unsigned int v91; // [rsp+20h] [rbp-99h]
  unsigned int style; // [rsp+24h] [rbp-95h]
  unsigned int v93; // [rsp+28h] [rbp-91h]
  Scaleform::Render::Tessellator::MonotoneType *v94; // [rsp+30h] [rbp-89h]
  unsigned int vertexRight; // [rsp+38h] [rbp-81h]
  Scaleform::Render::Tessellator::ScanChainType *scana; // [rsp+40h] [rbp-79h]
  unsigned int firstChain; // [rsp+48h] [rbp-71h]
  __int64 v98; // [rsp+50h] [rbp-69h]
  __int64 v99; // [rsp+60h] [rbp-59h]
  __int64 v100; // [rsp+70h] [rbp-49h]
  __int64 v101; // [rsp+80h] [rbp-39h]
  __int64 v102; // [rsp+90h] [rbp-29h]
  __int64 v103; // [rsp+A0h] [rbp-19h]
  __int64 v104; // [rsp+B0h] [rbp-9h]
  __int64 v105; // [rsp+C0h] [rbp+7h]
  char v106; // [rsp+120h] [rbp+67h]
  unsigned int styleLeft; // [rsp+128h] [rbp+6Fh]

  leftAbove = upperBase->leftAbove;
  v5 = targetVertex;
  v6 = scan;
  if ( (_DWORD)leftAbove == -1 )
    scana = scan;
  else
    scana = &this->ChainsAbove.Pages[leftAbove >> 4][leftAbove & 0xF];
  numChains = upperBase->numChains;
  vertexLeft = upperBase->vertexLeft;
  firstChain = upperBase->firstChain;
  vertexRight = upperBase->vertexRight;
  v93 = numChains;
  v106 = 1;
  vertex = this->ChainsAbove.Pages[(unsigned __int64)firstChain >> 4][firstChain & 0xF].vertex;
  styleLeft = upperBase->styleLeft;
  v91 = vertex;
  style = scan->monotone->style;
  started = Scaleform::Render::Tessellator::startMonotone(this, 0);
  monotone = v6->monotone;
  v13 = started;
  v94 = started;
  started->start = monotone->start;
  *(_QWORD *)&started->d.m.lastIdx = *(_QWORD *)&monotone->d.m.lastIdx;
  *(_QWORD *)&started->d.t.meshIdx = *(_QWORD *)&monotone->d.t.meshIdx;
  lowerBase = monotone->lowerBase;
  v15 = style;
  started->lowerBase = lowerBase;
  v16 = v6->monotone;
  rightAbove = styleLeft;
  v16->start = 0i64;
  *(_QWORD *)&v16->d.m.lastIdx = -1i64;
  v16->d.m.prevIdx2 = -1;
  v16->style = style;
  v16->lowerBase = 0i64;
  while ( 1 )
  {
    if ( !numChains )
    {
      v6->monotone = v13;
      if ( vertexLeft == -1 )
        goto LABEL_56;
      LODWORD(v99) = vertexLeft | 0x80000000;
      HIDWORD(v99) = vertexLeft | 0x80000000;
      if ( v13->start )
      {
        v57 = &this->MonoVertices.Pages[(unsigned __int64)v13->d.m.lastIdx >> 4][v13->d.m.lastIdx & 0xF];
        if ( v57->srcVer == (vertexLeft | 0x80000000) )
          goto LABEL_56;
        v58 = this->MonoVertices.Size >> 4;
        if ( v58 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v59 = this->MonoVertices.Pages[v58];
        vertex = v91;
        v60 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v59[v60].srcVer = v99;
        v59[v60].next = 0i64;
        v57->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v13->d.m.prevIdx2 = v13->d.m.prevIdx1;
        v13->d.m.prevIdx1 = v13->d.m.lastIdx;
      }
      else
      {
        v53 = this->MonoVertices.Size >> 4;
        if ( v53 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v54 = this->MonoVertices.Pages[v53];
        v55 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v54[v55].srcVer = v99;
        v54[v55].next = 0i64;
        v56 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v13->d.t.numTriangles = -1i64;
        v13->start = v56;
      }
      v13->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_56:
      if ( vertex != -1 )
      {
        LODWORD(v101) = vertex & 0x7FFFFFFF;
        HIDWORD(v101) = vertex & 0x7FFFFFFF;
        if ( v13->start )
        {
          v65 = &this->MonoVertices.Pages[(unsigned __int64)v13->d.m.lastIdx >> 4][v13->d.m.lastIdx & 0xF];
          if ( v65->srcVer != (vertex & 0x7FFFFFFF) )
          {
            v66 = this->MonoVertices.Size >> 4;
            if ( v66 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v67 = this->MonoVertices.Pages[v66];
            vertex = v91;
            v68 = this->MonoVertices.Size & 0xF;
            *(_QWORD *)&v67[v68].srcVer = v101;
            v67[v68].next = 0i64;
            v65->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
            v13->d.m.prevIdx2 = v13->d.m.prevIdx1;
            v13->d.m.prevIdx1 = v13->d.m.lastIdx;
            v13->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          }
        }
        else
        {
          v61 = this->MonoVertices.Size >> 4;
          if ( v61 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v62 = this->MonoVertices.Pages[v61];
          v63 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v62[v63].srcVer = v101;
          v62[v63].next = 0i64;
          v64 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v13->d.t.numTriangles = -1i64;
          v13->start = v64;
          v13->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
        }
      }
      goto LABEL_66;
    }
    if ( vertexLeft != vertex )
    {
      Scaleform::Render::Tessellator::replaceMonotone(this, v6, v15);
      v18 = v6->monotone;
      if ( v5 == -1 )
        goto LABEL_26;
      v19 = v5 | 0x80000000;
      LODWORD(v98) = v5 | 0x80000000;
      HIDWORD(v98) = v5 | 0x80000000;
      if ( v18->start )
      {
        v24 = &this->MonoVertices.Pages[(unsigned __int64)v18->d.m.lastIdx >> 4][v18->d.m.lastIdx & 0xF];
        if ( v24->srcVer == v19 )
          goto LABEL_17;
        v25 = this->MonoVertices.Size >> 4;
        if ( v25 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v26 = this->MonoVertices.Pages[v25];
        v27 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v26[v27].srcVer = v98;
        v26[v27].next = 0i64;
        v24->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v18->d.m.prevIdx2 = v18->d.m.prevIdx1;
        v18->d.m.prevIdx1 = v18->d.m.lastIdx;
      }
      else
      {
        v20 = this->MonoVertices.Size >> 4;
        if ( v20 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v21 = this->MonoVertices.Pages[v20];
        v22 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v21[v22].srcVer = v98;
        v21[v22].next = 0i64;
        v23 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v18->d.t.numTriangles = -1i64;
        v18->start = v23;
      }
      v18->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_17:
      LODWORD(v100) = targetVertex & 0x7FFFFFFF;
      HIDWORD(v100) = targetVertex & 0x7FFFFFFF;
      if ( v18->start )
      {
        v32 = &this->MonoVertices.Pages[(unsigned __int64)v18->d.m.lastIdx >> 4][v18->d.m.lastIdx & 0xF];
        if ( v32->srcVer == (targetVertex & 0x7FFFFFFF) )
          goto LABEL_26;
        v33 = this->MonoVertices.Size >> 4;
        if ( v33 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v34 = this->MonoVertices.Pages[v33];
        v35 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v34[v35].srcVer = v100;
        v34[v35].next = 0i64;
        v32->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v18->d.m.prevIdx2 = v18->d.m.prevIdx1;
        v18->d.m.prevIdx1 = v18->d.m.lastIdx;
      }
      else
      {
        v28 = this->MonoVertices.Size >> 4;
        if ( v28 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v29 = this->MonoVertices.Pages[v28];
        v30 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v29[v30].srcVer = v100;
        v29[v30].next = 0i64;
        v31 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v18->d.t.numTriangles = -1i64;
        v18->start = v31;
      }
      v18->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_26:
      v36 = v6->monotone;
      if ( vertexLeft == -1 )
        goto LABEL_36;
      LODWORD(v104) = vertexLeft | 0x80000000;
      HIDWORD(v104) = vertexLeft | 0x80000000;
      if ( v36->start )
      {
        v41 = &this->MonoVertices.Pages[(unsigned __int64)v36->d.m.lastIdx >> 4][v36->d.m.lastIdx & 0xF];
        if ( v41->srcVer == (vertexLeft | 0x80000000) )
          goto LABEL_36;
        v42 = this->MonoVertices.Size >> 4;
        if ( v42 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v43 = this->MonoVertices.Pages[v42];
        v44 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v43[v44].srcVer = v104;
        v43[v44].next = 0i64;
        v41->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v36->d.m.prevIdx2 = v36->d.m.prevIdx1;
        v36->d.m.prevIdx1 = v36->d.m.lastIdx;
      }
      else
      {
        v37 = this->MonoVertices.Size >> 4;
        if ( v37 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v38 = this->MonoVertices.Pages[v37];
        v39 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v38[v39].srcVer = v104;
        v38[v39].next = 0i64;
        v40 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v36->d.t.numTriangles = -1i64;
        v36->start = v40;
      }
      v36->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_36:
      vertex = v91;
      if ( v91 != -1 )
      {
        LODWORD(v102) = v91 & 0x7FFFFFFF;
        HIDWORD(v102) = v91 & 0x7FFFFFFF;
        if ( !v36->start )
        {
          v45 = this->MonoVertices.Size >> 4;
          if ( v45 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v46 = this->MonoVertices.Pages[v45];
          v47 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v46[v47].srcVer = v102;
          v46[v47].next = 0i64;
          v48 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v36->d.t.numTriangles = -1i64;
          v36->start = v48;
LABEL_41:
          v13 = v94;
          vertex = v91;
          v36->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_66:
          rightAbove = styleLeft;
          goto LABEL_67;
        }
        v49 = &this->MonoVertices.Pages[(unsigned __int64)v36->d.m.lastIdx >> 4][v36->d.m.lastIdx & 0xF];
        if ( v49->srcVer != (v91 & 0x7FFFFFFF) )
        {
          v50 = this->MonoVertices.Size >> 4;
          if ( v50 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v51 = this->MonoVertices.Pages[v50];
          v52 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v51[v52].srcVer = v102;
          v51[v52].next = 0i64;
          v49->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          v36->d.m.prevIdx2 = v36->d.m.prevIdx1;
          v36->d.m.prevIdx1 = v36->d.m.lastIdx;
          goto LABEL_41;
        }
      }
      v13 = v94;
      goto LABEL_66;
    }
LABEL_67:
    if ( rightAbove == style && v6->monotone )
      goto LABEL_93;
    if ( !rightAbove )
    {
      v6->monotone = 0i64;
      goto LABEL_93;
    }
    if ( v106 )
      v6 = scana;
    Scaleform::Render::Tessellator::replaceMonotone(this, v6, rightAbove);
    v69 = v6->monotone;
    if ( vertexLeft != -1 )
    {
      v70 = vertexLeft | 0x80000000;
      LODWORD(v103) = v70;
      HIDWORD(v103) = v70;
      if ( !v69->start )
      {
        v71 = this->MonoVertices.Size >> 4;
        if ( v71 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v72 = this->MonoVertices.Pages[v71];
        v73 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v72[v73].srcVer = v103;
        v72[v73].next = 0i64;
        v74 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v69->d.t.numTriangles = -1i64;
        v69->start = v74;
LABEL_82:
        v69->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
        goto LABEL_83;
      }
      v75 = &this->MonoVertices.Pages[(unsigned __int64)v69->d.m.lastIdx >> 4][v69->d.m.lastIdx & 0xF];
      if ( v75->srcVer != v70 )
      {
        v76 = this->MonoVertices.Size >> 4;
        if ( v76 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v77 = this->MonoVertices.Pages[v76];
        v78 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v77[v78].srcVer = v103;
        v77[v78].next = 0i64;
        v75->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v69->d.m.prevIdx2 = v69->d.m.prevIdx1;
        v69->d.m.prevIdx1 = v69->d.m.lastIdx;
        goto LABEL_82;
      }
    }
LABEL_83:
    if ( vertex == -1 )
      goto LABEL_93;
    LODWORD(v105) = vertex & 0x7FFFFFFF;
    HIDWORD(v105) = vertex & 0x7FFFFFFF;
    if ( v69->start )
    {
      v83 = &this->MonoVertices.Pages[(unsigned __int64)v69->d.m.lastIdx >> 4][v69->d.m.lastIdx & 0xF];
      if ( v83->srcVer == (vertex & 0x7FFFFFFF) )
        goto LABEL_93;
      v84 = this->MonoVertices.Size >> 4;
      if ( v84 >= this->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
          this->MonoVertices.Size >> 4);
      v85 = this->MonoVertices.Pages[v84];
      v86 = this->MonoVertices.Size & 0xF;
      *(_QWORD *)&v85[v86].srcVer = v105;
      v85[v86].next = 0i64;
      v83->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
      v69->d.m.prevIdx2 = v69->d.m.prevIdx1;
      v69->d.m.prevIdx1 = v69->d.m.lastIdx;
    }
    else
    {
      v79 = this->MonoVertices.Size >> 4;
      if ( v79 >= this->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
          this->MonoVertices.Size >> 4);
      v80 = this->MonoVertices.Pages[v79];
      v81 = this->MonoVertices.Size & 0xF;
      *(_QWORD *)&v80[v81].srcVer = v105;
      v80[v81].next = 0i64;
      v82 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
      *(_QWORD *)&v69->d.t.numTriangles = -1i64;
      v69->start = v82;
    }
    v69->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_93:
    v106 = 0;
    if ( !v93 )
      break;
    Pages = this->ChainsAbove.Pages;
    numChains = v93 - 1;
    v88 = firstChain + 1;
    v93 = numChains;
    vertexLeft = vertex;
    v89 = (unsigned __int64)firstChain >> 4;
    v90 = firstChain++ & 0xF;
    v6 = &Pages[v89][v90];
    if ( numChains )
      vertex = Pages[(unsigned __int64)v88 >> 4][v88 & 0xF].vertex;
    else
      vertex = vertexRight;
    v5 = targetVertex;
    v15 = style;
    rightAbove = v6->chain->rightAbove;
    v91 = vertex;
    styleLeft = rightAbove;
  }
  upperBase->numChains = 0;
}

// File Line: 1235
// RVA: 0x9DAF10
void __fastcall Scaleform::Render::Tessellator::connectStartingToRight(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        Scaleform::Render::Tessellator::BaseLineType *upperBase,
        unsigned int targetVertex)
{
  unsigned __int64 leftAbove; // rax
  unsigned int v5; // esi
  Scaleform::Render::Tessellator::ScanChainType *v6; // r14
  unsigned int vertexLeft; // r15d
  char v9; // di
  unsigned int vertex; // r13d
  unsigned int v11; // ecx
  unsigned int rightAbove; // eax
  Scaleform::Render::Tessellator::MonotoneType *monotone; // rdi
  unsigned __int64 v14; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v15; // rdx
  __int64 v16; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v17; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v18; // rsi
  unsigned __int64 v19; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v20; // rdx
  __int64 v21; // rcx
  unsigned __int64 v22; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v23; // rdx
  __int64 v24; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v25; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v26; // rsi
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *p_MonoVertices; // r13
  unsigned __int64 v28; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v29; // rdx
  __int64 v30; // rax
  Scaleform::Render::Tessellator::MonotoneType *v31; // rdi
  unsigned int v32; // edx
  unsigned __int64 v33; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v34; // rdx
  __int64 v35; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v36; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v37; // rsi
  unsigned __int64 v38; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v39; // rdx
  __int64 v40; // rcx
  unsigned __int64 v41; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v42; // rdx
  __int64 v43; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v44; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v45; // rsi
  unsigned __int64 v46; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v47; // rdx
  __int64 v48; // rcx
  unsigned __int64 v49; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v50; // rdx
  __int64 v51; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v52; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v53; // rsi
  unsigned __int64 v54; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v55; // rdx
  __int64 v56; // rcx
  unsigned __int64 v57; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v58; // rdx
  __int64 v59; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v60; // rdx
  unsigned __int64 v61; // r12
  __int64 v62; // rcx
  Scaleform::Render::Tessellator::MonoVertexType **Pages; // rax
  unsigned __int64 Size; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v65; // rdi
  unsigned int v66; // r15d
  unsigned __int64 v67; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v68; // rdx
  __int64 v69; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v70; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v71; // rsi
  unsigned __int64 v72; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v73; // rdx
  __int64 v74; // rcx
  unsigned __int64 v75; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v76; // rdx
  __int64 v77; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v78; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v79; // rsi
  unsigned __int64 v80; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v81; // rdx
  __int64 v82; // rcx
  unsigned int v83; // r10d
  Scaleform::Render::Tessellator::ScanChainType **v84; // rdx
  unsigned int v85; // r9d
  unsigned __int64 v86; // rax
  __int64 v87; // rcx
  unsigned int v88; // [rsp+20h] [rbp-89h]
  unsigned int v89; // [rsp+24h] [rbp-85h]
  unsigned int numChains; // [rsp+28h] [rbp-81h]
  unsigned int vertexRight; // [rsp+2Ch] [rbp-7Dh]
  Scaleform::Render::Tessellator::ScanChainType *scana; // [rsp+30h] [rbp-79h]
  unsigned int firstChain; // [rsp+38h] [rbp-71h]
  __int64 v94; // [rsp+40h] [rbp-69h]
  __int64 v95; // [rsp+50h] [rbp-59h]
  __int64 v96; // [rsp+60h] [rbp-49h]
  __int64 v97; // [rsp+70h] [rbp-39h]
  __int64 v98; // [rsp+80h] [rbp-29h]
  __int64 v99; // [rsp+90h] [rbp-19h]
  __int64 v100; // [rsp+A0h] [rbp-9h]
  __int64 v101; // [rsp+B0h] [rbp+7h]
  char v102; // [rsp+110h] [rbp+67h]
  unsigned int style; // [rsp+118h] [rbp+6Fh]

  leftAbove = upperBase->leftAbove;
  v5 = targetVertex;
  v6 = scan;
  if ( (_DWORD)leftAbove == -1 )
    scana = scan;
  else
    scana = &this->ChainsAbove.Pages[leftAbove >> 4][leftAbove & 0xF];
  vertexLeft = upperBase->vertexLeft;
  firstChain = upperBase->firstChain;
  numChains = upperBase->numChains;
  vertexRight = upperBase->vertexRight;
  v9 = 1;
  vertex = this->ChainsAbove.Pages[(unsigned __int64)firstChain >> 4][firstChain & 0xF].vertex;
  v102 = 1;
  style = upperBase->styleLeft;
  v11 = scan->monotone->style;
  rightAbove = style;
  v89 = v11;
  while ( 1 )
  {
    v88 = vertex;
    if ( v9 )
    {
      monotone = v6->monotone;
      if ( vertexLeft != -1 )
      {
        LODWORD(v94) = vertexLeft | 0x80000000;
        HIDWORD(v94) = vertexLeft | 0x80000000;
        if ( !monotone->start )
        {
          v14 = this->MonoVertices.Size >> 4;
          if ( v14 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v15 = this->MonoVertices.Pages[v14];
          v16 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v15[v16].srcVer = v94;
          v15[v16].next = 0i64;
          v17 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&monotone->d.t.numTriangles = -1i64;
          monotone->start = v17;
LABEL_15:
          monotone->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          goto LABEL_16;
        }
        v18 = &this->MonoVertices.Pages[(unsigned __int64)monotone->d.m.lastIdx >> 4][monotone->d.m.lastIdx & 0xF];
        if ( v18->srcVer != (vertexLeft | 0x80000000) )
        {
          v19 = this->MonoVertices.Size >> 4;
          if ( v19 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v20 = this->MonoVertices.Pages[v19];
          v21 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v20[v21].srcVer = v94;
          v20[v21].next = 0i64;
          ++this->MonoVertices.Size;
          v18->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][((unsigned int)this->MonoVertices.Size
                                                                                   - 1) & 0xF];
          monotone->d.m.prevIdx2 = monotone->d.m.prevIdx1;
          monotone->d.m.prevIdx1 = monotone->d.m.lastIdx;
          goto LABEL_15;
        }
      }
LABEL_16:
      if ( vertex != -1 )
      {
        LODWORD(v96) = vertex & 0x7FFFFFFF;
        HIDWORD(v96) = vertex & 0x7FFFFFFF;
        if ( !monotone->start )
        {
          v22 = this->MonoVertices.Size >> 4;
          if ( v22 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v23 = this->MonoVertices.Pages[v22];
          v24 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v23[v24].srcVer = v96;
          v23[v24].next = 0i64;
          v25 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&monotone->d.t.numTriangles = -1i64;
          monotone->start = v25;
          goto LABEL_64;
        }
        v26 = &this->MonoVertices.Pages[(unsigned __int64)monotone->d.m.lastIdx >> 4][monotone->d.m.lastIdx & 0xF];
        if ( v26->srcVer != (vertex & 0x7FFFFFFF) )
        {
          p_MonoVertices = &this->MonoVertices;
          v28 = this->MonoVertices.Size >> 4;
          if ( v28 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v29 = this->MonoVertices.Pages[v28];
          v30 = v96;
LABEL_63:
          v62 = p_MonoVertices->Size & 0xF;
          *(_QWORD *)&v29[v62].srcVer = v30;
          v29[v62].next = 0i64;
          ++p_MonoVertices->Size;
          Pages = p_MonoVertices->Pages;
          Size = p_MonoVertices->Size;
          vertex = v88;
          v26->next = &Pages[(Size - 1) >> 4][((_DWORD)Size - 1) & 0xF];
          monotone->d.m.prevIdx2 = monotone->d.m.prevIdx1;
          monotone->d.m.prevIdx1 = monotone->d.m.lastIdx;
LABEL_64:
          monotone->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          goto LABEL_65;
        }
      }
      goto LABEL_65;
    }
    if ( vertexLeft != vertex )
    {
      Scaleform::Render::Tessellator::replaceMonotone(this, v6, v11);
      v31 = v6->monotone;
      if ( v5 == -1 )
        goto LABEL_45;
      v32 = v5 | 0x80000000;
      LODWORD(v100) = v5 | 0x80000000;
      HIDWORD(v100) = v5 | 0x80000000;
      if ( v31->start )
      {
        v37 = &this->MonoVertices.Pages[(unsigned __int64)v31->d.m.lastIdx >> 4][v31->d.m.lastIdx & 0xF];
        if ( v37->srcVer == v32 )
          goto LABEL_36;
        v38 = this->MonoVertices.Size >> 4;
        if ( v38 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v39 = this->MonoVertices.Pages[v38];
        v40 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v39[v40].srcVer = v100;
        v39[v40].next = 0i64;
        v37->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v31->d.m.prevIdx2 = v31->d.m.prevIdx1;
        v31->d.m.prevIdx1 = v31->d.m.lastIdx;
      }
      else
      {
        v33 = this->MonoVertices.Size >> 4;
        if ( v33 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v34 = this->MonoVertices.Pages[v33];
        v35 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v34[v35].srcVer = v100;
        v34[v35].next = 0i64;
        v36 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v31->d.t.numTriangles = -1i64;
        v31->start = v36;
      }
      v31->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_36:
      LODWORD(v98) = targetVertex & 0x7FFFFFFF;
      HIDWORD(v98) = targetVertex & 0x7FFFFFFF;
      if ( v31->start )
      {
        v45 = &this->MonoVertices.Pages[(unsigned __int64)v31->d.m.lastIdx >> 4][v31->d.m.lastIdx & 0xF];
        if ( v45->srcVer == (targetVertex & 0x7FFFFFFF) )
          goto LABEL_45;
        v46 = this->MonoVertices.Size >> 4;
        if ( v46 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v47 = this->MonoVertices.Pages[v46];
        v48 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v47[v48].srcVer = v98;
        v47[v48].next = 0i64;
        v45->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v31->d.m.prevIdx2 = v31->d.m.prevIdx1;
        v31->d.m.prevIdx1 = v31->d.m.lastIdx;
      }
      else
      {
        v41 = this->MonoVertices.Size >> 4;
        if ( v41 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v42 = this->MonoVertices.Pages[v41];
        v43 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v42[v43].srcVer = v98;
        v42[v43].next = 0i64;
        v44 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v31->d.t.numTriangles = -1i64;
        v31->start = v44;
      }
      v31->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_45:
      monotone = v6->monotone;
      if ( vertexLeft != -1 )
      {
        LODWORD(v95) = vertexLeft | 0x80000000;
        HIDWORD(v95) = vertexLeft | 0x80000000;
        if ( monotone->start )
        {
          v53 = &this->MonoVertices.Pages[(unsigned __int64)monotone->d.m.lastIdx >> 4][monotone->d.m.lastIdx & 0xF];
          if ( v53->srcVer != (vertexLeft | 0x80000000) )
          {
            v54 = this->MonoVertices.Size >> 4;
            if ( v54 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v55 = this->MonoVertices.Pages[v54];
            v56 = this->MonoVertices.Size & 0xF;
            *(_QWORD *)&v55[v56].srcVer = v95;
            v55[v56].next = 0i64;
            v53->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
            monotone->d.m.prevIdx2 = monotone->d.m.prevIdx1;
            monotone->d.m.prevIdx1 = monotone->d.m.lastIdx;
            monotone->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          }
        }
        else
        {
          v49 = this->MonoVertices.Size >> 4;
          if ( v49 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v50 = this->MonoVertices.Pages[v49];
          v51 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v50[v51].srcVer = v95;
          v50[v51].next = 0i64;
          v52 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&monotone->d.t.numTriangles = -1i64;
          monotone->start = v52;
          monotone->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
        }
      }
      if ( vertex == -1 )
        goto LABEL_65;
      LODWORD(v97) = vertex & 0x7FFFFFFF;
      HIDWORD(v97) = vertex & 0x7FFFFFFF;
      if ( !monotone->start )
      {
        v57 = this->MonoVertices.Size >> 4;
        if ( v57 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v58 = this->MonoVertices.Pages[v57];
        v59 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v58[v59].srcVer = v97;
        v58[v59].next = 0i64;
        v60 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&monotone->d.t.numTriangles = -1i64;
        monotone->start = v60;
        goto LABEL_64;
      }
      v26 = &this->MonoVertices.Pages[(unsigned __int64)monotone->d.m.lastIdx >> 4][monotone->d.m.lastIdx & 0xF];
      if ( v26->srcVer != (vertex & 0x7FFFFFFF) )
      {
        p_MonoVertices = &this->MonoVertices;
        v61 = this->MonoVertices.Size >> 4;
        if ( v61 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v29 = this->MonoVertices.Pages[v61];
        v30 = v97;
        goto LABEL_63;
      }
LABEL_65:
      v9 = v102;
      rightAbove = style;
    }
    if ( rightAbove == v89 && v6->monotone )
      goto LABEL_92;
    if ( !rightAbove )
    {
      v6->monotone = 0i64;
      goto LABEL_92;
    }
    if ( v9 )
      v6 = scana;
    Scaleform::Render::Tessellator::replaceMonotone(this, v6, rightAbove);
    v65 = v6->monotone;
    if ( vertexLeft != -1 )
    {
      v66 = vertexLeft | 0x80000000;
      LODWORD(v99) = v66;
      HIDWORD(v99) = v66;
      if ( !v65->start )
      {
        v67 = this->MonoVertices.Size >> 4;
        if ( v67 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v68 = this->MonoVertices.Pages[v67];
        v69 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v68[v69].srcVer = v99;
        v68[v69].next = 0i64;
        v70 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v65->d.t.numTriangles = -1i64;
        v65->start = v70;
LABEL_81:
        v65->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
        goto LABEL_82;
      }
      v71 = &this->MonoVertices.Pages[(unsigned __int64)v65->d.m.lastIdx >> 4][v65->d.m.lastIdx & 0xF];
      if ( v71->srcVer != v66 )
      {
        v72 = this->MonoVertices.Size >> 4;
        if ( v72 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v73 = this->MonoVertices.Pages[v72];
        v74 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v73[v74].srcVer = v99;
        v73[v74].next = 0i64;
        v71->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v65->d.m.prevIdx2 = v65->d.m.prevIdx1;
        v65->d.m.prevIdx1 = v65->d.m.lastIdx;
        goto LABEL_81;
      }
    }
LABEL_82:
    if ( vertex == -1 )
      goto LABEL_92;
    LODWORD(v101) = vertex & 0x7FFFFFFF;
    HIDWORD(v101) = vertex & 0x7FFFFFFF;
    if ( v65->start )
    {
      v79 = &this->MonoVertices.Pages[(unsigned __int64)v65->d.m.lastIdx >> 4][v65->d.m.lastIdx & 0xF];
      if ( v79->srcVer == (vertex & 0x7FFFFFFF) )
        goto LABEL_92;
      v80 = this->MonoVertices.Size >> 4;
      if ( v80 >= this->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
          this->MonoVertices.Size >> 4);
      v81 = this->MonoVertices.Pages[v80];
      v82 = this->MonoVertices.Size & 0xF;
      *(_QWORD *)&v81[v82].srcVer = v101;
      v81[v82].next = 0i64;
      v79->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
      v65->d.m.prevIdx2 = v65->d.m.prevIdx1;
      v65->d.m.prevIdx1 = v65->d.m.lastIdx;
    }
    else
    {
      v75 = this->MonoVertices.Size >> 4;
      if ( v75 >= this->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
          this->MonoVertices.Size >> 4);
      v76 = this->MonoVertices.Pages[v75];
      v77 = this->MonoVertices.Size & 0xF;
      *(_QWORD *)&v76[v77].srcVer = v101;
      v76[v77].next = 0i64;
      v78 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
      *(_QWORD *)&v65->d.t.numTriangles = -1i64;
      v65->start = v78;
    }
    v65->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_92:
    v83 = numChains;
    v9 = 0;
    v102 = 0;
    if ( !numChains )
      break;
    v84 = this->ChainsAbove.Pages;
    v85 = firstChain + 1;
    --numChains;
    vertexLeft = vertex;
    v86 = (unsigned __int64)firstChain >> 4;
    v87 = firstChain++ & 0xF;
    v6 = &v84[v86][v87];
    if ( v83 == 1 )
      vertex = vertexRight;
    else
      vertex = v84[(unsigned __int64)v85 >> 4][v85 & 0xF].vertex;
    v5 = targetVertex;
    v11 = v89;
    rightAbove = v6->chain->rightAbove;
    style = rightAbove;
  }
  upperBase->numChains = 0;
}

// File Line: 1282
// RVA: 0x9D9630
void __fastcall Scaleform::Render::Tessellator::connectStartingToPending(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        Scaleform::Render::Tessellator::BaseLineType *upperBase)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // rax
  Scaleform::Render::Tessellator::BaseLineType *lowerBase; // r10
  unsigned int v6; // ecx
  unsigned int numChains; // esi
  unsigned int v8; // r9d
  unsigned int vertexLeft; // r15d
  unsigned int v10; // r12d
  Scaleform::Render::Tessellator::PendingEndType **Pages; // rax
  Scaleform::Render::Tessellator::ScanChainType *v12; // rdi
  Scaleform::Render::Tessellator::PendingEndType *v13; // rax
  Scaleform::Render::Tessellator::ScanChainType **v14; // rdx
  unsigned int styleLeft; // r10d
  unsigned int vertex; // r11d
  Scaleform::Render::Tessellator::ScanChainType *p_scana; // r13
  unsigned int v18; // r14d
  unsigned int rightAbove; // eax
  unsigned int v20; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v21; // rdi
  unsigned __int64 v22; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v23; // rdx
  __int64 v24; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v25; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v26; // rsi
  unsigned __int64 v27; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v28; // rdx
  __int64 v29; // rcx
  unsigned __int64 v30; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v31; // rdx
  __int64 v32; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v33; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v34; // rsi
  unsigned __int64 v35; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v36; // rdx
  __int64 v37; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v38; // rdi
  unsigned __int64 v39; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v40; // rdx
  __int64 v41; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v42; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v43; // rsi
  unsigned __int64 v44; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v45; // rdx
  __int64 v46; // rcx
  unsigned __int64 v47; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v48; // rdx
  __int64 v49; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v50; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v51; // rsi
  unsigned __int64 v52; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v53; // rdx
  __int64 v54; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v55; // rdi
  unsigned __int64 v56; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v57; // rdx
  __int64 v58; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v59; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v60; // rsi
  unsigned __int64 v61; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v62; // rdx
  __int64 v63; // rcx
  unsigned __int64 v64; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v65; // rdx
  __int64 v66; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v67; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v68; // rsi
  unsigned __int64 v69; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v70; // rdx
  __int64 v71; // rcx
  Scaleform::Render::Tessellator::PendingEndType **v72; // rdx
  unsigned int v73; // r10d
  unsigned int v74; // eax
  Scaleform::Render::Tessellator::MonotoneType *v75; // rax
  unsigned int v76; // esi
  Scaleform::Render::Tessellator::ScanChainType **v77; // rdx
  unsigned int v78; // r8d
  unsigned __int64 v79; // rax
  __int64 v80; // rcx
  unsigned int v81; // r15d
  unsigned int v82; // esi
  Scaleform::Render::Tessellator::MonotoneType *v83; // r8
  Scaleform::Render::Tessellator::PendingEndType **v84; // rdx
  unsigned int v85; // eax
  Scaleform::Render::Tessellator::ScanChainType **v86; // rdx
  unsigned int v87; // r10d
  unsigned int v88; // r9d
  unsigned __int64 v89; // rax
  __int64 v90; // rcx
  Scaleform::Render::Tessellator::ScanChainType *v91; // r12
  unsigned int v92; // edx
  unsigned int v93; // edi
  Scaleform::Render::Tessellator::MonotoneType *v94; // rax
  Scaleform::Render::Tessellator::MonotoneType *started; // rax
  Scaleform::Render::Tessellator::MonotoneType *v96; // rcx
  unsigned int v97; // eax
  Scaleform::Render::Tessellator::MonotoneType *v98; // rax
  Scaleform::Render::Tessellator::MonotoneType *v99; // rdi
  unsigned __int64 v100; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v101; // rdx
  __int64 v102; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v103; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v104; // rsi
  unsigned __int64 v105; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v106; // rdx
  __int64 v107; // rcx
  unsigned __int64 v108; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v109; // rdx
  __int64 v110; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v111; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v112; // rdi
  unsigned __int64 v113; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v114; // rdx
  __int64 v115; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v116; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v117; // rsi
  unsigned __int64 v118; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v119; // rdx
  __int64 v120; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v121; // rsi
  unsigned __int64 v122; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v123; // rdx
  __int64 v124; // rcx
  unsigned int v125; // r13d
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *p_MonoVertices; // rsi
  unsigned __int64 v127; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v128; // rdx
  __int64 v129; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v130; // rsi
  unsigned __int64 v131; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v132; // rdx
  __int64 v133; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v134; // rdi
  unsigned int v135; // edx
  unsigned __int64 v136; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v137; // rdx
  __int64 v138; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v139; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v140; // rsi
  unsigned __int64 v141; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v142; // rdx
  __int64 v143; // rcx
  unsigned __int64 v144; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v145; // rdx
  __int64 v146; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v147; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v148; // rsi
  unsigned __int64 v149; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v150; // rdx
  __int64 v151; // rcx
  unsigned __int64 v152; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v153; // rdx
  __int64 v154; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v155; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v156; // rsi
  unsigned __int64 v157; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v158; // rdx
  __int64 v159; // rcx
  bool v160; // zf
  unsigned __int64 v161; // r14
  __int64 v162; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v163; // rsi
  unsigned __int64 v164; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v165; // rdx
  __int64 v166; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v167; // rdi
  unsigned int v168; // r14d
  unsigned __int64 v169; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v170; // rdx
  __int64 v171; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v172; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v173; // rsi
  unsigned __int64 v174; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v175; // rdx
  __int64 v176; // rcx
  unsigned __int64 v177; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v178; // rdx
  __int64 v179; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v180; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v181; // rsi
  unsigned __int64 v182; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v183; // rdx
  __int64 v184; // rcx
  Scaleform::Render::Tessellator::ScanChainType **v185; // rdx
  unsigned int v186; // r9d
  __int64 v187; // rcx
  Scaleform::Render::Tessellator::ScanChainType *v188; // rax
  unsigned int v189; // edx
  unsigned __int64 v190; // rax
  unsigned __int64 Size; // rax
  unsigned int v192; // [rsp+20h] [rbp-E0h]
  unsigned int v193; // [rsp+20h] [rbp-E0h]
  unsigned int v194; // [rsp+24h] [rbp-DCh]
  unsigned int v195; // [rsp+24h] [rbp-DCh]
  unsigned int v196; // [rsp+28h] [rbp-D8h]
  unsigned int v197; // [rsp+2Ch] [rbp-D4h]
  unsigned int v198; // [rsp+2Ch] [rbp-D4h]
  unsigned int v199; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Tessellator::ScanChainType *v200; // [rsp+38h] [rbp-C8h]
  Scaleform::Render::Tessellator::MonotoneType *v201; // [rsp+38h] [rbp-C8h]
  unsigned int v202; // [rsp+40h] [rbp-C0h]
  unsigned int v203; // [rsp+44h] [rbp-BCh]
  unsigned int v204; // [rsp+48h] [rbp-B8h]
  unsigned int v205; // [rsp+48h] [rbp-B8h]
  unsigned int vertexRight; // [rsp+50h] [rbp-B0h]
  unsigned int firstChain; // [rsp+58h] [rbp-A8h]
  __int64 v208; // [rsp+58h] [rbp-A8h]
  __int64 v209; // [rsp+68h] [rbp-98h]
  __int64 v210; // [rsp+68h] [rbp-98h]
  __int64 v211; // [rsp+78h] [rbp-88h]
  __int64 v212; // [rsp+78h] [rbp-88h]
  __int64 v213; // [rsp+88h] [rbp-78h]
  __int64 v214; // [rsp+88h] [rbp-78h]
  __int64 v215; // [rsp+98h] [rbp-68h]
  __int64 v216; // [rsp+98h] [rbp-68h]
  __int64 v217; // [rsp+A8h] [rbp-58h]
  __int64 v218; // [rsp+A8h] [rbp-58h]
  __int64 v219; // [rsp+B8h] [rbp-48h]
  __int64 v220; // [rsp+B8h] [rbp-48h]
  Scaleform::Render::Tessellator::ScanChainType scana; // [rsp+C8h] [rbp-38h] BYREF
  __int64 v222; // [rsp+E8h] [rbp-18h]
  Scaleform::Render::Tessellator::BaseLineType *v223; // [rsp+F8h] [rbp-8h]
  unsigned int v224; // [rsp+150h] [rbp+50h]
  unsigned int v225; // [rsp+158h] [rbp+58h]
  unsigned int v226; // [rsp+158h] [rbp+58h]
  unsigned int style; // [rsp+168h] [rbp+68h]

  monotone = scan->monotone;
  lowerBase = monotone->lowerBase;
  v6 = monotone->style;
  monotone->lowerBase = 0i64;
  numChains = upperBase->numChains;
  v8 = lowerBase->numChains;
  vertexLeft = lowerBase->vertexLeft;
  v10 = upperBase->vertexLeft;
  scana.monotone = scan->monotone;
  style = v6;
  vertexRight = lowerBase->vertexRight;
  Pages = this->PendingEnds.Pages;
  firstChain = lowerBase->firstChain;
  v12 = scan;
  v200 = scan;
  v223 = lowerBase;
  v13 = Pages[(unsigned __int64)firstChain >> 4];
  v14 = this->ChainsAbove.Pages;
  styleLeft = lowerBase->styleLeft;
  v199 = vertexLeft;
  LODWORD(scana.chain) = vertexLeft;
  vertex = v13[firstChain & 0xF].vertex;
  v204 = upperBase->firstChain;
  v203 = upperBase->vertexRight;
  v194 = v8;
  p_scana = &scana;
  v18 = v14[(unsigned __int64)v204 >> 4][v204 & 0xF].vertex;
  rightAbove = upperBase->styleLeft;
  v196 = vertex;
  v20 = v8 < numChains;
  v202 = styleLeft;
  v225 = numChains;
  v192 = v20;
LABEL_2:
  v197 = rightAbove;
  v224 = v18;
  while ( 1 )
  {
    if ( (vertexLeft != vertex || v10 != -1 && v18 != -1)
      && (v10 != v18 || vertexLeft != -1 && vertex != -1)
      && (vertexLeft != vertex || v10 != v18) )
    {
      if ( styleLeft == style )
        goto LABEL_32;
      Scaleform::Render::Tessellator::replaceMonotone(this, p_scana, style);
      v21 = p_scana->monotone;
      if ( vertexLeft != -1 )
      {
        LODWORD(v213) = vertexLeft | 0x80000000;
        HIDWORD(v213) = vertexLeft | 0x80000000;
        if ( v21->start )
        {
          v26 = &this->MonoVertices.Pages[(unsigned __int64)v21->d.m.lastIdx >> 4][v21->d.m.lastIdx & 0xF];
          if ( v26->srcVer == (vertexLeft | 0x80000000) )
            goto LABEL_22;
          v27 = this->MonoVertices.Size >> 4;
          if ( v27 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v28 = this->MonoVertices.Pages[v27];
          v29 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v28[v29].srcVer = v213;
          v28[v29].next = 0i64;
          v26->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          v21->d.m.prevIdx2 = v21->d.m.prevIdx1;
          v21->d.m.prevIdx1 = v21->d.m.lastIdx;
        }
        else
        {
          v22 = this->MonoVertices.Size >> 4;
          if ( v22 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v23 = this->MonoVertices.Pages[v22];
          v24 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v23[v24].srcVer = v213;
          v23[v24].next = 0i64;
          v25 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v21->d.t.numTriangles = -1i64;
          v21->start = v25;
        }
        v21->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
      }
LABEL_22:
      if ( v196 == -1 )
        goto LABEL_32;
      LODWORD(v219) = v196 & 0x7FFFFFFF;
      HIDWORD(v219) = v196 & 0x7FFFFFFF;
      if ( v21->start )
      {
        v34 = &this->MonoVertices.Pages[(unsigned __int64)v21->d.m.lastIdx >> 4][v21->d.m.lastIdx & 0xF];
        if ( v34->srcVer == (v196 & 0x7FFFFFFF) )
          goto LABEL_32;
        v35 = this->MonoVertices.Size >> 4;
        if ( v35 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v36 = this->MonoVertices.Pages[v35];
        v37 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v36[v37].srcVer = v219;
        v36[v37].next = 0i64;
        v34->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v21->d.m.prevIdx2 = v21->d.m.prevIdx1;
        v21->d.m.prevIdx1 = v21->d.m.lastIdx;
      }
      else
      {
        v30 = this->MonoVertices.Size >> 4;
        if ( v30 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v31 = this->MonoVertices.Pages[v30];
        v32 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v31[v32].srcVer = v219;
        v31[v32].next = 0i64;
        v33 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v21->d.t.numTriangles = -1i64;
        v21->start = v33;
      }
      v21->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_32:
      v38 = p_scana->monotone;
      if ( v10 == -1 )
        goto LABEL_42;
      LODWORD(v217) = v10 | 0x80000000;
      HIDWORD(v217) = v10 | 0x80000000;
      if ( v38->start )
      {
        v43 = &this->MonoVertices.Pages[(unsigned __int64)v38->d.m.lastIdx >> 4][v38->d.m.lastIdx & 0xF];
        if ( v43->srcVer == (v10 | 0x80000000) )
          goto LABEL_42;
        v44 = this->MonoVertices.Size >> 4;
        if ( v44 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v45 = this->MonoVertices.Pages[v44];
        v46 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v45[v46].srcVer = v217;
        v45[v46].next = 0i64;
        v43->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v38->d.m.prevIdx2 = v38->d.m.prevIdx1;
        v38->d.m.prevIdx1 = v38->d.m.lastIdx;
      }
      else
      {
        v39 = this->MonoVertices.Size >> 4;
        if ( v39 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v40 = this->MonoVertices.Pages[v39];
        v41 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v40[v41].srcVer = v217;
        v40[v41].next = 0i64;
        v42 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v38->d.t.numTriangles = -1i64;
        v38->start = v42;
      }
      v38->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
LABEL_42:
      v18 = v224;
      if ( v224 != -1 )
      {
        LODWORD(v209) = v224 & 0x7FFFFFFF;
        HIDWORD(v209) = v224 & 0x7FFFFFFF;
        if ( !v38->start )
        {
          v47 = this->MonoVertices.Size >> 4;
          if ( v47 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v48 = this->MonoVertices.Pages[v47];
          v49 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v48[v49].srcVer = v209;
          v48[v49].next = 0i64;
          v50 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v38->d.t.numTriangles = -1i64;
          v38->start = v50;
LABEL_51:
          v18 = v224;
          v38->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          goto LABEL_52;
        }
        v51 = &this->MonoVertices.Pages[(unsigned __int64)v38->d.m.lastIdx >> 4][v38->d.m.lastIdx & 0xF];
        if ( v51->srcVer != (v224 & 0x7FFFFFFF) )
        {
          v52 = this->MonoVertices.Size >> 4;
          if ( v52 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v53 = this->MonoVertices.Pages[v52];
          v54 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v53[v54].srcVer = v209;
          v53[v54].next = 0i64;
          v51->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          v38->d.m.prevIdx2 = v38->d.m.prevIdx1;
          v38->d.m.prevIdx1 = v38->d.m.lastIdx;
          goto LABEL_51;
        }
      }
LABEL_52:
      v12 = v200;
      v8 = v194;
      v20 = v192;
      v200->monotone = p_scana->monotone;
      rightAbove = v197;
    }
    if ( rightAbove != style || !v12->monotone )
    {
      if ( !rightAbove )
      {
        v12->monotone = 0i64;
        goto LABEL_78;
      }
      Scaleform::Render::Tessellator::replaceMonotone(this, v12, rightAbove);
      v55 = v12->monotone;
      if ( v10 != -1 )
      {
        LODWORD(v211) = v10 | 0x80000000;
        HIDWORD(v211) = v10 | 0x80000000;
        if ( !v55->start )
        {
          v56 = this->MonoVertices.Size >> 4;
          if ( v56 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v57 = this->MonoVertices.Pages[v56];
          v58 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v57[v58].srcVer = v211;
          v57[v58].next = 0i64;
          v59 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v55->d.t.numTriangles = -1i64;
          v55->start = v59;
          goto LABEL_66;
        }
        v60 = &this->MonoVertices.Pages[(unsigned __int64)v55->d.m.lastIdx >> 4][v55->d.m.lastIdx & 0xF];
        if ( v60->srcVer != (v10 | 0x80000000) )
        {
          v61 = this->MonoVertices.Size >> 4;
          if ( v61 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v62 = this->MonoVertices.Pages[v61];
          v63 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v62[v63].srcVer = v211;
          v62[v63].next = 0i64;
          v60->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          v55->d.m.prevIdx2 = v55->d.m.prevIdx1;
          v55->d.m.prevIdx1 = v55->d.m.lastIdx;
LABEL_66:
          v18 = v224;
          v55->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
        }
      }
      if ( v18 != -1 )
      {
        LODWORD(v215) = v18 & 0x7FFFFFFF;
        HIDWORD(v215) = v18 & 0x7FFFFFFF;
        if ( !v55->start )
        {
          v64 = this->MonoVertices.Size >> 4;
          if ( v64 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v65 = this->MonoVertices.Pages[v64];
          v66 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v65[v66].srcVer = v215;
          v65[v66].next = 0i64;
          v67 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v55->d.t.numTriangles = -1i64;
          v55->start = v67;
          goto LABEL_76;
        }
        v68 = &this->MonoVertices.Pages[(unsigned __int64)v55->d.m.lastIdx >> 4][v55->d.m.lastIdx & 0xF];
        if ( v68->srcVer != (v18 & 0x7FFFFFFF) )
        {
          v69 = this->MonoVertices.Size >> 4;
          if ( v69 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v70 = this->MonoVertices.Pages[v69];
          v71 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v70[v71].srcVer = v215;
          v70[v71].next = 0i64;
          v68->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          v55->d.m.prevIdx2 = v55->d.m.prevIdx1;
          v55->d.m.prevIdx1 = v55->d.m.lastIdx;
LABEL_76:
          v18 = v224;
          v55->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
        }
      }
      v20 = v192;
      v8 = v194;
      v12 = v200;
    }
LABEL_78:
    if ( v8 == v20 )
      break;
    if ( v8 )
    {
      v72 = this->PendingEnds.Pages;
      vertexLeft = v196;
      v199 = v196;
      --v8;
      v73 = firstChain + 1;
      p_scana = (Scaleform::Render::Tessellator::ScanChainType *)&v72[(unsigned __int64)firstChain >> 4][firstChain & 0xF];
      v194 = v8;
      ++firstChain;
      if ( v8 )
      {
        v74 = v72[(unsigned __int64)v73 >> 4][v73 & 0xF].vertex;
        v20 = v192;
      }
      else
      {
        v74 = vertexRight;
      }
      v196 = v74;
      v75 = p_scana->monotone;
      if ( v75 )
      {
        styleLeft = v75->style;
        v202 = styleLeft;
      }
      else
      {
        styleLeft = 0;
        v202 = 0;
      }
    }
    else
    {
      styleLeft = v202;
      vertexLeft = v199;
    }
    v76 = v225;
    rightAbove = v197;
    vertex = v196;
    if ( v225 )
    {
      v77 = this->ChainsAbove.Pages;
      v78 = v204 + 1;
      --v225;
      v10 = v18;
      v79 = (unsigned __int64)v204 >> 4;
      v80 = v204++ & 0xF;
      v12 = &v77[v79][v80];
      v200 = v12;
      if ( v76 == 1 )
        v18 = v203;
      else
        v18 = v77[(unsigned __int64)v78 >> 4][v78 & 0xF].vertex;
      v20 = v192;
      rightAbove = v12->chain->rightAbove;
      goto LABEL_2;
    }
  }
  v81 = v199;
  v82 = v199;
  if ( v196 != -1 )
    v82 = v196;
  v198 = v82;
  if ( v225 && v82 != -1 )
  {
    v83 = 0i64;
    v201 = 0i64;
    if ( v8 )
    {
      v84 = this->PendingEnds.Pages;
      v81 = v196;
      v199 = v196;
      p_scana = (Scaleform::Render::Tessellator::ScanChainType *)&v84[(unsigned __int64)firstChain >> 4][firstChain & 0xF];
      if ( v8 == 1 )
        v85 = vertexRight;
      else
        v85 = v84[(unsigned __int64)(firstChain + 1) >> 4][(firstChain + 1) & 0xF].vertex;
      v196 = v85;
    }
    v86 = this->ChainsAbove.Pages;
    v87 = v225 - 1;
    v88 = v204 + 1;
    v226 = v87;
    v89 = v204;
    v90 = v204 & 0xF;
    v205 = v204 + 1;
    v91 = &v86[v89 >> 4][v90];
    if ( v87 )
      v92 = v86[(unsigned __int64)v88 >> 4][v88 & 0xF].vertex;
    else
      v92 = v203;
    v93 = style;
    v195 = v92;
    v94 = p_scana->monotone;
    v193 = v91->chain->rightAbove;
    if ( v94 && v94->style == style )
    {
      started = Scaleform::Render::Tessellator::startMonotone(this, style);
      v87 = v226;
      v83 = started;
      *started = *p_scana->monotone;
      v201 = started;
      v96 = p_scana->monotone;
      v96->start = 0i64;
      *(_QWORD *)&v96->d.m.lastIdx = -1i64;
      v96->d.m.prevIdx2 = -1;
      v96->style = style;
      v96->lowerBase = 0i64;
    }
    v97 = v193;
    while ( v87 )
    {
      v125 = v195;
      if ( v18 != v195 )
      {
        Scaleform::Render::Tessellator::replaceMonotone(this, v91, v93);
        v134 = v91->monotone;
        v135 = v82 | 0x80000000;
        LODWORD(v220) = v82 | 0x80000000;
        HIDWORD(v220) = v82 | 0x80000000;
        if ( v134->start )
        {
          v140 = &this->MonoVertices.Pages[(unsigned __int64)v134->d.m.lastIdx >> 4][v134->d.m.lastIdx & 0xF];
          if ( v140->srcVer != v135 )
          {
            v141 = this->MonoVertices.Size >> 4;
            if ( v141 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v142 = this->MonoVertices.Pages[v141];
            v143 = this->MonoVertices.Size & 0xF;
            *(_QWORD *)&v142[v143].srcVer = v220;
            v142[v143].next = 0i64;
            ++this->MonoVertices.Size;
            v18 = v224;
            v140->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][((unsigned int)this->MonoVertices.Size
                                                                                      - 1) & 0xF];
            v134->d.m.prevIdx2 = v134->d.m.prevIdx1;
            v134->d.m.prevIdx1 = v134->d.m.lastIdx;
            v134->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          }
        }
        else
        {
          v136 = this->MonoVertices.Size >> 4;
          if ( v136 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v137 = this->MonoVertices.Pages[v136];
          v18 = v224;
          v138 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v137[v138].srcVer = v220;
          v137[v138].next = 0i64;
          v139 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v134->d.t.numTriangles = -1i64;
          v134->start = v139;
          v134->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
        }
        LODWORD(v214) = v198 & 0x7FFFFFFF;
        HIDWORD(v214) = v198 & 0x7FFFFFFF;
        if ( !v134->start )
        {
          v144 = this->MonoVertices.Size >> 4;
          if ( v144 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v145 = this->MonoVertices.Pages[v144];
          v146 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v145[v146].srcVer = v214;
          v145[v146].next = 0i64;
          v147 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v134->d.t.numTriangles = -1i64;
          v134->start = v147;
          goto LABEL_166;
        }
        v148 = &this->MonoVertices.Pages[(unsigned __int64)v134->d.m.lastIdx >> 4][v134->d.m.lastIdx & 0xF];
        if ( v148->srcVer != (v198 & 0x7FFFFFFF) )
        {
          v149 = this->MonoVertices.Size >> 4;
          if ( v149 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v150 = this->MonoVertices.Pages[v149];
          v151 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v150[v151].srcVer = v214;
          v150[v151].next = 0i64;
          v148->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          v134->d.m.prevIdx2 = v134->d.m.prevIdx1;
          v134->d.m.prevIdx1 = v134->d.m.lastIdx;
LABEL_166:
          v18 = v224;
          v134->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
        }
        v112 = v91->monotone;
        if ( v18 != -1 )
        {
          LODWORD(v208) = v18 | 0x80000000;
          HIDWORD(v208) = v18 | 0x80000000;
          if ( !v112->start )
          {
            v152 = this->MonoVertices.Size >> 4;
            if ( v152 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v153 = this->MonoVertices.Pages[v152];
            v154 = this->MonoVertices.Size & 0xF;
            *(_QWORD *)&v153[v154].srcVer = v208;
            v153[v154].next = 0i64;
            v155 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
            *(_QWORD *)&v112->d.t.numTriangles = -1i64;
            v112->start = v155;
            goto LABEL_176;
          }
          v156 = &this->MonoVertices.Pages[(unsigned __int64)v112->d.m.lastIdx >> 4][v112->d.m.lastIdx & 0xF];
          if ( v156->srcVer != (v18 | 0x80000000) )
          {
            v157 = this->MonoVertices.Size >> 4;
            if ( v157 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v158 = this->MonoVertices.Pages[v157];
            v159 = this->MonoVertices.Size & 0xF;
            *(_QWORD *)&v158[v159].srcVer = v208;
            v158[v159].next = 0i64;
            v156->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
            v112->d.m.prevIdx2 = v112->d.m.prevIdx1;
            v112->d.m.prevIdx1 = v112->d.m.lastIdx;
LABEL_176:
            v18 = v224;
            v112->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          }
        }
        if ( v195 != -1 )
        {
          v160 = v112->start == 0i64;
          scana.vertex = v195 & 0x7FFFFFFF;
          *(&scana.vertex + 1) = v195 & 0x7FFFFFFF;
          if ( v160 )
          {
            p_MonoVertices = &this->MonoVertices;
            v161 = this->MonoVertices.Size >> 4;
            if ( v161 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v128 = this->MonoVertices.Pages[v161];
            v129 = *(_QWORD *)&scana.vertex;
LABEL_182:
            v162 = p_MonoVertices->Size & 0xF;
            *(_QWORD *)&v128[v162].srcVer = v129;
            v128[v162].next = 0i64;
            v112->start = &p_MonoVertices->Pages[p_MonoVertices->Size++ >> 4][(LODWORD(p_MonoVertices->Size) - 1) & 0xF];
            *(_QWORD *)&v112->d.t.numTriangles = -1i64;
LABEL_183:
            v18 = v224;
            v112->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          }
          else
          {
            v163 = &this->MonoVertices.Pages[(unsigned __int64)v112->d.m.lastIdx >> 4][v112->d.m.lastIdx & 0xF];
            if ( v163->srcVer != (v195 & 0x7FFFFFFF) )
            {
              v164 = this->MonoVertices.Size >> 4;
              if ( v164 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v165 = this->MonoVertices.Pages[v164];
              v166 = this->MonoVertices.Size & 0xF;
              *(_QWORD *)&v165[v166].srcVer = *(_QWORD *)&scana.vertex;
              v165[v166].next = 0i64;
              v163->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size)
                                                                                    - 1) & 0xF];
              v112->d.m.prevIdx2 = v112->d.m.prevIdx1;
              v112->d.m.prevIdx1 = v112->d.m.lastIdx;
              goto LABEL_183;
            }
          }
        }
LABEL_184:
        v97 = v193;
        v87 = v226;
        v93 = style;
      }
      if ( v97 != v93 || !v91->monotone )
      {
        if ( !v97 )
        {
          v91->monotone = 0i64;
          goto LABEL_214;
        }
        Scaleform::Render::Tessellator::replaceMonotone(this, v91, v97);
        v167 = v91->monotone;
        if ( v18 != -1 )
        {
          v168 = v18 | 0x80000000;
          v160 = v167->start == 0i64;
          LODWORD(v222) = v168;
          HIDWORD(v222) = v168;
          if ( v160 )
          {
            v169 = this->MonoVertices.Size >> 4;
            if ( v169 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v170 = this->MonoVertices.Pages[v169];
            v171 = this->MonoVertices.Size & 0xF;
            *(_QWORD *)&v170[v171].srcVer = v222;
            v170[v171].next = 0i64;
            v172 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
            *(_QWORD *)&v167->d.t.numTriangles = -1i64;
            v167->start = v172;
            goto LABEL_202;
          }
          v173 = &this->MonoVertices.Pages[(unsigned __int64)v167->d.m.lastIdx >> 4][v167->d.m.lastIdx & 0xF];
          if ( v173->srcVer != v168 )
          {
            v174 = this->MonoVertices.Size >> 4;
            if ( v174 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v175 = this->MonoVertices.Pages[v174];
            v176 = this->MonoVertices.Size & 0xF;
            *(_QWORD *)&v175[v176].srcVer = v222;
            v175[v176].next = 0i64;
            v173->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
            v167->d.m.prevIdx2 = v167->d.m.prevIdx1;
            v167->d.m.prevIdx1 = v167->d.m.lastIdx;
LABEL_202:
            v167->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          }
        }
        if ( v125 != -1 )
        {
          v160 = v167->start == 0i64;
          LODWORD(scana.chain) = v125 & 0x7FFFFFFF;
          HIDWORD(scana.chain) = v125 & 0x7FFFFFFF;
          if ( v160 )
          {
            v177 = this->MonoVertices.Size >> 4;
            if ( v177 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v178 = this->MonoVertices.Pages[v177];
            v179 = this->MonoVertices.Size & 0xF;
            *(_QWORD *)&v178[v179].srcVer = scana.chain;
            v178[v179].next = 0i64;
            v180 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
            *(_QWORD *)&v167->d.t.numTriangles = -1i64;
            v167->start = v180;
            goto LABEL_212;
          }
          v181 = &this->MonoVertices.Pages[(unsigned __int64)v167->d.m.lastIdx >> 4][v167->d.m.lastIdx & 0xF];
          if ( v181->srcVer != (v125 & 0x7FFFFFFF) )
          {
            v182 = this->MonoVertices.Size >> 4;
            if ( v182 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v183 = this->MonoVertices.Pages[v182];
            v184 = this->MonoVertices.Size & 0xF;
            *(_QWORD *)&v183[v184].srcVer = scana.chain;
            v183[v184].next = 0i64;
            v181->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
            v167->d.m.prevIdx2 = v167->d.m.prevIdx1;
            v167->d.m.prevIdx1 = v167->d.m.lastIdx;
LABEL_212:
            v167->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          }
        }
        v93 = style;
        v87 = v226;
      }
LABEL_214:
      if ( !v87 )
        goto LABEL_219;
      v185 = this->ChainsAbove.Pages;
      --v87;
      v186 = v205 + 1;
      v226 = v87;
      v18 = v125;
      v187 = v205 & 0xF;
      v224 = v125;
      v188 = v185[(unsigned __int64)v205++ >> 4];
      v91 = &v188[v187];
      if ( v87 )
        v189 = v185[(unsigned __int64)v186 >> 4][v186 & 0xF].vertex;
      else
        v189 = v203;
      v83 = v201;
      v82 = v198;
      v97 = v91->chain->rightAbove;
      v81 = v199;
      v195 = v189;
      v193 = v97;
    }
    v91->monotone = v83;
    if ( !v83 )
    {
      v98 = Scaleform::Render::Tessellator::startMonotone(this, v93);
      v99 = v98;
      v91->monotone = v98;
      if ( v81 != -1 )
      {
        LODWORD(v216) = v81 | 0x80000000;
        HIDWORD(v216) = v81 | 0x80000000;
        if ( !v98->start )
        {
          v100 = this->MonoVertices.Size >> 4;
          if ( v100 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v101 = this->MonoVertices.Pages[v100];
          v102 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v101[v102].srcVer = v216;
          v101[v102].next = 0i64;
          v103 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v99->d.t.numTriangles = -1i64;
          v99->start = v103;
          goto LABEL_119;
        }
        v104 = &this->MonoVertices.Pages[(unsigned __int64)v98->d.m.lastIdx >> 4][v98->d.m.lastIdx & 0xF];
        if ( v104->srcVer != (v81 | 0x80000000) )
        {
          v105 = this->MonoVertices.Size >> 4;
          if ( v105 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v106 = this->MonoVertices.Pages[v105];
          v107 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v106[v107].srcVer = v216;
          v106[v107].next = 0i64;
          v104->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          v99->d.m.prevIdx2 = v99->d.m.prevIdx1;
          v99->d.m.prevIdx1 = v99->d.m.lastIdx;
LABEL_119:
          v99->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
        }
      }
      if ( v196 == -1 )
      {
LABEL_125:
        v18 = v224;
      }
      else
      {
        LODWORD(v212) = v196 & 0x7FFFFFFF;
        HIDWORD(v212) = v196 & 0x7FFFFFFF;
        if ( !v99->start )
        {
          v108 = this->MonoVertices.Size >> 4;
          if ( v108 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v109 = this->MonoVertices.Pages[v108];
          v110 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v109[v110].srcVer = v212;
          v109[v110].next = 0i64;
          v111 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v99->d.t.numTriangles = -1i64;
          v99->start = v111;
          v99->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          goto LABEL_125;
        }
        v117 = &this->MonoVertices.Pages[(unsigned __int64)v99->d.m.lastIdx >> 4][v99->d.m.lastIdx & 0xF];
        if ( v117->srcVer == (v196 & 0x7FFFFFFF) )
          goto LABEL_125;
        v118 = this->MonoVertices.Size >> 4;
        if ( v118 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v119 = this->MonoVertices.Pages[v118];
        v120 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v119[v120].srcVer = v212;
        v119[v120].next = 0i64;
        ++this->MonoVertices.Size;
        v18 = v224;
        v117->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][((unsigned int)this->MonoVertices.Size
                                                                                  - 1) & 0xF];
        v99->d.m.prevIdx2 = v99->d.m.prevIdx1;
        v99->d.m.prevIdx1 = v99->d.m.lastIdx;
        v99->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
      }
    }
    v112 = v91->monotone;
    if ( v18 != -1 )
    {
      LODWORD(v210) = v18 | 0x80000000;
      HIDWORD(v210) = v18 | 0x80000000;
      if ( !v112->start )
      {
        v113 = this->MonoVertices.Size >> 4;
        if ( v113 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v114 = this->MonoVertices.Pages[v113];
        v115 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v114[v115].srcVer = v210;
        v114[v115].next = 0i64;
        v116 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        *(_QWORD *)&v112->d.t.numTriangles = -1i64;
        v112->start = v116;
        goto LABEL_139;
      }
      v121 = &this->MonoVertices.Pages[(unsigned __int64)v112->d.m.lastIdx >> 4][v112->d.m.lastIdx & 0xF];
      if ( v121->srcVer != (v18 | 0x80000000) )
      {
        v122 = this->MonoVertices.Size >> 4;
        if ( v122 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v123 = this->MonoVertices.Pages[v122];
        v124 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v123[v124].srcVer = v210;
        v123[v124].next = 0i64;
        v121->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v112->d.m.prevIdx2 = v112->d.m.prevIdx1;
        v112->d.m.prevIdx1 = v112->d.m.lastIdx;
LABEL_139:
        v18 = v224;
        v112->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
      }
    }
    v125 = v195;
    if ( v195 != -1 )
    {
      LODWORD(v218) = v195 & 0x7FFFFFFF;
      HIDWORD(v218) = v195 & 0x7FFFFFFF;
      if ( !v112->start )
      {
        p_MonoVertices = &this->MonoVertices;
        v127 = this->MonoVertices.Size >> 4;
        if ( v127 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v128 = this->MonoVertices.Pages[v127];
        v129 = v218;
        goto LABEL_182;
      }
      v130 = &this->MonoVertices.Pages[(unsigned __int64)v112->d.m.lastIdx >> 4][v112->d.m.lastIdx & 0xF];
      if ( v130->srcVer != (v195 & 0x7FFFFFFF) )
      {
        v131 = this->MonoVertices.Size >> 4;
        if ( v131 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v132 = this->MonoVertices.Pages[v131];
        v133 = this->MonoVertices.Size & 0xF;
        *(_QWORD *)&v132[v133].srcVer = v218;
        v132[v133].next = 0i64;
        v130->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
        v112->d.m.prevIdx2 = v112->d.m.prevIdx1;
        v112->d.m.prevIdx1 = v112->d.m.lastIdx;
        goto LABEL_183;
      }
    }
    goto LABEL_184;
  }
LABEL_219:
  if ( v223 == &this->BaseLines.Pages[(this->BaseLines.Size - 1) >> 4][(LODWORD(this->BaseLines.Size) - 1) & 0xF] )
  {
    v190 = v223->firstChain;
    if ( v190 < this->PendingEnds.Size )
      this->PendingEnds.Size = v190;
    Size = this->BaseLines.Size;
    if ( Size )
      this->BaseLines.Size = Size - 1;
  }
  upperBase->numChains = 0;
}onoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v132 = this->MonoVertices.Pages[v131]

// File Line: 1418
// RVA: 0x9D8770
void __fastcall Scaleform::Render::Tessellator::connectStarting(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        Scaleform::Render::Tessellator::BaseLineType *upperBase)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // rax
  unsigned __int64 lastIdx; // rcx
  signed int srcVer; // ebx
  unsigned int i; // r14d
  Scaleform::Render::Tessellator::MonotoneType *v10; // rax
  unsigned __int64 v11; // rcx
  unsigned int vertexRight; // eax
  Scaleform::Render::Tessellator::MonotoneType *v13; // r12
  unsigned __int64 v14; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v15; // rcx
  __int64 v16; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v17; // r14
  unsigned __int64 v18; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v19; // rcx
  __int64 v20; // rdx
  __int64 v21; // [rsp+20h] [rbp-38h]

  if ( !scan )
    goto LABEL_35;
  monotone = scan->monotone;
  if ( !monotone )
    goto LABEL_35;
  lastIdx = monotone->d.m.lastIdx;
  if ( (_DWORD)lastIdx == -1 )
    srcVer = -1;
  else
    srcVer = this->MonoVertices.Pages[lastIdx >> 4][monotone->d.m.lastIdx & 0xF].srcVer;
  *(_QWORD *)&upperBase->vertexLeft = -1i64;
  for ( i = 0; i < 2; ++i )
  {
    if ( srcVer == -1
      || upperBase->y > this->MeshVertices.Pages[(unsigned __int64)(srcVer & 0xFFFFFFF) >> 4][srcVer & 0xF].y )
    {
      break;
    }
    if ( srcVer >= 0 )
      upperBase->vertexRight = srcVer;
    else
      upperBase->vertexLeft = srcVer & 0xFFFFFFF;
    Scaleform::Render::Tessellator::removeLastMonoVertex(this, scan->monotone);
    v10 = scan->monotone;
    v11 = v10->d.m.lastIdx;
    srcVer = (_DWORD)v11 == -1 ? -1 : this->MonoVertices.Pages[v11 >> 4][v10->d.m.lastIdx & 0xF].srcVer;
  }
  if ( scan->monotone->lowerBase )
  {
    Scaleform::Render::Tessellator::connectStartingToPending(this, scan, upperBase);
    return;
  }
  if ( srcVer == -1 )
  {
    vertexRight = upperBase->vertexRight;
    if ( vertexRight == -1 )
    {
      vertexRight = upperBase->vertexLeft;
      if ( vertexRight == -1 )
        goto LABEL_32;
      upperBase->vertexLeft = -1;
    }
    else
    {
      upperBase->vertexRight = -1;
    }
    v13 = scan->monotone;
    srcVer = vertexRight;
    LODWORD(v21) = vertexRight;
    HIDWORD(v21) = vertexRight;
    if ( v13->start )
    {
      v17 = &this->MonoVertices.Pages[(unsigned __int64)v13->d.m.lastIdx >> 4][v13->d.m.lastIdx & 0xF];
      if ( v17->srcVer == vertexRight )
        goto LABEL_32;
      v18 = this->MonoVertices.Size >> 4;
      if ( v18 >= this->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
          this->MonoVertices.Size >> 4);
      v19 = this->MonoVertices.Pages[v18];
      v20 = this->MonoVertices.Size & 0xF;
      *(_QWORD *)&v19[v20].srcVer = v21;
      v19[v20].next = 0i64;
      v17->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
      v13->d.m.prevIdx2 = v13->d.m.prevIdx1;
      v13->d.m.prevIdx1 = v13->d.m.lastIdx;
    }
    else
    {
      v14 = this->MonoVertices.Size >> 4;
      if ( v14 >= this->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
          this->MonoVertices.Size >> 4);
      v15 = this->MonoVertices.Pages[v14];
      v16 = this->MonoVertices.Size & 0xF;
      *(_QWORD *)&v15[v16].srcVer = v21;
      v15[v16].next = 0i64;
      v13->start = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
      *(_QWORD *)&v13->d.t.numTriangles = -1i64;
    }
    v13->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
  }
LABEL_32:
  if ( srcVer >= 0 )
    Scaleform::Render::Tessellator::connectStartingToRight(this, scan, upperBase, srcVer);
  else
    Scaleform::Render::Tessellator::connectStartingToLeft(this, scan, upperBase, srcVer & 0xFFFFFFF);
LABEL_35:
  upperBase->numChains = 0;
}

// File Line: 1524
// RVA: 0x9F40D0
void __fastcall Scaleform::Render::Tessellator::sweepScanbeam(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8> *aet,
        float yb)
{
  __int64 v3; // r8
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8> *v4; // r11
  unsigned __int64 i; // rdi
  Scaleform::Render::Tessellator::MonoChainType *v7; // r15
  bool v8; // zf
  unsigned __int64 v9; // r14
  Scaleform::Render::Tessellator::ScanChainType *v10; // rdx
  __int64 v11; // rax
  unsigned int v12; // r12d
  unsigned int v13; // r14d
  Scaleform::Render::Tessellator::ScanChainType *v14; // r15
  unsigned __int64 Size; // rax
  __int64 v16; // rbx
  Scaleform::Render::Tessellator::ScanChainType *v17; // rdi
  __int64 v18; // r13
  Scaleform::Render::Tessellator::MonoChainType *chain; // r8
  unsigned int posScan; // ecx
  Scaleform::Render::Tessellator::MonoChainType *v21; // rdx
  unsigned int v22; // eax
  unsigned int v23; // eax
  Scaleform::Render::Tessellator::ScanChainType *v24; // rbx
  __int64 v25; // rdi
  Scaleform::Render::Tessellator::ScanChainType *v26; // rbx
  unsigned int v27; // eax
  unsigned int v28; // r9d
  unsigned __int64 v29; // r12
  unsigned int v30; // eax
  unsigned int v31; // r10d
  Scaleform::Render::Tessellator::ScanChainType *v32; // r13
  unsigned __int64 v33; // rcx
  unsigned __int64 v34; // rax
  unsigned __int64 v35; // rdx
  __int64 v36; // rcx
  Scaleform::Render::Tessellator::ScanChainType *v37; // rax
  signed int vertex; // ebx
  Scaleform::Render::Tessellator::ScanChainType *v39; // r14
  Scaleform::Render::Tessellator::ScanChainType *v40; // rax
  signed int v41; // r8d
  Scaleform::Render::Tessellator::ScanChainType *v42; // rcx
  int v43; // eax
  int v44; // eax
  int v45; // eax
  Scaleform::Render::Tessellator::MonotoneType *v46; // rdi
  Scaleform::Render::Tessellator::BaseLineType *v47; // r8
  unsigned __int64 v48; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v49; // rcx
  __int64 v50; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v51; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v52; // r14
  unsigned __int64 v53; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v54; // rcx
  __int64 v55; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v56; // rbx
  unsigned int v57; // r8d
  Scaleform::Render::Tessellator::BaseLineType *v58; // r9
  unsigned __int64 v59; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v60; // rcx
  __int64 v61; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v62; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v63; // rdi
  unsigned __int64 v64; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v65; // rcx
  __int64 v66; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v67; // rax
  Scaleform::Render::Tessellator::MonoChainType *v68; // rax
  unsigned int leftAbove; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v70; // rax
  Scaleform::Render::Tessellator::BaseLineType *v71; // rax
  Scaleform::Render::Tessellator::MonotoneType *v72; // rbx
  Scaleform::Render::Tessellator::BaseLineType *v73; // r9
  unsigned __int64 v74; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v75; // rcx
  __int64 v76; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v77; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v78; // rdi
  unsigned __int64 v79; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v80; // rcx
  __int64 v81; // rdx
  Scaleform::Render::Tessellator::MonotoneType *monotone; // rdi
  Scaleform::Render::Tessellator::BaseLineType *lowerBase; // r8
  unsigned __int64 v84; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v85; // rcx
  __int64 v86; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v87; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v88; // r14
  unsigned __int64 v89; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v90; // rcx
  __int64 v91; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v92; // rdi
  Scaleform::Render::Tessellator::BaseLineType *v93; // r8
  unsigned __int64 v94; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v95; // rcx
  __int64 v96; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v97; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v98; // r14
  unsigned __int64 v99; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v100; // rcx
  __int64 v101; // rdx
  unsigned int v102; // r14d
  unsigned int v103; // edi
  unsigned int v104; // r10d
  unsigned int v105; // r11d
  Scaleform::Render::Tessellator::ScanChainType *v106; // r13
  Scaleform::Render::Tessellator::ScanChainType *v107; // r9
  Scaleform::Render::Tessellator::ScanChainType *v108; // r8
  Scaleform::Render::Tessellator::ScanChainType *v109; // r13
  Scaleform::Render::Tessellator::ScanChainType *v110; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v111; // rdi
  Scaleform::Render::Tessellator::BaseLineType *v112; // r8
  unsigned __int64 v113; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v114; // rcx
  __int64 v115; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v116; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v117; // r14
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *p_MonoVertices; // r15
  unsigned __int64 v119; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v120; // rcx
  __int64 v121; // rax
  Scaleform::Render::Tessellator::ScanChainType *v122; // r15
  unsigned int v123; // r8d
  Scaleform::Render::Tessellator::MonotoneType *v124; // rdi
  Scaleform::Render::Tessellator::BaseLineType *v125; // r9
  unsigned __int64 v126; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v127; // rcx
  __int64 v128; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v129; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v130; // r14
  unsigned __int64 v131; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v132; // rcx
  __int64 v133; // rdx
  Scaleform::Render::Tessellator::BaseLineType *v134; // r8
  unsigned __int64 v135; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v136; // rcx
  __int64 v137; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v138; // rdx
  unsigned __int64 v139; // r12
  __int64 v140; // rdx
  unsigned int v141; // edi
  Scaleform::Render::Tessellator::MonotoneType *v142; // r14
  Scaleform::Render::Tessellator::BaseLineType *v143; // r8
  unsigned __int64 v144; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v145; // rcx
  __int64 v146; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v147; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v148; // r15
  unsigned __int64 v149; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v150; // rcx
  __int64 v151; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v152; // rdi
  Scaleform::Render::Tessellator::BaseLineType *v153; // r8
  unsigned __int64 v154; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v155; // rcx
  __int64 v156; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v157; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v158; // r14
  unsigned __int64 v159; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v160; // rcx
  __int64 v161; // rdx
  Scaleform::Render::Tessellator::ScanChainType *v162; // rcx
  Scaleform::Render::Tessellator::ScanChainType *v163; // rax
  signed int v164; // r8d
  Scaleform::Render::Tessellator::MonotoneType *v165; // rbx
  Scaleform::Render::Tessellator::BaseLineType *v166; // r9
  unsigned __int64 v167; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v168; // rcx
  __int64 v169; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v170; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v171; // rdi
  unsigned __int64 v172; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v173; // rcx
  __int64 v174; // rdx
  unsigned __int64 v175; // rdx
  __int64 v176; // rcx
  Scaleform::Render::Tessellator::ScanChainType *v177; // rax
  signed int v178; // r8d
  Scaleform::Render::Tessellator::ScanChainType *v179; // r13
  Scaleform::Render::Tessellator::MonotoneType *v180; // rbx
  Scaleform::Render::Tessellator::BaseLineType *v181; // r9
  unsigned __int64 v182; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v183; // rcx
  __int64 v184; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v185; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v186; // rdi
  unsigned __int64 v187; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v188; // rcx
  __int64 v189; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v190; // rbx
  unsigned int v191; // r8d
  Scaleform::Render::Tessellator::BaseLineType *v192; // r9
  unsigned __int64 v193; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v194; // rcx
  __int64 v195; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v196; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v197; // rdi
  unsigned __int64 v198; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v199; // rcx
  __int64 v200; // rdx
  unsigned __int64 v201; // r14
  unsigned __int64 v202; // rdi
  __int64 v203; // r15
  Scaleform::Render::Tessellator::ScanChainType *v204; // r12
  Scaleform::Render::Tessellator::ScanChainType *v205; // rdx
  __int64 v206; // r8
  unsigned __int64 v207; // rdx
  unsigned __int64 v208; // rcx
  Scaleform::Render::Tessellator::MonoChainType *v209; // rdx
  unsigned __int16 v210; // ax
  unsigned int v211; // [rsp+20h] [rbp-E0h]
  Scaleform::Render::Tessellator::ScanChainType *v212; // [rsp+28h] [rbp-D8h]
  Scaleform::Render::Tessellator::ScanChainType *dst; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Tessellator::ScanChainType *scan; // [rsp+38h] [rbp-C8h]
  Scaleform::Render::Tessellator::BaseLineType upperBase; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v216; // [rsp+60h] [rbp-A0h]
  __int64 v217; // [rsp+70h] [rbp-90h]
  __int64 v218; // [rsp+80h] [rbp-80h]
  __int64 v219; // [rsp+90h] [rbp-70h]
  __int64 v220; // [rsp+A0h] [rbp-60h]
  __int64 v221; // [rsp+B0h] [rbp-50h]
  __int64 v222; // [rsp+C0h] [rbp-40h]
  __int64 v223; // [rsp+D0h] [rbp-30h]
  __int64 v224; // [rsp+E0h] [rbp-20h]
  __int64 v225; // [rsp+F0h] [rbp-10h]
  __int64 v226; // [rsp+100h] [rbp+0h]
  __int64 v227; // [rsp+110h] [rbp+10h]
  __int64 v228; // [rsp+118h] [rbp+18h]
  __int64 v229; // [rsp+128h] [rbp+28h]
  Scaleform::Render::Tessellator::ScanChainType *v230; // [rsp+1A0h] [rbp+A0h]
  unsigned int v231; // [rsp+1A0h] [rbp+A0h]
  unsigned int v233; // [rsp+1B0h] [rbp+B0h]
  int v234; // [rsp+1B8h] [rbp+B8h]
  unsigned int v235; // [rsp+1B8h] [rbp+B8h]

  this->LastX = -1.0e30;
  this->ChainsAbove.Size = 0i64;
  v4 = aet;
  for ( i = 0i64; i < v4->Size; ++i )
  {
    v7 = v4->Pages[i >> 4][i & 0xF];
    v8 = (v7->flags & 4) == 0;
    v7->posScan = i;
    if ( !v8 )
    {
      LODWORD(v227) = -1;
      v9 = this->ChainsAbove.Size >> 4;
      if ( v9 >= this->ChainsAbove.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::ScanChainType,4,8>::allocPage(
          &this->ChainsAbove,
          this->ChainsAbove.Size >> 4);
        v4 = aet;
      }
      v10 = this->ChainsAbove.Pages[v9];
      v3 = 3i64 * (this->ChainsAbove.Size & 0xF);
      v11 = v227;
      *((_QWORD *)&v10->chain + v3) = v7;
      *((_QWORD *)&v10->monotone + v3) = 0i64;
      *((_QWORD *)&v10->vertex + v3) = v11;
      ++this->ChainsAbove.Size;
    }
  }
  upperBase.y = yb;
  v12 = 0;
  v13 = 0;
  v234 = -1;
  v14 = 0i64;
  dst = 0i64;
  upperBase.numChains = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        Size = this->ChainsBelow.Size;
        if ( v12 >= Size || v13 >= this->ChainsAbove.Size )
          break;
        v16 = v12 & 0xF;
        v17 = this->ChainsBelow.Pages[(unsigned __int64)v12 >> 4];
        v18 = v13 & 0xF;
        chain = v17[v12 & 0xF].chain;
        posScan = chain->posScan;
        v21 = this->ChainsAbove.Pages[(unsigned __int64)v13 >> 4][v13 & 0xF].chain;
        v230 = this->ChainsAbove.Pages[(unsigned __int64)v13 >> 4];
        v22 = v21->posScan;
        if ( v22 == posScan )
        {
          v23 = Scaleform::Render::Tessellator::addEventVertex(this, v21, yb, 0);
          ++v12;
          v230[v13 & 0xF].vertex = v23;
          v17[v16].vertex = v23;
          ++v13;
        }
        else if ( v22 >= posScan )
        {
          ++v12;
          v17[v16].vertex = Scaleform::Render::Tessellator::addEventVertex(this, chain, yb, 1);
        }
        else
        {
          ++v13;
          v230[v18].vertex = Scaleform::Render::Tessellator::addEventVertex(this, v21, yb, 1);
        }
      }
      LODWORD(v3) = v13;
      if ( v13 >= this->ChainsAbove.Size )
        break;
      v24 = this->ChainsAbove.Pages[(unsigned __int64)v13++ >> 4];
      v24[v3].vertex = Scaleform::Render::Tessellator::addEventVertex(this, v24[v3 & 0xF].chain, yb, 1);
    }
    if ( v12 >= Size )
      break;
    v25 = v12 & 0xF;
    v26 = this->ChainsBelow.Pages[(unsigned __int64)v12 >> 4];
    v27 = Scaleform::Render::Tessellator::addEventVertex(this, v26[v12++ & 0xF].chain, yb, 1);
    v26[v25].vertex = v27;
  }
  v28 = -1;
  v29 = 0i64;
  v30 = 0;
  v31 = 0;
  v233 = 0;
  v32 = 0i64;
LABEL_20:
  while ( 2 )
  {
    v231 = v30;
    while ( 1 )
    {
      while ( 1 )
      {
        v33 = v30;
        v34 = this->ChainsBelow.Size;
        if ( v33 >= v34 || v31 >= this->ChainsAbove.Size )
          break;
        v35 = (unsigned int)v33;
        v36 = v33 & 0xF;
        v37 = this->ChainsBelow.Pages[v35 >> 4];
        vertex = v37[v36].vertex;
        v39 = &v37[v36];
        v212 = v39;
        v40 = this->ChainsAbove.Pages[(unsigned __int64)v31 >> 4];
        v41 = v40[v31 & 0xF].vertex;
        v42 = &v40[v31 & 0xF];
        v43 = 1;
        scan = v42;
        if ( vertex != v41 )
          v43 = 3 - (v42->chain->posScan < v39->chain->posScan);
        v44 = v43 - 1;
        if ( !v44 )
        {
          if ( vertex == -1 )
          {
            if ( upperBase.numChains )
            {
              Scaleform::Render::Tessellator::connectStarting(this, v14, &upperBase);
              v31 = v233;
            }
            v106 = v39;
LABEL_235:
            v162 = scan;
            scan->monotone = v106->monotone;
            goto LABEL_236;
          }
          if ( v14 )
          {
            monotone = v14->monotone;
            if ( monotone )
            {
              lowerBase = monotone->lowerBase;
              if ( !lowerBase )
              {
                v8 = monotone->start == 0i64;
                LODWORD(v219) = vertex;
                HIDWORD(v219) = vertex;
                if ( v8 )
                {
                  v84 = this->MonoVertices.Size >> 4;
                  if ( v84 >= this->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                      this->MonoVertices.Size >> 4);
                  v85 = this->MonoVertices.Pages[v84];
                  v86 = this->MonoVertices.Size & 0xF;
                  v29 = 0i64;
                  *(_QWORD *)&v85[v86].srcVer = v219;
                  v85[v86].next = 0i64;
                  v87 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
                  *(_QWORD *)&monotone->d.t.numTriangles = -1i64;
                  monotone->start = v87;
                }
                else
                {
                  v88 = &this->MonoVertices.Pages[(unsigned __int64)monotone->d.m.lastIdx >> 4][monotone->d.m.lastIdx & 0xF];
                  if ( v88->srcVer == vertex )
                    goto LABEL_111;
                  v89 = this->MonoVertices.Size >> 4;
                  if ( v89 >= this->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                      this->MonoVertices.Size >> 4);
                  v90 = this->MonoVertices.Pages[v89];
                  v91 = this->MonoVertices.Size & 0xF;
                  v29 = 0i64;
                  *(_QWORD *)&v90[v91].srcVer = v219;
                  v90[v91].next = 0i64;
                  ++this->MonoVertices.Size;
                  v32 = dst;
                  v88->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][((unsigned int)this->MonoVertices.Size
                                                                                           - 1) & 0xF];
                  monotone->d.m.prevIdx2 = monotone->d.m.prevIdx1;
                  monotone->d.m.prevIdx1 = monotone->d.m.lastIdx;
                }
                monotone->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
                goto LABEL_111;
              }
              if ( this->MeshVertices.Pages[(unsigned __int64)(vertex & 0xFFFFFFF) >> 4][vertex & 0xF].y == lowerBase->y )
              {
                lowerBase->vertexRight = vertex & 0xFFFFFFF;
              }
              else if ( vertex >= 0 )
              {
                Scaleform::Render::Tessellator::connectPendingToRight(this, v14, vertex);
              }
              else
              {
                Scaleform::Render::Tessellator::connectPendingToLeft(this, v14, vertex);
              }
            }
          }
LABEL_111:
          if ( v32 )
          {
            v92 = v32->monotone;
            if ( v92 )
            {
              v93 = v92->lowerBase;
              if ( v93 )
              {
                if ( this->MeshVertices.Pages[(unsigned __int64)(vertex & 0xFFFFFFF) >> 4][vertex & 0xF].y == v93->y )
                {
                  v93->vertexRight = vertex & 0xFFFFFFF;
                }
                else if ( vertex >= 0 )
                {
                  Scaleform::Render::Tessellator::connectPendingToRight(this, v32, vertex);
                }
                else
                {
                  Scaleform::Render::Tessellator::connectPendingToLeft(this, v32, vertex);
                }
                goto LABEL_128;
              }
              v8 = v92->start == 0i64;
              LODWORD(v216) = vertex;
              HIDWORD(v216) = vertex;
              if ( v8 )
              {
                v94 = this->MonoVertices.Size >> 4;
                if ( v94 >= this->MonoVertices.NumPages )
                  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                    (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                    this->MonoVertices.Size >> 4);
                v95 = this->MonoVertices.Pages[v94];
                v96 = this->MonoVertices.Size & 0xF;
                v29 = 0i64;
                *(_QWORD *)&v95[v96].srcVer = v216;
                v95[v96].next = 0i64;
                v97 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
                *(_QWORD *)&v92->d.t.numTriangles = -1i64;
                v92->start = v97;
                goto LABEL_127;
              }
              v98 = &this->MonoVertices.Pages[(unsigned __int64)v92->d.m.lastIdx >> 4][v92->d.m.lastIdx & 0xF];
              if ( v98->srcVer != vertex )
              {
                v99 = this->MonoVertices.Size >> 4;
                if ( v99 >= this->MonoVertices.NumPages )
                  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                    (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                    this->MonoVertices.Size >> 4);
                v100 = this->MonoVertices.Pages[v99];
                v101 = this->MonoVertices.Size & 0xF;
                v29 = 0i64;
                *(_QWORD *)&v100[v101].srcVer = v216;
                v100[v101].next = 0i64;
                v98->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size)
                                                                                     - 1) & 0xF];
                v92->d.m.prevIdx2 = v92->d.m.prevIdx1;
                v92->d.m.prevIdx1 = v92->d.m.lastIdx;
LABEL_127:
                v92->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
              }
            }
          }
LABEL_128:
          if ( upperBase.numChains )
            Scaleform::Render::Tessellator::connectStarting(this, v14, &upperBase);
          v102 = v231;
          v103 = v233;
          v104 = v231 + 1;
          v105 = v233 + 1;
          v235 = v231 + 1;
          v211 = v233 + 1;
          while ( 2 )
          {
            v106 = v212;
LABEL_135:
            v107 = 0i64;
            v108 = 0i64;
            if ( v104 < this->ChainsBelow.Size )
              v107 = &this->ChainsBelow.Pages[(unsigned __int64)v104 >> 4][v104 & 0xF];
            if ( v105 < this->ChainsAbove.Size )
              v108 = &this->ChainsAbove.Pages[(unsigned __int64)v105 >> 4][v105 & 0xF];
            if ( v107 )
            {
              if ( v108 )
              {
                if ( v107->vertex == v108->vertex )
                  goto LABEL_197;
                goto LABEL_142;
              }
            }
            else
            {
LABEL_142:
              if ( v108 && v108->vertex == vertex )
              {
                ++v103;
                v109 = scan;
                dst = scan;
                v233 = v103;
                v211 = v105 + 1;
                v110 = scan;
                scan = &this->ChainsAbove.Pages[(unsigned __int64)v103 >> 4][v103 & 0xF];
                Scaleform::Render::Tessellator::startMonotone(this, v110, vertex | 0x80000000);
                v104 = v235;
                v105 = v211;
                if ( !v109 )
                  continue;
                v111 = v109->monotone;
                if ( v111 )
                {
                  v112 = v111->lowerBase;
                  if ( v112 )
                  {
                    if ( this->MeshVertices.Pages[(unsigned __int64)(vertex & 0xFFFFFFF) >> 4][vertex & 0xF].y == v112->y )
                    {
                      v106 = v212;
                      v112->vertexRight = vertex & 0xFFFFFFF;
                    }
                    else
                    {
                      if ( vertex >= 0 )
                        Scaleform::Render::Tessellator::connectPendingToRight(this, v109, vertex);
                      else
                        Scaleform::Render::Tessellator::connectPendingToLeft(this, v109, vertex);
                      v106 = v212;
                      v104 = v235;
                      v105 = v211;
                    }
                    goto LABEL_134;
                  }
                  v8 = v111->start == 0i64;
                  LODWORD(v221) = vertex;
                  HIDWORD(v221) = vertex;
                  if ( v8 )
                  {
                    v113 = this->MonoVertices.Size >> 4;
                    if ( v113 >= this->MonoVertices.NumPages )
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                        this->MonoVertices.Size >> 4);
                    v106 = v212;
                    v114 = this->MonoVertices.Pages[v113];
                    v115 = this->MonoVertices.Size & 0xF;
                    *(_QWORD *)&v114[v115].srcVer = v221;
                    v114[v115].next = 0i64;
                    v116 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size)
                                                                                    - 1) & 0xF];
                    *(_QWORD *)&v111->d.t.numTriangles = -1i64;
                    v111->start = v116;
                    goto LABEL_196;
                  }
                  v106 = v212;
                  v117 = &this->MonoVertices.Pages[(unsigned __int64)v111->d.m.lastIdx >> 4][v111->d.m.lastIdx & 0xF];
                  if ( v117->srcVer != vertex )
                  {
                    p_MonoVertices = &this->MonoVertices;
                    v119 = this->MonoVertices.Size >> 4;
                    if ( v119 >= this->MonoVertices.NumPages )
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                        this->MonoVertices.Size >> 4);
                    v120 = this->MonoVertices.Pages[v119];
                    v121 = v221;
LABEL_195:
                    v29 = 0i64;
                    v140 = p_MonoVertices->Size & 0xF;
                    *(_QWORD *)&v120[v140].srcVer = v121;
                    v120[v140].next = 0i64;
                    v117->next = &p_MonoVertices->Pages[p_MonoVertices->Size++ >> 4][(LODWORD(p_MonoVertices->Size) - 1) & 0xF];
                    v111->d.m.prevIdx2 = v111->d.m.prevIdx1;
                    v111->d.m.prevIdx1 = v111->d.m.lastIdx;
                    goto LABEL_196;
                  }
                  goto LABEL_133;
                }
                v106 = v212;
                goto LABEL_134;
              }
            }
            break;
          }
          if ( v107 && v107->vertex == vertex )
          {
            ++v102;
            v122 = v106;
            ++v104;
            v231 = v102;
            v235 = v104;
            v106 = &this->ChainsBelow.Pages[(unsigned __int64)v102 >> 4][v102 & 0xF];
            v212 = v106;
            v123 = vertex | 0x80000000;
            if ( !v122 )
              goto LABEL_135;
            v124 = v122->monotone;
            if ( !v124 )
            {
LABEL_179:
              v111 = v122->monotone;
              v104 = v235;
              v105 = v211;
              if ( v111 )
              {
                v134 = v111->lowerBase;
                if ( v134 )
                {
                  if ( this->MeshVertices.Pages[(unsigned __int64)(vertex & 0xFFFFFFF) >> 4][vertex & 0xF].y == v134->y )
                  {
                    v134->vertexRight = vertex & 0xFFFFFFF;
                  }
                  else
                  {
                    if ( vertex >= 0 )
                      Scaleform::Render::Tessellator::connectPendingToRight(this, v122, vertex);
                    else
                      Scaleform::Render::Tessellator::connectPendingToLeft(this, v122, vertex);
                    v104 = v235;
                    v105 = v211;
                  }
                  goto LABEL_134;
                }
                v8 = v111->start == 0i64;
                LODWORD(v217) = vertex;
                HIDWORD(v217) = vertex;
                if ( v8 )
                {
                  v135 = this->MonoVertices.Size >> 4;
                  if ( v135 >= this->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                      this->MonoVertices.Size >> 4);
                  v136 = this->MonoVertices.Pages[v135];
                  v137 = this->MonoVertices.Size & 0xF;
                  *(_QWORD *)&v136[v137].srcVer = v217;
                  v136[v137].next = 0i64;
                  v138 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
                  *(_QWORD *)&v111->d.t.numTriangles = -1i64;
                  v111->start = v138;
LABEL_196:
                  v104 = v235;
                  v105 = v211;
                  v111->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
                }
                else
                {
                  v117 = &this->MonoVertices.Pages[(unsigned __int64)v111->d.m.lastIdx >> 4][v111->d.m.lastIdx & 0xF];
                  if ( v117->srcVer != vertex )
                  {
                    p_MonoVertices = &this->MonoVertices;
                    v139 = this->MonoVertices.Size >> 4;
                    if ( v139 >= this->MonoVertices.NumPages )
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                        this->MonoVertices.Size >> 4);
                    v120 = this->MonoVertices.Pages[v139];
                    v121 = v217;
                    goto LABEL_195;
                  }
                }
LABEL_133:
                v102 = v231;
              }
LABEL_134:
              v103 = v233;
              goto LABEL_135;
            }
            v125 = v124->lowerBase;
            if ( v125 )
            {
              if ( this->MeshVertices.Pages[(unsigned __int64)(vertex & 0xFFFFFFF) >> 4][vertex & 0xF].y == v125->y )
                v125->vertexRight = vertex & 0xFFFFFFF;
              else
                Scaleform::Render::Tessellator::connectPendingToLeft(this, v122, v123);
              goto LABEL_179;
            }
            v8 = v124->start == 0i64;
            LODWORD(v225) = vertex | 0x80000000;
            HIDWORD(v225) = vertex | 0x80000000;
            if ( v8 )
            {
              v126 = this->MonoVertices.Size >> 4;
              if ( v126 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v127 = this->MonoVertices.Pages[v126];
              v128 = this->MonoVertices.Size & 0xF;
              v29 = 0i64;
              *(_QWORD *)&v127[v128].srcVer = v225;
              v127[v128].next = 0i64;
              v129 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
              *(_QWORD *)&v124->d.t.numTriangles = -1i64;
              v124->start = v129;
              goto LABEL_177;
            }
            v130 = &this->MonoVertices.Pages[(unsigned __int64)v124->d.m.lastIdx >> 4][v124->d.m.lastIdx & 0xF];
            if ( v130->srcVer != v123 )
            {
              v131 = this->MonoVertices.Size >> 4;
              if ( v131 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v132 = this->MonoVertices.Pages[v131];
              v133 = this->MonoVertices.Size & 0xF;
              v29 = 0i64;
              *(_QWORD *)&v132[v133].srcVer = v225;
              v132[v133].next = 0i64;
              ++this->MonoVertices.Size;
              v130->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][((unsigned int)this->MonoVertices.Size
                                                                                        - 1) & 0xF];
              v124->d.m.prevIdx2 = v124->d.m.prevIdx1;
              v124->d.m.prevIdx1 = v124->d.m.lastIdx;
LABEL_177:
              v124->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
            }
            v102 = v231;
            goto LABEL_179;
          }
LABEL_197:
          v141 = vertex | 0x80000000;
          if ( v106 )
          {
            v142 = v106->monotone;
            if ( v142 )
            {
              v143 = v142->lowerBase;
              if ( v143 )
              {
                if ( this->MeshVertices.Pages[(unsigned __int64)(vertex & 0xFFFFFFF) >> 4][vertex & 0xF].y == v143->y )
                  v143->vertexRight = vertex & 0xFFFFFFF;
                else
                  Scaleform::Render::Tessellator::connectPendingToLeft(this, v106, v141);
              }
              else
              {
                v8 = v142->start == 0i64;
                LODWORD(v218) = vertex | 0x80000000;
                HIDWORD(v218) = vertex | 0x80000000;
                if ( v8 )
                {
                  v144 = this->MonoVertices.Size >> 4;
                  if ( v144 >= this->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                      this->MonoVertices.Size >> 4);
                  v145 = this->MonoVertices.Pages[v144];
                  v146 = this->MonoVertices.Size & 0xF;
                  v29 = 0i64;
                  *(_QWORD *)&v145[v146].srcVer = v218;
                  v145[v146].next = 0i64;
                  v147 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
                  *(_QWORD *)&v142->d.t.numTriangles = -1i64;
                  v142->start = v147;
                }
                else
                {
                  v148 = &this->MonoVertices.Pages[(unsigned __int64)v142->d.m.lastIdx >> 4][v142->d.m.lastIdx & 0xF];
                  if ( v148->srcVer == v141 )
                    goto LABEL_212;
                  v149 = this->MonoVertices.Size >> 4;
                  if ( v149 >= this->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                      this->MonoVertices.Size >> 4);
                  v150 = this->MonoVertices.Pages[v149];
                  v151 = this->MonoVertices.Size & 0xF;
                  v29 = 0i64;
                  *(_QWORD *)&v150[v151].srcVer = v218;
                  v150[v151].next = 0i64;
                  ++this->MonoVertices.Size;
                  v106 = v212;
                  v148->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][((unsigned int)this->MonoVertices.Size
                                                                                            - 1) & 0xF];
                  v142->d.m.prevIdx2 = v142->d.m.prevIdx1;
                  v142->d.m.prevIdx1 = v142->d.m.lastIdx;
                }
                v142->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
              }
            }
          }
LABEL_212:
          if ( v106->chain->rightBelow == scan->chain->rightAbove )
          {
            if ( dst )
            {
              v152 = dst->monotone;
              if ( v152 )
              {
                v153 = v152->lowerBase;
                if ( v153 )
                {
                  if ( this->MeshVertices.Pages[(unsigned __int64)(vertex & 0xFFFFFFF) >> 4][vertex & 0xF].y == v153->y )
                  {
                    v31 = v233;
                    v153->vertexRight = vertex & 0xFFFFFFF;
                  }
                  else
                  {
                    if ( vertex >= 0 )
                      Scaleform::Render::Tessellator::connectPendingToRight(this, dst, vertex);
                    else
                      Scaleform::Render::Tessellator::connectPendingToLeft(this, dst, vertex);
                    v31 = v233;
                  }
                  goto LABEL_235;
                }
                v8 = v152->start == 0i64;
                LODWORD(v220) = vertex;
                HIDWORD(v220) = vertex;
                if ( v8 )
                {
                  v154 = this->MonoVertices.Size >> 4;
                  if ( v154 >= this->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                      this->MonoVertices.Size >> 4);
                  v31 = v233;
                  v155 = this->MonoVertices.Pages[v154];
                  v156 = this->MonoVertices.Size & 0xF;
                  *(_QWORD *)&v155[v156].srcVer = v220;
                  v155[v156].next = 0i64;
                  v157 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
                  *(_QWORD *)&v152->d.t.numTriangles = -1i64;
                  v152->start = v157;
                  v152->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
                  goto LABEL_235;
                }
                v158 = &this->MonoVertices.Pages[(unsigned __int64)v152->d.m.lastIdx >> 4][v152->d.m.lastIdx & 0xF];
                if ( v158->srcVer != vertex )
                {
                  v159 = this->MonoVertices.Size >> 4;
                  if ( v159 >= this->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                      this->MonoVertices.Size >> 4);
                  v160 = this->MonoVertices.Pages[v159];
                  v161 = this->MonoVertices.Size & 0xF;
                  *(_QWORD *)&v160[v161].srcVer = v220;
                  v160[v161].next = 0i64;
                  v158->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size)
                                                                                        - 1) & 0xF];
                  v152->d.m.prevIdx2 = v152->d.m.prevIdx1;
                  v152->d.m.prevIdx1 = v152->d.m.lastIdx;
                  v152->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
                }
              }
            }
            v31 = v233;
            goto LABEL_235;
          }
          Scaleform::Render::Tessellator::startMonotone(this, scan, v141);
          v162 = scan;
          v31 = v233;
LABEL_236:
          v28 = v31;
          v234 = v31;
          v30 = v231 + 1;
          ++v31;
          v14 = v106;
          v233 = v31;
          v32 = v162;
          dst = v162;
          goto LABEL_20;
        }
        v45 = v44 - 1;
        if ( v45 )
        {
          v8 = v45 == 1;
          v30 = v231;
          if ( v8 )
          {
            if ( !v14 || (v46 = v14->monotone) == 0i64 )
            {
LABEL_46:
              v56 = v39->monotone;
              v57 = v39->vertex | 0x80000000;
              if ( v56 )
              {
                v58 = v56->lowerBase;
                if ( v58 )
                {
                  if ( this->MeshVertices.Pages[(unsigned __int64)(v39->vertex & 0xFFFFFFF) >> 4][v39->vertex & 0xF].y == v58->y )
                    v58->vertexRight = v39->vertex & 0xFFFFFFF;
                  else
                    Scaleform::Render::Tessellator::connectPendingToLeft(this, v39, v57);
                  goto LABEL_60;
                }
                v8 = v56->start == 0i64;
                LODWORD(v229) = v39->vertex | 0x80000000;
                HIDWORD(v229) = v57;
                if ( v8 )
                {
                  v59 = this->MonoVertices.Size >> 4;
                  if ( v59 >= this->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                      this->MonoVertices.Size >> 4);
                  v60 = this->MonoVertices.Pages[v59];
                  v61 = this->MonoVertices.Size & 0xF;
                  *(_QWORD *)&v60[v61].srcVer = v229;
                  v60[v61].next = 0i64;
                  v62 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
                  *(_QWORD *)&v56->d.t.numTriangles = -1i64;
                  v56->start = v62;
LABEL_59:
                  v39 = v212;
                  v56->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
                  goto LABEL_60;
                }
                v63 = &this->MonoVertices.Pages[(unsigned __int64)v56->d.m.lastIdx >> 4][v56->d.m.lastIdx & 0xF];
                if ( v63->srcVer != v57 )
                {
                  v64 = this->MonoVertices.Size >> 4;
                  if ( v64 >= this->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                      this->MonoVertices.Size >> 4);
                  v65 = this->MonoVertices.Pages[v64];
                  v66 = this->MonoVertices.Size & 0xF;
                  v29 = 0i64;
                  *(_QWORD *)&v65[v66].srcVer = v229;
                  v65[v66].next = 0i64;
                  v63->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size)
                                                                                       - 1) & 0xF];
                  v56->d.m.prevIdx2 = v56->d.m.prevIdx1;
                  v56->d.m.prevIdx1 = v56->d.m.lastIdx;
                  goto LABEL_59;
                }
              }
LABEL_60:
              if ( upperBase.numChains )
                Scaleform::Render::Tessellator::connectStarting(this, v14, &upperBase);
              Scaleform::Render::Tessellator::addPendingEnd(this, v32, v39, yb);
              v31 = v233;
              v28 = -1;
              v14 = v39;
              v30 = v231 + 1;
              v234 = -1;
              goto LABEL_20;
            }
            v47 = v46->lowerBase;
            if ( v47 )
            {
              if ( this->MeshVertices.Pages[(unsigned __int64)(vertex & 0xFFFFFFF) >> 4][vertex & 0xF].y == v47->y )
              {
                v47->vertexRight = vertex & 0xFFFFFFF;
              }
              else if ( vertex >= 0 )
              {
                Scaleform::Render::Tessellator::connectPendingToRight(this, v14, vertex);
              }
              else
              {
                Scaleform::Render::Tessellator::connectPendingToLeft(this, v14, vertex);
              }
              goto LABEL_46;
            }
            v8 = v46->start == 0i64;
            LODWORD(v228) = vertex;
            HIDWORD(v228) = vertex;
            if ( v8 )
            {
              v48 = this->MonoVertices.Size >> 4;
              if ( v48 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v49 = this->MonoVertices.Pages[v48];
              v50 = this->MonoVertices.Size & 0xF;
              *(_QWORD *)&v49[v50].srcVer = v228;
              v49[v50].next = 0i64;
              v51 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
              *(_QWORD *)&v46->d.t.numTriangles = -1i64;
              v46->start = v51;
            }
            else
            {
              v52 = &this->MonoVertices.Pages[(unsigned __int64)v46->d.m.lastIdx >> 4][v46->d.m.lastIdx & 0xF];
              if ( v52->srcVer == vertex )
              {
LABEL_45:
                v39 = v212;
                goto LABEL_46;
              }
              v53 = this->MonoVertices.Size >> 4;
              if ( v53 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v54 = this->MonoVertices.Pages[v53];
              v55 = this->MonoVertices.Size & 0xF;
              v29 = 0i64;
              *(_QWORD *)&v54[v55].srcVer = v228;
              v54[v55].next = 0i64;
              v52->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
              v46->d.m.prevIdx2 = v46->d.m.prevIdx1;
              v46->d.m.prevIdx1 = v46->d.m.lastIdx;
            }
            v46->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
            goto LABEL_45;
          }
        }
        else
        {
          if ( !v14 || (v67 = v14->monotone) == 0i64 || !v67->style )
          {
            if ( !v32 )
              goto LABEL_91;
            v72 = v32->monotone;
            if ( !v72 )
              goto LABEL_91;
            v73 = v72->lowerBase;
            if ( v73 )
            {
              if ( this->MeshVertices.Pages[(unsigned __int64)(v41 & 0xFFFFFFF) >> 4][v41 & 0xF].y == v73->y )
              {
                v73->vertexRight = v41 & 0xFFFFFFF;
              }
              else if ( v41 >= 0 )
              {
                Scaleform::Render::Tessellator::connectPendingToRight(this, v32, v41);
              }
              else
              {
                Scaleform::Render::Tessellator::connectPendingToLeft(this, v32, v41);
              }
              goto LABEL_91;
            }
            v8 = v72->start == 0i64;
            LODWORD(v223) = v41;
            HIDWORD(v223) = v41;
            if ( v8 )
            {
              v74 = this->MonoVertices.Size >> 4;
              if ( v74 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v75 = this->MonoVertices.Pages[v74];
              v76 = this->MonoVertices.Size & 0xF;
              *(_QWORD *)&v75[v76].srcVer = v223;
              v75[v76].next = 0i64;
              v77 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
              *(_QWORD *)&v72->d.t.numTriangles = -1i64;
              v72->start = v77;
              goto LABEL_90;
            }
            v78 = &this->MonoVertices.Pages[(unsigned __int64)v72->d.m.lastIdx >> 4][v72->d.m.lastIdx & 0xF];
            if ( v78->srcVer != v41 )
            {
              v79 = this->MonoVertices.Size >> 4;
              if ( v79 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v80 = this->MonoVertices.Pages[v79];
              v81 = this->MonoVertices.Size & 0xF;
              v29 = 0i64;
              *(_QWORD *)&v80[v81].srcVer = v223;
              v80[v81].next = 0i64;
              v78->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
              v72->d.m.prevIdx2 = v72->d.m.prevIdx1;
              v72->d.m.prevIdx1 = v72->d.m.lastIdx;
LABEL_90:
              v72->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
            }
LABEL_91:
            Scaleform::Render::Tessellator::startMonotone(this, scan, scan->vertex | 0x80000000);
            v28 = v234;
            v31 = v233;
            goto LABEL_92;
          }
          if ( upperBase.numChains )
          {
            ++upperBase.numChains;
          }
          else
          {
            v68 = v42->chain;
            upperBase.firstChain = v31;
            upperBase.numChains = 1;
            leftAbove = v68->leftAbove;
            upperBase.leftAbove = v28;
            upperBase.styleLeft = leftAbove;
          }
          if ( v32 )
          {
            v70 = v32->monotone;
            if ( v70 )
            {
              v71 = v70->lowerBase;
              if ( v71 )
              {
                if ( yb == v71->y )
                  v71->vertexRight = v41;
              }
            }
          }
LABEL_92:
          v30 = v231;
          ++v31;
          v32 = scan;
          dst = scan;
          v233 = v31;
        }
      }
      if ( v31 >= this->ChainsAbove.Size )
        break;
      v163 = this->ChainsAbove.Pages[(unsigned __int64)v31 >> 4];
      v164 = v163[v31 & 0xF].vertex;
      v32 = &v163[v31 & 0xF];
      if ( dst )
      {
        v165 = dst->monotone;
        if ( v165 )
        {
          v166 = v165->lowerBase;
          if ( v166 )
          {
            if ( this->MeshVertices.Pages[(unsigned __int64)(v164 & 0xFFFFFFF) >> 4][v164 & 0xF].y == v166->y )
            {
              v166->vertexRight = v164 & 0xFFFFFFF;
            }
            else if ( v164 >= 0 )
            {
              Scaleform::Render::Tessellator::connectPendingToRight(this, dst, v164);
            }
            else
            {
              Scaleform::Render::Tessellator::connectPendingToLeft(this, dst, v164);
            }
          }
          else
          {
            v8 = v165->start == 0i64;
            LODWORD(v222) = v163[v31 & 0xF].vertex;
            HIDWORD(v222) = v164;
            if ( v8 )
            {
              v167 = this->MonoVertices.Size >> 4;
              if ( v167 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v168 = this->MonoVertices.Pages[v167];
              v169 = this->MonoVertices.Size & 0xF;
              *(_QWORD *)&v168[v169].srcVer = v222;
              v168[v169].next = 0i64;
              v170 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
              *(_QWORD *)&v165->d.t.numTriangles = -1i64;
              v165->start = v170;
            }
            else
            {
              v171 = &this->MonoVertices.Pages[(unsigned __int64)v165->d.m.lastIdx >> 4][v165->d.m.lastIdx & 0xF];
              if ( v171->srcVer == v164 )
                goto LABEL_255;
              v172 = this->MonoVertices.Size >> 4;
              if ( v172 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v173 = this->MonoVertices.Pages[v172];
              v174 = this->MonoVertices.Size & 0xF;
              v29 = 0i64;
              *(_QWORD *)&v173[v174].srcVer = v222;
              v173[v174].next = 0i64;
              v171->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size)
                                                                                    - 1) & 0xF];
              v165->d.m.prevIdx2 = v165->d.m.prevIdx1;
              v165->d.m.prevIdx1 = v165->d.m.lastIdx;
            }
            v165->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          }
        }
      }
LABEL_255:
      Scaleform::Render::Tessellator::startMonotone(this, v32, v32->vertex | 0x80000000);
      v28 = v234;
      v30 = v231;
      v31 = v233 + 1;
      dst = v32;
      ++v233;
    }
    if ( v33 < v34 )
    {
      v175 = v33 >> 4;
      v176 = v33 & 0xF;
      v177 = this->ChainsBelow.Pages[v175];
      v178 = v177[v176].vertex;
      v179 = &v177[v176];
      if ( v14 )
      {
        v180 = v14->monotone;
        if ( v180 )
        {
          v181 = v180->lowerBase;
          if ( v181 )
          {
            if ( this->MeshVertices.Pages[(unsigned __int64)(v178 & 0xFFFFFFF) >> 4][v178 & 0xF].y == v181->y )
            {
              v181->vertexRight = v178 & 0xFFFFFFF;
            }
            else if ( v178 >= 0 )
            {
              Scaleform::Render::Tessellator::connectPendingToRight(this, v14, v178);
            }
            else
            {
              Scaleform::Render::Tessellator::connectPendingToLeft(this, v14, v178);
            }
          }
          else
          {
            v8 = v180->start == 0i64;
            LODWORD(v224) = v177[v176].vertex;
            HIDWORD(v224) = v178;
            if ( v8 )
            {
              v182 = this->MonoVertices.Size >> 4;
              if ( v182 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v183 = this->MonoVertices.Pages[v182];
              v184 = this->MonoVertices.Size & 0xF;
              *(_QWORD *)&v183[v184].srcVer = v224;
              v183[v184].next = 0i64;
              v185 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
              *(_QWORD *)&v180->d.t.numTriangles = -1i64;
              v180->start = v185;
            }
            else
            {
              v186 = &this->MonoVertices.Pages[(unsigned __int64)v180->d.m.lastIdx >> 4][v180->d.m.lastIdx & 0xF];
              if ( v186->srcVer == v178 )
                goto LABEL_274;
              v187 = this->MonoVertices.Size >> 4;
              if ( v187 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v188 = this->MonoVertices.Pages[v187];
              v189 = this->MonoVertices.Size & 0xF;
              v29 = 0i64;
              *(_QWORD *)&v188[v189].srcVer = v224;
              v188[v189].next = 0i64;
              v186->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size)
                                                                                    - 1) & 0xF];
              v180->d.m.prevIdx2 = v180->d.m.prevIdx1;
              v180->d.m.prevIdx1 = v180->d.m.lastIdx;
            }
            v180->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
          }
        }
      }
LABEL_274:
      v190 = v179->monotone;
      v191 = v179->vertex | 0x80000000;
      if ( v190 )
      {
        v192 = v190->lowerBase;
        if ( v192 )
        {
          if ( this->MeshVertices.Pages[(unsigned __int64)(v179->vertex & 0xFFFFFFF) >> 4][v179->vertex & 0xF].y == v192->y )
            v192->vertexRight = v179->vertex & 0xFFFFFFF;
          else
            Scaleform::Render::Tessellator::connectPendingToLeft(this, v179, v191);
          goto LABEL_288;
        }
        v8 = v190->start == 0i64;
        LODWORD(v226) = v179->vertex | 0x80000000;
        HIDWORD(v226) = v191;
        if ( v8 )
        {
          v193 = this->MonoVertices.Size >> 4;
          if ( v193 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v194 = this->MonoVertices.Pages[v193];
          v195 = this->MonoVertices.Size & 0xF;
          *(_QWORD *)&v194[v195].srcVer = v226;
          v194[v195].next = 0i64;
          v196 = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          *(_QWORD *)&v190->d.t.numTriangles = -1i64;
          v190->start = v196;
          goto LABEL_287;
        }
        v197 = &this->MonoVertices.Pages[(unsigned __int64)v190->d.m.lastIdx >> 4][v190->d.m.lastIdx & 0xF];
        if ( v197->srcVer != v191 )
        {
          v198 = this->MonoVertices.Size >> 4;
          if ( v198 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v199 = this->MonoVertices.Pages[v198];
          v200 = this->MonoVertices.Size & 0xF;
          v29 = 0i64;
          *(_QWORD *)&v199[v200].srcVer = v226;
          v199[v200].next = 0i64;
          v197->next = &this->MonoVertices.Pages[this->MonoVertices.Size++ >> 4][(LODWORD(this->MonoVertices.Size) - 1) & 0xF];
          v190->d.m.prevIdx2 = v190->d.m.prevIdx1;
          v190->d.m.prevIdx1 = v190->d.m.lastIdx;
LABEL_287:
          v190->d.m.lastIdx = LODWORD(this->MonoVertices.Size) - 1;
        }
      }
LABEL_288:
      if ( upperBase.numChains )
        Scaleform::Render::Tessellator::connectStarting(this, v14, &upperBase);
      Scaleform::Render::Tessellator::addPendingEnd(this, dst, v179, yb);
      v31 = v233;
      v28 = -1;
      v14 = v179;
      v32 = dst;
      v30 = v231 + 1;
      v234 = -1;
      continue;
    }
    break;
  }
  v8 = this->ChainsAbove.Size == 0;
  this->ChainsBelow.Size = 0i64;
  v201 = 0i64;
  if ( !v8 )
  {
    do
    {
      v202 = this->ChainsBelow.Size >> 4;
      v203 = v201 & 0xF;
      v204 = this->ChainsAbove.Pages[v201 >> 4];
      if ( v202 >= this->ChainsBelow.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::ScanChainType,4,8>::allocPage(
          &this->ChainsBelow,
          this->ChainsBelow.Size >> 4);
      ++v201;
      v205 = this->ChainsBelow.Pages[v202];
      v206 = this->ChainsBelow.Size & 0xF;
      v205[v206].chain = v204[v203].chain;
      v205[v206].monotone = v204[v203].monotone;
      *(_QWORD *)&v205[v206].vertex = *(_QWORD *)&v204[v203].vertex;
      ++this->ChainsBelow.Size;
    }
    while ( v201 < this->ChainsAbove.Size );
    v29 = 0i64;
  }
  if ( aet->Size )
  {
    do
    {
      v207 = v29 >> 4;
      v208 = v29++ & 0xF;
      v209 = aet->Pages[v207][v208];
      v210 = v209->leftAbove;
      v209->flags &= ~0x10u;
      v209->leftBelow = v210;
      v209->rightBelow = v209->rightAbove;
    }
    while ( v29 < aet->Size );
  }
}= v210;
      v209->rightBelow = v209->rightAbove;
    }
    while ( v29 < aet->Size );
  }
}

// File Line: 1809
// RVA: 0x9F3BA0
void __fastcall Scaleform::Render::Tessellator::swapChains(
        Scaleform::Render::Tessellator *this,
        unsigned int startIn,
        unsigned int endIn)
{
  __int64 v4; // rsi
  unsigned __int64 v5; // rdi
  __int64 v6; // rax
  unsigned __int64 v7; // r8
  __int64 v8; // rcx
  Scaleform::Render::Tessellator::IntersectionType *v9; // rax
  unsigned int **Pages; // r8
  Scaleform::Render::Tessellator::IntersectionType *v11; // r11
  unsigned int v12; // edx
  unsigned __int64 v13; // r10
  unsigned __int64 v14; // r9
  Scaleform::Render::Tessellator::MonoChainType *v15; // rax
  __int64 v16; // rdx
  unsigned __int64 v17; // r8
  Scaleform::Render::Tessellator::MonoChainType *v18; // rax
  Scaleform::Render::Tessellator::MonoChainType ***v19; // rcx
  Scaleform::Render::Tessellator::MonoChainType **v20; // r8
  Scaleform::Render::Tessellator::MonoChainType **v21; // rcx
  Scaleform::Render::Tessellator::MonoChainType **v22; // r8
  Scaleform::Render::Tessellator::MonoChainType *v23; // rdx
  unsigned int **v24; // rdx
  unsigned int *v25; // r8
  unsigned __int64 pos1; // rax
  __int64 v27; // r9
  unsigned int *v28; // rax

  if ( startIn < endIn )
  {
    v4 = endIn - startIn;
    v5 = startIn;
    do
    {
      v6 = v5 & 0xF;
      v7 = v5++ >> 4;
      v8 = v6;
      v9 = this->Intersections.Pages[v7];
      Pages = this->InteriorOrder.Pages;
      v11 = &v9[v8];
      v12 = Pages[(unsigned __int64)v11->pos1 >> 4][v11->pos1 & 0xF];
      LODWORD(Pages) = Pages[(unsigned __int64)v11->pos2 >> 4][v11->pos2 & 0xF];
      v13 = (unsigned __int64)v12 >> 4;
      v14 = v12 & 0xF;
      v15 = this->InteriorChains.Pages[v13][v14];
      v15->flags |= 0x10u;
      v16 = (unsigned __int8)Pages & 0xF;
      v17 = (unsigned __int64)(unsigned int)Pages >> 4;
      v18 = this->InteriorChains.Pages[v17][v16];
      v18->flags |= 0x10u;
      v19 = this->InteriorChains.Pages;
      v20 = v19[v17];
      v21 = v19[v13];
      v22 = &v20[v16];
      v23 = v21[v14];
      v21[v14] = *v22;
      *v22 = v23;
      v24 = this->InteriorOrder.Pages;
      v25 = &v24[(unsigned __int64)v11->pos2 >> 4][v11->pos2 & 0xF];
      pos1 = v11->pos1;
      v27 = pos1 & 0xF;
      v28 = v24[pos1 >> 4];
      LODWORD(v24) = v28[v27];
      v28[v27] = *v25;
      *v25 = (unsigned int)v24;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 1825
// RVA: 0x9ED640
// local variable allocation has failed, the output may be wrong!
void __fastcall Scaleform::Render::Tessellator::processInterior(
        Scaleform::Render::Tessellator *this,
        double yb,
        float yTop,
        unsigned int perceiveFlag)
{
  unsigned __int64 Size; // r8
  unsigned int v5; // ebx
  float v8; // xmm8_4
  __int128 y_low; // xmm7
  unsigned __int64 v10; // rdx
  unsigned __int64 v11; // r8
  unsigned __int64 i; // rcx
  __int128 v13; // xmm6
  unsigned int v14; // esi

  Size = this->Intersections.Size;
  v5 = 0;
  v8 = *(float *)&yb;
  y_low = *(_OWORD *)&yb;
  if ( Size )
  {
    v10 = 0i64;
    do
    {
      y_low = LODWORD(this->Intersections.Pages[v10 >> 4][v10 & 0xF].y);
      if ( *(float *)&y_low > *(float *)&yb )
        break;
      ++v5;
      perceiveFlag = 1;
      v10 = v5;
    }
    while ( v5 < Size );
  }
  Scaleform::Render::Tessellator::swapChains(this, 0, v5);
  if ( perceiveFlag )
    Scaleform::Render::Tessellator::perceiveStyles(this, &this->InteriorChains);
  v11 = this->Intersections.Size;
  for ( i = v5; v5 < v11; y_low = v13 )
  {
    v13 = y_low;
    v14 = v5;
    if ( i < v11 )
    {
      do
      {
        v13 = LODWORD(this->Intersections.Pages[i >> 4][i & 0xF].y);
        if ( *(float *)&v13 > *(float *)&y_low )
          break;
        i = ++v5;
      }
      while ( v5 < v11 );
    }
    Scaleform::Render::Tessellator::perceiveStyles(this, &this->InteriorChains);
    Scaleform::Render::Tessellator::sweepScanbeam(this, &this->InteriorChains, v8);
    Scaleform::Render::Tessellator::swapChains(this, v14, v5);
    v11 = this->Intersections.Size;
    i = v5;
    v8 = *(float *)&y_low;
  }
  Scaleform::Render::Tessellator::perceiveStyles(this, &this->ActiveChains);
  if ( *(float *)&y_low < yTop )
    Scaleform::Render::Tessellator::sweepScanbeam(this, &this->ActiveChains, *(float *)&y_low);
}

// File Line: 1878
// RVA: 0x9E9CA0
void __fastcall Scaleform::Render::Tessellator::monotonize(Scaleform::Render::Tessellator *this)
{
  unsigned __int64 i; // rbp
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // rdx
  unsigned __int64 v5; // r8
  float j; // xmm2_4
  unsigned int **Pages; // rbx
  __int64 v8; // r9
  Scaleform::Render::Tessellator::SrcVertexType *v9; // r10
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rcx
  unsigned __int64 k; // rbx
  unsigned __int64 Size; // rbp
  void *v14; // r14
  Scaleform::Render::Tessellator::MonoChainType **Array; // rdx
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // r9
  unsigned __int64 v18; // rdx
  unsigned __int64 v19; // r8
  unsigned int v20; // r15d
  unsigned int v21; // ebx
  unsigned __int64 v22; // rcx
  float y; // xmm7_4
  unsigned __int64 v24; // rax
  float v25; // xmm6_4
  unsigned __int64 v26; // rsi
  unsigned __int64 v27; // rcx
  unsigned int v28; // r9d
  unsigned int Scanbeam; // eax
  char v30; // bp
  unsigned __int64 v31; // rdx
  unsigned __int64 m; // r8
  Scaleform::Render::Tessellator::MonoChainType ***v33; // r9
  Scaleform::Render::Tessellator::MonoChainType *v34; // r10
  unsigned __int64 v35; // rax
  unsigned __int64 v36; // rcx

  if ( this->SrcVertices.Size )
  {
    Scaleform::Render::ArrayUnsafe<int>::Resize(&this->StyleCounts, this->MaxStyle + 1);
    for ( i = 0i64; i < this->SrcVertices.Size; ++i )
    {
      v3 = this->Scanbeams.Size >> 4;
      if ( v3 >= this->Scanbeams.NumPages )
        Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->Scanbeams,
          this->Scanbeams.Size >> 4);
      this->Scanbeams.Pages[v3][this->Scanbeams.Size & 0xF] = i;
      ++this->Scanbeams.Size;
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<unsigned int,4,16>,Scaleform::Render::Tessellator::CmpScanbeams>(
      &this->Scanbeams,
      0i64,
      this->Scanbeams.Size,
      (Scaleform::Render::Tessellator::CmpScanbeams)&this->SrcVertices);
    v4 = 0i64;
    v5 = 0i64;
    for ( j = FLOAT_N1_0e30; v4 < this->Scanbeams.Size; ++v4 )
    {
      Pages = this->Scanbeams.Pages;
      v8 = Pages[v4 >> 4][v4 & 0xF] & 0xF;
      v9 = this->SrcVertices.Pages[(unsigned __int64)Pages[v4 >> 4][v4 & 0xF] >> 4];
      if ( (float)(v9[v8].y - j) <= (float)(COERCE_FLOAT(LODWORD(v9[v8].y) & _xmm) * this->Epsilon) )
      {
        v9[v8].y = j;
      }
      else
      {
        v10 = v5 >> 4;
        v11 = v5++ & 0xF;
        Pages[v10][v11] = Pages[v4 >> 4][v4 & 0xF];
        j = v9[v8].y;
      }
    }
    if ( v5 < this->Scanbeams.Size )
      this->Scanbeams.Size = v5;
    for ( k = 0i64; k < this->Paths.Size; ++k )
      Scaleform::Render::Tessellator::decomposePath(this, &this->Paths.Pages[k >> 4][k & 0xF]);
    Size = this->MonoChains.Size;
    if ( Size > this->MonoChainsSorted.Size )
    {
      v14 = Scaleform::Render::LinearHeap::Alloc(this->MonoChainsSorted.pHeap, 8 * Size);
      memset(v14, 0, 8 * Size);
      Array = this->MonoChainsSorted.Array;
      if ( Array )
      {
        v16 = this->MonoChainsSorted.Size;
        if ( v16 )
          memmove(v14, Array, 8 * v16);
      }
      this->MonoChainsSorted.Array = (Scaleform::Render::Tessellator::MonoChainType **)v14;
    }
    v17 = 0i64;
    for ( this->MonoChainsSorted.Size = Size;
          v17 < this->MonoChains.Size;
          this->MonoChainsSorted.Array[v17 - 1] = &this->MonoChains.Pages[v19][v18] )
    {
      v18 = v17 & 0xF;
      v19 = v17++ >> 4;
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayUnsafe<Scaleform::Render::Tessellator::MonoChainType *>,bool (*)(Scaleform::Render::Tessellator::MonoChainType const *,Scaleform::Render::Tessellator::MonoChainType const *)>(
      &this->MonoChainsSorted,
      0i64,
      this->MonoChainsSorted.Size,
      Scaleform::Render::Hairliner::cmpMonoChains);
    v20 = 0;
    v21 = 0;
    v22 = **this->Scanbeams.Pages;
    y = this->SrcVertices.Pages[v22 >> 4][v22 & 0xF].y;
    v24 = this->Scanbeams.Size;
    v25 = y;
    if ( v24 )
    {
      v26 = 0i64;
      do
      {
        if ( ++v20 < v24 )
          y = this->SrcVertices.Pages[(unsigned __int64)this->Scanbeams.Pages[(unsigned __int64)v20 >> 4][v20 & 0xF] >> 4][this->Scanbeams.Pages[(unsigned __int64)v20 >> 4][v20 & 0xF] & 0xF].y;
        v27 = this->MonoChainsSorted.Size;
        v28 = v21;
        if ( v26 < v27 )
        {
          do
          {
            if ( v25 < this->MonoChainsSorted.Array[v26]->ySort )
              break;
            v26 = ++v21;
          }
          while ( v21 < v27 );
        }
        Scanbeam = Scaleform::Render::Tessellator::nextScanbeam(this, v25, y, v28, v21 - v28);
        v30 = Scanbeam;
        if ( this->Intersections.Size )
        {
          Scaleform::Render::Tessellator::processInterior(this, v25, y, Scanbeam);
        }
        else
        {
          if ( Scanbeam )
            Scaleform::Render::Tessellator::perceiveStyles(this, &this->ActiveChains);
          Scaleform::Render::Tessellator::sweepScanbeam(this, &this->ActiveChains, v25);
        }
        if ( (v30 & 2) != 0 )
        {
          v31 = 0i64;
          for ( m = 0i64; v31 < this->ActiveChains.Size; ++v31 )
          {
            v33 = this->ActiveChains.Pages;
            v34 = v33[v31 >> 4][v31 & 0xF];
            if ( (v34->flags & 2) == 0 )
            {
              v35 = m >> 4;
              v36 = m++ & 0xF;
              v33[v35][v36] = v34;
            }
          }
          if ( m < this->ActiveChains.Size )
            this->ActiveChains.Size = m;
        }
        v24 = this->Scanbeams.Size;
        v25 = y;
      }
      while ( v20 < v24 );
    }
  }
}

// File Line: 1980
// RVA: 0x9F0AA0
__int64 __fastcall Scaleform::Render::Tessellator::setMesh(Scaleform::Render::Tessellator *this, unsigned int style)
{
  __int64 v2; // rsi
  unsigned __int16 *v5; // r10
  unsigned int Size; // r12d
  unsigned __int64 v7; // r15
  Scaleform::Render::TessMesh *v8; // rax
  __int64 v9; // rcx

  v2 = style;
  if ( !this->HasComplexFill )
    return 0i64;
  v5 = &this->StyleMatrix.Array[style * (this->StyleMatrix.Size + 1)];
  if ( *v5 == 0xFFFF )
  {
    if ( ((1 << (style & 0x1F)) & this->ComplexFlags.Array[(unsigned __int64)style >> 5]) != 0 )
    {
      *v5 = this->Meshes.Size;
      Size = this->Meshes.Size;
      v7 = this->Meshes.Size >> 4;
      if ( v7 >= this->Meshes.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::allocPage(&this->Meshes, this->Meshes.Size >> 4);
      v8 = this->Meshes.Pages[v7];
      v9 = this->Meshes.Size & 0xF;
      v8[v9].MeshIdx = Size;
      v8[v9].Style1 = v2;
      v8[v9].Style2 = v2;
      v8[v9].Flags1 = 0x8000;
      *(_QWORD *)&v8[v9].Flags2 = 0x8000i64;
      v8[v9].VertexCount = 0;
      ++this->Meshes.Size;
      Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(&this->MeshTriangles);
    }
    else
    {
      *v5 = 0;
    }
  }
  return this->StyleMatrix.Array[v2 * (this->StyleMatrix.Size + 1)];
}

// File Line: 2019
// RVA: 0x9F0BE0
__int64 __fastcall Scaleform::Render::Tessellator::setMesh(
        Scaleform::Render::Tessellator *this,
        unsigned int style1,
        __int64 style2)
{
  unsigned int v3; // r12d
  unsigned __int64 v4; // r13
  unsigned __int64 Size; // r9
  unsigned __int16 *Array; // r10
  __int64 v9; // rdi
  unsigned int *v10; // rdx
  int v11; // ebp
  int v12; // esi
  unsigned int v13; // eax
  unsigned __int16 v14; // r14
  unsigned __int16 v15; // r8
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4> *p_Meshes; // r8
  unsigned int v17; // eax
  unsigned __int64 v18; // rax
  Scaleform::Render::TessMesh *v19; // rax
  __int64 v20; // rcx
  unsigned __int16 *v21; // rax
  unsigned __int64 v22; // rcx
  unsigned __int16 *v23; // rax
  unsigned __int64 v24; // rcx
  unsigned __int64 v25; // [rsp+20h] [rbp-48h]
  unsigned int v26; // [rsp+70h] [rbp+8h]
  unsigned int v27; // [rsp+88h] [rbp+20h]

  v3 = style2;
  v4 = style1;
  if ( !this->HasComplexFill )
    return 0i64;
  Size = this->StyleMatrix.Size;
  Array = this->StyleMatrix.Array;
  v9 = style1;
  style2 = (unsigned int)style2;
  if ( Array[(unsigned int)style2 + style1 * Size] == 0xFFFF )
  {
    v10 = this->ComplexFlags.Array;
    v11 = v10[v4 >> 5] & (1 << (v4 & 0x1F));
    v12 = v10[(unsigned __int64)(unsigned int)style2 >> 5] & (1 << (style2 & 0x1F));
    if ( v11 | v12 )
    {
      if ( v11 )
        v11 = 0x8000;
      if ( v12 )
        v12 = 0x8000;
      if ( !v11 )
      {
        v13 = v4;
        v11 = v12;
        LODWORD(v4) = style2;
        v3 = v13;
        v12 = 0;
      }
      v14 = this->Meshes.Size;
      v9 = (unsigned int)v4;
      v15 = Array[(unsigned int)v4 * (Size + 1)];
      if ( v12 || v15 == 0xFFFF || (this->Meshes.Pages[(unsigned __int64)v15 >> 4][v15 & 0xF].Flags2 & 0x8000) != 0 )
      {
        p_Meshes = &this->Meshes;
        v26 = this->Meshes.Size;
        v17 = 0;
        if ( v12 )
          v17 = v3;
        v27 = v17;
        v18 = this->Meshes.Size >> 4;
        v25 = v18;
        if ( v18 >= this->Meshes.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::allocPage(&this->Meshes, v18);
          p_Meshes = &this->Meshes;
        }
        v19 = p_Meshes->Pages[v25];
        v20 = p_Meshes->Size & 0xF;
        v19[v20].MeshIdx = v26;
        v19[v20].Style1 = v4;
        v19[v20].Style2 = v27;
        v19[v20].Flags1 = v11;
        v19[v20].Flags2 = v12;
        *(_QWORD *)&v19[v20].StartVertex = 0i64;
        ++p_Meshes->Size;
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(&this->MeshTriangles);
      }
      else
      {
        v14 = Array[(unsigned int)v4 * (Size + 1)];
      }
      style2 = v3;
      this->StyleMatrix.Array[v3 + this->StyleMatrix.Size * (unsigned int)v4] = v14;
      this->StyleMatrix.Array[(unsigned int)v4 + this->StyleMatrix.Size * v3] = v14;
      v21 = this->StyleMatrix.Array;
      v22 = (unsigned int)v4 * (this->StyleMatrix.Size + 1);
      if ( this->InvasiveMerge )
      {
        if ( v21[v22] == 0xFFFF )
          v21[v22] = v14;
        v23 = this->StyleMatrix.Array;
        v24 = v3 * (this->StyleMatrix.Size + 1);
        if ( v23[v24] == 0xFFFF )
          v23[v24] = v14;
      }
      else if ( v21[v22] == 0xFFFF && v11 && !v12 )
      {
        v21[v22] = v14;
      }
    }
    else
    {
      Array[v4 * (Size + 1)] = 0;
      this->StyleMatrix.Array[(unsigned int)style2 * (this->StyleMatrix.Size + 1)] = 0;
      this->StyleMatrix.Array[(unsigned int)style2 + this->StyleMatrix.Size * v4] = 0;
      this->StyleMatrix.Array[v4 + this->StyleMatrix.Size * (unsigned int)style2] = 0;
    }
  }
  return this->StyleMatrix.Array[style2 + this->StyleMatrix.Size * v9];
}

// File Line: 2099
// RVA: 0x989240
void __fastcall Scaleform::Render::Tessellator::GetMesh(
        Scaleform::Render::Tessellator *this,
        unsigned int meshIdx,
        Scaleform::Render::TessMesh *mesh)
{
  *mesh = this->Meshes.Pages[(unsigned __int64)meshIdx >> 4][meshIdx & 0xF];
  mesh->StartVertex = 0;
}

// File Line: 2106
// RVA: 0x98F260
__int64 __fastcall Scaleform::Render::Tessellator::GetVertices(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::TessMesh *mesh,
        Scaleform::Render::TessVertex *vertices,
        unsigned int num)
{
  __int64 i; // r11
  unsigned __int64 StartVertex; // rax
  Scaleform::Render::TessVertex **Pages; // r9
  __int64 v10; // rcx
  Scaleform::Render::TessVertex *v11; // rdx
  Scaleform::Render::TessVertex *v12; // r9

  for ( i = 0i64; (unsigned int)i < num; ++mesh->StartVertex )
  {
    StartVertex = mesh->StartVertex;
    if ( StartVertex >= this->MeshVertices.Size )
      break;
    Pages = this->MeshVertices.Pages;
    if ( Pages[(unsigned __int64)(unsigned int)StartVertex >> 4][StartVertex & 0xF].Mesh == mesh->MeshIdx )
    {
      v10 = i;
      i = (unsigned int)(i + 1);
      v11 = Pages[(unsigned __int64)(unsigned int)StartVertex >> 4];
      v12 = &vertices[v10];
      v12->x = v11[StartVertex & 0xF].x;
      v12->y = v11[StartVertex & 0xF].y;
      v12->Idx = v11[StartVertex & 0xF].Idx;
      *(_DWORD *)v12->Styles = *(_DWORD *)v11[StartVertex & 0xF].Styles;
      *(_DWORD *)&v12->Flags = *(_DWORD *)&v11[StartVertex & 0xF].Flags;
    }
  }
  return (unsigned int)i;
}

// File Line: 2122
// RVA: 0x98E090
void __fastcall Scaleform::Render::Tessellator::GetTrianglesI16(
        Scaleform::Render::Tessellator *this,
        unsigned int meshIdx,
        unsigned __int16 *idx,
        unsigned int start,
        unsigned int num)
{
  unsigned int i; // ebx
  unsigned int v7; // eax
  Scaleform::Render::Tessellator::TriangleType *v8; // r9

  for ( i = 0; i < num; *(idx - 1) = this->MeshVertices.Pages[(unsigned __int64)v8->d.t.v3 >> 4][v8->d.t.v3 & 0xF].Idx )
  {
    v7 = i + start;
    ++i;
    idx += 3;
    v8 = &this->MeshTriangles.Arrays[meshIdx].Pages[(unsigned __int64)v7 >> 4][v7 & 0xF];
    *(idx - 3) = this->MeshVertices.Pages[(unsigned __int64)v8->d.t.v1 >> 4][v8->d.t.v1 & 0xF].Idx;
    *(idx - 2) = this->MeshVertices.Pages[(unsigned __int64)v8->d.t.v2 >> 4][v8->d.t.v2 & 0xF].Idx;
  }
}

// File Line: 2135
// RVA: 0x9E16E0
__int64 __fastcall Scaleform::Render::Tessellator::emitVertex(
        Scaleform::Render::Tessellator *this,
        unsigned int meshIdx,
        unsigned int ver,
        unsigned int style,
        __int16 flags)
{
  Scaleform::Render::TessVertex **Pages; // rbx
  unsigned int v6; // r8d
  Scaleform::Render::TessVertex *v8; // rax
  unsigned int Idx; // edx
  __int64 v10; // rax
  __int64 result; // rax
  unsigned int v12; // edx
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *p_MeshVertices; // rbx
  unsigned __int64 Size; // rsi
  int v15; // ebp
  int v16; // r14d
  unsigned __int64 v17; // rdi
  _DWORD *p_x; // r8
  int v19; // [rsp+2Ch] [rbp-1Ch]
  int v20; // [rsp+30h] [rbp-18h]

  Pages = this->MeshVertices.Pages;
  v6 = ver & 0xFFFFFFF;
  v8 = Pages[(unsigned __int64)v6 >> 4];
  Idx = v8[v6 & 0xF].Idx;
  v10 = (__int64)&v8[v6 & 0xF];
  if ( Idx == -1 )
  {
    *(_DWORD *)(v10 + 8) = v6;
    *(_WORD *)(v10 + 14) = style;
    *(_WORD *)(v10 + 12) = style;
    *(_WORD *)(v10 + 16) = flags;
    *(_WORD *)(v10 + 18) = meshIdx;
    return v6;
  }
  if ( *(unsigned __int16 *)(v10 + 18) == meshIdx && *(unsigned __int16 *)(v10 + 12) == style )
    return v6;
  if ( Idx == v6 )
  {
LABEL_10:
    p_MeshVertices = &this->MeshVertices;
    Size = this->MeshVertices.Size;
    *(_DWORD *)(v10 + 8) = Size;
    v15 = *(_DWORD *)v10;
    v16 = *(_DWORD *)(v10 + 4);
    v17 = this->MeshVertices.Size >> 4;
    HIWORD(v19) = style;
    LOWORD(v20) = flags;
    HIWORD(v20) = meshIdx;
    LOWORD(v19) = style;
    if ( v17 >= this->MeshVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(p_MeshVertices, v17);
    result = (unsigned int)Size;
    p_x = (_DWORD *)&p_MeshVertices->Pages[v17][p_MeshVertices->Size & 0xF].x;
    *p_x = v15;
    p_x[1] = v16;
    p_x[2] = Size;
    p_x[3] = v19;
    p_x[4] = v20;
    ++p_MeshVertices->Size;
  }
  else
  {
    while ( 1 )
    {
      v12 = *(_DWORD *)(v10 + 8);
      v10 = (__int64)&Pages[(unsigned __int64)v12 >> 4][v12 & 0xF];
      if ( *(unsigned __int16 *)(v10 + 18) == meshIdx && *(unsigned __int16 *)(v10 + 12) == style )
        return v12;
      if ( *(_DWORD *)(v10 + 8) == v12 )
        goto LABEL_10;
    }
  }
  return result;
}

// File Line: 2189
// RVA: 0x9F2AF0
void __fastcall Scaleform::Render::Tessellator::splitMesh(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::TessMesh *mesh)
{
  unsigned int MeshIdx; // esi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *p_MeshTriangles; // r14
  __int64 v6; // rbp
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *p_MeshVertices; // rbx
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *v8; // r9
  unsigned __int64 v9; // r15
  unsigned int Size; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *Arrays; // rcx
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // r12
  unsigned __int64 v14; // r9
  unsigned __int64 v15; // r10
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // rax
  Scaleform::Render::Tessellator::TriangleType *v18; // r8
  unsigned __int64 v19; // rbp
  unsigned __int64 v20; // rbx
  unsigned __int64 v21; // r15
  unsigned __int64 v22; // rdi
  unsigned __int64 v23; // rdx
  unsigned int v24; // r14d
  Scaleform::Render::TessMesh *v25; // rcx
  unsigned int Style1; // r12d
  unsigned __int64 v27; // rsi
  Scaleform::Render::TessMesh *v28; // rax
  __int64 v29; // rcx
  unsigned __int64 v30; // rbp
  __int64 v31; // r9
  unsigned __int64 v32; // rcx
  Scaleform::Render::TessVertex **Pages; // r8
  Scaleform::Render::Tessellator::TriangleType *v34; // r9
  __int64 v35; // r12
  __int64 v36; // r14
  __int64 v37; // r15
  unsigned __int64 v38; // rsi
  unsigned __int64 MaxPages; // rdx
  Scaleform::Render::LinearHeap *pHeap; // rcx
  void *v41; // rdi
  unsigned __int64 v42; // rax
  Scaleform::Render::TessVertex *v43; // rax
  _DWORD *p_x; // rdx
  unsigned __int64 v45; // rsi
  unsigned __int64 v46; // rdx
  Scaleform::Render::LinearHeap *v47; // rcx
  void *v48; // rdi
  unsigned __int64 v49; // rax
  Scaleform::Render::TessVertex *v50; // rax
  _DWORD *v51; // rdx
  unsigned __int64 v52; // rsi
  unsigned __int64 v53; // rdx
  Scaleform::Render::LinearHeap *v54; // rcx
  void *v55; // rdi
  unsigned __int64 v56; // rax
  _DWORD *v57; // rdx
  unsigned int VertexCount; // [rsp+20h] [rbp-78h]
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayAdaptor arr; // [rsp+28h] [rbp-70h] BYREF
  unsigned int Style2; // [rsp+A0h] [rbp+8h]
  __int64 v61; // [rsp+A0h] [rbp+8h]
  unsigned int Flags1; // [rsp+A8h] [rbp+10h]
  Scaleform::Render::Tessellator::TriangleType *v63; // [rsp+A8h] [rbp+10h]
  unsigned int Flags2; // [rsp+B0h] [rbp+18h]
  unsigned __int64 v65; // [rsp+B0h] [rbp+18h]
  unsigned int StartVertex; // [rsp+B8h] [rbp+20h]
  unsigned __int64 v67; // [rsp+B8h] [rbp+20h]

  MeshIdx = mesh->MeshIdx;
  p_MeshTriangles = &this->MeshTriangles;
  v6 = mesh->MeshIdx;
  p_MeshVertices = &this->MeshVertices;
  v8 = &this->MeshVertices;
  v9 = (this->VertexLimit - (this->VertexLimit >> 2) + mesh->VertexCount - 1)
     / (this->VertexLimit - (this->VertexLimit >> 2));
  Size = this->MeshTriangles.Arrays[v6].Size;
  Arrays = this->MeshTriangles.Arrays;
  v12 = Arrays[v6].Size;
  arr.Pages = Arrays[v6].Pages;
  v13 = Size / (unsigned int)v9;
  arr.Size = v12;
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayAdaptor,Scaleform::Render::Tessellator::CmpVer1>(
    &arr,
    0i64,
    v12,
    (Scaleform::Render::Tessellator::CmpVer1)v8);
  v14 = 0i64;
  v15 = this->MeshTriangles.Arrays[mesh->MeshIdx].Size;
  if ( v15 )
  {
    do
    {
      v16 = v14 >> 4;
      v17 = v14++ & 0xF;
      v18 = &this->MeshTriangles.Arrays[v6].Pages[v16][v17];
      this->MeshVertices.Pages[(unsigned __int64)v18->d.t.v1 >> 4][v18->d.t.v1 & 0xF].Mesh = -1;
      this->MeshVertices.Pages[(unsigned __int64)v18->d.t.v2 >> 4][v18->d.t.v2 & 0xF].Mesh = -1;
      this->MeshVertices.Pages[(unsigned __int64)v18->d.t.v3 >> 4][v18->d.t.v3 & 0xF].Mesh = -1;
    }
    while ( v14 < v15 );
  }
  v19 = 1i64;
  if ( v9 > 1 )
  {
    v20 = v9;
    v21 = v13;
    do
    {
      if ( !Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::Split(
              p_MeshTriangles,
              MeshIdx,
              v21) )
        break;
      v22 = MeshIdx & 0xF;
      v23 = (unsigned __int64)MeshIdx >> 4;
      this->Meshes.Pages[v23][v22].VertexCount = -1;
      v24 = this->Meshes.Size;
      v25 = this->Meshes.Pages[v23];
      Style1 = v25[v22].Style1;
      LODWORD(arr.Size) = v25[v22].MeshIdx;
      Style2 = v25[v22].Style2;
      Flags1 = v25[v22].Flags1;
      Flags2 = v25[v22].Flags2;
      StartVertex = v25[v22].StartVertex;
      VertexCount = v25[v22].VertexCount;
      v27 = this->Meshes.Size >> 4;
      if ( v27 >= this->Meshes.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::allocPage(&this->Meshes, v27);
      v28 = this->Meshes.Pages[v27];
      ++v19;
      MeshIdx = v24;
      v29 = this->Meshes.Size & 0xF;
      v28[v29].MeshIdx = v24;
      v28[v29].Style1 = Style1;
      v28[v29].Style2 = Style2;
      p_MeshTriangles = &this->MeshTriangles;
      v28[v29].Flags1 = Flags1;
      v28[v29].Flags2 = Flags2;
      v28[v29].StartVertex = StartVertex;
      v28[v29].VertexCount = VertexCount;
      ++this->Meshes.Size;
    }
    while ( v19 < v20 );
    p_MeshVertices = &this->MeshVertices;
  }
  v30 = 0i64;
  if ( this->Meshes.Size )
  {
    v31 = 0i64;
    v61 = 0i64;
    do
    {
      if ( this->Meshes.Pages[v30 >> 4][v30 & 0xF].VertexCount == -1 )
      {
        v32 = 0i64;
        v65 = 0i64;
        v67 = *(unsigned __int64 *)((char *)&this->MeshTriangles.Arrays->Size + v31);
        if ( v67 )
        {
          do
          {
            Pages = this->MeshVertices.Pages;
            v34 = &(*(Scaleform::Render::Tessellator::TriangleType ***)((char *)&this->MeshTriangles.Arrays->Pages + v31))[v32 >> 4][v32 & 0xF];
            v63 = v34;
            v35 = (__int64)&Pages[(unsigned __int64)v34->d.t.v1 >> 4][v34->d.t.v1 & 0xF];
            v36 = (__int64)&Pages[(unsigned __int64)v34->d.t.v2 >> 4][v34->d.t.v2 & 0xF];
            v37 = (__int64)&Pages[(unsigned __int64)v34->d.t.v3 >> 4][v34->d.t.v3 & 0xF];
            if ( *(_WORD *)(v35 + 18) == 0xFFFF )
              *(_WORD *)(v35 + 18) = v30;
            if ( *(_WORD *)(v36 + 18) == 0xFFFF )
              *(_WORD *)(v36 + 18) = v30;
            if ( *(_WORD *)(v37 + 18) == 0xFFFF )
              *(_WORD *)(v37 + 18) = v30;
            if ( *(unsigned __int16 *)(v35 + 18) != v30 )
            {
              v34->d.t.v1 = this->MeshVertices.Size;
              v38 = p_MeshVertices->Size >> 4;
              if ( v38 >= p_MeshVertices->NumPages )
              {
                MaxPages = p_MeshVertices->MaxPages;
                if ( v38 >= MaxPages )
                {
                  pHeap = p_MeshVertices->pHeap;
                  if ( p_MeshVertices->Pages )
                  {
                    v41 = Scaleform::Render::LinearHeap::Alloc(pHeap, 16 * MaxPages);
                    memmove(v41, p_MeshVertices->Pages, 8 * p_MeshVertices->NumPages);
                    v42 = p_MeshVertices->MaxPages;
                    p_MeshVertices->Pages = (Scaleform::Render::TessVertex **)v41;
                    p_MeshVertices->MaxPages = 2 * v42;
                  }
                  else
                  {
                    p_MeshVertices->MaxPages = 16i64;
                    p_MeshVertices->Pages = (Scaleform::Render::TessVertex **)Scaleform::Render::LinearHeap::Alloc(
                                                                                pHeap,
                                                                                0x80ui64);
                  }
                }
                v43 = (Scaleform::Render::TessVertex *)Scaleform::Render::LinearHeap::Alloc(
                                                         p_MeshVertices->pHeap,
                                                         0x140ui64);
                v34 = v63;
                p_MeshVertices->Pages[v38] = v43;
                ++p_MeshVertices->NumPages;
              }
              p_x = (_DWORD *)&p_MeshVertices->Pages[v38][p_MeshVertices->Size & 0xF].x;
              *p_x = *(_DWORD *)v35;
              p_x[1] = *(_DWORD *)(v35 + 4);
              p_x[2] = *(_DWORD *)(v35 + 8);
              p_x[3] = *(_DWORD *)(v35 + 12);
              p_x[4] = *(_DWORD *)(v35 + 16);
              p_MeshVertices->Pages[p_MeshVertices->Size++ >> 4][(LODWORD(p_MeshVertices->Size) - 1) & 0xF].Mesh = v30;
            }
            if ( *(unsigned __int16 *)(v36 + 18) != v30 )
            {
              v34->d.t.v2 = this->MeshVertices.Size;
              v45 = p_MeshVertices->Size >> 4;
              if ( v45 >= p_MeshVertices->NumPages )
              {
                v46 = p_MeshVertices->MaxPages;
                if ( v45 >= v46 )
                {
                  v47 = p_MeshVertices->pHeap;
                  if ( p_MeshVertices->Pages )
                  {
                    v48 = Scaleform::Render::LinearHeap::Alloc(v47, 16 * v46);
                    memmove(v48, p_MeshVertices->Pages, 8 * p_MeshVertices->NumPages);
                    v49 = p_MeshVertices->MaxPages;
                    p_MeshVertices->Pages = (Scaleform::Render::TessVertex **)v48;
                    p_MeshVertices->MaxPages = 2 * v49;
                  }
                  else
                  {
                    p_MeshVertices->MaxPages = 16i64;
                    p_MeshVertices->Pages = (Scaleform::Render::TessVertex **)Scaleform::Render::LinearHeap::Alloc(
                                                                                v47,
                                                                                0x80ui64);
                  }
                }
                v50 = (Scaleform::Render::TessVertex *)Scaleform::Render::LinearHeap::Alloc(
                                                         p_MeshVertices->pHeap,
                                                         0x140ui64);
                v34 = v63;
                p_MeshVertices->Pages[v45] = v50;
                ++p_MeshVertices->NumPages;
              }
              v51 = (_DWORD *)&p_MeshVertices->Pages[v45][p_MeshVertices->Size & 0xF].x;
              *v51 = *(_DWORD *)v36;
              v51[1] = *(_DWORD *)(v36 + 4);
              v51[2] = *(_DWORD *)(v36 + 8);
              v51[3] = *(_DWORD *)(v36 + 12);
              v51[4] = *(_DWORD *)(v36 + 16);
              p_MeshVertices->Pages[p_MeshVertices->Size++ >> 4][(LODWORD(p_MeshVertices->Size) - 1) & 0xF].Mesh = v30;
            }
            if ( *(unsigned __int16 *)(v37 + 18) != v30 )
            {
              v34->d.t.v3 = this->MeshVertices.Size;
              v52 = p_MeshVertices->Size >> 4;
              if ( v52 >= p_MeshVertices->NumPages )
              {
                v53 = p_MeshVertices->MaxPages;
                if ( v52 >= v53 )
                {
                  v54 = p_MeshVertices->pHeap;
                  if ( p_MeshVertices->Pages )
                  {
                    v55 = Scaleform::Render::LinearHeap::Alloc(v54, 16 * v53);
                    memmove(v55, p_MeshVertices->Pages, 8 * p_MeshVertices->NumPages);
                    v56 = p_MeshVertices->MaxPages;
                    p_MeshVertices->Pages = (Scaleform::Render::TessVertex **)v55;
                    p_MeshVertices->MaxPages = 2 * v56;
                  }
                  else
                  {
                    p_MeshVertices->MaxPages = 16i64;
                    p_MeshVertices->Pages = (Scaleform::Render::TessVertex **)Scaleform::Render::LinearHeap::Alloc(
                                                                                v54,
                                                                                0x80ui64);
                  }
                }
                p_MeshVertices->Pages[v52] = (Scaleform::Render::TessVertex *)Scaleform::Render::LinearHeap::Alloc(
                                                                                p_MeshVertices->pHeap,
                                                                                0x140ui64);
                ++p_MeshVertices->NumPages;
              }
              v57 = (_DWORD *)&p_MeshVertices->Pages[v52][p_MeshVertices->Size & 0xF].x;
              *v57 = *(_DWORD *)v37;
              v57[1] = *(_DWORD *)(v37 + 4);
              v57[2] = *(_DWORD *)(v37 + 8);
              v57[3] = *(_DWORD *)(v37 + 12);
              v57[4] = *(_DWORD *)(v37 + 16);
              p_MeshVertices->Pages[p_MeshVertices->Size++ >> 4][(LODWORD(p_MeshVertices->Size) - 1) & 0xF].Mesh = v30;
            }
            v31 = v61;
            v32 = v65 + 1;
            v65 = v32;
          }
          while ( v32 < v67 );
        }
      }
      v31 += 32i64;
      ++v30;
      v61 = v31;
    }
    while ( v30 < this->Meshes.Size );
  }
}

// File Line: 2260
// RVA: 0x9B76F0
void __fastcall Scaleform::Render::Tessellator::SplitMeshes(Scaleform::Render::Tessellator *this)
{
  unsigned __int64 Size; // rsi
  char v3; // r8
  unsigned __int64 v4; // rdi
  Scaleform::Render::TessMesh *v5; // rdx
  unsigned __int64 i; // r8
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // rcx
  unsigned __int64 j; // r9
  Scaleform::Render::TessVertex *v10; // r8
  unsigned __int16 Mesh; // ax
  __int64 v12; // rdx
  Scaleform::Render::TessMesh *v13; // rcx

  while ( 1 )
  {
    Size = this->Meshes.Size;
    v3 = 1;
    v4 = 0i64;
    if ( !Size )
      break;
    do
    {
      v5 = &this->Meshes.Pages[v4 >> 4][v4 & 0xF];
      if ( v5->VertexCount > this->VertexLimit )
      {
        Scaleform::Render::Tessellator::splitMesh(this, v5);
        v3 = 0;
      }
      ++v4;
    }
    while ( v4 < Size );
    if ( v3 )
      break;
    for ( i = 0i64; i < this->Meshes.Size; this->Meshes.Pages[v7][v8].VertexCount = 0 )
    {
      v7 = i >> 4;
      v8 = i++ & 0xF;
    }
    for ( j = 0i64; j < this->MeshVertices.Size; ++j )
    {
      v10 = &this->MeshVertices.Pages[j >> 4][j & 0xF];
      Mesh = v10->Mesh;
      if ( Mesh != 0xFFFF )
      {
        v12 = Mesh & 0xF;
        v13 = this->Meshes.Pages[(unsigned __int64)Mesh >> 4];
        v10->Idx = v13[v12].VertexCount++;
      }
    }
  }
}

// File Line: 2294
// RVA: 0x9E1870
__int64 __fastcall Scaleform::Render::Tessellator::emitVertex(
        Scaleform::Render::Tessellator *this,
        unsigned int meshIdx,
        unsigned int ver,
        unsigned int style1,
        unsigned int style2,
        unsigned int flags,
        bool strictStyle)
{
  Scaleform::Render::TessVertex **Pages; // rsi
  unsigned int v8; // r8d
  Scaleform::Render::TessVertex *v11; // rax
  unsigned int Idx; // edx
  __int64 v13; // rax
  __int64 result; // rax
  unsigned int v15; // edx
  unsigned __int64 Size; // rsi
  float v17; // ebp
  float v18; // r14d
  unsigned __int64 v19; // rdi
  Scaleform::Render::TessVertex *v20; // r8
  int v21; // [rsp+2Ch] [rbp-2Ch]
  int v22; // [rsp+30h] [rbp-28h]

  Pages = this->MeshVertices.Pages;
  v8 = ver & 0xFFFFFFF;
  v11 = Pages[(unsigned __int64)v8 >> 4];
  Idx = v11[v8 & 0xF].Idx;
  v13 = (__int64)&v11[v8 & 0xF];
  if ( Idx == -1 )
  {
    *(_DWORD *)(v13 + 8) = v8;
    *(_WORD *)(v13 + 12) = style1;
    *(_WORD *)(v13 + 14) = style2;
    *(_WORD *)(v13 + 18) = meshIdx;
    *(_WORD *)(v13 + 16) = flags;
    return v8;
  }
  else if ( *(unsigned __int16 *)(v13 + 18) == meshIdx
         && *(unsigned __int16 *)(v13 + 12) == style1
         && *(unsigned __int16 *)(v13 + 14) == style2
         && (!strictStyle || *(unsigned __int16 *)(v13 + 16) == flags) )
  {
    return v8;
  }
  else if ( Idx == v8 )
  {
LABEL_16:
    Size = this->MeshVertices.Size;
    *(_DWORD *)(v13 + 8) = Size;
    v17 = *(float *)v13;
    v18 = *(float *)(v13 + 4);
    HIWORD(v22) = meshIdx;
    HIWORD(v21) = style2;
    LOWORD(v21) = style1;
    LOWORD(v22) = flags;
    v19 = this->MeshVertices.Size >> 4;
    if ( v19 >= this->MeshVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(&this->MeshVertices, v19);
    result = (unsigned int)Size;
    v20 = &this->MeshVertices.Pages[v19][this->MeshVertices.Size & 0xF];
    v20->x = v17;
    v20->y = v18;
    v20->Idx = Size;
    *(_DWORD *)v20->Styles = v21;
    *(_DWORD *)&v20->Flags = v22;
    ++this->MeshVertices.Size;
  }
  else
  {
    while ( 1 )
    {
      v15 = *(_DWORD *)(v13 + 8);
      v13 = (__int64)&Pages[(unsigned __int64)v15 >> 4][v15 & 0xF];
      if ( *(unsigned __int16 *)(v13 + 18) == meshIdx
        && *(unsigned __int16 *)(v13 + 12) == style1
        && *(unsigned __int16 *)(v13 + 14) == style2
        && (!strictStyle || *(unsigned __int16 *)(v13 + 16) == flags) )
      {
        return v15;
      }
      if ( *(_DWORD *)(v13 + 8) == v15 )
        goto LABEL_16;
    }
  }
  return result;
}

// File Line: 2346
// RVA: 0x9D6360
void __fastcall Scaleform::Render::Tessellator::collectFanEdges(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *chain,
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *oppos,
        unsigned __int16 style)
{
  Scaleform::Render::Tessellator::MonoVertexType *v7; // rbp
  unsigned __int64 Size; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v9; // rdi
  unsigned __int16 v10; // si
  unsigned __int64 v11; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v12; // r10
  unsigned __int64 v13; // r8
  Scaleform::Render::TessVertex *v14; // r9
  Scaleform::Render::Tessellator::EdgeAAType *v15; // r8

  if ( oppos->Size )
    v7 = **oppos->Pages;
  else
    v7 = chain->Pages[(chain->Size - 1) >> 4][(LODWORD(chain->Size) - 1) & 0xF];
  Size = chain->Size;
  v9 = **chain->Pages;
  if ( Size )
  {
    v10 = style ^ 0x8000;
    v11 = 1i64;
    do
    {
      if ( v11 >= Size )
      {
        v13 = oppos->Size;
        if ( v13 )
          v12 = oppos->Pages[(v13 - 1) >> 4][((_DWORD)v13 - 1) & 0xF];
        else
          v12 = **chain->Pages;
      }
      else
      {
        v12 = chain->Pages[v11 >> 4][v11 & 0xF];
      }
      ++v11;
      v14 = &this->MeshVertices.Pages[(unsigned __int64)(v9->srcVer & 0xFFFFFFF) >> 4][v9->srcVer & 0xF];
      v15 = &this->EdgeFans.Array[v14->Mesh + v14->Idx];
      v15->cntVer = v9;
      v15->rayVer = v7;
      v15->slope = 0;
      v15->style = style;
      v15[1].cntVer = v9;
      v15[1].rayVer = v12;
      v15[1].slope = 0;
      v15[1].style = v10;
      v14->Mesh += 2;
      Size = chain->Size;
      v7 = v9;
      v9 = v12;
    }
    while ( v11 - 1 < Size );
  }
}

// File Line: 2381
// RVA: 0x9DCC50
__int64 __fastcall Scaleform::Render::Tessellator::countFanEdges(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::MonotoneType *m)
{
  Scaleform::Render::Tessellator::MonoVertexType *start; // r10
  unsigned int v3; // edi
  Scaleform::Render::Tessellator::MonoVertexType *v6; // r8
  Scaleform::Render::Tessellator::MonoVertexType *next; // rax
  int v8; // r9d
  int v9; // edx
  int v10; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v12; // rbx
  Scaleform::Render::Tessellator::MonoVertexType *v13; // r8
  Scaleform::Render::TessVertex *v14; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v15; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v16; // rax
  __int64 v17; // rcx
  Scaleform::Render::Tessellator::BaseLineType *lowerBase; // rcx
  Scaleform::Render::Tessellator::MonotoneType val; // [rsp+20h] [rbp-28h] BYREF

  start = m->start;
  v3 = 0;
  if ( m->start && (v6 = start->next) != 0i64 )
  {
    next = v6->next;
    if ( next )
    {
      while ( 1 )
      {
        v8 = start->srcVer & 0xFFFFFFF;
        v9 = v6->srcVer & 0xFFFFFFF;
        v10 = next->srcVer & 0xFFFFFFF;
        if ( v8 != v9 && v9 != v10 && v10 != v8 )
          break;
        start = v6;
        v6 = next;
        next = next->next;
        if ( !next )
          goto LABEL_8;
      }
      v12 = 0i64;
      m->start = start;
      v13 = start;
      if ( start )
      {
        while ( !v12 || ((v12->srcVer ^ v13->srcVer) & 0xFFFFFFF) != 0 )
        {
          v12 = v13;
          v3 += 2;
          v14 = this->MeshVertices.Pages[(unsigned __int64)(v13->srcVer & 0xFFFFFFF) >> 4];
          v14[v13->srcVer & 0xF].Mesh += 2;
          v13 = v13->next;
          if ( !v13 )
            return v3;
        }
        v15 = v13->next;
        if ( v15 )
        {
          if ( v15->next )
          {
            v16 = m->start;
            *(_QWORD *)&val.d.m.lastIdx = *(_QWORD *)&m->d.m.lastIdx;
            v17 = *(_QWORD *)&m->d.t.meshIdx;
            val.start = v16;
            *(_QWORD *)&val.d.t.meshIdx = v17;
            lowerBase = m->lowerBase;
            val.start = v13;
            val.lowerBase = lowerBase;
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16>::PushBack(
              &this->Monotones,
              &val);
          }
        }
        v12->next = 0i64;
      }
      return v3;
    }
    else
    {
LABEL_8:
      m->start = 0i64;
      return 0i64;
    }
  }
  else
  {
    m->start = 0i64;
    return 0i64;
  }
}

// File Line: 2449
// RVA: 0x9D64D0
void __fastcall Scaleform::Render::Tessellator::collectFanEdges(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::MonotoneType *m)
{
  Scaleform::Render::Tessellator::MonoVertexType *i; // rbx
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *p_LeftChain; // rdi
  unsigned __int64 v6; // rsi

  this->LeftChain.Size = 0i64;
  this->RightChain.Size = 0i64;
  for ( i = m->start; i; i = i->next )
  {
    p_LeftChain = &this->LeftChain;
    if ( (i->srcVer & 0x80000000) == 0 )
      p_LeftChain = &this->RightChain;
    v6 = p_LeftChain->Size >> 4;
    if ( v6 >= p_LeftChain->NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8>::allocPage(
        p_LeftChain,
        p_LeftChain->Size >> 4);
    p_LeftChain->Pages[v6][p_LeftChain->Size & 0xF] = i;
    ++p_LeftChain->Size;
  }
  if ( this->LeftChain.Size )
    Scaleform::Render::Tessellator::collectFanEdges(this, &this->LeftChain, &this->RightChain, m->style | 0x8000);
  if ( this->RightChain.Size )
    Scaleform::Render::Tessellator::collectFanEdges(this, &this->RightChain, &this->LeftChain, m->style);
}

// File Line: 2485
// RVA: 0x9D6E80
__int64 __fastcall Scaleform::Render::Tessellator::computeMiter(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::TessVertex *v1,
        Scaleform::Render::TessVertex *v2,
        Scaleform::Render::TessVertex *v3,
        Scaleform::Render::TessVertex *newVer1,
        Scaleform::Render::TessVertex *newVer2)
{
  float x; // xmm7_4
  __m128 y_low; // xmm8
  __m128 v12; // xmm12
  __m128 v13; // xmm6
  float v14; // xmm13_4
  __m128 v15; // xmm0
  float v16; // xmm10_4
  __m128 v17; // xmm0
  float len2; // xmm11_4
  float EdgeAAWidth; // xmm4_4
  float v20; // xmm9_4
  float v21; // xmm15_4
  bool v22; // cl
  unsigned __int8 v23; // dl
  float v24; // xmm6_4
  float v25; // xmm12_4
  float v26; // xmm15_4
  float v27; // xmm14_4
  float v28; // xmm5_4
  __m128 v29; // xmm2
  float v30; // xmm3_4
  __int64 result; // rax
  float v32; // xmm1_4
  __m128 v33; // xmm0
  float v34; // xmm13_4
  float v35; // xmm3_4
  float v36; // xmm6_4
  float v37; // xmm1_4
  float v38; // xmm6_4
  __m128 v39; // xmm13
  __m128 v40; // xmm1
  float v41; // xmm0_4
  float v42; // xmm4_4
  float v43; // xmm4_4
  float v44; // xmm4_4
  float v45; // [rsp+30h] [rbp-E8h]
  float v46; // [rsp+38h] [rbp-E0h]
  float v47; // [rsp+120h] [rbp+8h]
  float v48; // [rsp+128h] [rbp+10h]

  x = v2->x;
  y_low = (__m128)LODWORD(v2->y);
  v12 = (__m128)LODWORD(v3->y);
  v12.m128_f32[0] = v12.m128_f32[0] - y_low.m128_f32[0];
  v13 = y_low;
  v13.m128_f32[0] = y_low.m128_f32[0] - v1->y;
  v14 = v3->x;
  v15 = v13;
  v15.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)((float)(x - v1->x) * (float)(x - v1->x));
  v16 = _mm_sqrt_ps(v15).m128_f32[0];
  v17 = v12;
  v17.m128_f32[0] = (float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)((float)(v3->x - x) * (float)(v3->x - x));
  len2 = _mm_sqrt_ps(v17).m128_f32[0];
  v17.m128_f32[0] = Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType>(
                      v1,
                      v2,
                      v3,
                      v16,
                      len2);
  EdgeAAWidth = this->EdgeAAWidth;
  v20 = 0.0;
  v21 = EdgeAAWidth * v13.m128_f32[0];
  v22 = v17.m128_f32[0] < 0.0;
  v23 = 0;
  v24 = v1->x;
  LODWORD(v46) = v17.m128_i32[0] & _xmm;
  v25 = (float)(v12.m128_f32[0] * EdgeAAWidth) * (float)(1.0 / len2);
  v26 = v21 * (float)(1.0 / v16);
  v27 = (float)((float)(v1->x - x) * EdgeAAWidth) * (float)(1.0 / v16);
  v28 = (float)((float)(x - v14) * EdgeAAWidth) * (float)(1.0 / len2);
  if ( COERCE_FLOAT(v17.m128_i32[0] & _xmm) < 0.125 )
  {
    if ( v16 <= len2 )
    {
      v30 = x + v25;
      v29.m128_f32[0] = y_low.m128_f32[0] + v28;
      goto LABEL_5;
    }
    x = x + v26;
    y_low.m128_f32[0] = y_low.m128_f32[0] + v27;
    goto LABEL_4;
  }
  v45 = v24 + v26;
  v32 = (float)(v3->y + v28) - (float)(y_low.m128_f32[0] + v28);
  v48 = x + v25;
  v33 = y_low;
  v34 = (float)(v14 + v25) - (float)(x + v25);
  v33.m128_f32[0] = y_low.m128_f32[0] + v27;
  v29 = v33;
  v35 = (float)(x + v26) - (float)(v24 + v26);
  v29.m128_f32[0] = (float)(y_low.m128_f32[0] + v27) - (float)(v1->y + v27);
  v47 = v1->y + v27;
  v36 = (float)(v32 * v35) - (float)(v34 * v29.m128_f32[0]);
  if ( COERCE_FLOAT(LODWORD(v36) & _xmm) < (float)((float)(len2 + v16) * this->IntersectionEpsilon) )
  {
LABEL_4:
    v29.m128_i32[0] = y_low.m128_i32[0];
    v30 = x;
    goto LABEL_5;
  }
  v37 = (float)((float)((float)(v47 - (float)(y_low.m128_f32[0] + v28)) * v34) - (float)((float)(v45 - v48) * v32))
      / v36;
  v29.m128_f32[0] = (float)(v29.m128_f32[0] * v37) + v47;
  v30 = (float)(v35 * v37) + v45;
  v39 = v29;
  v38 = v30 - x;
  v39.m128_f32[0] = v29.m128_f32[0] - y_low.m128_f32[0];
  v40 = v39;
  v40.m128_f32[0] = (float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v38 * v38);
  LODWORD(v41) = _mm_sqrt_ps(v40).m128_u32[0];
  if ( v22 )
  {
    v42 = EdgeAAWidth * 4.0;
  }
  else
  {
    if ( v16 >= len2 )
      v43 = len2;
    else
      v43 = v16;
    v42 = v43 / v46;
  }
  if ( v41 > v42 )
  {
    if ( newVer2 )
    {
      if ( v22 )
        v20 = FLOAT_2_0;
      v23 = 1;
      v29.m128_f32[0] = (float)(v20 * v26) + (float)(y_low.m128_f32[0] + v27);
      v30 = (float)(x + v26) - (float)(v20 * v27);
      newVer2->x = (float)(v20 * v28) + v48;
      newVer2->y = (float)(v28 + v2->y) - (float)(v20 * v25);
    }
    else
    {
      v44 = v42 / v41;
      v30 = (float)(v38 * v44) + x;
      v29.m128_f32[0] = (float)(v39.m128_f32[0] * v44) + y_low.m128_f32[0];
    }
  }
LABEL_5:
  result = v23;
  newVer1->x = v30;
  LODWORD(newVer1->y) = v29.m128_i32[0];
  return result;
}

// File Line: 2579
// RVA: 0x9EC880
void __fastcall Scaleform::Render::Tessellator::processFan(
        Scaleform::Render::Tessellator *this,
        unsigned int start,
        unsigned int end)
{
  unsigned int v3; // esi
  unsigned int v4; // r14d
  unsigned int v6; // r12d
  unsigned __int64 v7; // r13
  unsigned int v8; // r13d
  __int64 v9; // r14
  Scaleform::Render::Tessellator::EdgeAAType *Array; // r8
  bool v11; // zf
  unsigned __int64 v12; // r15
  unsigned __int64 v13; // r15
  Scaleform::Render::Tessellator::EdgeAAType *v14; // r9
  Scaleform::Render::TessVertex *v15; // rax
  float v16; // xmm6_4
  float v17; // xmm7_4
  unsigned __int64 v18; // rdx
  unsigned __int64 v19; // r8
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *p_MeshVertices; // rbx
  unsigned __int64 v21; // rdi
  unsigned int v22; // xmm0_4
  int v23; // xmm1_4
  __int64 v24; // rdx
  Scaleform::Render::TessVertex *v25; // rax
  int v26; // xmm0_4
  unsigned int *v27; // r14
  unsigned __int64 v28; // rsi
  unsigned __int64 v29; // r8
  Scaleform::Render::Tessellator::EdgeAAType *v30; // rax
  unsigned int Size; // edx
  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *p_StarVertices; // rsi
  unsigned __int64 v33; // rdx
  unsigned __int64 v34; // r13
  unsigned __int64 v35; // r8
  unsigned int **Pages; // rax
  __int64 v37; // rdi
  unsigned __int64 v38; // rcx
  unsigned int *v39; // rax
  Scaleform::Render::Tessellator::EdgeAAType *v40; // r8
  __int64 v41; // r15
  Scaleform::Render::Tessellator::EdgeAAType *v42; // r12
  unsigned int srcVer; // r11d
  Scaleform::Render::Tessellator::MonoVertexType *cntVer; // rax
  unsigned int v45; // r10d
  unsigned int v46; // ecx
  float y; // xmm6_4
  float x; // xmm7_4
  Scaleform::Render::TessVertex **v49; // r8
  unsigned int v50; // r10d
  unsigned int v51; // r8d
  unsigned int v52; // esi
  int v53; // edx
  __int64 v54; // rax
  unsigned __int16 v55; // ax
  unsigned __int64 v56; // rdi
  unsigned int Idx; // xmm0_4
  int v58; // xmm1_4
  __int64 v59; // rdx
  Scaleform::Render::TessVertex *v60; // rax
  int v61; // xmm0_4
  unsigned __int64 v62; // rdi
  Scaleform::Render::Tessellator::EdgeAAType *v63; // rax
  Scaleform::Render::Tessellator::MonoVertexType *rayVer; // r8
  __int64 v65; // r13
  unsigned int v66; // r11d
  unsigned int v67; // r9d
  unsigned __int64 v68; // r15
  Scaleform::Render::Tessellator::InnerQuadType *v69; // rcx
  __int64 v70; // rdx
  char v71; // r15
  unsigned int v72; // r10d
  char v73; // al
  float v74; // xmm6_4
  float v75; // xmm7_4
  Scaleform::Render::TessVertex **v76; // r8
  unsigned int v77; // r10d
  unsigned int v78; // r12d
  unsigned __int16 v79; // ax
  unsigned __int16 v80; // cx
  unsigned __int64 v81; // rdi
  unsigned int v82; // xmm0_4
  int v83; // xmm1_4
  __int64 v84; // rdx
  Scaleform::Render::TessVertex *v85; // rax
  int v86; // xmm0_4
  unsigned __int64 v87; // rdi
  Scaleform::Render::TessVertex *v88; // rdx
  __int64 v89; // r8
  int v90; // eax
  unsigned __int64 v91; // rdi
  unsigned __int64 v92; // r15
  unsigned __int64 v93; // rdi
  unsigned __int64 v94; // rcx
  unsigned __int64 v95; // r15
  Scaleform::Render::VertexBasic *v96; // r13
  unsigned __int64 v97; // rdi
  unsigned __int64 v98; // r15
  unsigned __int64 v99; // rdi
  unsigned __int64 v100; // rcx
  unsigned __int64 v101; // r15
  Scaleform::Render::VertexBasic *v102; // r13
  int v103; // ecx
  unsigned __int64 v104; // r15
  Scaleform::Render::Tessellator::OuterEdgeType *v105; // rcx
  __int64 v106; // rdx
  __int64 v107; // rax
  unsigned __int64 v108; // r15
  Scaleform::Render::Tessellator::OuterEdgeType *v109; // rcx
  __int64 v110; // rdx
  Scaleform::Render::TessVertex newVer1; // [rsp+10h] [rbp-69h] BYREF
  int newVer2; // [rsp+28h] [rbp-51h]
  unsigned int newVer2_4; // [rsp+2Ch] [rbp-4Dh]
  Scaleform::Render::TessVertex v114; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::Render::VertexBasic v115; // [rsp+48h] [rbp-31h]
  Scaleform::Render::Tessellator::EdgeAAType *v116; // [rsp+50h] [rbp-29h]
  Scaleform::Render::Tessellator::EdgeAAType *v117; // [rsp+58h] [rbp-21h]
  unsigned __int64 v118; // [rsp+60h] [rbp-19h]
  __int64 v119; // [rsp+70h] [rbp-9h]
  char v120; // [rsp+E8h] [rbp+6Fh]
  unsigned int vars0; // [rsp+F0h] [rbp+77h]
  unsigned __int64 retaddr; // [rsp+F8h] [rbp+7Fh]

  if ( start != end )
  {
    v3 = start;
    v4 = end;
    v6 = end - 1;
    this->StartFan.Size = 0i64;
    this->EndFan.Size = 0i64;
    v7 = start;
    retaddr = start;
    newVer2 = end - start;
    if ( start < end )
    {
      v8 = vars0;
      v9 = start;
      while ( 1 )
      {
        Array = this->EdgeFans.Array;
        if ( ((Array[v6].rayVer->srcVer ^ Array[v9].rayVer->srcVer) & 0xFFFFFFF) == 0 )
          break;
        if ( Array[v6].slope != Array[v9].slope && (Array[v6].style & 0x8000) == 0 )
        {
          v11 = (Array[v9].style & 0x8000u) == 0;
LABEL_9:
          if ( !v11 )
          {
            v12 = this->StartFan.Size >> 3;
            if ( v12 >= this->StartFan.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)&this->StartFan,
                this->StartFan.Size >> 3);
            this->StartFan.Pages[v12][this->StartFan.Size & 7] = v3;
            ++this->StartFan.Size;
            v13 = this->EndFan.Size >> 3;
            if ( v13 >= this->EndFan.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)&this->EndFan,
                this->EndFan.Size >> 3);
            this->EndFan.Pages[v13][this->EndFan.Size & 7] = v6;
            ++this->EndFan.Size;
          }
        }
        v6 = v3++;
        ++v9;
        if ( v3 >= v8 )
        {
          v7 = retaddr;
          v4 = vars0;
          goto LABEL_17;
        }
      }
      v11 = ((Array[v6].style ^ Array[v9].style) & 0x7FFF) == 0;
      goto LABEL_9;
    }
LABEL_17:
    if ( this->StartFan.Size )
    {
      v27 = *this->EndFan.Pages;
      v28 = this->EndFan.Size >> 3;
      if ( v28 >= this->EndFan.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)&this->EndFan,
          this->EndFan.Size >> 3);
      v29 = 0i64;
      this->EndFan.Pages[v28][this->EndFan.Size & 7] = *v27;
      ++this->EndFan.Size;
      v30 = this->EdgeFans.Array;
      Size = this->StarVertices.Size;
      newVer2_4 = Size;
      v11 = this->StartFan.Size == 0;
      LODWORD(v115.x) = v30[v7].cntVer->srcVer & 0xFFFFFFF;
      if ( !v11 )
      {
        p_StarVertices = (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StarVertices;
        do
        {
          v33 = v29 & 7;
          v34 = v29 >> 3;
          v35 = v29 + 1;
          Pages = this->EndFan.Pages;
          retaddr = v33;
          v37 = this->StartFan.Pages[v34][v33];
          v38 = v35 & 7;
          v118 = v35;
          v39 = Pages[v35 >> 3];
          v40 = this->EdgeFans.Array;
          v41 = v39[v38];
          v42 = &v40[v37];
          srcVer = v42->rayVer->srcVer;
          cntVer = v42->cntVer;
          v116 = v42;
          v45 = cntVer->srcVer;
          if ( (srcVer & 0xFFFFFFF) == (cntVer->srcVer & 0xFFFFFFF)
            || (v46 = v40[v41].rayVer->srcVer, (v46 & 0xFFFFFFF) == (cntVer->srcVer & 0xFFFFFFF)) )
          {
            v49 = this->MeshVertices.Pages;
            v50 = v45 & 0xFFFFFFF;
            x = v49[(unsigned __int64)v50 >> 4][v50 & 0xF].x;
            newVer1.x = x;
            y = v49[(unsigned __int64)v50 >> 4][v50 & 0xF].y;
            newVer1.y = y;
          }
          else
          {
            Scaleform::Render::Tessellator::computeMiter(
              this,
              &this->MeshVertices.Pages[(unsigned __int64)(srcVer & 0xFFFFFFF) >> 4][srcVer & 0xF],
              &this->MeshVertices.Pages[(unsigned __int64)(v45 & 0xFFFFFFF) >> 4][v45 & 0xF],
              &this->MeshVertices.Pages[(unsigned __int64)(v46 & 0xFFFFFFF) >> 4][v46 & 0xF],
              &newVer1,
              0i64);
            y = newVer1.y;
            x = newVer1.x;
          }
          v51 = this->MeshVertices.Size;
          if ( (unsigned int)v41 >= (unsigned int)v37
            || (LODWORD(v41) = newVer2 + v41, (unsigned int)v37 <= (unsigned int)v41) )
          {
            v52 = vars0;
            v53 = -newVer2;
            do
            {
              if ( (unsigned int)v37 >= v52 )
                v54 = (unsigned int)(v53 + v37);
              else
                v54 = (unsigned int)v37;
              LODWORD(v37) = v37 + 1;
              this->EdgeFans.Array[v54].cntVer->aaVer = v51;
            }
            while ( (unsigned int)v37 <= (unsigned int)v41 );
            p_StarVertices = (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StarVertices;
          }
          v55 = v42->style & 0x7FFF;
          v56 = this->MeshVertices.Size >> 4;
          newVer1.Idx = -1;
          *(_DWORD *)&newVer1.Flags = -65534;
          LODWORD(v115.y) = v51;
          newVer1.Styles[1] = v55;
          newVer1.Styles[0] = v55;
          if ( v56 >= this->MeshVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(&this->MeshVertices, v56);
          Idx = newVer1.Idx;
          v58 = *(_DWORD *)newVer1.Styles;
          v59 = this->MeshVertices.Size & 0xF;
          v60 = this->MeshVertices.Pages[v56];
          v60[v59].x = x;
          v60[v59].y = y;
          v60[v59].Idx = Idx;
          v61 = *(_DWORD *)&newVer1.Flags;
          *(_DWORD *)v60[v59].Styles = v58;
          *(_DWORD *)&v60[v59].Flags = v61;
          ++this->MeshVertices.Size;
          v62 = p_StarVertices->Size >> 4;
          if ( v62 >= p_StarVertices->NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
              p_StarVertices,
              p_StarVertices->Size >> 4);
          p_StarVertices->Pages[v62][p_StarVertices->Size & 0xF] = v115;
          ++p_StarVertices->Size;
          v63 = this->EdgeFans.Array;
          rayVer = v63[this->EndFan.Pages[v34][retaddr]].rayVer;
          v65 = (__int64)&v63[this->EndFan.Pages[v34][retaddr]];
          v66 = rayVer->srcVer;
          v67 = v42->rayVer->srcVer;
          v117 = (Scaleform::Render::Tessellator::EdgeAAType *)v65;
          if ( (v67 & 0xFFFFFFF) == (v66 & 0xFFFFFFF) )
          {
            if ( (rayVer->aaVer & 0x40000000) == 0 )
            {
              v68 = this->InnerQuads.Size >> 4;
              if ( v68 >= this->InnerQuads.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->InnerQuads,
                  this->InnerQuads.Size >> 4);
              v69 = this->InnerQuads.Pages[v68];
              v70 = this->InnerQuads.Size & 0xF;
              v69[v70].e1 = v42;
              v69[v70].e2 = (Scaleform::Render::Tessellator::EdgeAAType *)v65;
              ++this->InnerQuads.Size;
              v42->cntVer->aaVer |= 0x40000000u;
            }
          }
          else
          {
            v71 = 0;
            v72 = v42->cntVer->srcVer;
            v120 = 0;
            if ( (v67 & 0xFFFFFFF) == (v72 & 0xFFFFFFF) || (v66 & 0xFFFFFFF) == (v72 & 0xFFFFFFF) )
            {
              v76 = this->MeshVertices.Pages;
              v77 = v72 & 0xFFFFFFF;
              v75 = v76[(unsigned __int64)v77 >> 4][v77 & 0xF].x;
              newVer1.x = v75;
              v74 = v76[(unsigned __int64)v77 >> 4][v77 & 0xF].y;
              newVer1.y = v74;
            }
            else
            {
              v73 = Scaleform::Render::Tessellator::computeMiter(
                      this,
                      &this->MeshVertices.Pages[(unsigned __int64)(v66 & 0xFFFFFFF) >> 4][v66 & 0xF],
                      &this->MeshVertices.Pages[(unsigned __int64)(v72 & 0xFFFFFFF) >> 4][v72 & 0xF],
                      &this->MeshVertices.Pages[(unsigned __int64)(v67 & 0xFFFFFFF) >> 4][v67 & 0xF],
                      &newVer1,
                      &v114);
              v74 = newVer1.y;
              v75 = newVer1.x;
              v71 = v73;
              v120 = v73;
            }
            v78 = this->MeshVertices.Size;
            LODWORD(retaddr) = v78;
            v79 = *(_WORD *)(v65 + 16) & 0x7FFF;
            v80 = v116->style & 0x7FFF;
            newVer1.Idx = -1;
            *(_DWORD *)&v114.Flags = -65536;
            *(_DWORD *)&newVer1.Flags = -65536;
            newVer1.Styles[1] = v79;
            newVer1.Styles[0] = v79;
            v114.Styles[1] = v80;
            v114.Styles[0] = v80;
            if ( v79 != v80 )
              Scaleform::Render::Tessellator::setMesh(this, v79, v80);
            v81 = this->MeshVertices.Size >> 4;
            if ( v81 >= this->MeshVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
                &this->MeshVertices,
                this->MeshVertices.Size >> 4);
            v82 = newVer1.Idx;
            v83 = *(_DWORD *)newVer1.Styles;
            v84 = this->MeshVertices.Size & 0xF;
            v85 = this->MeshVertices.Pages[v81];
            v85[v84].x = v75;
            v85[v84].y = v74;
            v85[v84].Idx = v82;
            v86 = *(_DWORD *)&newVer1.Flags;
            *(_DWORD *)v85[v84].Styles = v83;
            *(_DWORD *)&v85[v84].Flags = v86;
            ++this->MeshVertices.Size;
            if ( v71 )
            {
              v87 = this->MeshVertices.Size >> 4;
              LODWORD(retaddr) = this->MeshVertices.Size;
              if ( v87 >= this->MeshVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
                  &this->MeshVertices,
                  this->MeshVertices.Size >> 4);
              v88 = this->MeshVertices.Pages[v87];
              v89 = this->MeshVertices.Size & 0xF;
              v88[v89].x = v114.x;
              v88[v89].y = v114.y;
              v90 = *(_DWORD *)v114.Styles;
              v88[v89].Idx = -1;
              *(_DWORD *)v88[v89].Styles = v90;
              *(_DWORD *)&v88[v89].Flags = *(_DWORD *)&v114.Flags;
              ++this->MeshVertices.Size;
            }
            v91 = p_StarVertices->Size;
            v92 = v91 - 1;
            v93 = v91 >> 4;
            v94 = v92;
            v95 = v92 & 0xF;
            v96 = p_StarVertices->Pages[v94 >> 4];
            if ( v93 >= p_StarVertices->NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(p_StarVertices, v93);
            p_StarVertices->Pages[v93][p_StarVertices->Size & 0xF] = v96[v95];
            v97 = ++p_StarVertices->Size;
            if ( v120 )
            {
              v98 = v97 - 1;
              v99 = v97 >> 4;
              v100 = v98;
              v101 = v98 & 0xF;
              v102 = p_StarVertices->Pages[v100 >> 4];
              if ( v99 >= p_StarVertices->NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(p_StarVertices, v99);
              p_StarVertices->Pages[v99][p_StarVertices->Size & 0xF] = v102[v101];
              ++p_StarVertices->Size;
              this->StarVertices.Pages[(this->StarVertices.Size - 3) >> 4][(LODWORD(this->StarVertices.Size) - 3) & 0xF].starVer = v78;
              v103 = retaddr;
              this->StarVertices.Pages[(this->StarVertices.Size - 2) >> 4][(LODWORD(this->StarVertices.Size) - 2) & 0xF].starVer = retaddr;
            }
            else
            {
              v103 = retaddr;
              this->StarVertices.Pages[(this->StarVertices.Size - 2) >> 4][(LODWORD(this->StarVertices.Size) - 2) & 0xF].starVer = v78;
            }
            LODWORD(v119) = v103;
            v104 = this->OuterEdges.Size >> 4;
            if ( v104 >= this->OuterEdges.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->OuterEdges,
                this->OuterEdges.Size >> 4);
            v105 = this->OuterEdges.Pages[v104];
            v106 = this->OuterEdges.Size & 0xF;
            v105[v106].edge = v116;
            v107 = v119;
            LODWORD(v119) = v78 | 0x40000000;
            *(_QWORD *)&v105[v106].outVer = v107;
            v108 = ++this->OuterEdges.Size >> 4;
            if ( v108 >= this->OuterEdges.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->OuterEdges,
                this->OuterEdges.Size >> 4);
            v109 = this->OuterEdges.Pages[v108];
            v110 = this->OuterEdges.Size & 0xF;
            v109[v110].edge = v117;
            *(_QWORD *)&v109[v110].outVer = v119;
            ++this->OuterEdges.Size;
          }
          v29 = v118;
        }
        while ( v118 < this->StartFan.Size );
        Size = newVer2_4;
      }
      if ( Size + 3 > this->StarVertices.Size && Size < this->StarVertices.Size )
        this->StarVertices.Size = Size;
    }
    else
    {
      v14 = this->EdgeFans.Array;
      newVer1.Idx = -1;
      *(_DWORD *)&newVer1.Flags = -65534;
      v15 = this->MeshVertices.Pages[(unsigned __int64)(v14[v7].cntVer->srcVer & 0xFFFFFFF) >> 4];
      v16 = v15[v14[v7].cntVer->srcVer & 0xF].x;
      v17 = v15[v14[v7].cntVer->srcVer & 0xF].y;
      newVer1.Styles[1] = v14[v7].style & 0x7FFF;
      newVer1.Styles[0] = newVer1.Styles[1];
      if ( v7 < v4 )
      {
        v18 = v7;
        v19 = v4 - v7;
        do
        {
          this->EdgeFans.Array[v18++].cntVer->aaVer = this->MeshVertices.Size;
          --v19;
        }
        while ( v19 );
      }
      p_MeshVertices = &this->MeshVertices;
      v21 = p_MeshVertices->Size >> 4;
      if ( v21 >= p_MeshVertices->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
          p_MeshVertices,
          p_MeshVertices->Size >> 4);
      v22 = newVer1.Idx;
      v23 = *(_DWORD *)newVer1.Styles;
      v24 = p_MeshVertices->Size & 0xF;
      v25 = p_MeshVertices->Pages[v21];
      v25[v24].x = v16;
      v25[v24].y = v17;
      v25[v24].Idx = v22;
      v26 = *(_DWORD *)&newVer1.Flags;
      *(_DWORD *)v25[v24].Styles = v23;
      *(_DWORD *)&v25[v24].Flags = v26;
      ++p_MeshVertices->Size;
    }
  }
}

// File Line: 2780
// RVA: 0x9E0940
void __fastcall Scaleform::Render::Tessellator::emitTriangles(Scaleform::Render::Tessellator *this)
{
  unsigned int v1; // r8d
  unsigned __int64 v3; // rdi
  Scaleform::Render::Tessellator::MonotoneType *v4; // rdi
  unsigned int prevIdx2; // r12d
  int v6; // esi
  unsigned int v7; // r14d
  int flags; // esi
  __int64 v9; // r15
  Scaleform::Render::Tessellator::TriangleType *v10; // rbx
  Scaleform::Render::Tessellator::MonoVertexType *v11; // rax
  unsigned int aaVer; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v13; // rax
  unsigned __int64 v14; // rdx
  unsigned __int64 v15; // rcx
  __int64 v16; // rdx
  Scaleform::Render::Tessellator::InnerQuadType *v17; // rax
  Scaleform::Render::Tessellator::EdgeAAType *e1; // r14
  Scaleform::Render::Tessellator::EdgeAAType *e2; // r15
  int v20; // ebx
  int v21; // edi
  unsigned int v22; // r10d
  __int64 v23; // rsi
  Scaleform::Render::TessMesh *v24; // r8
  unsigned int v25; // ecx
  Scaleform::Render::Tessellator::EdgeAAType *v26; // rax
  Scaleform::Render::Tessellator::MonoVertexType *cntVer; // rdx
  int v28; // r14d
  unsigned int v29; // r15d
  int v30; // r14d
  __int64 v31; // rsi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v32; // rbx
  unsigned __int64 v33; // rdi
  __int64 v34; // rdx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v35; // rbx
  unsigned __int64 v36; // rdi
  __int64 v37; // rdx
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::OuterEdgeType,4,16> *p_OuterEdges; // rsi
  unsigned __int64 Size; // r14
  unsigned int v40; // edx
  unsigned __int64 v41; // rbx
  Scaleform::Render::Tessellator::OuterEdgeType **Pages; // r12
  unsigned int *v43; // rbx
  __int64 v44; // r8
  __int64 v45; // r10
  Scaleform::Render::Tessellator::MonoVertexType *v46; // r11
  Scaleform::Render::Tessellator::OuterEdgeType **v47; // rsi
  Scaleform::Render::Tessellator::EdgeAAType *edge; // rax
  bool v49; // cf
  int v50; // r12d
  unsigned int v51; // r14d
  unsigned int v52; // r15d
  __int64 v53; // rdi
  unsigned int v54; // esi
  unsigned int v55; // eax
  __int64 v56; // r14
  int v57; // r12d
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v58; // rbx
  unsigned __int64 v59; // rdi
  Scaleform::Render::Tessellator::TriangleType *v60; // rdx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v61; // rbx
  unsigned __int64 v62; // rdi
  Scaleform::Render::Tessellator::TriangleType *v63; // rdx
  unsigned __int64 v64; // rdx
  unsigned int v65; // r12d
  Scaleform::Render::Tessellator::StarVertexType **v66; // r8
  unsigned __int64 v67; // r9
  unsigned __int64 v68; // rax
  unsigned int v69; // r14d
  Scaleform::Render::Tessellator::StarVertexType *v70; // r11
  __int64 v71; // rcx
  __int64 v72; // rax
  unsigned int *v73; // r11
  Scaleform::Render::TessVertex **v74; // r10
  unsigned int starVer; // edx
  unsigned int v76; // r8d
  unsigned __int64 v77; // rax
  __int64 v78; // rcx
  Scaleform::Render::TessVertex *v79; // rax
  unsigned __int64 v80; // rdi
  Scaleform::Render::TessVertex *v81; // r9
  Scaleform::Render::TessVertex *v82; // rax
  unsigned __int64 v83; // r15
  unsigned int v84; // edx
  Scaleform::Render::TessVertex *v85; // rax
  unsigned int v86; // esi
  unsigned int v87; // ebx
  unsigned int v88; // ecx
  unsigned __int64 v89; // rcx
  Scaleform::Render::Tessellator::StarVertexType **v90; // rdx
  Scaleform::Render::TessVertex **v91; // r8
  Scaleform::Render::TessVertex *v92; // rax
  unsigned int v93; // edi
  int v94; // r12d
  Scaleform::Render::TessVertex *v95; // rax
  unsigned int v96; // r15d
  int v97; // esi
  unsigned int v98; // r10d
  Scaleform::Render::TessMesh *v99; // rbx
  unsigned int v100; // eax
  unsigned int v101; // edx
  unsigned int v102; // eax
  Scaleform::Render::Tessellator::StarVertexType **v103; // rcx
  unsigned int v104; // r10d
  unsigned int v105; // r11d
  Scaleform::Render::TessMesh *v106; // rax
  unsigned int *Array; // rdx
  unsigned int v108; // r8d
  int v109; // r12d
  int v110; // edi
  int v111; // r15d
  unsigned int v112; // eax
  unsigned int v113; // eax
  bool v114; // zf
  unsigned int v115; // ecx
  unsigned int v116; // ecx
  unsigned int v117; // r12d
  __int64 v118; // rsi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v119; // rdi
  unsigned __int64 v120; // rbx
  __int64 v121; // rdx
  unsigned int v122; // r12d
  int v123; // ecx
  int v124; // eax
  unsigned int v125; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v126; // rbx
  unsigned __int64 v127; // rdi
  __int64 v128; // rdx
  unsigned int ver; // [rsp+40h] [rbp-59h]
  unsigned int vera; // [rsp+40h] [rbp-59h]
  unsigned int verb; // [rsp+40h] [rbp-59h]
  __int128 v132; // [rsp+48h] [rbp-51h]
  Scaleform::Render::Tessellator::MonoVertexType *v133; // [rsp+58h] [rbp-41h]
  Scaleform::Render::Tessellator::MonoVertexType *rayVer; // [rsp+60h] [rbp-39h]
  __int64 v135; // [rsp+60h] [rbp-39h]
  Scaleform::Render::Tessellator::MonoVertexType *v136; // [rsp+68h] [rbp-31h]
  unsigned int v137; // [rsp+68h] [rbp-31h]
  unsigned int v138; // [rsp+68h] [rbp-31h]
  unsigned int v139; // [rsp+70h] [rbp-29h]
  unsigned int v140; // [rsp+74h] [rbp-25h]
  unsigned int v141; // [rsp+78h] [rbp-21h]
  __int64 v142; // [rsp+80h] [rbp-19h]
  __int64 v143; // [rsp+88h] [rbp-11h]
  unsigned __int64 v144; // [rsp+90h] [rbp-9h]
  __int64 v145; // [rsp+98h] [rbp-1h]
  unsigned __int64 v146; // [rsp+A8h] [rbp+Fh]
  unsigned int style2; // [rsp+100h] [rbp+67h]
  unsigned int style2a; // [rsp+100h] [rbp+67h]
  unsigned int style2b; // [rsp+100h] [rbp+67h]
  unsigned int style2c; // [rsp+100h] [rbp+67h]
  unsigned int meshIdx; // [rsp+108h] [rbp+6Fh]
  unsigned int meshIdxa; // [rsp+108h] [rbp+6Fh]
  unsigned int meshIdxb; // [rsp+108h] [rbp+6Fh]
  unsigned int meshIdxc; // [rsp+108h] [rbp+6Fh]
  Scaleform::Render::Tessellator::MonoVertexType *style1; // [rsp+110h] [rbp+77h]
  unsigned int *style1a; // [rsp+110h] [rbp+77h]
  int style1b; // [rsp+110h] [rbp+77h]
  unsigned int style1c; // [rsp+110h] [rbp+77h]
  unsigned int style1d; // [rsp+110h] [rbp+77h]
  Scaleform::Render::Tessellator::MonoVertexType *v160; // [rsp+118h] [rbp+7Fh]
  __int64 v161; // [rsp+118h] [rbp+7Fh]
  unsigned int v162; // [rsp+118h] [rbp+7Fh]
  unsigned int v163; // [rsp+118h] [rbp+7Fh]

  v1 = 0;
  style2 = 0;
  if ( this->Monotones.Size )
  {
    v3 = 0i64;
    do
    {
      v4 = &this->Monotones.Pages[v3 >> 4][v3 & 0xF];
      if ( v4->d.m.prevIdx1 )
      {
        prevIdx2 = v4->d.m.prevIdx2;
        v6 = 0;
        if ( v4->style == this->Meshes.Pages[(unsigned __int64)prevIdx2 >> 4][prevIdx2 & 0xF].Style1 )
          v6 = 8;
        v7 = 0;
        flags = v6 | 2;
        v9 = v4->d.m.prevIdx2;
        do
        {
          v10 = &this->MeshTriangles.Arrays[v9].Pages[(unsigned __int64)(v7 + v4->d.m.lastIdx) >> 4][((_BYTE)v7 + LOBYTE(v4->d.m.lastIdx)) & 0xF];
          v10->d.m.v1->aaVer = Scaleform::Render::Tessellator::emitVertex(
                                 this,
                                 prevIdx2,
                                 v10->d.m.v1->aaVer,
                                 v4->style,
                                 flags);
          v10->d.m.v2->aaVer = Scaleform::Render::Tessellator::emitVertex(
                                 this,
                                 prevIdx2,
                                 v10->d.m.v2->aaVer,
                                 v4->style,
                                 flags);
          ++v7;
          v10->d.m.v3->aaVer = Scaleform::Render::Tessellator::emitVertex(
                                 this,
                                 prevIdx2,
                                 v10->d.m.v3->aaVer,
                                 v4->style,
                                 flags);
          v11 = v10->d.m.v2;
          v10->d.t.v1 = v10->d.m.v1->aaVer & 0xFFFFFFF;
          aaVer = v11->aaVer;
          v13 = v10->d.m.v3;
          v10->d.t.v2 = aaVer & 0xFFFFFFF;
          v10->d.t.v3 = v13->aaVer & 0xFFFFFFF;
        }
        while ( v7 < v4->d.m.prevIdx1 );
        v1 = style2;
      }
      v3 = ++v1;
      style2 = v1;
    }
    while ( v1 < this->Monotones.Size );
  }
  style2a = 0;
  if ( this->InnerQuads.Size )
  {
    v14 = 0i64;
    do
    {
      v15 = v14;
      v16 = v14 & 0xF;
      v17 = this->InnerQuads.Pages[v15 >> 4];
      e1 = v17[v16].e1;
      e2 = v17[v16].e2;
      v20 = e1->style & 0x7FFF;
      v21 = e2->style & 0x7FFF;
      v22 = Scaleform::Render::Tessellator::setMesh(this, v20, v21);
      meshIdx = v22;
      v23 = v22;
      v24 = &this->Meshes.Pages[(unsigned __int64)v22 >> 4][v22 & 0xF];
      v25 = v24->Style1;
      if ( v25 && v20 != v25 )
      {
        v26 = e1;
        e1 = e2;
        e2 = v26;
        LODWORD(v26) = v20;
        v20 = v21;
        v21 = (int)v26;
      }
      cntVer = e1->cntVer;
      rayVer = e1->rayVer;
      v28 = 0;
      v160 = e2->rayVer;
      style1 = cntVer;
      v136 = e2->cntVer;
      v29 = v20;
      if ( ((v24->Flags1 ^ v24->Flags2) & 0x8000) != 0 )
      {
        v29 = v21;
        v28 = 32;
      }
      v30 = v28 | 0xA;
      cntVer->aaVer = Scaleform::Render::Tessellator::emitVertex(this, v22, cntVer->aaVer, v20, v29, v30, 0);
      rayVer->aaVer = Scaleform::Render::Tessellator::emitVertex(this, meshIdx, rayVer->aaVer, v20, v29, v30, 0);
      v136->aaVer = Scaleform::Render::Tessellator::emitVertex(this, meshIdx, v136->aaVer, v21, 2u);
      v31 = v23;
      v160->aaVer = Scaleform::Render::Tessellator::emitVertex(this, meshIdx, v160->aaVer, v21, 2u);
      v32 = &this->MeshTriangles.Arrays[v31];
      LODWORD(v132) = style1->aaVer & 0xFFFFFFF;
      v33 = v32->Size >> 4;
      DWORD1(v132) = rayVer->aaVer & 0xFFFFFFF;
      DWORD2(v132) = v136->aaVer & 0xFFFFFFF;
      if ( v33 >= v32->NumPages )
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
          &this->MeshTriangles,
          v32,
          v33);
      v34 = (__int64)&v32->Pages[v33][v32->Size & 0xF];
      *(_OWORD *)v34 = v132;
      *(_QWORD *)(v34 + 16) = v133;
      ++this->MeshTriangles.Arrays[v31].Size;
      v35 = &this->MeshTriangles.Arrays[v31];
      LODWORD(v132) = v160->aaVer & 0xFFFFFFF;
      v36 = v35->Size >> 4;
      DWORD1(v132) = v136->aaVer & 0xFFFFFFF;
      DWORD2(v132) = rayVer->aaVer & 0xFFFFFFF;
      if ( v36 >= v35->NumPages )
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
          &this->MeshTriangles,
          v35,
          v36);
      v37 = (__int64)&v35->Pages[v36][v35->Size & 0xF];
      *(_OWORD *)v37 = v132;
      *(_QWORD *)(v37 + 16) = v133;
      ++this->MeshTriangles.Arrays[v31].Size;
      v14 = ++style2a;
    }
    while ( style2a < this->InnerQuads.Size );
  }
  p_OuterEdges = &this->OuterEdges;
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::OuterEdgeType,4,16>,bool (*)(Scaleform::Render::Tessellator::OuterEdgeType const &,Scaleform::Render::Tessellator::OuterEdgeType const &)>(
    &this->OuterEdges,
    0i64,
    this->OuterEdges.Size,
    Scaleform::Render::Tessellator::cmpOuterEdges);
  Size = this->OuterEdges.Size;
  v40 = 0;
  style2b = 0;
  if ( Size )
  {
    v41 = 0i64;
    do
    {
      Pages = this->OuterEdges.Pages;
      v43 = (unsigned int *)&Pages[v41 >> 4][v41 & 0xF];
      style1a = v43;
      if ( (v43[2] & 0x40000000) == 0 )
      {
        v44 = p_OuterEdges->Size;
        v45 = 0i64;
        v46 = *(Scaleform::Render::Tessellator::MonoVertexType **)(*(_QWORD *)v43 + 8i64);
        if ( v44 > 0 )
        {
          v47 = p_OuterEdges->Pages;
          do
          {
            edge = v47[(unsigned __int64)((v44 >> 1) + v45) >> 4][((unsigned __int8)(v44 >> 1) + (_BYTE)v45) & 0xF].edge;
            v49 = edge->cntVer < v46;
            if ( edge->cntVer == v46 )
              v49 = edge->rayVer < (Scaleform::Render::Tessellator::MonoVertexType *)**(_QWORD **)v43;
            if ( v49 )
            {
              v45 += (v44 >> 1) + 1;
              v44 += -1 - (v44 >> 1);
            }
            else
            {
              v44 >>= 1;
            }
          }
          while ( v44 > 0 );
          v40 = style2b;
        }
        if ( (unsigned int)v45 < Size )
        {
          v161 = (__int64)&Pages[(unsigned __int64)(unsigned int)v45 >> 4][v45 & 0xF];
          if ( **(Scaleform::Render::Tessellator::MonoVertexType ***)v161 == v46 )
          {
            v50 = *(_WORD *)(*(_QWORD *)v43 + 16i64) & 0x7FFF;
            v51 = 0;
            v52 = Scaleform::Render::Tessellator::setMesh(this, v50);
            if ( v50 == this->Meshes.Pages[(unsigned __int64)v52 >> 4][v52 & 0xF].Style1 )
              v51 = 8;
            v53 = *(_QWORD *)(*(_QWORD *)v43 + 8i64);
            v54 = Scaleform::Render::Tessellator::emitVertex(
                    this,
                    v52,
                    *(_DWORD *)(**(_QWORD **)v43 + 4i64),
                    v50,
                    v51 | 2);
            meshIdxa = Scaleform::Render::Tessellator::emitVertex(this, v52, *(_DWORD *)(v53 + 4), v50, v51 | 2);
            v43[2] = Scaleform::Render::Tessellator::emitVertex(this, v52, v43[2], v50, v51) | 0x40000000;
            v55 = Scaleform::Render::Tessellator::emitVertex(this, v52, *(_DWORD *)(v161 + 8), v50, v51);
            *(_DWORD *)(v161 + 8) = v55 | 0x40000000;
            v56 = v52;
            v57 = v55 & 0xFFFFFFF;
            v58 = &this->MeshTriangles.Arrays[v56];
            style1b = style1a[2] & 0xFFFFFFF;
            DWORD2(v132) = style1b;
            v59 = v58->Size >> 4;
            if ( v59 >= v58->NumPages )
              Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
                &this->MeshTriangles,
                v58,
                v58->Size >> 4);
            v60 = &v58->Pages[v59][v58->Size & 0xF];
            v60->d.m.v1 = (Scaleform::Render::Tessellator::MonoVertexType *)__PAIR64__(meshIdxa, v54);
            v60->d.m.v2 = (Scaleform::Render::Tessellator::MonoVertexType *)*((_QWORD *)&v132 + 1);
            v60->d.m.v3 = v133;
            ++this->MeshTriangles.Arrays[v52].Size;
            v61 = &this->MeshTriangles.Arrays[v56];
            DWORD2(v132) = meshIdxa;
            v62 = v61->Size >> 4;
            if ( v62 >= v61->NumPages )
              Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
                &this->MeshTriangles,
                v61,
                v62);
            v63 = &v61->Pages[v62][v61->Size & 0xF];
            v63->d.m.v1 = (Scaleform::Render::Tessellator::MonoVertexType *)__PAIR64__(style1b, v57);
            v63->d.m.v2 = (Scaleform::Render::Tessellator::MonoVertexType *)*((_QWORD *)&v132 + 1);
            v63->d.m.v3 = v133;
            ++this->MeshTriangles.Arrays[v52].Size;
            v40 = style2b;
          }
        }
      }
      Size = this->OuterEdges.Size;
      ++v40;
      p_OuterEdges = &this->OuterEdges;
      v41 = v40;
      style2b = v40;
    }
    while ( v40 < Size );
  }
  v64 = this->StarVertices.Size;
  v65 = 0;
  v162 = 0;
  if ( v64 )
  {
    while ( 1 )
    {
      v66 = this->StarVertices.Pages;
      v67 = v65;
      v68 = (unsigned __int64)v65 >> 4;
      v135 = v65;
      v69 = v65;
      v70 = v66[v68];
      v71 = 8 * v68;
      v72 = v65 & 0xF;
      v143 = v71;
      v73 = (unsigned int *)&v70[v72];
      v145 = v72;
      v137 = *v73;
      do
        ++v69;
      while ( v69 < v64 && *v73 == v66[(unsigned __int64)v69 >> 4][v69 & 0xF].cntVer );
      if ( v65 + 3 == v69 )
        break;
LABEL_54:
      v89 = v69 - 1;
      if ( v65 < v69 )
      {
        do
        {
          v90 = this->StarVertices.Pages;
          style2c = v90[v89 >> 4][v89 & 0xF].starVer;
          v91 = this->MeshVertices.Pages;
          meshIdxc = v90[v67 >> 4][v67 & 0xF].starVer;
          v92 = v91[(unsigned __int64)style2c >> 4];
          v93 = v92[style2c & 0xF].Styles[0];
          v94 = v92[style2c & 0xF].Flags & 2;
          v95 = v91[(unsigned __int64)meshIdxc >> 4];
          v96 = v95[meshIdxc & 0xF].Styles[0];
          style1d = v94;
          v97 = v95[meshIdxc & 0xF].Flags & 2;
          v98 = Scaleform::Render::Tessellator::setMesh(this, v93, v96);
          v142 = v98;
          vera = v98;
          v99 = &this->Meshes.Pages[(unsigned __int64)v98 >> 4][v98 & 0xF];
          v100 = v99->Style1;
          if ( !v100 || v93 == v100 )
          {
            v101 = style2c;
          }
          else
          {
            v101 = meshIdxc;
            style1d = v97;
            meshIdxc = style2c;
            v102 = v93;
            v93 = v96;
            v96 = v102;
            v97 = v94;
          }
          v122 = v93;
          v123 = style1d | 8;
          if ( ((v99->Flags2 ^ v99->Flags1) & 0x8000) != 0 )
          {
            v122 = v96;
            v123 = style1d | 0x28;
          }
          LODWORD(v132) = Scaleform::Render::Tessellator::emitVertex(this, v98, v101, v93, v122, v123, 0);
          DWORD1(v132) = Scaleform::Render::Tessellator::emitVertex(this, vera, meshIdxc, v96, v97);
          v124 = (((unsigned __int8)style1d & (unsigned __int8)v97 & 2) != 0) + 1;
          if ( ((v99->Flags2 | v99->Flags1) & 0x8000) != 0 )
          {
            v125 = v124 & 0xFFFFFFD3 | 0x24;
          }
          else
          {
            v122 = v96;
            v125 = v124 | 0x10;
          }
          DWORD2(v132) = Scaleform::Render::Tessellator::emitVertex(this, vera, v137, v93, v122, v125, 1);
          v126 = &this->MeshTriangles.Arrays[v142];
          v127 = v126->Size >> 4;
          if ( v127 >= v126->NumPages )
            Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
              &this->MeshTriangles,
              v126,
              v126->Size >> 4);
          v67 = v135 + 1;
          v128 = (__int64)&v126->Pages[v127][v126->Size & 0xF];
          v89 = v162;
          *(_OWORD *)v128 = v132;
          ++v162;
          *(_QWORD *)(v128 + 16) = v133;
          ++v135;
          ++this->MeshTriangles.Arrays[v142].Size;
        }
        while ( v162 < v69 );
      }
LABEL_94:
      v64 = this->StarVertices.Size;
      v65 = v69;
      v162 = v69;
      if ( v69 >= v64 )
        return;
    }
    v74 = this->MeshVertices.Pages;
    v146 = (unsigned __int64)(v65 + 1) >> 4;
    starVer = v66[v146][((_BYTE)v65 + 1) & 0xF].starVer;
    v144 = (unsigned __int64)(v65 + 2) >> 4;
    v76 = v66[v144][((_BYTE)v65 + 2) & 0xF].starVer;
    v77 = v73[1];
    v78 = v77 & 0xF;
    v79 = v74[v77 >> 4];
    v80 = v79[v78].Styles[0];
    v81 = &v79[v78];
    style1c = v80;
    v82 = v74[(unsigned __int64)starVer >> 4];
    v83 = v82[starVer & 0xF].Styles[0];
    v84 = v82[starVer & 0xF].Flags;
    v140 = v81->Flags;
    v85 = v74[(unsigned __int64)v76 >> 4];
    v141 = v84;
    v86 = v85[v76 & 0xF].Styles[0];
    meshIdxb = v83;
    v139 = v85[v76 & 0xF].Flags;
    ver = Scaleform::Render::Tessellator::setMesh(this, v80, v83);
    v87 = Scaleform::Render::Tessellator::setMesh(this, v83, v86);
    v88 = Scaleform::Render::Tessellator::setMesh(this, v86, v80);
    if ( ver == v87 || ver == v88 )
    {
      v87 = ver;
    }
    else if ( v87 != v88 )
    {
LABEL_53:
      v67 = v65;
      goto LABEL_54;
    }
    if ( v87 != -1 )
    {
      v103 = this->StarVertices.Pages;
      v104 = (*(Scaleform::Render::Tessellator::StarVertexType **)((char *)v103 + v143))[v145].starVer;
      v105 = v103[v146][((_BYTE)v65 + 1) & 0xF].starVer;
      v138 = v104;
      v163 = v105;
      verb = v103[v144][((_BYTE)v65 + 2) & 0xF].starVer;
      *(_QWORD *)((char *)&v132 + 4) = -1i64;
      LODWORD(v132) = -1;
      v106 = this->Meshes.Pages[(unsigned __int64)v87 >> 4];
      if ( ((v106[v87 & 0xF].Flags1 ^ v106[v87 & 0xF].Flags2) & 0x8000) != 0 )
      {
        Array = this->ComplexFlags.Array;
        v108 = v86;
        v109 = Array[v80 >> 5] & (1 << (v80 & 0x1F));
        v110 = Array[v83 >> 5] & (1 << (v83 & 0x1F));
        v111 = Array[(unsigned __int64)v86 >> 5] & (1 << (v86 & 0x1F));
        if ( v109 )
        {
          v112 = meshIdxb;
          if ( v110 )
            v112 = v86;
          v113 = Scaleform::Render::Tessellator::emitVertex(this, v87, v104, style1c, v112, v140 | 0x20, 0);
          v108 = v86;
          v105 = v163;
          LODWORD(v132) = v113;
        }
        v114 = v110 == 0;
        LODWORD(v80) = style1c;
        if ( !v114 )
        {
          v115 = v108;
          if ( v111 )
            v115 = style1c;
          DWORD1(v132) = Scaleform::Render::Tessellator::emitVertex(this, v87, v105, meshIdxb, v115, v141 | 0x20, 0);
        }
        v114 = v111 == 0;
        LODWORD(v83) = meshIdxb;
        if ( v114 )
        {
          v117 = v86;
        }
        else
        {
          v116 = style1c;
          v114 = v109 == 0;
          v117 = v86;
          if ( !v114 )
            v116 = meshIdxb;
          DWORD2(v132) = Scaleform::Render::Tessellator::emitVertex(this, v87, verb, v86, v116, v139 | 0x20, 0);
        }
        if ( (_DWORD)v132 == -1 )
        {
          v104 = v138;
          goto LABEL_76;
        }
      }
      else
      {
        v117 = v86;
LABEL_76:
        LODWORD(v132) = Scaleform::Render::Tessellator::emitVertex(this, v87, v104, v80, v140);
      }
      if ( DWORD1(v132) == -1 )
        DWORD1(v132) = Scaleform::Render::Tessellator::emitVertex(this, v87, v163, v83, v141);
      if ( DWORD2(v132) == -1 )
        DWORD2(v132) = Scaleform::Render::Tessellator::emitVertex(this, v87, verb, v117, v139);
      v118 = v87;
      v119 = &this->MeshTriangles.Arrays[v118];
      v120 = v119->Size >> 4;
      if ( v120 >= v119->NumPages )
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
          &this->MeshTriangles,
          &this->MeshTriangles.Arrays[v118],
          v119->Size >> 4);
      v121 = (__int64)&v119->Pages[v120][v119->Size & 0xF];
      *(_OWORD *)v121 = v132;
      *(_QWORD *)(v121 + 16) = v133;
      ++this->MeshTriangles.Arrays[v118].Size;
      goto LABEL_94;
    }
    goto LABEL_53;
  }
}

// File Line: 3058
// RVA: 0x9EA0C0
void __fastcall Scaleform::Render::Tessellator::moveVertexAA(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::TessVertex *refVer,
        Scaleform::Render::TessVertex *aaVer,
        Scaleform::Render::TessVertex *v2,
        Scaleform::Render::TessVertex *v3)
{
  float x; // xmm8_4
  float y; // xmm11_4
  float v7; // xmm10_4
  float v8; // xmm15_4
  float v9; // xmm9_4
  float v10; // xmm14_4
  float v11; // xmm13_4
  float v12; // xmm12_4
  float v13; // xmm1_4

  x = refVer->x;
  y = refVer->y;
  v7 = aaVer->y - y;
  v8 = v2->y;
  v9 = aaVer->x - refVer->x;
  v10 = v3->x - v2->x;
  v11 = v3->y - v8;
  v12 = (float)(v9 * v11) - (float)(v10 * v7);
  if ( COERCE_FLOAT(LODWORD(v12) & _xmm) < (float)((float)((float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(y - aaVer->y) & _xmm)
                                                                         + COERCE_FLOAT(COERCE_UNSIGNED_INT(refVer->x - aaVer->x) & _xmm))
                                                                 + COERCE_FLOAT(COERCE_UNSIGNED_INT(v2->x - v3->x) & _xmm))
                                                         + COERCE_FLOAT(COERCE_UNSIGNED_INT(v8 - v3->y) & _xmm))
                                                 * this->IntersectionEpsilon)
    || (v13 = (float)((float)((float)(y - v8) * v10) - (float)((float)(x - v2->x) * v11)) / v12, v13 <= 0.0)
    || v13 >= 1.0 )
  {
    aaVer->x = x;
    aaVer->y = refVer->y;
  }
  else
  {
    aaVer->x = (float)((float)(x - (float)((float)(v9 * v13) + x)) * 0.125) + (float)((float)(v9 * v13) + x);
    aaVer->y = (float)((float)(refVer->y - (float)((float)(v7 * v13) + y)) * 0.125) + (float)((float)(v7 * v13) + y);
  }
}

// File Line: 3082
// RVA: 0x9CAF40
void __fastcall Scaleform::Render::Tessellator::addTriangleAA(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::MonoVertexType *v1,
        Scaleform::Render::Tessellator::MonoVertexType *v2,
        Scaleform::Render::Tessellator::MonoVertexType *v3,
        float cp)
{
  Scaleform::Render::Tessellator::MonoVertexType *v5; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v7; // r14
  Scaleform::Render::TessVertex **Pages; // r8
  Scaleform::Render::TessVertex *v10; // rdi
  Scaleform::Render::TessVertex *v11; // rsi
  Scaleform::Render::TessVertex *v12; // rax
  float x; // xmm3_4
  Scaleform::Render::TessVertex *v14; // rbp
  Scaleform::Render::TessVertex *v15; // rax
  Scaleform::Render::TessVertex *v16; // rdx
  Scaleform::Render::TessVertex *v17; // r13
  unsigned int v18; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *p_MeshTriangles; // rbp
  __int64 MeshIdx; // rsi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v21; // rdi
  unsigned __int64 v22; // rbx
  __int64 v23; // rdx
  Scaleform::Render::Tessellator::TriangleType *v24; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v25; // [rsp+30h] [rbp-58h]
  Scaleform::Render::Tessellator::MonoVertexType *v26; // [rsp+38h] [rbp-50h]
  Scaleform::Render::Tessellator::MonoVertexType *v27; // [rsp+40h] [rbp-48h]
  Scaleform::Render::TessVertex *v28; // [rsp+90h] [rbp+8h]

  v5 = v3;
  v7 = v1;
  if ( this->EdgeAAFlag )
  {
    Pages = this->MeshVertices.Pages;
    v10 = &Pages[(unsigned __int64)(v1->srcVer & 0xFFFFFFF) >> 4][v1->srcVer & 0xF];
    v11 = &Pages[(unsigned __int64)(v2->srcVer & 0xFFFFFFF) >> 4][v2->srcVer & 0xF];
    v12 = Pages[(unsigned __int64)(v3->srcVer & 0xFFFFFFF) >> 4];
    x = v12[v3->srcVer & 0xF].x;
    v14 = &v12[v3->srcVer & 0xF];
    v15 = Pages[(unsigned __int64)(v1->aaVer & 0xFFFFFFF) >> 4];
    v16 = &Pages[(unsigned __int64)(v2->aaVer & 0xFFFFFFF) >> 4][v2->aaVer & 0xF];
    v28 = v16;
    v17 = &Pages[(unsigned __int64)(v3->aaVer & 0xFFFFFFF) >> 4][v3->aaVer & 0xF];
    if ( (float)((float)((float)(v15[v7->aaVer & 0xF].x - x) * (float)(v14->y - v11->y))
               - (float)((float)(v15[v7->aaVer & 0xF].y - v14->y) * (float)(x - v11->x))) >= 0.0 )
    {
      Scaleform::Render::Tessellator::moveVertexAA(this, v10, &v15[v7->aaVer & 0xF], v11, v14);
      v16 = v28;
    }
    if ( (float)((float)((float)(v10->y - v14->y) * (float)(v16->x - v10->x))
               - (float)((float)(v16->y - v10->y) * (float)(v10->x - v14->x))) >= 0.0 )
      Scaleform::Render::Tessellator::moveVertexAA(this, v11, v16, v14, v10);
    if ( (float)((float)((float)(v17->x - v11->x) * (float)(v11->y - v10->y))
               - (float)((float)(v17->y - v11->y) * (float)(v11->x - v10->x))) >= 0.0 )
      Scaleform::Render::Tessellator::moveVertexAA(this, v14, v17, v10, v11);
  }
  else
  {
    LODWORD(v25) = Scaleform::Render::Tessellator::emitVertex(
                     this,
                     this->MeshIdx,
                     v1->srcVer & 0xFFFFFFF,
                     this->MonoStyle,
                     this->FactorOneFlag);
    HIDWORD(v25) = Scaleform::Render::Tessellator::emitVertex(
                     this,
                     this->MeshIdx,
                     v2->srcVer & 0xFFFFFFF,
                     this->MonoStyle,
                     this->FactorOneFlag);
    v18 = Scaleform::Render::Tessellator::emitVertex(
            this,
            this->MeshIdx,
            v5->srcVer & 0xFFFFFFF,
            this->MonoStyle,
            this->FactorOneFlag);
    v5 = v27;
    v7 = v25;
    LODWORD(v26) = v18;
    v2 = v26;
  }
  p_MeshTriangles = &this->MeshTriangles;
  MeshIdx = this->MeshIdx;
  v21 = &this->MeshTriangles.Arrays[MeshIdx];
  v22 = v21->Size >> 4;
  if ( v22 >= v21->NumPages )
    Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
      p_MeshTriangles,
      v21,
      v21->Size >> 4);
  v23 = v21->Size & 0xF;
  v24 = v21->Pages[v22];
  v24[v23].d.m.v1 = v7;
  v24[v23].d.m.v2 = v2;
  v24[v23].d.m.v3 = v5;
  ++p_MeshTriangles->Arrays[MeshIdx].Size;
}

// File Line: 3152
// RVA: 0x9F77C0
void __fastcall Scaleform::Render::Tessellator::triangulateMountainAA(Scaleform::Render::Tessellator *this)
{
  unsigned __int64 Size; // r9
  Scaleform::Render::Tessellator *v2; // rbp
  Scaleform::Render::Tessellator::MonoVertexType ***Pages; // r11
  Scaleform::Render::TessVertex **v4; // r10
  unsigned int v5; // r13d
  float v6; // xmm2_4
  __int64 v7; // r8
  Scaleform::Render::TessVertex *v8; // rdi
  Scaleform::Render::TessVertex *v9; // rdx
  char v10; // cl
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rax
  int v13; // edi
  unsigned int v14; // ecx
  unsigned int v15; // r15d
  Scaleform::Render::Tessellator::MonoVertexType ***v16; // r14
  Scaleform::Render::TessVertex **v17; // r12
  unsigned int v18; // edi
  unsigned __int64 v19; // rsi
  Scaleform::Render::TessVertex *v20; // r10
  Scaleform::Render::TessVertex *v21; // r8
  unsigned int v22; // ebx
  Scaleform::Render::TessVertex *v23; // rax
  float v24; // xmm8_4
  Scaleform::Render::TessVertex *v25; // rcx
  float v26; // xmm6_4
  unsigned int v27; // edi
  unsigned int v28; // ebx
  Scaleform::Render::TessVertex *v29; // r10
  Scaleform::Render::TessVertex *v30; // r8
  Scaleform::Render::TessVertex *v31; // rcx
  float v32; // xmm9_4
  Scaleform::Render::TessVertex *v33; // r10
  Scaleform::Render::TessVertex *v34; // r8
  Scaleform::Render::TessVertex *v35; // rcx
  float v36; // xmm0_4
  unsigned int v37; // ebx
  float v38; // xmm2_4
  int v39; // xmm1_4
  float EdgeAAWidth; // xmm0_4
  unsigned __int64 v41; // r8
  __int64 v42; // r9
  Scaleform::Render::Tessellator::MonoVertexType ***v43; // rax
  unsigned int v44; // eax
  Scaleform::Render::Tessellator::MonoVertexType **v45; // rdx
  Scaleform::Render::Tessellator::MonoVertexType **v46; // rcx
  Scaleform::Render::Tessellator::MonoVertexType ***v47; // rax
  unsigned __int64 v48; // rdi
  float v49; // xmm6_4
  Scaleform::Render::TessVertex *v50; // r10
  Scaleform::Render::TessVertex *v51; // r8
  Scaleform::Render::TessVertex *v52; // rcx
  float v53; // xmm0_4
  unsigned __int64 v54; // r10
  unsigned __int64 v55; // r11
  Scaleform::Render::Tessellator::MonoVertexType ***v56; // r9
  unsigned __int64 v57; // r8
  unsigned __int64 v58; // rdx
  Scaleform::Render::Tessellator::MonoVertexType **v59; // rax
  Scaleform::Render::Tessellator::MonoVertexType **v60; // rcx
  Scaleform::Render::Tessellator::MonoVertexType ***v61; // rdx
  int v62; // [rsp+30h] [rbp-118h]
  int v63; // [rsp+40h] [rbp-108h]
  __int64 v64; // [rsp+48h] [rbp-100h]
  unsigned __int64 v65; // [rsp+50h] [rbp-F8h]
  __int64 v66; // [rsp+58h] [rbp-F0h]
  unsigned __int64 v67; // [rsp+60h] [rbp-E8h]
  __int64 v68; // [rsp+68h] [rbp-E0h]
  unsigned __int64 v69; // [rsp+70h] [rbp-D8h]
  unsigned __int64 v70; // [rsp+78h] [rbp-D0h]
  __int64 v71; // [rsp+80h] [rbp-C8h]
  __int64 v72; // [rsp+88h] [rbp-C0h]
  unsigned __int64 v73; // [rsp+90h] [rbp-B8h]
  unsigned __int64 v74; // [rsp+98h] [rbp-B0h]
  __int64 v75; // [rsp+A0h] [rbp-A8h]
  __int64 v76; // [rsp+A8h] [rbp-A0h]
  unsigned int v78; // [rsp+158h] [rbp+10h]
  unsigned int v79; // [rsp+160h] [rbp+18h]
  unsigned int v80; // [rsp+168h] [rbp+20h]

  Size = this->MonoStack.Size;
  v2 = this;
  if ( Size <= 2 )
    return;
  Pages = this->MonoStack.Pages;
  v4 = this->MeshVertices.Pages;
  v5 = 1;
  v6 = 0.0;
  v7 = 1i64;
  do
  {
    v10 = v7;
    v11 = v7++;
    v12 = Pages[v11 >> 4][v10 & 0xF]->srcVer & 0xFFFFFFF;
    v9 = v4[(unsigned __int64)(Pages[(Size - 1) >> 4][((_DWORD)Size - 1) & 0xF]->srcVer & 0xFFFFFFF) >> 4];
    v8 = v4[(unsigned __int64)((**Pages)->srcVer & 0xFFFFFFF) >> 4];
    v6 = v6
       + (float)((float)((float)(v4[v12 >> 4][v12 & 0xF].x
                               - v9[Pages[(Size - 1) >> 4][((_DWORD)Size - 1) & 0xF]->srcVer & 0xF].x)
                       * (float)(v9[Pages[(Size - 1) >> 4][((_DWORD)Size - 1) & 0xF]->srcVer & 0xF].y
                               - v8[(**Pages)->srcVer & 0xF].y))
               - (float)((float)(v4[v12 >> 4][v12 & 0xF].y
                               - v9[Pages[(Size - 1) >> 4][((_DWORD)Size - 1) & 0xF]->srcVer & 0xF].y)
                       * (float)(v9[Pages[(Size - 1) >> 4][((_DWORD)Size - 1) & 0xF]->srcVer & 0xF].x
                               - v8[(**Pages)->srcVer & 0xF].x)));
  }
  while ( v7 + 1 < Size );
  v13 = -1;
  v78 = Size;
  if ( v6 > 0.0 )
    v13 = 1;
  v14 = 0;
  v63 = v13;
  v79 = 0;
  v68 = v13;
  if ( (unsigned int)Size <= 3 )
  {
LABEL_57:
    v61 = v2->MonoStack.Pages;
    Scaleform::Render::Tessellator::addTriangleAA(
      v2,
      v61[(unsigned __int64)(v14 - v13 + 1) >> 4][(v14 - v13 + 1) & 0xF],
      v61[(unsigned __int64)(v14 + 1) >> 4][(v14 + 1) & 0xF],
      v61[(unsigned __int64)(v14 + v13 + 1) >> 4][((_BYTE)v14 + (_BYTE)v13 + 1) & 0xF],
      0.0);
    return;
  }
  v15 = 2;
  v80 = 3;
  v62 = 2;
  while ( 1 )
  {
    v16 = v2->MonoStack.Pages;
    v17 = v2->MeshVertices.Pages;
    v70 = (unsigned __int64)v5 >> 4;
    v71 = v5 & 0xF;
    v64 = v14 & 0xF;
    v67 = (unsigned __int64)v14 >> 4;
    v18 = v16[v70][v71]->srcVer & 0xFFFFFFF;
    v75 = v15 & 0xF;
    v19 = v5;
    v73 = (unsigned __int64)v15 >> 4;
    v20 = v17[(unsigned __int64)v18 >> 4];
    v21 = v17[(unsigned __int64)(v16[v67][v64]->srcVer & 0xFFFFFFF) >> 4];
    v22 = v16[v73][v75]->srcVer & 0xFFFFFFF;
    v23 = v17[(unsigned __int64)v22 >> 4];
    v24 = Scaleform::Render::Math2D::LinePointDistance(
            v23[v16[v73][v75]->srcVer & 0xF].x,
            v23[v16[v73][v75]->srcVer & 0xF].y,
            v21[v16[v67][v64]->srcVer & 0xF].x,
            v21[v16[v67][v64]->srcVer & 0xF].y,
            v20[v16[v70][v71]->srcVer & 0xF].x,
            v20[v16[v70][v71]->srcVer & 0xF].y);
    v25 = v17[(unsigned __int64)(v16[(unsigned __int64)v80 >> 4][v80 & 0xF]->srcVer & 0xFFFFFFF) >> 4];
    v26 = Scaleform::Render::Math2D::LinePointDistance(
            v25[v16[(unsigned __int64)v80 >> 4][v80 & 0xF]->srcVer & 0xF].x,
            v25[v16[(unsigned __int64)v80 >> 4][v80 & 0xF]->srcVer & 0xF].y,
            v17[(unsigned __int64)v18 >> 4][v18 & 0xF].x,
            v17[(unsigned __int64)v18 >> 4][v18 & 0xF].y,
            v17[(unsigned __int64)v22 >> 4][v22 & 0xF].x,
            v17[(unsigned __int64)v22 >> 4][v22 & 0xF].y);
    v69 = (unsigned __int64)(v78 - 2) >> 4;
    v72 = (v78 - 2) & 0xF;
    v76 = (v78 - 3) & 0xF;
    v74 = (unsigned __int64)(v78 - 3) >> 4;
    v27 = v16[v69][v72]->srcVer & 0xFFFFFFF;
    v66 = ((_BYTE)v78 - 1) & 0xF;
    v65 = (unsigned __int64)(v78 - 1) >> 4;
    v28 = v16[v74][v76]->srcVer & 0xFFFFFFF;
    v29 = v17[(unsigned __int64)v27 >> 4];
    v30 = v17[(unsigned __int64)v28 >> 4];
    v31 = v17[(unsigned __int64)(v16[v65][v66]->srcVer & 0xFFFFFFF) >> 4];
    v32 = Scaleform::Render::Math2D::LinePointDistance(
            v31[v16[v65][v66]->srcVer & 0xF].x,
            v31[v16[v65][v66]->srcVer & 0xF].y,
            v30[v16[v74][v76]->srcVer & 0xF].x,
            v30[v16[v74][v76]->srcVer & 0xF].y,
            v29[v16[v69][v72]->srcVer & 0xF].x,
            v29[v16[v69][v72]->srcVer & 0xF].y);
    v33 = v17[(unsigned __int64)v28 >> 4];
    v34 = v17[(unsigned __int64)(v16[(unsigned __int64)(v78 - 4) >> 4][((_BYTE)v78 - 4) & 0xF]->srcVer & 0xFFFFFFF) >> 4];
    v35 = v17[(unsigned __int64)v27 >> 4];
    v36 = Scaleform::Render::Math2D::LinePointDistance(
            v35[v27 & 0xF].x,
            v35[v27 & 0xF].y,
            v34[v16[(unsigned __int64)(v78 - 4) >> 4][((_BYTE)v78 - 4) & 0xF]->srcVer & 0xF].x,
            v34[v16[(unsigned __int64)(v78 - 4) >> 4][((_BYTE)v78 - 4) & 0xF]->srcVer & 0xF].y,
            v33[v28 & 0xF].x,
            v33[v28 & 0xF].y);
    v37 = -1;
    v38 = v36;
    if ( v68 <= 0 )
    {
      EdgeAAWidth = v2->EdgeAAWidth;
      if ( v24 > 0.0 && v26 > 0.0 )
      {
        if ( v24 > EdgeAAWidth )
        {
          EdgeAAWidth = v24;
          v37 = v5;
        }
        if ( v26 > EdgeAAWidth )
        {
          EdgeAAWidth = v26;
          v37 = v15;
        }
      }
      if ( v32 > 0.0 && v38 > 0.0 )
      {
        if ( v32 > EdgeAAWidth )
        {
          v37 = v78 - 2;
          EdgeAAWidth = v32;
        }
        if ( v38 > EdgeAAWidth )
          v37 = v78 - 3;
      }
    }
    else
    {
      v39 = LODWORD(v2->EdgeAAWidth) ^ _xmm[0];
      if ( v24 < 0.0 )
      {
        if ( v26 >= 0.0 )
          break;
        if ( v24 < *(float *)&v39 )
        {
          *(float *)&v39 = v24;
          v37 = v5;
        }
        if ( v26 < *(float *)&v39 )
        {
          *(float *)&v39 = v26;
          v37 = v15;
        }
      }
      if ( v26 < 0.0 && v36 < 0.0 )
      {
        if ( v32 < *(float *)&v39 )
        {
          v37 = v78 - 2;
          *(float *)&v39 = v32;
        }
        if ( v36 < *(float *)&v39 )
          v37 = v78 - 3;
      }
    }
    if ( v37 == -1 )
      break;
    v13 = v63;
    Scaleform::Render::Tessellator::addTriangleAA(
      v2,
      v16[(unsigned __int64)(v37 - v63) >> 4][(v37 - v63) & 0xF],
      v16[(unsigned __int64)v37 >> 4][v37 & 0xF],
      v16[(unsigned __int64)(v63 + v37) >> 4][((_BYTE)v63 + (_BYTE)v37) & 0xF],
      0.0);
    if ( v37 == v5 )
    {
      v41 = (unsigned __int64)v5 >> 4;
      v42 = v5 & 0xF;
    }
    else
    {
      v43 = v2->MonoStack.Pages;
      if ( v37 != v15 )
      {
        if ( v37 == v78 - 2 )
        {
          v45 = v43[v69];
          v46 = v43[v65];
        }
        else
        {
          v43[v74][v76] = v43[v69][v72];
          v47 = v2->MonoStack.Pages;
          v46 = v47[v65];
          v45 = v47[v69];
        }
        v45[v72] = v46[v66];
        v44 = --v78;
        goto LABEL_55;
      }
      v41 = (unsigned __int64)v5 >> 4;
      v42 = v5 & 0xF;
      v43[v73][v75] = v43[v70][v71];
    }
    ++v15;
    ++v5;
    v14 = v79 + 1;
    ++v80;
    v2->MonoStack.Pages[v41][v42] = v2->MonoStack.Pages[v67][v64];
    v44 = v78;
    ++v79;
    v62 = v15;
LABEL_56:
    if ( v44 <= v80 )
      goto LABEL_57;
  }
  v48 = v5 + 1i64;
  v49 = 0.0;
  if ( v48 >= v78 )
    return;
  do
  {
    v50 = v17[(unsigned __int64)(v16[v19 >> 4][v19 & 0xF]->srcVer & 0xFFFFFFF) >> 4];
    v51 = v17[(unsigned __int64)(v16[(v48 - 2) >> 4][((_DWORD)v48 - 2) & 0xF]->srcVer & 0xFFFFFFF) >> 4];
    v52 = v17[(unsigned __int64)(v16[v48 >> 4][v48 & 0xF]->srcVer & 0xFFFFFFF) >> 4];
    v53 = Scaleform::Render::Math2D::LinePointDistance(
            v52[v16[v48 >> 4][v48 & 0xF]->srcVer & 0xF].x,
            v52[v16[v48 >> 4][v48 & 0xF]->srcVer & 0xF].y,
            v51[v16[(v48 - 2) >> 4][((_DWORD)v48 - 2) & 0xF]->srcVer & 0xF].x,
            v51[v16[(v48 - 2) >> 4][((_DWORD)v48 - 2) & 0xF]->srcVer & 0xF].y,
            v50[v16[v19 >> 4][v19 & 0xF]->srcVer & 0xF].x,
            v50[v16[v19 >> 4][v19 & 0xF]->srcVer & 0xF].y);
    if ( v68 <= 0 )
    {
      if ( v53 <= v49 )
        goto LABEL_49;
    }
    else if ( v53 >= v49 )
    {
      goto LABEL_49;
    }
    v37 = v19;
    v49 = v53;
LABEL_49:
    ++v48;
    ++v19;
  }
  while ( v48 < v78 );
  v2 = this;
  if ( v37 != -1 )
  {
    v13 = v63;
    Scaleform::Render::Tessellator::addTriangleAA(
      this,
      v16[(unsigned __int64)(v37 - v63) >> 4][(v37 - v63) & 0xF],
      v16[(unsigned __int64)v37 >> 4][v37 & 0xF],
      v16[(unsigned __int64)(v63 + v37) >> 4][((_BYTE)v63 + (_BYTE)v37) & 0xF],
      0.0);
    v54 = v37 + 1;
    if ( v54 < v78 )
    {
      v55 = v37 + 1 - 1i64;
      do
      {
        v56 = this->MonoStack.Pages;
        v57 = v54 & 0xF;
        v58 = v55 & 0xF;
        v59 = v56[v54 >> 4];
        v60 = v56[v55 >> 4];
        ++v54;
        ++v55;
        v60[v58] = v59[v57];
      }
      while ( v54 < v78 );
    }
    v44 = v78 - 1;
    v15 = v62;
    --v78;
LABEL_55:
    v14 = v79;
    goto LABEL_56;
  }
}] = v59[v57];
      }
      while ( v54 < v78 );
    }
    v44 = v78 - 1;
    v15 = v62;
    --v78;
LABEL_55:
    v14 = v79;
    goto LABEL_56;
  }
}

// File Line: 3287
// RVA: 0x9F7540
void __fastcall Scaleform::Render::Tessellator::triangulateMonotoneAA(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::MonotoneType *m)
{
  Scaleform::Render::Tessellator::MonoVertexType *start; // rsi
  unsigned int style; // edx
  unsigned int v6; // r9d
  Scaleform::Render::TessMesh **Pages; // rax
  Scaleform::Render::TessMesh **v8; // rdx
  int v9; // ecx
  __int64 v10; // r9
  int v11; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *next; // rax
  unsigned __int64 v13; // rdi
  Scaleform::Render::Tessellator::MonoVertexType *v14; // rsi
  unsigned __int64 v15; // rdi
  Scaleform::Render::Tessellator::MonoVertexType *i; // rdi
  unsigned __int64 Size; // rsi
  unsigned __int64 v18; // rdx
  unsigned __int64 v19; // rsi
  Scaleform::Render::Tessellator::MonoVertexType *v20; // r14
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // rsi

  start = m->start;
  style = m->style;
  this->MonoStyle = style;
  v6 = Scaleform::Render::Tessellator::setMesh(this, style);
  Pages = this->Meshes.Pages;
  this->MeshIdx = v6;
  v8 = &Pages[(unsigned __int64)v6 >> 4];
  v9 = 0;
  v10 = v6 & 0xF;
  if ( this->MonoStyle == (*v8)[v10].Style1 )
    v9 = 8;
  v11 = v9 | 2;
  this->FactorOneFlag = v11;
  (*v8)[v10].Flags1 |= v11 & 8;
  m->d.m.lastIdx = -1;
  m->d.m.prevIdx1 = 0;
  m->d.m.prevIdx2 = this->MeshIdx;
  if ( start )
  {
    next = start->next;
    if ( next )
    {
      if ( next->next )
      {
        m->d.m.lastIdx = this->MeshTriangles.Arrays[this->MeshIdx].Size;
        this->MonoStack.Size = 0i64;
        v13 = this->MonoStack.Size >> 4;
        if ( v13 >= this->MonoStack.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
            &this->MonoStack,
            this->MonoStack.Size >> 4);
        this->MonoStack.Pages[v13][this->MonoStack.Size & 0xF] = start;
        ++this->MonoStack.Size;
        v14 = start->next;
        v15 = this->MonoStack.Size >> 4;
        if ( v15 >= this->MonoStack.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
            &this->MonoStack,
            this->MonoStack.Size >> 4);
        this->MonoStack.Pages[v15][this->MonoStack.Size & 0xF] = v14;
        ++this->MonoStack.Size;
        for ( i = v14->next; i; i = i->next )
        {
          Size = this->MonoStack.Size;
          v18 = Size - 1;
          v19 = Size >> 4;
          v20 = this->MonoStack.Pages[v18 >> 4][v18 & 0xF];
          if ( v19 >= this->MonoStack.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
              &this->MonoStack,
              v19);
          this->MonoStack.Pages[v19][this->MonoStack.Size & 0xF] = i;
          ++this->MonoStack.Size;
          if ( ((i->srcVer & 0x80000000) != 0) != ((v20->srcVer & 0x80000000) != 0) )
          {
            Scaleform::Render::Tessellator::triangulateMountainAA(this);
            this->MonoStack.Size = 0i64;
            v21 = this->MonoStack.Size >> 4;
            if ( v21 >= this->MonoStack.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
                &this->MonoStack,
                this->MonoStack.Size >> 4);
            this->MonoStack.Pages[v21][this->MonoStack.Size & 0xF] = v20;
            v22 = ++this->MonoStack.Size >> 4;
            if ( v22 >= this->MonoStack.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
                &this->MonoStack,
                this->MonoStack.Size >> 4);
            this->MonoStack.Pages[v22][this->MonoStack.Size & 0xF] = i;
            ++this->MonoStack.Size;
          }
        }
        Scaleform::Render::Tessellator::triangulateMountainAA(this);
        m->d.m.prevIdx1 = LODWORD(this->MeshTriangles.Arrays[this->MeshIdx].Size) - m->d.m.lastIdx;
      }
    }
  }
}1 = LODWORD(this->MeshTriangles.Arrays[this->MeshIdx].Size) -

// File Line: 3382
// RVA: 0x9F8230
void __fastcall Scaleform::Render::Tessellator::unflipTriangles(Scaleform::Render::Tessellator *this)
{
  Scaleform::Render::Tessellator *v1; // r10
  unsigned int v2; // eax
  unsigned __int64 v3; // rdx
  char v4; // cl
  __int64 v5; // r8
  unsigned __int64 v6; // r13
  Scaleform::Render::TessVertex **Pages; // rbx
  Scaleform::Render::Tessellator::TriangleType *v8; // r8
  Scaleform::Render::Tessellator::MonoVertexType *v9; // r11
  Scaleform::Render::Tessellator::MonoVertexType *v10; // r10
  Scaleform::Render::Tessellator::MonoVertexType *v11; // rdx
  __int64 v12; // rdi
  Scaleform::Render::TessVertex *v13; // rsi
  __int64 v14; // rbp
  Scaleform::Render::TessVertex *v15; // r14
  __int64 v16; // r15
  Scaleform::Render::TessVertex *v17; // r12
  __int64 v18; // r8
  Scaleform::Render::TessVertex *v19; // r9
  unsigned __int64 v20; // rax
  __int64 v21; // r10
  float x; // xmm9_4
  float y; // xmm8_4
  Scaleform::Render::TessVertex *v24; // r11
  __int64 v25; // rcx
  unsigned __int64 v26; // rax
  __int64 v27; // rdx
  float v28; // xmm14_4
  float v29; // xmm13_4
  Scaleform::Render::TessVertex *v30; // rbx
  float v31; // xmm15_4
  float v32; // xmm10_4
  float v33; // xmm11_4
  __m128 v34; // xmm6
  float v35; // xmm7_4
  float v36; // xmm6_4
  float v37; // xmm4_4
  __m128 v38; // xmm3
  __m128 v39; // xmm1
  float v40; // xmm2_4
  float v41; // xmm1_4
  int v42; // ecx
  int v43; // ecx
  int v44; // ecx
  float v45; // xmm2_4
  float v46; // xmm4_4
  float v47; // xmm5_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm5_4
  float v51; // xmm3_4
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm5_4
  float v55; // xmm3_4
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // [rsp+0h] [rbp-108h]
  float v59; // [rsp+4h] [rbp-104h]
  __int64 v60; // [rsp+8h] [rbp-100h]
  unsigned __int64 v61; // [rsp+10h] [rbp-F8h]
  unsigned __int64 v62; // [rsp+18h] [rbp-F0h]
  char v64; // [rsp+118h] [rbp+10h]
  unsigned int v65; // [rsp+120h] [rbp+18h]
  float v66; // [rsp+128h] [rbp+20h]

  v1 = this;
  v2 = 0;
  v65 = 0;
  do
  {
    if ( v2 >= 8 )
      break;
    v3 = 0i64;
    v4 = 0;
    v64 = 0;
    v61 = 0i64;
    if ( v1->MeshTriangles.NumArrays )
    {
      v5 = 0i64;
      v60 = 0i64;
      do
      {
        v6 = 0i64;
        v62 = *(unsigned __int64 *)((char *)&v1->MeshTriangles.Arrays->Size + v5);
        if ( v62 )
        {
          do
          {
            Pages = v1->MeshVertices.Pages;
            v8 = (*(Scaleform::Render::Tessellator::TriangleType ***)((char *)&v1->MeshTriangles.Arrays->Pages + v5))[v6 >> 4];
            v9 = v8[v6 & 0xF].d.m.v1;
            v10 = v8[v6 & 0xF].d.m.v2;
            v11 = v8[v6 & 0xF].d.m.v3;
            v12 = v9->srcVer & 0xF;
            v13 = Pages[(unsigned __int64)(v9->srcVer & 0xFFFFFFF) >> 4];
            v14 = v10->srcVer & 0xF;
            v15 = Pages[(unsigned __int64)(v10->srcVer & 0xFFFFFFF) >> 4];
            v16 = v11->srcVer & 0xF;
            v17 = Pages[(unsigned __int64)(v11->srcVer & 0xFFFFFFF) >> 4];
            v18 = v9->aaVer & 0xF;
            v19 = Pages[(unsigned __int64)(v9->aaVer & 0xFFFFFFF) >> 4];
            v20 = v10->aaVer & 0xFFFFFFF;
            v21 = v10->aaVer & 0xF;
            x = v19[v9->aaVer & 0xF].x;
            y = v19[v9->aaVer & 0xF].y;
            v24 = Pages[v20 >> 4];
            v25 = v11->aaVer & 0xF;
            v26 = (unsigned __int64)(v11->aaVer & 0xFFFFFFF) >> 4;
            v27 = v25;
            v28 = v24[v21].x;
            v29 = v24[v21].y;
            v30 = Pages[v26];
            v31 = v28 - x;
            v59 = v29 - y;
            v32 = v30[v25].x;
            v33 = v30[v25].y;
            v34 = (__m128)LODWORD(v33);
            v34.m128_f32[0] = v33 - v29;
            v58 = v32 - v28;
            v66 = v33 - v29;
            if ( (float)((float)((float)(v32 - v28) * (float)(v29 - y)) - (float)((float)(v28 - x) * (float)(v33 - v29))) < 0.0 )
            {
              v4 = v64;
            }
            else
            {
              v38 = v34;
              v38.m128_f32[0] = v34.m128_f32[0] * v34.m128_f32[0];
              v35 = y - v33;
              v36 = x - v32;
              v37 = (float)((float)(v29 - y) * (float)(v29 - y)) + (float)(v31 * v31);
              v38.m128_f32[0] = v38.m128_f32[0] + (float)((float)(v32 - v28) * (float)(v32 - v28));
              v39 = v38;
              v40 = (float)(v35 * v35) + (float)(v36 * v36);
              v39.m128_f32[0] = (float)(v38.m128_f32[0] + v37) + v40;
              v41 = _mm_sqrt_ps(v39).m128_f32[0] * this->IntersectionEpsilon;
              if ( v37 <= v38.m128_f32[0] )
              {
                v42 = (v38.m128_f32[0] <= v40) + 2;
              }
              else
              {
                v42 = 3;
                if ( v37 > v40 )
                  v42 = 1;
              }
              v43 = v42 - 1;
              if ( v43 )
              {
                v44 = v43 - 1;
                if ( v44 )
                {
                  if ( v44 == 1 )
                  {
                    v45 = v15[v14].x;
                    v46 = v15[v14].y - v29;
                    v47 = (float)((float)(v45 - v28) * v35) - (float)(v46 * v36);
                    if ( COERCE_FLOAT(LODWORD(v47) & _xmm) < v41
                      || (v48 = (float)((float)((float)(v29 - v33) * v36) - (float)((float)(v28 - v32) * v35)) / v47,
                          v48 <= 0.0)
                      || v48 >= 1.0 )
                    {
                      v24[v21].x = v45;
                      v24[v21].y = v15[v14].y;
                    }
                    else
                    {
                      v24[v21].x = (float)((float)(v45 - (float)((float)((float)(v45 - v28) * v48) + v28)) * 0.125)
                                 + (float)((float)((float)(v45 - v28) * v48) + v28);
                      v24[v21].y = (float)((float)(v15[v14].y - (float)((float)(v46 * v48) + v29)) * 0.125)
                                 + (float)((float)(v46 * v48) + v29);
                    }
                  }
                }
                else
                {
                  v49 = v13[v12].x;
                  v50 = v13[v12].y - y;
                  v51 = (float)(v66 * (float)(v49 - x)) - (float)(v58 * v50);
                  if ( COERCE_FLOAT(LODWORD(v51) & _xmm) < v41
                    || (v52 = (float)((float)((float)(y - v29) * v58) - (float)((float)(x - v28) * v66)) / v51,
                        v52 <= 0.0)
                    || v52 >= 1.0 )
                  {
                    v19[v18].x = v49;
                    v19[v18].y = v13[v12].y;
                  }
                  else
                  {
                    v19[v18].x = (float)((float)(v49 - (float)((float)(v52 * (float)(v49 - x)) + x)) * 0.125)
                               + (float)((float)(v52 * (float)(v49 - x)) + x);
                    v19[v18].y = (float)((float)(v13[v12].y - (float)((float)(v52 * v50) + y)) * 0.125)
                               + (float)((float)(v52 * v50) + y);
                  }
                }
              }
              else
              {
                v53 = v17[v16].x;
                v54 = v17[v16].y - v33;
                v55 = (float)(v59 * (float)(v53 - v32)) - (float)(v31 * v54);
                if ( COERCE_FLOAT(LODWORD(v55) & _xmm) < v41
                  || (v56 = (float)(v32 - x) * v59,
                      v57 = (float)((float)((float)(v33 - y) * v31) - v56) / v55,
                      v57 <= 0.0)
                  || v57 >= 1.0 )
                {
                  v30[v27].x = v53;
                  v30[v27].y = v17[v16].y;
                }
                else
                {
                  v30[v27].x = (float)((float)(v53
                                             - (float)((float)((float)((float)((float)((float)(v33 - y) * v31) - v56)
                                                                     / v55)
                                                             * (float)(v53 - v32))
                                                     + v32))
                                     * 0.125)
                             + (float)((float)((float)((float)((float)((float)(v33 - y) * v31) - v56) / v55)
                                             * (float)(v53 - v32))
                                     + v32);
                  v30[v27].y = (float)((float)(v17[v16].y - (float)((float)(v57 * v54) + v33)) * 0.125)
                             + (float)((float)(v57 * v54) + v33);
                }
              }
              if ( (float)((float)((float)(v24[v21].y - v19[v18].y) * (float)(v30[v27].x - v24[v21].x))
                         - (float)((float)(v24[v21].x - v19[v18].x) * (float)(v30[v27].y - v24[v21].y))) >= 0.0 )
              {
                v19[v18].x = v13[v12].x;
                v19[v18].y = v13[v12].y;
                v24[v21].x = v15[v14].x;
                v24[v21].y = v15[v14].y;
                v30[v27].x = v17[v16].x;
                v30[v27].y = v17[v16].y;
              }
              v4 = 1;
              v64 = 1;
            }
            v1 = this;
            v5 = v60;
            ++v6;
          }
          while ( v6 < v62 );
          v3 = v61;
        }
        ++v3;
        v5 += 32i64;
        v61 = v3;
        v60 = v5;
      }
      while ( v3 < v1->MeshTriangles.NumArrays );
      v2 = v65;
    }
    v65 = ++v2;
  }
  while ( v4 );
}

// File Line: 3504
// RVA: 0x9E06F0
void __fastcall Scaleform::Render::Tessellator::emitStrokerTrapezoid(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::StrokerEdgeType *edge,
        unsigned int v1,
        unsigned int v2)
{
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *p_MeshTriangles; // rbx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *Arrays; // rsi
  unsigned __int64 v8; // rdi
  Scaleform::Render::Tessellator::TriangleType *v9; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v10; // rax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v11; // rdi
  unsigned __int64 v12; // rsi
  Scaleform::Render::Tessellator::TriangleType *v13; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v14; // [rsp+20h] [rbp-38h]
  Scaleform::Render::Tessellator::MonoVertexType *v15; // [rsp+20h] [rbp-38h]
  Scaleform::Render::Tessellator::MonoVertexType *v16; // [rsp+28h] [rbp-30h]
  Scaleform::Render::Tessellator::MonoVertexType *v17; // [rsp+30h] [rbp-28h]

  p_MeshTriangles = &this->MeshTriangles;
  Arrays = this->MeshTriangles.Arrays;
  HIDWORD(v14) = v1;
  LODWORD(v16) = v2;
  v8 = Arrays->Size >> 4;
  LODWORD(v14) = edge->node1 & 0xFFFFFFF;
  if ( v8 >= Arrays->NumPages )
    Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
      &this->MeshTriangles,
      Arrays,
      v8);
  v9 = &Arrays->Pages[v8][Arrays->Size & 0xF];
  v9->d.m.v1 = v14;
  v10 = v16;
  LODWORD(v16) = v2;
  v9->d.m.v2 = v10;
  v9->d.m.v3 = v17;
  ++p_MeshTriangles->Arrays->Size;
  v11 = p_MeshTriangles->Arrays;
  LODWORD(v15) = edge->node2 & 0xFFFFFFF;
  v12 = v11->Size >> 4;
  HIDWORD(v15) = edge->node1 & 0xFFFFFFF;
  if ( v12 >= v11->NumPages )
    Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
      p_MeshTriangles,
      v11,
      v12);
  v13 = &v11->Pages[v12][v11->Size & 0xF];
  v13->d.m.v1 = v15;
  v13->d.m.v2 = v16;
  v13->d.m.v3 = v17;
  ++p_MeshTriangles->Arrays->Size;
}

// File Line: 3519
// RVA: 0x9E0810
void __fastcall Scaleform::Render::Tessellator::emitStrokerVertex(
        Scaleform::Render::Tessellator *this,
        float x,
        float y)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *p_MeshVertices; // rbx
  unsigned __int64 v4; // rdi
  __int64 v5; // rdx
  Scaleform::Render::TessVertex *v6; // rax

  p_MeshVertices = &this->MeshVertices;
  v4 = this->MeshVertices.Size >> 4;
  if ( v4 >= this->MeshVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
      &this->MeshVertices,
      this->MeshVertices.Size >> 4);
  v5 = p_MeshVertices->Size & 0xF;
  v6 = p_MeshVertices->Pages[v4];
  v6[v5].x = x;
  v6[v5].y = y;
  v6[v5].Idx = -1;
  *(_QWORD *)v6[v5].Styles = 65537i64;
  ++p_MeshVertices->Size;
}

// File Line: 3532
// RVA: 0x9C9C50
__int64 __fastcall Scaleform::Render::Tessellator::addStrokerJoin(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::StrokerEdgeType *e1,
        Scaleform::Render::Tessellator::StrokerEdgeType *e2)
{
  unsigned int node1; // r9d
  unsigned int node2; // ebp
  Scaleform::Render::TessVertex **Pages; // rdx
  unsigned int v7; // ebp
  unsigned __int64 v8; // rax
  __int64 v9; // r9
  Scaleform::Render::TessVertex *v10; // rax
  float v11; // xmm12_4
  float y; // xmm7_4
  Scaleform::Render::TessVertex *v13; // rbx
  __int64 v14; // rsi
  float v15; // xmm9_4
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  float v18; // xmm11_4
  Scaleform::Render::TessVertex *v19; // r8
  float x; // xmm15_4
  float v21; // xmm14_4
  float v22; // xmm10_4
  __m128 v23; // xmm1
  float v24; // xmm8_4
  float len2; // xmm13_4
  float v26; // xmm0_4
  float v27; // xmm5_4
  float v28; // xmm7_4
  float v29; // xmm8_4
  float v30; // xmm11_4
  float v31; // xmm6_4
  float v32; // xmm9_4
  float v34; // xmm14_4
  float v35; // xmm1_4
  float v36; // xmm15_4
  __m128 v37; // xmm12
  float v38; // xmm4_4
  __m128 v39; // xmm2
  float v40; // xmm3_4
  float v41; // xmm13_4
  float v42; // xmm1_4
  float v43; // xmm3_4
  __m128 v44; // xmm0
  float v45; // xmm1_4
  Scaleform::Render::Tessellator *v46; // rcx
  int Size; // ecx
  float v48; // [rsp+34h] [rbp-F4h]
  float v49; // [rsp+38h] [rbp-F0h]
  float v50; // [rsp+3Ch] [rbp-ECh]
  Scaleform::Render::Tessellator::TriangleType val; // [rsp+40h] [rbp-E8h] BYREF
  float v52; // [rsp+130h] [rbp+8h]
  float v53; // [rsp+140h] [rbp+18h]

  node1 = e1->node1;
  node2 = e1->node2;
  Pages = this->MeshVertices.Pages;
  v7 = node2 & 0xFFFFFFF;
  v8 = node1 & 0xFFFFFFF;
  v9 = node1 & 0xF;
  v10 = Pages[v8 >> 4];
  v11 = this->EdgeAAWidth * -2.0;
  v50 = v11;
  y = v10[v9].y;
  v13 = &v10[v9];
  v14 = (__int64)&Pages[(unsigned __int64)v7 >> 4][v7 & 0xF];
  v15 = *(float *)v14;
  v16 = (__m128)*(unsigned int *)(v14 + 4);
  v17 = v16;
  v18 = *(float *)v14 - v13->x;
  v19 = &Pages[(unsigned __int64)(e2->node2 & 0xFFFFFFF) >> 4][e2->node2 & 0xF];
  x = v19->x;
  v21 = v19->y;
  v17.m128_f32[0] = (float)((float)(v17.m128_f32[0] - y) * (float)(v17.m128_f32[0] - y)) + (float)(v18 * v18);
  v22 = _mm_sqrt_ps(v17).m128_f32[0];
  v23 = (__m128)LODWORD(v21);
  v24 = v19->x - *(float *)v14;
  v23.m128_f32[0] = (float)((float)(v23.m128_f32[0] - v16.m128_f32[0]) * (float)(v23.m128_f32[0] - v16.m128_f32[0]))
                  + (float)(v24 * v24);
  len2 = _mm_sqrt_ps(v23).m128_f32[0];
  v49 = len2;
  v26 = Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType>(
          v13,
          (Scaleform::Render::TessVertex *)v14,
          v19,
          v22,
          len2);
  v52 = (float)(len2 + v22) * this->IntersectionEpsilon;
  v48 = v26;
  v27 = (float)((float)(y - v16.m128_f32[0]) * v11) * (float)(1.0 / v22);
  v28 = (float)((float)(v16.m128_f32[0] - v21) * v11) * (float)(1.0 / len2);
  v29 = (float)(v24 * v11) * (float)(1.0 / len2);
  v30 = (float)(v18 * v11) * (float)(1.0 / v22);
  if ( COERCE_FLOAT(LODWORD(v26) & _xmm) >= 0.125 )
  {
    v37 = v16;
    v53 = v13->x + v27;
    v34 = (float)(v21 + v29) - (float)(v16.m128_f32[0] + v29);
    v35 = v13->y + v30;
    v36 = (float)(x + v28) - (float)(v15 + v28);
    v37.m128_f32[0] = v16.m128_f32[0] + v30;
    v39 = v37;
    v38 = v15 + v27;
    v39.m128_f32[0] = (float)(v16.m128_f32[0] + v30) - v35;
    v40 = (float)(v15 + v27) - v53;
    v41 = (float)(v34 * v40) - (float)(v36 * v39.m128_f32[0]);
    if ( COERCE_FLOAT(LODWORD(v41) & _xmm) < v52 )
    {
      v46 = this;
    }
    else
    {
      v42 = (float)((float)((float)(v35 - (float)(v16.m128_f32[0] + v29)) * v36)
                  - (float)((float)(v53 - (float)(v15 + v28)) * v34))
          / v41;
      v39.m128_f32[0] = (float)(v39.m128_f32[0] * v42) + (float)(v13->y + v30);
      v43 = (float)(v40 * v42) + v53;
      v44 = v39;
      v44.m128_f32[0] = (float)((float)(v39.m128_f32[0] - v16.m128_f32[0]) * (float)(v39.m128_f32[0] - v16.m128_f32[0]))
                      + (float)((float)(v43 - v15) * (float)(v43 - v15));
      LODWORD(v45) = _mm_sqrt_ps(v44).m128_u32[0];
      if ( v48 <= 0.0 )
      {
        v46 = this;
        if ( v45 <= (float)(v50 * -4.0) )
        {
LABEL_11:
          Scaleform::Render::Tessellator::emitStrokerVertex(v46, v43, v39.m128_f32[0]);
          return 1i64;
        }
        Scaleform::Render::Tessellator::emitStrokerVertex(
          this,
          v38 - (float)(v30 * 2.0),
          (float)(v27 * 2.0) + v37.m128_f32[0]);
        Scaleform::Render::Tessellator::emitStrokerVertex(
          this,
          (float)(v28 + *(float *)v14) + (float)(v29 * 2.0),
          (float)(v29 + *(float *)(v14 + 4)) - (float)(v28 * 2.0));
        Size = this->MeshVertices.Size;
        val.d.t.v1 = v7;
        val.d.t.v2 = Size - 2;
        val.d.t.v3 = Size - 1;
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::PushBack(
          &this->MeshTriangles,
          0i64,
          &val);
        return 2i64;
      }
      if ( v22 >= v49 )
        v22 = v49;
      v46 = this;
      if ( v45 <= (float)(v22 / v48) )
        goto LABEL_11;
    }
    Scaleform::Render::Tessellator::emitStrokerVertex(v46, v38, v37.m128_f32[0]);
    Scaleform::Render::Tessellator::emitStrokerVertex(this, v28 + *(float *)v14, v29 + *(float *)(v14 + 4));
    return 2i64;
  }
  if ( v22 <= len2 )
  {
    v31 = v16.m128_f32[0] + v29;
    v32 = v15 + v28;
  }
  else
  {
    v31 = v16.m128_f32[0] + v30;
    v32 = v15 + v27;
  }
  Scaleform::Render::Tessellator::emitStrokerVertex(this, v32, v31);
  return 1i64;
}

// File Line: 3638
// RVA: 0x9ED7D0
void __fastcall Scaleform::Render::Tessellator::processStrokerEdges(Scaleform::Render::Tessellator *this)
{
  unsigned __int64 i; // r12
  Scaleform::Render::Tessellator::MonoVertexType *start; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *next; // rsi
  unsigned int srcVer; // ebp
  unsigned int v6; // r14d
  unsigned __int64 v7; // rdi
  Scaleform::Render::Tessellator::MonoVertexType *j; // rdi
  int v9; // ecx
  unsigned __int64 v10; // rsi
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rdi
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType,4,16> *p_StrokerEdges; // rbx
  unsigned __int64 Size; // rbp
  unsigned __int64 v15; // rsi
  Scaleform::Render::Tessellator::StrokerEdgeType **Pages; // r8
  unsigned __int64 v17; // rcx
  Scaleform::Render::Tessellator::StrokerEdgeType *v18; // rax
  unsigned int node1; // ebx
  int *v20; // r14
  __int64 v21; // rdx
  int v22; // r13d
  unsigned __int64 v23; // r9
  unsigned int v24; // edi
  Scaleform::Render::Tessellator::StrokerEdgeType *v25; // r10
  unsigned int v26; // eax
  bool v27; // cf
  unsigned __int64 v28; // rax
  unsigned __int64 v29; // r9
  Scaleform::Render::Tessellator::StrokerEdgeType *v30; // rax
  unsigned __int64 k; // r12
  unsigned __int64 v32; // rcx
  Scaleform::Render::Tessellator::StrokerEdgeType *v33; // rax
  Scaleform::Render::Tessellator::StrokerEdgeType *v34; // r14
  unsigned int v35; // ebp
  Scaleform::Render::Tessellator::StrokerEdgeType *v36; // rdi
  unsigned int m; // esi
  __int64 v38; // r8
  unsigned __int64 v39; // rax
  Scaleform::Render::Tessellator::StrokerEdgeType **v40; // rbx
  unsigned __int64 v41; // r8
  Scaleform::Render::Tessellator::StrokerEdgeType *v42; // rbx
  int v43; // eax
  Scaleform::Render::Tessellator::StrokerEdgeType v44; // [rsp+70h] [rbp+8h]
  Scaleform::Render::Tessellator::StrokerEdgeType v45; // [rsp+78h] [rbp+10h]
  Scaleform::Render::Tessellator::StrokerEdgeType v46; // [rsp+80h] [rbp+18h]
  Scaleform::Render::Tessellator::StrokerEdgeType v47; // [rsp+88h] [rbp+20h]

  for ( i = 0i64; i < this->Monotones.Size; ++i )
  {
    start = this->Monotones.Pages[i >> 4][i & 0xF].start;
    if ( start )
    {
      next = start->next;
      srcVer = start->srcVer;
      if ( next )
      {
        v6 = next->srcVer;
        v44.node1 = srcVer & 0xFFFFFFF;
        v44.node2 = next->srcVer & 0xFFFFFFF;
        if ( (srcVer & 0xFFFFFFF) != v44.node2 )
        {
          v7 = this->StrokerEdges.Size >> 4;
          if ( v7 >= this->StrokerEdges.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StrokerEdges,
              this->StrokerEdges.Size >> 4);
          this->StrokerEdges.Pages[v7][this->StrokerEdges.Size & 0xF] = v44;
          ++this->StrokerEdges.Size;
        }
        for ( j = next->next; j; j = j->next )
        {
          v9 = j->srcVer & 0xFFFFFFF;
          if ( (j->srcVer & 0x80000000) == 0 )
          {
            v46.node2 = j->srcVer & 0xFFFFFFF;
            if ( (v6 & 0xFFFFFFF) != v9 )
            {
              v11 = this->StrokerEdges.Size >> 4;
              if ( v11 >= this->StrokerEdges.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StrokerEdges,
                  this->StrokerEdges.Size >> 4);
              v46.node1 = v6 & 0xFFFFFFF;
              this->StrokerEdges.Pages[v11][this->StrokerEdges.Size & 0xF] = v46;
              ++this->StrokerEdges.Size;
            }
            v6 = j->srcVer;
          }
          else
          {
            v45.node1 = j->srcVer & 0xFFFFFFF;
            if ( v9 != (srcVer & 0xFFFFFFF) )
            {
              v10 = this->StrokerEdges.Size >> 4;
              if ( v10 >= this->StrokerEdges.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StrokerEdges,
                  this->StrokerEdges.Size >> 4);
              v45.node2 = srcVer & 0xFFFFFFF;
              this->StrokerEdges.Pages[v10][this->StrokerEdges.Size & 0xF] = v45;
              ++this->StrokerEdges.Size;
            }
            srcVer = j->srcVer;
          }
        }
        if ( (v6 & 0xFFFFFFF) != (srcVer & 0xFFFFFFF) )
        {
          v12 = this->StrokerEdges.Size >> 4;
          if ( v12 >= this->StrokerEdges.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StrokerEdges,
              this->StrokerEdges.Size >> 4);
          v47.node2 = srcVer & 0xFFFFFFF;
          v47.node1 = v6 & 0xFFFFFFF;
          this->StrokerEdges.Pages[v12][this->StrokerEdges.Size & 0xF] = v47;
          ++this->StrokerEdges.Size;
        }
      }
    }
  }
  if ( this->StrokerEdges.Size >= 2 )
  {
    p_StrokerEdges = &this->StrokerEdges;
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType,4,16>,bool (*)(Scaleform::Render::Tessellator::StrokerEdgeType const &,Scaleform::Render::Tessellator::StrokerEdgeType const &)>(
      &this->StrokerEdges,
      0i64,
      this->StrokerEdges.Size,
      (bool (__fastcall *)(Scaleform::Render::Tessellator::StrokerEdgeType *, Scaleform::Render::Tessellator::StrokerEdgeType *))Scaleform::Render::Tessellator::cmpStrokerEdges);
    Size = this->StrokerEdges.Size;
    v15 = 0i64;
    if ( Size )
    {
      do
      {
        Pages = this->StrokerEdges.Pages;
        v17 = v15 & 0xF;
        v18 = Pages[v15 >> 4];
        node1 = v18[v17].node1;
        v20 = (int *)&v18[v17];
        if ( (node1 & 0x40000000) == 0 )
        {
          v21 = this->StrokerEdges.Size;
          v22 = v20[1];
          v23 = 0i64;
          if ( v21 > 0 )
          {
            v24 = v22 & 0xFFFFFFF;
            do
            {
              v25 = &this->StrokerEdges.Pages[((v21 >> 1) + v23) >> 4][((unsigned __int8)(v21 >> 1) + (_BYTE)v23) & 0xF];
              v26 = v25->node1 & 0xFFFFFFF;
              v27 = v26 < v24;
              if ( v26 == v24 )
                v27 = (v25->node2 & 0xFFFFFFF) < (node1 & 0xFFFFFFF);
              if ( v27 )
              {
                v23 += (v21 >> 1) + 1;
                v21 += -1 - (v21 >> 1);
              }
              else
              {
                v21 >>= 1;
              }
            }
            while ( v21 > 0 );
            Pages = this->StrokerEdges.Pages;
          }
          if ( v23 < Size )
          {
            v28 = v23;
            v29 = v23 & 0xF;
            v30 = Pages[v28 >> 4];
            if ( node1 == v30[v29].node2 && v22 == v30[v29].node1 )
            {
              *v20 = node1 | 0x40000000;
              v30[v29].node1 |= 0x40000000u;
            }
          }
        }
        Size = this->StrokerEdges.Size;
        ++v15;
      }
      while ( v15 < Size );
      p_StrokerEdges = &this->StrokerEdges;
    }
    for ( k = 0i64; k < this->StrokerEdges.Size; p_StrokerEdges = &this->StrokerEdges )
    {
      v32 = k & 0xF;
      v33 = this->StrokerEdges.Pages[k >> 4];
      v34 = &v33[v32];
      if ( (v34->node1 & 0x40000000) == 0 )
      {
        v35 = -1;
        v36 = &v33[v32];
        for ( m = -1; ; m = LODWORD(this->MeshVertices.Size) - 1 )
        {
          v38 = p_StrokerEdges->Size;
          v39 = 0i64;
          if ( v38 > 0 )
          {
            v40 = p_StrokerEdges->Pages;
            do
            {
              if ( (v40[((v38 >> 1) + v39) >> 4][((unsigned __int8)(v38 >> 1) + (_BYTE)v39) & 0xF].node1 & 0xFFFFFFF) >= (v36->node2 & 0xFFFFFFF) )
              {
                v38 >>= 1;
              }
              else
              {
                v39 += (v38 >> 1) + 1;
                v38 += -1 - (v38 >> 1);
              }
            }
            while ( v38 > 0 );
          }
          v41 = this->StrokerEdges.Size;
          if ( v39 >= v41 )
            break;
          while ( 1 )
          {
            v42 = &this->StrokerEdges.Pages[v39 >> 4][v39 & 0xF];
            if ( (v42->node1 & 0x40000000) == 0 && ((v42->node1 ^ v36->node2) & 0xFFFFFFF) == 0 )
              break;
            if ( ++v39 >= v41 )
              goto LABEL_64;
          }
          v43 = Scaleform::Render::Tessellator::addStrokerJoin(this, v36, v42);
          if ( m == -1 )
          {
            v35 = LODWORD(this->MeshVertices.Size) - v43;
          }
          else
          {
            Scaleform::Render::Tessellator::emitStrokerTrapezoid(this, v36, m, LODWORD(this->MeshVertices.Size) - v43);
            v36->node1 |= 0x40000000u;
          }
          if ( v42 == v34 )
          {
            Scaleform::Render::Tessellator::emitStrokerTrapezoid(this, v34, LODWORD(this->MeshVertices.Size) - 1, v35);
            v34->node1 |= 0x40000000u;
            break;
          }
          v36 = v42;
          p_StrokerEdges = &this->StrokerEdges;
        }
      }
LABEL_64:
      ++k;
    }
  }
}

// File Line: 3750
// RVA: 0x9EC320
void __fastcall Scaleform::Render::Tessellator::processEdgeAA(Scaleform::Render::Tessellator *this)
{
  unsigned __int64 v1; // r14
  unsigned __int64 v2; // rbx
  unsigned __int64 i; // rdi
  int v5; // eax
  Scaleform::Render::Tessellator::EdgeAAType *v6; // rbp
  Scaleform::Render::Tessellator::EdgeAAType *Array; // rdx
  unsigned __int64 Size; // rcx
  unsigned int v9; // r11d
  unsigned __int64 j; // r10
  __int64 v11; // rax
  unsigned __int64 v12; // rdx
  Scaleform::Render::TessVertex *v13; // r8
  __int64 v14; // r9
  unsigned __int64 k; // rbx
  unsigned __int64 v16; // rax
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4> *p_TmpEdgeFan; // rdi
  unsigned __int64 v18; // rdx
  __int64 v19; // rax
  __int64 v20; // r15
  unsigned __int64 v21; // r13
  Scaleform::Render::TessVertex *v22; // r12
  Scaleform::Render::TessVertex **Pages; // r10
  Scaleform::Render::Tessellator::EdgeAAType *v24; // rax
  Scaleform::Render::Tessellator::MonoVertexType *rayVer; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *cntVer; // rbx
  Scaleform::Render::TessVertex *v27; // r8
  Scaleform::Render::TessVertex *v28; // rcx
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm1_4
  unsigned __int64 v34; // rbp
  unsigned __int64 MaxPages; // rdx
  Scaleform::Render::LinearHeap *pHeap; // rcx
  void *v37; // rbx
  unsigned __int64 v38; // rax
  Scaleform::Render::Tessellator::TmpEdgeAAType *v39; // rdx
  __int64 v40; // r8
  unsigned __int64 v41; // rbx
  unsigned __int16 v42; // bp
  float m; // xmm1_4
  Scaleform::Render::Tessellator::EdgeAAType *v44; // r10
  unsigned __int64 v45; // r11
  Scaleform::Render::Tessellator::TmpEdgeAAType *v46; // r8
  unsigned __int16 style; // ax
  __int64 v48; // [rsp+30h] [rbp-A8h]
  unsigned __int64 v49; // [rsp+E0h] [rbp+8h]
  Scaleform::Render::Tessellator::MonoVertexType *v50; // [rsp+E8h] [rbp+10h]
  Scaleform::Render::Tessellator::MonoVertexType *v51; // [rsp+F0h] [rbp+18h]
  unsigned __int64 v52; // [rsp+F8h] [rbp+20h]

  v1 = 0i64;
  v2 = 0i64;
  for ( i = 0i64; v2 < this->Monotones.Size; i = (unsigned int)(v5 + i) )
  {
    v5 = Scaleform::Render::Tessellator::countFanEdges(this, &this->Monotones.Pages[v2 >> 4][v2 & 0xF]);
    ++v2;
  }
  if ( i > this->EdgeFans.Size )
  {
    v6 = (Scaleform::Render::Tessellator::EdgeAAType *)Scaleform::Render::LinearHeap::Alloc(
                                                         this->EdgeFans.pHeap,
                                                         24 * i);
    memset(v6, 0, 24 * i);
    Array = this->EdgeFans.Array;
    if ( Array )
    {
      Size = this->EdgeFans.Size;
      if ( Size )
        memmove(v6, Array, 24 * Size);
    }
    this->EdgeFans.Array = v6;
  }
  this->EdgeFans.Size = i;
  v9 = 0;
  for ( j = 0i64; j < this->MeshVertices.Size; v9 += v11 )
  {
    v11 = j & 0xF;
    v12 = j++ >> 4;
    v13 = this->MeshVertices.Pages[v12];
    v14 = v11;
    LODWORD(v11) = v13[v11].Mesh;
    v13[v14].Idx = v9;
    v13[v14].Mesh = 0;
  }
  for ( k = 0i64; k < this->Monotones.Size; ++k )
    Scaleform::Render::Tessellator::collectFanEdges(this, &this->Monotones.Pages[k >> 4][k & 0xF]);
  v16 = 0i64;
  v52 = this->MeshVertices.Size;
  v49 = 0i64;
  if ( v52 )
  {
    p_TmpEdgeFan = &this->TmpEdgeFan;
    do
    {
      v18 = v16;
      v19 = v16 & 0xF;
      v20 = v19;
      v21 = 0i64;
      v22 = this->MeshVertices.Pages[v18 >> 4];
      this->TmpEdgeFan.Size = 0i64;
      if ( v22[v19].Mesh )
      {
        do
        {
          Pages = this->MeshVertices.Pages;
          v24 = this->EdgeFans.Array;
          rayVer = v24[v21 + v22[v20].Idx].rayVer;
          cntVer = v24[v21 + v22[v20].Idx].cntVer;
          v51 = rayVer;
          HIDWORD(v48) = v24[v21 + v22[v20].Idx].style;
          v50 = cntVer;
          v27 = Pages[(unsigned __int64)(rayVer->srcVer & 0xFFFFFFF) >> 4];
          v28 = Pages[(unsigned __int64)(cntVer->srcVer & 0xFFFFFFF) >> 4];
          v29 = v27[rayVer->srcVer & 0xF].x - v28[cntVer->srcVer & 0xF].x;
          v30 = v27[rayVer->srcVer & 0xF].y - v28[cntVer->srcVer & 0xF].y;
          v31 = (float)((float)(v30 * v30) + (float)(v29 * v29)) * 2.0;
          if ( v31 == 0.0 )
          {
            v32 = 0.0;
          }
          else
          {
            v33 = (float)(v29 * v29) / v31;
            if ( v29 < 0.0 )
              LODWORD(v33) ^= _xmm[0];
            if ( v30 > 0.0 )
              v33 = 1.0 - v33;
            v32 = v33 - 0.5;
          }
          *(float *)&v48 = v32;
          v34 = this->TmpEdgeFan.Size >> 3;
          if ( v34 >= this->TmpEdgeFan.NumPages )
          {
            MaxPages = this->TmpEdgeFan.MaxPages;
            if ( v34 >= MaxPages )
            {
              pHeap = p_TmpEdgeFan->pHeap;
              if ( this->TmpEdgeFan.Pages )
              {
                v37 = Scaleform::Render::LinearHeap::Alloc(pHeap, 16 * MaxPages);
                memmove(v37, this->TmpEdgeFan.Pages, 8 * this->TmpEdgeFan.NumPages);
                v38 = this->TmpEdgeFan.MaxPages;
                this->TmpEdgeFan.Pages = (Scaleform::Render::Tessellator::TmpEdgeAAType **)v37;
                cntVer = v50;
                this->TmpEdgeFan.MaxPages = 2 * v38;
              }
              else
              {
                this->TmpEdgeFan.MaxPages = 4i64;
                this->TmpEdgeFan.Pages = (Scaleform::Render::Tessellator::TmpEdgeAAType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                             pHeap,
                                                                                             0x20ui64);
              }
            }
            this->TmpEdgeFan.Pages[v34] = (Scaleform::Render::Tessellator::TmpEdgeAAType *)Scaleform::Render::LinearHeap::Alloc(
                                                                                             p_TmpEdgeFan->pHeap,
                                                                                             0xC0ui64);
            ++this->TmpEdgeFan.NumPages;
          }
          ++v21;
          v39 = this->TmpEdgeFan.Pages[v34];
          v40 = this->TmpEdgeFan.Size & 7;
          v39[v40].cntVer = cntVer;
          v39[v40].rayVer = v51;
          *(_QWORD *)&v39[v40].slope = v48;
          ++this->TmpEdgeFan.Size;
        }
        while ( v21 < v22[v20].Mesh );
      }
      Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4>,bool (*)(Scaleform::Render::Tessellator::TmpEdgeAAType const &,Scaleform::Render::Tessellator::TmpEdgeAAType const &)>(
        &this->TmpEdgeFan,
        0i64,
        this->TmpEdgeFan.Size,
        Scaleform::Render::Tessellator::cmpEdgeAA);
      v41 = 0i64;
      v42 = 0;
      for ( m = FLOAT_N1_0e30; v41 < this->TmpEdgeFan.Size; ++v41 )
      {
        v44 = this->EdgeFans.Array;
        v45 = v41 + v22[v20].Idx;
        v46 = this->TmpEdgeFan.Pages[v41 >> 3];
        v44[v45].cntVer = v46[v41 & 7].cntVer;
        v44[v45].rayVer = v46[v41 & 7].rayVer;
        style = v46[v41 & 7].style;
        v44[v45].slope = v42;
        v44[v45].style = style;
        if ( v46[v41 & 7].slope != m )
        {
          ++v42;
          m = v46[v41 & 7].slope;
        }
      }
      Scaleform::Render::Tessellator::processFan(this, v22[v20].Idx, v22[v20].Idx + v22[v20].Mesh);
      v22[v20].Idx = -1;
      v22[v20].Mesh = -1;
      v16 = v49 + 1;
      v49 = v16;
    }
    while ( v16 < v52 );
  }
  if ( this->Monotones.Size )
  {
    do
    {
      Scaleform::Render::Tessellator::triangulateMonotoneAA(this, &this->Monotones.Pages[v1 >> 4][v1 & 0xF]);
      ++v1;
    }
    while ( v1 < this->Monotones.Size );
  }
  Scaleform::Render::Tessellator::unflipTriangles(this);
  Scaleform::Render::Tessellator::emitTriangles(this);
}der::Tessellator::unflipTriangles(this);
  Scaleform::Render::Tessellator::emitTriangles(this);
}

// File Line: 3832
// RVA: 0x9B8C50
void __fastcall Scaleform::Render::Tessellator::Tessellate(Scaleform::Render::Tessellator *this, bool autoSplitMeshes)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbp
  Scaleform::Render::TessMesh *v6; // rcx
  __int64 v7; // rdx
  Scaleform::Render::LinearHeap *pHeap; // rcx
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // rbx
  unsigned __int16 *v11; // rax
  unsigned __int64 i; // rbx
  Scaleform::Render::Tessellator::PathType *v13; // r8
  unsigned int leftStyle; // edx
  unsigned int rightStyle; // r8d
  unsigned __int64 j; // rbp
  Scaleform::Render::Tessellator::PathType *v17; // rbx
  unsigned int v18; // edx
  unsigned int v19; // edx
  unsigned __int64 k; // rbx
  unsigned __int64 v21; // rbx
  unsigned __int64 m; // rbx
  Scaleform::Render::TessVertex *v23; // r9
  unsigned __int16 Mesh; // ax
  __int64 v25; // rdx
  Scaleform::Render::TessMesh *v26; // rcx
  unsigned __int64 VertexLimit; // rax

  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  Scaleform::Render::Tessellator::monotonize(this);
  v4 = 0i64;
  v5 = this->Meshes.Size >> 4;
  if ( v5 >= this->Meshes.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::allocPage(&this->Meshes, this->Meshes.Size >> 4);
  v6 = this->Meshes.Pages[v5];
  v7 = this->Meshes.Size & 0xF;
  *(_QWORD *)&v6[v7].MeshIdx = 0i64;
  *(_QWORD *)&v6[v7].Style2 = 0i64;
  *(_QWORD *)&v6[v7].Flags2 = 0i64;
  v6[v7].VertexCount = 0;
  ++this->Meshes.Size;
  if ( this->HasComplexFill )
  {
    pHeap = this->StyleMatrix.pHeap;
    v9 = this->MaxStyle + 1;
    this->StyleMatrix.Size = v9;
    v10 = 2 * v9 * v9;
    v11 = (unsigned __int16 *)Scaleform::Render::LinearHeap::Alloc(pHeap, v10);
    this->StyleMatrix.Array = v11;
    memset(v11, 255, v10);
    for ( i = 0i64; i < this->Paths.Size; ++i )
    {
      v13 = &this->Paths.Pages[i >> 4][i & 0xF];
      leftStyle = v13->leftStyle;
      if ( leftStyle )
      {
        rightStyle = v13->rightStyle;
        if ( rightStyle )
          Scaleform::Render::Tessellator::setMesh(this, leftStyle, rightStyle);
      }
    }
    for ( j = 0i64; j < this->Paths.Size; ++j )
    {
      v17 = &this->Paths.Pages[j >> 4][j & 0xF];
      v18 = v17->leftStyle;
      if ( v18 )
        Scaleform::Render::Tessellator::setMesh(this, v18);
      v19 = v17->rightStyle;
      if ( v19 )
        Scaleform::Render::Tessellator::setMesh(this, v19);
    }
  }
  Scaleform::Render::Tessellator::clearHeap1(this);
  for ( k = 0i64; k < this->Meshes.Size; ++k )
    Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(&this->MeshTriangles);
  if ( this->EdgeAAFlag )
  {
    if ( this->StrokerMode )
    {
      Scaleform::Render::Tessellator::setMesh(this, 1u);
      v21 = 0i64;
      for ( this->EdgeAAFlag = 0; v21 < this->Monotones.Size; ++v21 )
        Scaleform::Render::Tessellator::triangulateMonotoneAA(this, &this->Monotones.Pages[v21 >> 4][v21 & 0xF]);
      this->EdgeAAFlag = 1;
      Scaleform::Render::Tessellator::processStrokerEdges(this);
    }
    else
    {
      Scaleform::Render::Tessellator::processEdgeAA(this);
    }
  }
  else
  {
    for ( m = 0i64; m < this->Monotones.Size; ++m )
      Scaleform::Render::Tessellator::triangulateMonotoneAA(this, &this->Monotones.Pages[m >> 4][m & 0xF]);
  }
  if ( this->MeshVertices.Size )
  {
    do
    {
      v23 = this->MeshVertices.Pages[v4 >> 4];
      Mesh = v23[v4 & 0xF].Mesh;
      if ( Mesh != 0xFFFF )
      {
        v25 = Mesh & 0xF;
        v26 = this->Meshes.Pages[(unsigned __int64)Mesh >> 4];
        v23[v4 & 0xF].Idx = v26[v25].VertexCount++;
      }
      ++v4;
    }
    while ( v4 < this->MeshVertices.Size );
  }
  if ( autoSplitMeshes )
  {
    VertexLimit = this->VertexLimit;
    if ( (_DWORD)VertexLimit )
    {
      if ( this->MeshVertices.Size > VertexLimit )
        Scaleform::Render::Tessellator::SplitMeshes(this);
    }
  }
}

// File Line: 4085
// RVA: 0x9BA8A0
void __fastcall Scaleform::Render::Tessellator::Transform(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Matrix2x4<float> *m)
{
  unsigned __int64 v2; // r10
  __int64 v3; // r9
  Scaleform::Render::TessVertex *v4; // rax
  float x; // xmm2_4
  float y; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4

  v2 = 0i64;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  for ( this->MaxY = -1.0e30; v2 < this->MeshVertices.Size; ++v2 )
  {
    v3 = v2 & 0xF;
    v4 = this->MeshVertices.Pages[v2 >> 4];
    x = v4[v2 & 0xF].x;
    y = v4[v2 & 0xF].y;
    v4[v3].x = (float)((float)(x * m->M[0][0]) + (float)(y * m->M[0][1])) + m->M[0][3];
    v4[v3].y = (float)((float)(y * m->M[1][1]) + (float)(x * m->M[1][0])) + m->M[1][3];
    v7 = v4[v2 & 0xF].x;
    if ( v7 < this->MinX )
      this->MinX = v7;
    v8 = v4[v2 & 0xF].y;
    if ( v8 < this->MinY )
      this->MinY = v8;
    v9 = v4[v2 & 0xF].x;
    if ( v9 > this->MaxX )
      this->MaxX = v9;
    v10 = v4[v2 & 0xF].y;
    if ( v10 > this->MaxY )
      this->MaxY = v10;
  }
}

// File Line: 4105
// RVA: 0x9B8220
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::Tessellator::StretchTo(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Matrix2x4<float> *result,
        float x1,
        float y1,
        float x2,
        float y2)
{
  unsigned __int64 v6; // rsi
  unsigned __int64 Size; // r9
  unsigned __int64 v12; // r8
  float v13; // xmm4_4
  Scaleform::Render::TessVertex **Pages; // r10
  float v15; // xmm7_4
  float v16; // xmm5_4
  float v17; // xmm6_4
  Scaleform::Render::TessVertex *v18; // rax
  float x; // xmm3_4
  float v20; // xmm1_4
  float y; // xmm2_4
  float v22; // xmm0_4
  float MinX; // xmm3_4
  float MaxX; // xmm1_4
  float MinY; // xmm0_4
  float MaxY; // xmm2_4
  __int64 v27; // rax
  unsigned __int64 v28; // rdx
  __int64 v29; // r8
  Scaleform::Render::TessVertex *v30; // rax
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float dst[2]; // [rsp+20h] [rbp-39h] BYREF
  float v37; // [rsp+28h] [rbp-31h]
  float v38; // [rsp+2Ch] [rbp-2Dh]
  float v39; // [rsp+30h] [rbp-29h]
  float v40; // [rsp+34h] [rbp-25h]
  Scaleform::Render::Matrix2x4<float> src; // [rsp+40h] [rbp-19h] BYREF

  v6 = 0i64;
  *(_QWORD *)&result->M[0][0] = 1065353216i64;
  *(_QWORD *)&result->M[1][1] = 1065353216i64;
  *(_QWORD *)&result->M[0][2] = 0i64;
  result->M[1][0] = 0.0;
  result->M[1][3] = 0.0;
  if ( this->MaxX <= this->MinX || this->MaxY <= this->MinY )
  {
    Size = this->MeshVertices.Size;
    this->MinX = 1.0e30;
    this->MinY = 1.0e30;
    this->MaxX = -1.0e30;
    this->MaxY = -1.0e30;
    v12 = 0i64;
    if ( Size )
    {
      v13 = FLOAT_N1_0e30;
      Pages = this->MeshVertices.Pages;
      v15 = FLOAT_1_0e30;
      v16 = FLOAT_N1_0e30;
      v17 = FLOAT_1_0e30;
      do
      {
        v18 = Pages[v12 >> 4];
        x = v18[v12 & 0xF].x;
        v20 = *(float *)v18[v12 & 0xF].Styles;
        y = v18[v12 & 0xF].y;
        v37 = *(float *)&v18[v12 & 0xF].Idx;
        v22 = *(float *)&v18[v12 & 0xF].Flags;
        v38 = v20;
        v39 = v22;
        if ( x < v15 )
        {
          this->MinX = x;
          v15 = x;
        }
        if ( y < v17 )
        {
          this->MinY = y;
          v17 = y;
        }
        if ( x > v13 )
        {
          this->MaxX = x;
          v13 = x;
        }
        if ( y > v16 )
        {
          this->MaxY = y;
          v16 = y;
        }
        ++v12;
      }
      while ( v12 < Size );
    }
  }
  MinX = this->MinX;
  MaxX = this->MaxX;
  if ( MinX < MaxX )
  {
    MinY = this->MinY;
    MaxY = this->MaxY;
    if ( MinY < MaxY )
    {
      src.M[0][1] = this->MinY;
      v37 = x2;
      v39 = x2;
      v40 = y2;
      src.M[0][0] = MinX;
      *(_QWORD *)&src.M[0][2] = __PAIR64__(LODWORD(MinY), LODWORD(MaxX));
      *(_QWORD *)&src.M[1][0] = __PAIR64__(LODWORD(MaxY), LODWORD(MaxX));
      dst[0] = x1;
      dst[1] = y1;
      v38 = y1;
      Scaleform::Render::Matrix2x4<float>::SetParlToParl(result, (float *)&src, dst);
      if ( this->MeshVertices.Size )
      {
        do
        {
          v27 = v6 & 0xF;
          v28 = v6++ >> 4;
          v29 = v27;
          v30 = this->MeshVertices.Pages[v28];
          v31 = v30[v29].x;
          v32 = v30[v29].y;
          v30[v29].x = (float)((float)(v31 * result->M[0][0]) + (float)(v32 * result->M[0][1])) + result->M[0][3];
          v30[v29].y = (float)((float)(v31 * result->M[1][0]) + (float)(v32 * result->M[1][1])) + result->M[1][3];
        }
        while ( v6 < this->MeshVertices.Size );
      }
      v33 = result->M[0][1];
      src.M[0][0] = result->M[0][0];
      *(_QWORD *)&src.M[0][1] = __PAIR64__(LODWORD(result->M[0][2]), LODWORD(v33));
      v34 = result->M[1][0];
      src.M[0][3] = result->M[0][3];
      *(_QWORD *)&src.M[1][0] = __PAIR64__(LODWORD(result->M[1][1]), LODWORD(v34));
      *(_QWORD *)&src.M[1][2] = *(_QWORD *)&result->M[1][2];
      Scaleform::Render::Matrix2x4<float>::SetInverse(result, &src);
    }
  }
  return result;
}M[1][2] = *(_QWORD *)&result->M[1][2];
      Scaleform::Render::Matrix2x4<float>::Se

