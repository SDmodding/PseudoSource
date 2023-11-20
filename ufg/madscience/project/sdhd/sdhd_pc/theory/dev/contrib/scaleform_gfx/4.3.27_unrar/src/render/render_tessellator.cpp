// File Line: 86
// RVA: 0x945A00
void __fastcall Scaleform::Render::Tessellator::Tessellator(Scaleform::Render::Tessellator *this, Scaleform::Render::LinearHeap *heap1, Scaleform::Render::LinearHeap *heap2)
{
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::Tessellator::`vftable';
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
  Scaleform::Render::Tessellator *v1; // rbx

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
  v1 = this;
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
  Scaleform::Render::LinearHeap::ClearAndRelease(v1->pHeap2);
}

// File Line: 147
// RVA: 0x9D5BD0
void __fastcall Scaleform::Render::Tessellator::clearHeap1(Scaleform::Render::Tessellator *this)
{
  unsigned __int64 v1; // rax
  Scaleform::Render::LinearHeap *v2; // r9
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
  v2 = this->pHeap1;
  if ( v2->MaxPages )
  {
    v3 = 0i64;
    do
    {
      ++v1;
      ++v3;
      *((_QWORD *)&v2->pPagePool[v3] - 1) = v2->pPagePool[v3 - 1].pStart;
    }
    while ( v1 < v2->MaxPages );
  }
  v2->pLastPage = v2->pPagePool;
}l[v3] - 1) = v2->pPagePool

// File Line: 247
// RVA: 0x9D6230
bool __fastcall Scaleform::Render::Tessellator::cmpEdgeAA(Scaleform::Render::Tessellator::TmpEdgeAAType *a, Scaleform::Render::Tessellator::TmpEdgeAAType *b)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  bool result; // al

  v2 = a->slope;
  v3 = b->slope;
  if ( v2 == v3 )
    result = a->style < b->style;
  else
    result = v3 > v2;
  return result;
}

// File Line: 255
// RVA: 0x9D62C0
bool __fastcall Scaleform::Render::Tessellator::cmpOuterEdges(Scaleform::Render::Tessellator::OuterEdgeType *a, Scaleform::Render::Tessellator::OuterEdgeType *b)
{
  Scaleform::Render::Tessellator::EdgeAAType *v2; // r8
  Scaleform::Render::Tessellator::EdgeAAType *v3; // r9
  Scaleform::Render::Tessellator::MonoVertexType *v4; // rcx
  Scaleform::Render::Tessellator::MonoVertexType *v5; // rdx
  bool v6; // cf

  v2 = a->edge;
  v3 = b->edge;
  v4 = a->edge->cntVer;
  v5 = b->edge->cntVer;
  v6 = v4 < v5;
  if ( v4 == v5 )
    v6 = v2->rayVer < v3->rayVer;
  return v6;
}

// File Line: 263
// RVA: 0x9D6320
_BOOL8 __fastcall Scaleform::Render::Tessellator::cmpStrokerEdges(Scaleform::Render::Tessellator::StrokerEdgeType *a, Scaleform::Render::Tessellator::StrokerEdgeType *b)
{
  unsigned int v2; // er8
  unsigned int v3; // er9
  _BOOL8 result; // rax

  v2 = a->node1 & 0xFFFFFFF;
  v3 = b->node1 & 0xFFFFFFF;
  if ( v2 == v3 )
    result = (a->node2 & 0xFFFFFFF) < (b->node2 & 0xFFFFFFF);
  else
    result = v2 < v3;
  return result;
}

// File Line: 309
// RVA: 0x9CF930
void __fastcall Scaleform::Render::Tessellator::buildEdgeList(Scaleform::Render::Tessellator *this, unsigned int start, unsigned int numEdges, int step, unsigned int leftStyle, unsigned int rightStyle)
{
  unsigned __int64 v6; // r13
  int v7; // er12
  Scaleform::Render::Tessellator *v8; // r15
  unsigned int v9; // er14
  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *v10; // rbx
  __int64 v11; // rsi
  Scaleform::Render::Tessellator::SrcVertexType **v12; // rcx
  char v13; // r8
  Scaleform::Render::Tessellator::SrcVertexType *v14; // rdx
  unsigned __int64 v15; // rdi
  Scaleform::Render::Tessellator::SrcVertexType *v16; // rcx
  Scaleform::Render::Tessellator::EdgeType **v17; // rax
  __int64 v18; // r10
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType,4,16> *v19; // r15
  Scaleform::Render::Tessellator::EdgeType *v20; // r9
  unsigned int v21; // er8
  float v22; // xmm8_4
  unsigned __int64 v23; // rbx
  unsigned __int64 v24; // rcx
  __int64 v25; // r8
  __int64 v26; // rdx
  float v27; // xmm6_4
  float v28; // xmm7_4
  Scaleform::Render::Tessellator::MonoChainType *v29; // rcx
  signed __int64 v30; // rdx
  __int64 v31; // [rsp+8h] [rbp-39h]
  int v32; // [rsp+1Ch] [rbp-25h]
  int v33; // [rsp+20h] [rbp-21h]
  Scaleform::Render::VertexBasic v34; // [rsp+98h] [rbp+57h]
  __int16 v35; // [rsp+B8h] [rbp+77h]
  __int16 v36; // [rsp+C0h] [rbp+7Fh]

  v6 = LODWORD(this->Edges.Size);
  v7 = step;
  v8 = this;
  v9 = start;
  if ( numEdges )
  {
    v10 = (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->Edges;
    v11 = numEdges;
    do
    {
      v12 = v8->SrcVertices.Pages;
      v13 = v9;
      LODWORD(v34.x) = v9;
      v14 = v12[(unsigned __int64)v9 >> 4];
      v9 += v7;
      v15 = v10->Size >> 4;
      v16 = v12[(unsigned __int64)v9 >> 4];
      v34.y = (float)(v16[v9 & 0xF].x - v14[v13 & 0xF].x) / (float)(v16[v9 & 0xF].y - v14[v13 & 0xF].y);
      if ( v15 >= v10->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(v10, v15);
      v10->Pages[v15][v10->Size & 0xF] = v34;
      ++v10->Size;
      --v11;
    }
    while ( v11 );
  }
  v17 = v8->Edges.Pages;
  v18 = v6 & 0xF;
  v19 = &v8->MonoChains;
  LODWORD(v31) = v6;
  v20 = v17[v6 >> 4];
  v21 = v20[v18].lower;
  v22 = v20[v18].slope;
  v23 = v19->Size >> 4;
  v24 = v21;
  v25 = v21 & 0xF;
  v32 = (unsigned __int16)v7;
  v26 = *(_QWORD *)(v19[-2].MaxPages + 8 * (v24 >> 4));
  HIDWORD(v31) = LODWORD(v19[-1].Size) - 1;
  v27 = *(float *)(v26 + 8 * v25 + 4);
  v28 = *(float *)(v26 + 8 * v25);
  LOWORD(v33) = v35;
  HIWORD(v33) = v36;
  if ( v23 >= v19->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType,4,16>::allocPage(v19, v23);
  v29 = v19->Pages[v23];
  v30 = v19->Size & 0xF;
  *(_QWORD *)&v29[v30].edge = v31;
  v29[v30].ySort = v27;
  v29[v30].xb = v28;
  v29[v30].xt = v22;
  *(_DWORD *)&v29[v30].dir = v32;
  *(_DWORD *)&v29[v30].leftStyle = v33;
  *(_DWORD *)&v29[v30].leftBelow = 0;
  *(_DWORD *)&v29[v30].rightBelow = 0;
  v29[v30].posIntr = -1;
  v29[v30].posScan = 0;
  ++v19->Size;
}

// File Line: 344
// RVA: 0x9CA0B0
void __fastcall Scaleform::Render::Tessellator::addStyle(Scaleform::Render::Tessellator *this, unsigned int style, bool complex)
{
  unsigned __int64 v3; // r15
  bool v4; // r12
  Scaleform::Render::Tessellator *v5; // rbx
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // rsi
  void *v8; // rbp
  unsigned int *v9; // rdx
  unsigned __int64 v10; // r8

  if ( style )
  {
    v3 = style;
    v4 = complex;
    v5 = this;
    if ( 32 * this->ComplexFlags.Size <= style )
    {
      do
      {
        v6 = v5->ComplexFlags.Size;
        if ( v6 )
          v7 = 2 * v6;
        else
          v7 = 8i64;
        if ( v7 > v5->ComplexFlags.Size )
        {
          v8 = Scaleform::Render::LinearHeap::Alloc(v5->ComplexFlags.pHeap, 4 * v7);
          memset(v8, 0, 4 * v7);
          v9 = v5->ComplexFlags.Array;
          if ( v9 )
          {
            v10 = v5->ComplexFlags.Size;
            if ( v10 )
              memmove(v8, v9, 4 * v10);
          }
          v5->ComplexFlags.Array = (unsigned int *)v8;
        }
        v5->ComplexFlags.Size = v7;
      }
      while ( 32 * v7 <= v3 );
    }
    if ( v4 )
    {
      v5->ComplexFlags.Array[(unsigned __int64)(unsigned int)v3 >> 5] |= 1 << (v3 & 0x1F);
      v5->HasComplexFill = 1;
    }
    if ( v5->MaxStyle < (unsigned int)v3 )
      v5->MaxStyle = v3;
  }
}

// File Line: 367
// RVA: 0x961650
void __fastcall Scaleform::Render::Tessellator::ClosePath(Scaleform::Render::Tessellator *this)
{
  unsigned int v1; // er8
  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *v2; // rbx
  unsigned __int64 v3; // rsi
  Scaleform::Render::Tessellator::SrcVertexType **v4; // r10
  Scaleform::Render::Tessellator::SrcVertexType **v5; // r14
  unsigned __int64 v6; // rsi
  __int64 v7; // rdi
  Scaleform::Render::Tessellator::SrcVertexType *v8; // r14

  v1 = this->LastVertex;
  if ( this->SrcVertices.Size > v1 + 2 )
  {
    v2 = (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcVertices;
    v3 = this->SrcVertices.Size;
    v4 = this->SrcVertices.Pages;
    v5 = this->SrcVertices.Pages;
    if ( v4[(v3 - 1) >> 4][((_BYTE)v3 - 1) & 0xF].x != v5[(unsigned __int64)v1 >> 4][v1 & 0xF].x
      || v4[(v3 - 1) >> 4][((_BYTE)v3 - 1) & 0xF].y != v5[(unsigned __int64)v1 >> 4][v1 & 0xF].y )
    {
      v6 = v3 >> 4;
      v7 = v1 & 0xF;
      v8 = v5[(unsigned __int64)v1 >> 4];
      if ( v6 >= this->SrcVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(v2, v6);
      v2->Pages[v6][v2->Size & 0xF] = (Scaleform::Render::VertexBasic)v8[v7];
      ++v2->Size;
    }
  }
}

// File Line: 381
// RVA: 0x979250
void __fastcall Scaleform::Render::Tessellator::FinalizePath(Scaleform::Render::Tessellator *this, unsigned int leftStyle, unsigned int rightStyle, bool leftComplex, bool rightComplex)
{
  unsigned int v5; // edi
  unsigned __int64 v6; // rdx
  unsigned int v7; // esi
  Scaleform::Render::Tessellator *v8; // rbx
  bool v9; // bp
  unsigned int v10; // er12
  unsigned __int64 v11; // r14
  int v12; // er15
  Scaleform::Render::Tessellator::PathType *v13; // rax
  signed __int64 v14; // rcx

  v5 = leftStyle;
  v6 = this->LastVertex;
  v7 = rightStyle;
  v8 = this;
  if ( this->SrcVertices.Size < (unsigned int)(v6 + 2) || v5 == rightStyle )
  {
    if ( v6 < this->SrcVertices.Size )
      this->SrcVertices.Size = v6;
  }
  else
  {
    if ( this->StrokerMode )
    {
      if ( (v5 == 0) == (rightStyle == 0) )
      {
        if ( v6 < this->SrcVertices.Size )
          this->SrcVertices.Size = v6;
        return;
      }
      v5 = v5 != 0;
      v7 = rightStyle != 0;
      v9 = 0;
      leftComplex = 0;
    }
    else
    {
      v9 = rightComplex;
    }
    Scaleform::Render::Tessellator::addStyle(this, v5, leftComplex);
    Scaleform::Render::Tessellator::addStyle(v8, v7, v9);
    v10 = v8->LastVertex;
    v11 = v8->Paths.Size >> 4;
    v12 = LODWORD(v8->SrcVertices.Size) - 1;
    if ( v11 >= v8->Paths.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4> *)&v8->Paths,
        v8->Paths.Size >> 4);
    v13 = v8->Paths.Pages[v11];
    v14 = v8->Paths.Size & 0xF;
    v13[v14].start = v10;
    v13[v14].end = v12;
    v13[v14].leftStyle = v5;
    v13[v14].rightStyle = v7;
    ++v8->Paths.Size;
    v8->LastVertex = v8->SrcVertices.Size;
  }
}

// File Line: 435
// RVA: 0x9DF530
void __fastcall Scaleform::Render::Tessellator::decomposePath(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::PathType *path)
{
  int v2; // edi
  signed int v3; // esi
  Scaleform::Render::Tessellator::PathType *v4; // r14
  Scaleform::Render::Tessellator *v5; // rbp
  Scaleform::Render::Tessellator::SrcVertexType **v6; // r11
  float v7; // xmm0_4
  int v8; // er9
  unsigned int v9; // ebx
  int i; // er10
  signed int v11; // edi
  int j; // er11
  Scaleform::Render::Tessellator::SrcVertexType **v13; // rsi
  int v14; // er9
  float v15; // xmm0_4
  __int64 v16; // rcx
  Scaleform::Render::Tessellator::SrcVertexType *v17; // rax
  unsigned int v18; // ebx
  int k; // er10

  v2 = path->start;
  v3 = path->end;
  v4 = path;
  v5 = this;
  if ( (signed int)path->start < v3 )
  {
    do
    {
      v6 = v5->SrcVertices.Pages;
      v7 = v6[(unsigned __int64)v2 >> 4][v2 & 0xF].y;
      if ( v2 > (signed int)v4->start )
      {
        if ( v7 <= v6[(unsigned __int64)(v2 - 1) >> 4][(v2 - 1) & 0xF].y )
        {
          v8 = v2 + 1;
          if ( v7 < v6[(unsigned __int64)(v2 + 1) >> 4][(v2 + 1) & 0xF].y )
          {
LABEL_7:
            v9 = 1;
            for ( i = v8 + 1;
                  v8 < v3 && v6[(unsigned __int64)i >> 4][i & 0xF].y > v6[(unsigned __int64)v8 >> 4][v8 & 0xF].y;
                  ++i )
            {
              ++v9;
              ++v8;
            }
            Scaleform::Render::Tessellator::buildEdgeList(v5, v2, v9, 1, v4->leftStyle, v4->rightStyle);
            v2 = v9 + v2 - 1;
            goto LABEL_12;
          }
        }
      }
      else
      {
        v8 = v2 + 1;
        if ( v7 < v6[(unsigned __int64)(v2 + 1) >> 4][(v2 + 1) & 0xF].y )
          goto LABEL_7;
      }
LABEL_12:
      v3 = v4->end;
      ++v2;
    }
    while ( v2 < v3 );
  }
  v11 = v4->end;
  for ( j = v4->start; v11 > (signed int)v4->start; --v11 )
  {
    v13 = v5->SrcVertices.Pages;
    v14 = v11 - 1;
    v15 = v13[(unsigned __int64)v11 >> 4][v11 & 0xF].y;
    v16 = (v11 - 1) & 0xF;
    v17 = v13[(unsigned __int64)(v11 - 1) >> 4];
    if ( v11 < (signed int)v4->end )
    {
      if ( v15 < v17[v16].y && v15 <= v13[(unsigned __int64)(v11 + 1) >> 4][(v11 + 1) & 0xF].y )
      {
LABEL_19:
        v18 = 1;
        for ( k = v11 - 2;
              v14 > j && v13[(unsigned __int64)k >> 4][k & 0xF].y > v13[(unsigned __int64)v14 >> 4][v14 & 0xF].y;
              --k )
        {
          ++v18;
          --v14;
        }
        Scaleform::Render::Tessellator::buildEdgeList(v5, v11, v18, -1, v4->leftStyle, v4->rightStyle);
        v11 += 1 - v18;
        goto LABEL_24;
      }
    }
    else if ( v15 < v17[v16].y )
    {
      goto LABEL_19;
    }
LABEL_24:
    j = v4->start;
  }
}

// File Line: 512
// RVA: 0x9EBD70
void __fastcall Scaleform::Render::Tessellator::perceiveStyles(Scaleform::Render::Tessellator *this, Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8> *aet)
{
  Scaleform::Render::Tessellator *v2; // rbx
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8> *v3; // rdi
  unsigned __int16 v4; // r11
  unsigned __int64 v5; // r9
  Scaleform::Render::Tessellator::MonoChainType *v6; // r8
  __int64 v7; // r10
  __int64 v8; // rcx
  int *v9; // rax
  unsigned __int64 v10; // rax
  int *v11; // rdx
  unsigned __int16 v12; // ax

  v2 = this;
  v3 = aet;
  memset(this->StyleCounts.Array, 0, 4 * this->StyleCounts.Size);
  v4 = 0;
  v5 = 0i64;
  if ( v3->Size )
  {
    do
    {
      v6 = v3->Pages[v5 >> 4][v5 & 0xF];
      v6->flags &= 0xFFFBu;
      if ( !(v6->flags & 2) )
      {
        v7 = v6->rightStyle;
        v8 = v6->leftStyle;
        v9 = v2->StyleCounts.Array;
        if ( v2->FillRule )
        {
          v9[v8] ^= 1u;
          v2->StyleCounts.Array[v7] ^= 1u;
        }
        else
        {
          v9[v8] += v6->dir;
          v2->StyleCounts.Array[v7] -= v6->dir;
        }
        v10 = v2->StyleCounts.Size;
        if ( v10 )
        {
          v11 = &v2->StyleCounts.Array[v10 - 1];
          while ( !*v11 )
          {
            --v11;
            if ( !--v10 )
              goto LABEL_10;
          }
          v12 = v10 - 1;
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
      ++v5;
    }
    while ( v5 < v3->Size );
  }
}

// File Line: 535
// RVA: 0x9F2270
void __fastcall Scaleform::Render::Tessellator::setupIntersections(Scaleform::Render::Tessellator *this)
{
  unsigned __int64 v1; // rdi
  Scaleform::Render::Tessellator *v2; // r14
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *v3; // rbp
  Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *v4; // rbx
  signed __int64 v5; // r8
  signed __int64 v6; // rdx
  unsigned __int64 v7; // rsi
  Scaleform::Render::Tessellator::MonoVertexType **v8; // r15
  unsigned __int64 v9; // rsi

  v1 = 0i64;
  v2 = this;
  this->InteriorChains.Size = 0i64;
  this->InteriorOrder.Size = 0i64;
  if ( this->ActiveChains.Size )
  {
    v3 = (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *)&this->InteriorChains;
    v4 = (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&this->InteriorOrder;
    do
    {
      v5 = v1 >> 4;
      v6 = v1 & 0xF;
      v2->ActiveChains.Pages[v5][v6]->posIntr = v1;
      v7 = v3->Size >> 4;
      v8 = (Scaleform::Render::Tessellator::MonoVertexType **)&v2->ActiveChains.Pages[v5][v6];
      if ( v7 >= v3->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8>::allocPage(v3, v3->Size >> 4);
      v3->Pages[v7][v3->Size & 0xF] = *v8;
      ++v3->Size;
      v9 = v4->Size >> 4;
      if ( v9 >= v4->NumPages )
        Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(v4, v4->Size >> 4);
      v4->Pages[v9][v4->Size & 0xF] = (Scaleform::Render::GlyphFitter::VertexType)v1;
      ++v4->Size;
      ++v1;
    }
    while ( v1 < v2->ActiveChains.Size );
  }
}

// File Line: 556
// RVA: 0x9EAE70
__int64 __fastcall Scaleform::Render::Tessellator::nextScanbeam(Scaleform::Render::Tessellator *this, float yb, float yt, unsigned int startMc, unsigned int numMc)
{
  float v5; // xmm7_4
  unsigned int v6; // er13
  Scaleform::Render::Tessellator *v7; // rdi
  signed int v8; // ebp
  signed __int64 v9; // r12
  unsigned __int64 v10; // r14
  Scaleform::Render::Tessellator::MonoChainType *v11; // rbx
  unsigned int v12; // er10
  int v13; // er15
  Scaleform::Render::Tessellator::SrcVertexType **v14; // rsi
  __int64 v15; // r9
  Scaleform::Render::Tessellator::EdgeType *v16; // r11
  __int64 v17; // r9
  Scaleform::Render::Tessellator::EdgeType *v18; // r10
  Scaleform::Render::Tessellator::SrcVertexType **v19; // rcx
  unsigned int v20; // edx
  Scaleform::Render::Tessellator::SrcVertexType *v21; // r11
  __int64 v22; // r8
  float v23; // xmm0_4
  __int64 v24; // r8
  Scaleform::Render::Tessellator::SrcVertexType *v25; // rdx
  unsigned __int64 v26; // rbp
  unsigned int *v27; // rax
  unsigned int v28; // eax
  __int64 v29; // rdx
  Scaleform::Render::Tessellator::SrcVertexType *v30; // rcx
  float v31; // xmm0_4
  __int64 v32; // r8
  Scaleform::Render::Tessellator::SrcVertexType *v33; // rdx
  unsigned __int64 v34; // rsi
  signed __int64 v35; // r14
  __int64 v36; // rbp
  Scaleform::Render::Tessellator::MonoChainType *v37; // r10
  __int64 v38; // r9
  Scaleform::Render::Tessellator::EdgeType *v39; // r11
  Scaleform::Render::Tessellator::SrcVertexType **v40; // rcx
  unsigned int v41; // edx
  Scaleform::Render::Tessellator::SrcVertexType *v42; // rsi
  __int64 v43; // r8
  float v44; // xmm0_4
  __int64 v45; // r8
  Scaleform::Render::Tessellator::SrcVertexType *v46; // rdx
  unsigned __int64 v47; // rsi
  unsigned __int64 v48; // r10
  __int64 v49; // rbx
  unsigned __int64 v50; // r11
  int v51; // er12
  unsigned __int64 v52; // rsi
  Scaleform::Render::Tessellator::MonoChainType ***v53; // r9
  Scaleform::Render::Tessellator::MonoChainType *v54; // rdx
  float v55; // xmm1_4
  Scaleform::Render::Tessellator::MonoChainType *v56; // r8
  float v57; // xmm0_4
  bool v58; // al
  Scaleform::Render::Tessellator::MonoChainType **v59; // rcx
  Scaleform::Render::Tessellator::MonoChainType *v60; // rax
  unsigned int v61; // er15
  unsigned __int64 v62; // r14
  unsigned __int64 i; // rsi
  unsigned __int64 v64; // rbp
  unsigned __int64 v65; // r13
  unsigned __int64 v66; // r9
  unsigned int **v67; // rdx
  Scaleform::Render::Tessellator::MonoChainType ***v68; // r8
  __int64 v69; // r14
  unsigned __int64 v70; // r12
  unsigned __int64 v71; // r15
  unsigned int v72; // ecx
  Scaleform::Render::Tessellator::MonoChainType *v73; // rbx
  unsigned int v74; // ecx
  Scaleform::Render::Tessellator::MonoChainType *v75; // rsi
  float v76; // xmm1_4
  float v77; // xmm6_4
  float v78; // xmm0_4
  float v79; // xmm6_4
  unsigned __int64 v80; // rsi
  unsigned __int64 v81; // rdx
  Scaleform::Render::LinearHeap *v82; // rcx
  void *v83; // rbx
  unsigned __int64 v84; // rax
  signed __int64 v85; // rdx
  Scaleform::Render::Tessellator::IntersectionType *v86; // rax
  unsigned int **v87; // rcx
  Scaleform::Render::Tessellator::MonoChainType ***v88; // rdx
  unsigned int v89; // er10
  unsigned int v90; // er9
  unsigned __int64 v91; // rax
  __int64 v92; // r10
  Scaleform::Render::Tessellator::MonoChainType **v93; // r8
  unsigned __int64 v94; // rax
  __int64 v95; // r9
  Scaleform::Render::Tessellator::MonoChainType **v96; // rdx
  Scaleform::Render::Tessellator::MonoChainType *v97; // rcx
  unsigned __int64 v98; // rdx
  signed __int64 v99; // r8
  Scaleform::Render::Tessellator::IntersectionType *v100; // rcx
  __int64 v102; // [rsp+20h] [rbp-A8h]
  unsigned int v103; // [rsp+30h] [rbp-98h]
  unsigned int v104; // [rsp+34h] [rbp-94h]
  signed __int64 v105; // [rsp+D0h] [rbp+8h]
  signed int v106; // [rsp+D8h] [rbp+10h]

  v5 = yb;
  v6 = numMc;
  v7 = this;
  v8 = 0;
  if ( numMc )
    v8 = 1;
  v9 = startMc;
  this->ValidChains.Size = 0i64;
  v106 = v8;
  v10 = 0i64;
  if ( this->ActiveChains.Size > 0 )
  {
    do
    {
      v11 = v7->ActiveChains.Pages[v10 >> 4][v10 & 0xF];
      v11->flags &= 0xFFF7u;
      v12 = v11->edge;
      v13 = v11->dir;
      v14 = v7->SrcVertices.Pages;
      v15 = v11->edge & 0xF;
      v16 = v7->Edges.Pages[(unsigned __int64)v11->edge >> 4];
      if ( yb == v14[(unsigned __int64)(v13 + v16[v15].lower) >> 4][(v13 + v16[v15].lower) & 0xF].y )
      {
        if ( v12 >= v11->end )
        {
          v28 = LODWORD(v11->xt);
          v8 |= 2u;
          v11->flags |= 2u;
          v11->flags |= 8u;
          LODWORD(v11->xb) = v28;
          v106 = v8;
        }
        else
        {
          v11->edge = v12 + 1;
          v17 = ((_BYTE)v12 + 1) & 0xF;
          v18 = v7->Edges.Pages[(unsigned __int64)(v12 + 1) >> 4];
          v19 = v7->SrcVertices.Pages;
          v20 = v18[v17].lower;
          v21 = v19[(unsigned __int64)(v20 + v13) >> 4];
          v22 = ((_BYTE)v20 + (_BYTE)v13) & 0xF;
          v11->xb = v19[(unsigned __int64)v18[v17].lower >> 4][v20 & 0xF].x;
          if ( yt == v21[v22].y )
          {
            v23 = v21[v22].x;
          }
          else
          {
            v24 = v18[v17].lower & 0xF;
            v25 = v7->SrcVertices.Pages[(unsigned __int64)v18[v17].lower >> 4];
            v23 = (float)((float)(yt - v25[v24].y) * v18[v17].slope) + v25[v24].x;
          }
          v11->xt = v23;
          v26 = v7->ValidChains.Size >> 4;
          if ( v26 >= v7->ValidChains.NumPages )
            Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&v7->ValidChains,
              v7->ValidChains.Size >> 4);
          v27 = v7->ValidChains.Pages[v26];
          v8 = v106;
          v27[v7->ValidChains.Size & 0xF] = v10;
          ++v7->ValidChains.Size;
          v11->flags |= 8u;
        }
      }
      else
      {
        v29 = (v13 + v16[v15].lower) & 0xF;
        v30 = v14[(unsigned __int64)(v13 + v16[v15].lower) >> 4];
        v11->xb = v11->xt;
        if ( yt == v30[v29].y )
        {
          v31 = v30[v29].x;
        }
        else
        {
          v32 = v16[v15].lower & 0xF;
          v33 = v7->SrcVertices.Pages[(unsigned __int64)v16[v15].lower >> 4];
          v31 = (float)((float)(yt - v33[v32].y) * v16[v15].slope) + v33[v32].x;
        }
        v11->xt = v31;
        v34 = v7->ValidChains.Size >> 4;
        if ( v34 >= v7->ValidChains.NumPages )
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&v7->ValidChains,
            v7->ValidChains.Size >> 4);
        v7->ValidChains.Pages[v34][v7->ValidChains.Size & 0xF] = v10;
        ++v7->ValidChains.Size;
      }
      ++v10;
    }
    while ( v10 < v7->ActiveChains.Size );
    v6 = numMc;
  }
  if ( v6 )
  {
    v35 = v9;
    v36 = v6;
    do
    {
      v37 = v7->MonoChainsSorted.Array[v35];
      v38 = v37->edge & 0xF;
      v39 = v7->Edges.Pages[(unsigned __int64)v37->edge >> 4];
      v40 = v7->SrcVertices.Pages;
      v41 = v39[v38].lower;
      v42 = v40[(unsigned __int64)(v41 + v37->dir) >> 4];
      v43 = ((_BYTE)v41 + (unsigned __int8)v37->dir) & 0xF;
      *(float *)&v40 = v40[(unsigned __int64)v39[v38].lower >> 4][v41 & 0xF].x;
      v37->flags = 8;
      LODWORD(v37->xb) = (_DWORD)v40;
      if ( yt == v42[v43].y )
      {
        v44 = v42[v43].x;
      }
      else
      {
        v45 = v39[v38].lower & 0xF;
        v46 = v7->SrcVertices.Pages[(unsigned __int64)v39[v38].lower >> 4];
        v44 = (float)((float)(yt - v46[v45].y) * v39[v38].slope) + v46[v45].x;
      }
      v37->xt = v44;
      v47 = v7->ActiveChains.Size >> 4;
      if ( v47 >= v7->ActiveChains.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *)&v7->ActiveChains,
          v7->ActiveChains.Size >> 4);
      ++v35;
      v7->ActiveChains.Pages[v47][v7->ActiveChains.Size & 0xF] = 0i64;
      ++v7->ActiveChains.Size;
      --v36;
    }
    while ( v36 );
    v48 = v7->ActiveChains.Size;
    LODWORD(v49) = v9 + numMc;
    v50 = v7->ActiveChains.Size - v6;
    v51 = -(signed int)v9;
    v52 = v50 - 1;
    do
    {
      if ( !v50
        || ((v53 = v7->ActiveChains.Pages,
             v54 = v7->MonoChainsSorted.Array[(unsigned int)(v49 - 1)],
             v55 = v54->xb,
             v56 = v53[v52 >> 4][v52 & 0xF],
             v57 = v56->xb,
             v57 == v55) ? (v58 = v56->xt < v54->xt) : (v58 = v55 > v57),
            v58) )
      {
        --v48;
        v49 = (unsigned int)(v49 - 1);
        v59 = v7->ActiveChains.Pages[v48 >> 4];
        v60 = v7->MonoChainsSorted.Array[v49];
      }
      else
      {
        --v50;
        --v48;
        --v52;
        v59 = v53[v48 >> 4];
        v60 = v53[v50 >> 4][v50 & 0xF];
      }
      v59[v48 & 0xF] = v60;
    }
    while ( v51 + (_DWORD)v49 );
  }
  v61 = v106;
  v62 = 0i64;
  v7->Intersections.Size = 0i64;
  if ( v106 & 1 )
  {
    v7->ValidChains.Size = 0i64;
    for ( i = 0i64; i < v7->ActiveChains.Size; ++i )
    {
      if ( !(v7->ActiveChains.Pages[i >> 4][i & 0xF]->flags & 2) )
      {
        v64 = v7->ValidChains.Size >> 4;
        if ( v64 >= v7->ValidChains.NumPages )
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&v7->ValidChains,
            v7->ValidChains.Size >> 4);
        v7->ValidChains.Pages[v64][v7->ValidChains.Size & 0xF] = i;
        ++v7->ValidChains.Size;
      }
    }
  }
  if ( v7->ValidChains.Size > 1 )
  {
    v65 = 0i64;
    v102 = 0i64;
    do
    {
      if ( (v65 & 0x8000000000000000ui64) == 0i64 )
      {
        v66 = v65 + 1;
        v105 = v65 + 1;
        do
        {
          v67 = v7->ValidChains.Pages;
          v68 = v7->ActiveChains.Pages;
          v69 = v65 & 0xF;
          v70 = v66 & 0xF;
          v71 = v66 >> 4;
          v72 = v67[v65 >> 4][v69];
          v73 = v68[(unsigned __int64)v72 >> 4][v72 & 0xF];
          v74 = v67[v66 >> 4][v70];
          v75 = v68[(unsigned __int64)v74 >> 4][v74 & 0xF];
          if ( v75->xt >= v73->xt )
            break;
          if ( !v7->Intersections.Size )
            Scaleform::Render::Tessellator::setupIntersections(v7);
          v76 = v75->xb;
          v103 = v73->posIntr;
          v77 = v73->xb;
          v104 = v75->posIntr;
          v78 = (float)((float)(v75->xt - v76) - v73->xt) + v77;
          if ( v78 != 0.0 )
          {
            v79 = (float)((float)((float)(v77 - v76) * (float)(yt - v5)) / v78) + v5;
            if ( v79 >= v5 )
              continue;
          }
          v79 = v5;
          if ( v79 > yt )
            v79 = yt;
          v80 = v7->Intersections.Size >> 4;
          if ( v80 >= v7->Intersections.NumPages )
          {
            v81 = v7->Intersections.MaxPages;
            if ( v80 >= v81 )
            {
              v82 = v7->Intersections.pHeap;
              if ( v7->Intersections.Pages )
              {
                v83 = Scaleform::Render::LinearHeap::Alloc(v82, 16 * v81);
                memmove(v83, v7->Intersections.Pages, 8 * v7->Intersections.NumPages);
                v84 = v7->Intersections.MaxPages;
                v7->Intersections.Pages = (Scaleform::Render::Tessellator::IntersectionType **)v83;
                v7->Intersections.MaxPages = 2 * v84;
              }
              else
              {
                v7->Intersections.MaxPages = 4i64;
                v7->Intersections.Pages = (Scaleform::Render::Tessellator::IntersectionType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                                 v82,
                                                                                                 0x20ui64);
              }
            }
            v7->Intersections.Pages[v80] = (Scaleform::Render::Tessellator::IntersectionType *)Scaleform::Render::LinearHeap::Alloc(
                                                                                                 v7->Intersections.pHeap,
                                                                                                 0xC0ui64);
            ++v7->Intersections.NumPages;
          }
          v85 = v7->Intersections.Size & 0xF;
          v86 = v7->Intersections.Pages[v80];
          v86[v85].pos1 = v103;
          v86[v85].pos2 = v104;
          v86[v85].y = v79;
          ++v7->Intersections.Size;
          v87 = v7->ValidChains.Pages;
          v88 = v7->ActiveChains.Pages;
          v89 = v87[v71][v70];
          v90 = v87[v65 >> 4][v69];
          v91 = v89;
          v92 = v89 & 0xF;
          v93 = v88[v91 >> 4];
          v94 = v90;
          v95 = v90 & 0xF;
          v96 = v88[v94 >> 4];
          v97 = v96[v95];
          v96[v95] = v93[v92];
          v66 = v105 - 1;
          --v65;
          v93[v92] = v97;
          --v105;
        }
        while ( (v65 & 0x8000000000000000ui64) == 0i64 );
        v65 = v102;
      }
      v102 = ++v65;
    }
    while ( v65 + 1 < v7->ValidChains.Size );
    v61 = v106;
    v62 = 0i64;
  }
  if ( v7->Intersections.Size > 1 )
  {
    Scaleform::Alg::InsertionSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::IntersectionType,4,4>,bool (*)(Scaleform::Render::Tessellator::IntersectionType const &,Scaleform::Render::Tessellator::IntersectionType const &)>(
      &v7->Intersections,
      0i64,
      v7->Intersections.Size,
      (bool (__fastcall *)(Scaleform::Render::Tessellator::IntersectionType *, Scaleform::Render::Tessellator::IntersectionType *))UFG::SectionChooser::fnSectionStreamPriority);
    if ( v7->HasEpsilon )
    {
      if ( v7->Intersections.Size )
      {
        do
        {
          v98 = v62 >> 4;
          v99 = v62 & 0xF;
          v100 = v7->Intersections.Pages[v62 >> 4];
          if ( (float)(v100[v62 & 0xF].y - v5) < (float)(COERCE_FLOAT(LODWORD(v5) & _xmm) * v7->Epsilon) )
            v100[v62 & 0xF].y = v5;
          ++v62;
          v5 = v7->Intersections.Pages[v98][v99].y;
        }
        while ( v62 < v7->Intersections.Size );
      }
    }
  }
  return v61;
}

// File Line: 763
// RVA: 0x9C6BE0
signed __int64 __fastcall Scaleform::Render::Tessellator::addEventVertex(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::MonoChainType *mc, float yb, bool enforceFlag)
{
  __int64 v4; // r10
  Scaleform::Render::Tessellator *v5; // rbx
  Scaleform::Render::Tessellator::EdgeType *v6; // r11
  unsigned __int16 v7; // cx
  unsigned int v8; // edx
  Scaleform::Render::Tessellator::SrcVertexType **v9; // r8
  Scaleform::Render::Tessellator::SrcVertexType *v10; // rcx
  __int64 v11; // rdx
  float v12; // xmm6_4
  float v13; // xmm7_4
  signed __int64 v14; // rdi
  unsigned __int64 v15; // rsi
  signed __int64 v16; // rdx
  Scaleform::Render::TessVertex *v17; // rax
  unsigned int v19; // er8
  Scaleform::Render::Tessellator::SrcVertexType **v20; // r9
  unsigned __int64 v21; // rax
  __int64 v22; // r8
  Scaleform::Render::Tessellator::SrcVertexType *v23; // rcx
  Scaleform::Render::Tessellator::SrcVertexType *v24; // rcx
  float v25; // xmm7_4
  unsigned __int64 v26; // rsi

  v4 = mc->edge & 0xF;
  v5 = this;
  v6 = this->Edges.Pages[(unsigned __int64)mc->edge >> 4];
  if ( !enforceFlag )
  {
    v7 = mc->flags;
    if ( !(v7 & 0x10) && *(_DWORD *)&mc->leftAbove == __PAIR__(mc->rightAbove, mc->leftBelow) )
    {
      if ( !(v7 & 8) )
        return 0xFFFFFFFFi64;
      v8 = v6[v4].lower;
      v9 = v5->SrcVertices.Pages;
      if ( yb != v9[(unsigned __int64)v6[v4].lower >> 4][v6[v4].lower & 0xF].y )
        return 0xFFFFFFFFi64;
      v10 = v9[(unsigned __int64)v8 >> 4];
LABEL_7:
      v11 = v8 & 0xF;
      v12 = v10[v11].x;
      if ( v12 > v5->LastX )
      {
        v5->LastX = v12;
        v13 = v10[v11].y;
LABEL_9:
        v14 = (signed __int64)&v5->MeshVertices;
        v15 = v5->MeshVertices.Size >> 4;
        if ( v15 >= v5->MeshVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
            &v5->MeshVertices,
            v5->MeshVertices.Size >> 4);
        v16 = v5->MeshVertices.Size & 0xF;
        v17 = v5->MeshVertices.Pages[v15];
        v17[v16].x = v12;
        v17[v16].y = v13;
LABEL_23:
        *(_QWORD *)&v17[v16].Idx = -1i64;
        *(_DWORD *)&v17[v16].Flags = 2;
        ++*(_QWORD *)(v14 + 8);
        return (unsigned int)(LODWORD(v5->MeshVertices.Size) - 1);
      }
      return (unsigned int)(LODWORD(v5->MeshVertices.Size) - 1);
    }
  }
  v19 = v6[v4].lower;
  v20 = v5->SrcVertices.Pages;
  if ( yb != v20[(unsigned __int64)v6[v4].lower >> 4][v6[v4].lower & 0xF].y )
  {
    if ( !(mc->flags & 2) || (v8 = v19 + mc->dir, yb != v20[(unsigned __int64)v8 >> 4][v8 & 0xF].y) )
    {
      v24 = v20[(unsigned __int64)v6[v4].lower >> 4];
      v25 = (float)((float)(yb - v24[v19 & 0xF].y) * v6[v4].slope) + v24[v19 & 0xF].x;
      if ( (float)(v25 - v5->LastX) > (float)(COERCE_FLOAT(LODWORD(yb) & _xmm) * v5->Epsilon) )
      {
        v14 = (signed __int64)&v5->MeshVertices;
        v5->LastX = v25;
        v26 = v5->MeshVertices.Size >> 4;
        if ( v26 >= v5->MeshVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(&v5->MeshVertices, v26);
        v16 = v5->MeshVertices.Size & 0xF;
        v17 = v5->MeshVertices.Pages[v26];
        v17[v16].x = v25;
        v17[v16].y = yb;
        goto LABEL_23;
      }
      return (unsigned int)(LODWORD(v5->MeshVertices.Size) - 1);
    }
    v10 = v20[(unsigned __int64)v8 >> 4];
    goto LABEL_7;
  }
  v21 = v19;
  v22 = v19 & 0xF;
  v23 = v20[v21 >> 4];
  v12 = v23[v22].x;
  if ( v12 > v5->LastX )
  {
    v5->LastX = v12;
    v13 = v23[v22].y;
    goto LABEL_9;
  }
  return (unsigned int)(LODWORD(v5->MeshVertices.Size) - 1);
}

// File Line: 893
// RVA: 0x9F03F0
void __fastcall Scaleform::Render::Tessellator::removeLastMonoVertex(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::MonotoneType *m)
{
  Scaleform::Render::Tessellator *v2; // r8
  unsigned int v3; // ecx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rcx
  unsigned int v6; // eax

  v2 = this;
  v3 = m->d.m.lastIdx;
  if ( v3 != -1 )
  {
    if ( v3 == LODWORD(v2->MonoVertices.Size) - 1 )
    {
      v4 = v2->MonoVertices.Size;
      if ( v4 )
        v2->MonoVertices.Size = v4 - 1;
    }
    v5 = m->d.m.prevIdx1;
    v6 = m->d.m.prevIdx2;
    m->d.m.prevIdx2 = -1;
    m->d.m.lastIdx = v5;
    m->d.m.prevIdx1 = v6;
    if ( (_DWORD)v5 == -1 )
      m->start = 0i64;
    else
      v2->MonoVertices.Pages[v5 >> 4][v5 & 0xF].next = 0i64;
  }
}

// File Line: 952
// RVA: 0x9F3640
Scaleform::Render::Tessellator::MonotoneType *__fastcall Scaleform::Render::Tessellator::startMonotone(Scaleform::Render::Tessellator *this, unsigned int style)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16> *v2; // rbx
  unsigned __int64 v3; // rdi
  Scaleform::Render::Tessellator::MonotoneType *v4; // rdx
  __int64 v6; // [rsp+30h] [rbp-18h]

  v2 = &this->Monotones;
  LODWORD(v6) = -1;
  HIDWORD(v6) = style;
  v3 = this->Monotones.Size >> 4;
  if ( v3 >= this->Monotones.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16>::allocPage(&this->Monotones, v3);
  v4 = &v2->Pages[v3][v2->Size & 0xF];
  v4->start = 0i64;
  *(_QWORD *)&v4->d.m.lastIdx = -1i64;
  *(_QWORD *)&v4->d.t.meshIdx = v6;
  v4->lowerBase = 0i64;
  ++v2->Size;
  return &v2->Pages[(v2->Size - 1) >> 4][((unsigned int)v2->Size - 1) & 0xF];
}

// File Line: 961
// RVA: 0x9F36F0
void __fastcall Scaleform::Render::Tessellator::startMonotone(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::ScanChainType *scan, unsigned int vertex)
{
  Scaleform::Render::Tessellator::MonoChainType *v3; // rax
  Scaleform::Render::Tessellator *v4; // rdi
  unsigned __int16 v5; // cx
  signed int v6; // ebx
  Scaleform::Render::Tessellator::ScanChainType *v7; // r14
  Scaleform::Render::Tessellator::MonotoneType *v8; // rax
  Scaleform::Render::Tessellator::MonotoneType *v9; // rsi
  Scaleform::Render::Tessellator::BaseLineType *v10; // r8
  unsigned __int64 v11; // rbp
  Scaleform::Render::Tessellator::MonoVertexType *v12; // rcx
  signed __int64 v13; // rdx
  signed __int64 v14; // rdx
  signed __int64 v15; // rbp
  unsigned __int64 v16; // rbx
  Scaleform::Render::Tessellator::MonoVertexType *v17; // rcx
  signed __int64 v18; // rdx
  __int64 v19; // [rsp+20h] [rbp-18h]

  v3 = scan->chain;
  v4 = this;
  scan->monotone = 0i64;
  v5 = v3->rightAbove;
  v6 = vertex;
  v7 = scan;
  if ( v5 )
  {
    v8 = Scaleform::Render::Tessellator::startMonotone(v4, v5);
    v9 = v8;
    v7->monotone = v8;
    if ( v8 )
    {
      v10 = v8->lowerBase;
      if ( v10 )
      {
        if ( v4->MeshVertices.Pages[(unsigned __int64)(v6 & 0xFFFFFFF) >> 4][v6 & 0xF].y == v10->y )
        {
          v10->vertexRight = v6 & 0xFFFFFFF;
        }
        else if ( v6 >= 0 )
        {
          Scaleform::Render::Tessellator::connectPendingToRight(v4, v7, v6);
        }
        else
        {
          Scaleform::Render::Tessellator::connectPendingToLeft(v4, v7, v6);
        }
      }
      else
      {
        LODWORD(v19) = v6;
        HIDWORD(v19) = v6;
        if ( v8->start )
        {
          v15 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v8->d.m.lastIdx >> 4][v8->d.m.lastIdx & 0xF];
          if ( *(_DWORD *)v15 == v6 )
            return;
          v16 = v4->MonoVertices.Size >> 4;
          if ( v16 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v17 = v4->MonoVertices.Pages[v16];
          v18 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v17[v18].srcVer = v19;
          v17[v18].next = 0i64;
          *(_QWORD *)(v15 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          v9->d.m.prevIdx2 = v9->d.m.prevIdx1;
          v9->d.m.prevIdx1 = v9->d.m.lastIdx;
        }
        else
        {
          v11 = v4->MonoVertices.Size >> 4;
          if ( v11 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v12 = v4->MonoVertices.Pages[v11];
          v13 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v12[v13].srcVer = v19;
          v12[v13].next = 0i64;
          v14 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)&v9->d.t.numTriangles = -1i64;
          v9->start = (Scaleform::Render::Tessellator::MonoVertexType *)v14;
        }
        v9->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
      }
    }
  }
}

// File Line: 994
// RVA: 0x9F0520
void __fastcall Scaleform::Render::Tessellator::replaceMonotone(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::ScanChainType *scan, unsigned int style)
{
  Scaleform::Render::Tessellator::MonotoneType *v3; // rax
  unsigned int v4; // ebx
  Scaleform::Render::Tessellator::ScanChainType *v5; // rdi
  Scaleform::Render::Tessellator::MonotoneType *v6; // rax
  Scaleform::Render::Tessellator::MonotoneType *v7; // rdx

  if ( style )
  {
    v3 = scan->monotone;
    v4 = style;
    v5 = scan;
    if ( v3 )
    {
      if ( v3->style != style )
      {
        if ( v3->start )
        {
          v6 = Scaleform::Render::Tessellator::startMonotone(this, style);
          v7 = v5->monotone;
          v6->start = v7->start;
          *(_QWORD *)&v6->d.m.lastIdx = *(_QWORD *)&v7->d.m.lastIdx;
          *(_QWORD *)&v6->d.t.meshIdx = *(_QWORD *)&v7->d.t.meshIdx;
          v6->lowerBase = v7->lowerBase;
          v3 = v5->monotone;
          v3->start = 0i64;
          *(_QWORD *)&v3->d.m.lastIdx = -1i64;
          v3->d.m.prevIdx2 = -1;
          v3->lowerBase = 0i64;
        }
      }
      v3->style = v4;
    }
    else
    {
      scan->monotone = Scaleform::Render::Tessellator::startMonotone(this, style);
    }
  }
}

// File Line: 1018
// RVA: 0x9C8960
void __fastcall Scaleform::Render::Tessellator::addPendingEnd(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::ScanChainType *dst, Scaleform::Render::Tessellator::ScanChainType *pending, float y)
{
  Scaleform::Render::Tessellator::MonotoneType *v4; // rsi
  Scaleform::Render::Tessellator::ScanChainType *v5; // rdi
  Scaleform::Render::Tessellator *v6; // rbp
  Scaleform::Render::Tessellator::MonoChainType *v7; // rax
  unsigned int v8; // ecx
  float v9; // eax
  Scaleform::Render::Tessellator::MonotoneType *v10; // r14
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // rdi
  Scaleform::Render::Tessellator::PendingEndType *v13; // rcx
  signed __int64 v14; // rdx
  Scaleform::Render::Tessellator::BaseLineType val; // [rsp+20h] [rbp-28h]

  if ( dst )
  {
    v4 = dst->monotone;
    v5 = pending;
    v6 = this;
    if ( v4 )
    {
      if ( v4->style )
      {
        if ( !v4->lowerBase )
        {
          v7 = pending->chain;
          val.y = y;
          val.vertexRight = -1;
          v8 = v7->leftBelow;
          val.vertexLeft = dst->vertex;
          LODWORD(v7) = v6->PendingEnds.Size;
          val.styleLeft = v8;
          val.leftAbove = -1;
          *(_QWORD *)&val.firstChain = (unsigned int)v7;
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4>::PushBack(
            &v6->BaseLines,
            &val);
          v4->lowerBase = &v6->BaseLines.Pages[(v6->BaseLines.Size - 1) >> 4][(LODWORD(v6->BaseLines.Size) - 1) & 0xF];
        }
        v9 = *(float *)&v5->vertex;
        v10 = v5->monotone;
        v11 = v6->PendingEnds.Size;
        val.y = v9;
        v12 = v11 >> 4;
        if ( v12 >= v6->PendingEnds.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4>::allocPage(
            &v6->PendingEnds,
            v12);
        v13 = v6->PendingEnds.Pages[v12];
        v14 = v6->PendingEnds.Size & 0xF;
        *(_QWORD *)&v13[v14].vertex = *(_QWORD *)&val.y;
        v13[v14].monotone = v10;
        ++v6->PendingEnds.Size;
        ++v4->lowerBase->numChains;
      }
    }
  }
}

// File Line: 1097
// RVA: 0x9D7260
void __fastcall Scaleform::Render::Tessellator::connectPendingToLeft(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::ScanChainType *scan, unsigned int targetVertex)
{
  Scaleform::Render::Tessellator::MonotoneType *v3; // rax
  unsigned int v4; // er11
  Scaleform::Render::Tessellator *v5; // rbx
  unsigned int v6; // er9
  Scaleform::Render::Tessellator::BaseLineType *v7; // r8
  unsigned int v8; // er13
  int v9; // er14
  int v10; // er15
  Scaleform::Render::Tessellator::ScanChainType *v11; // r10
  int v12; // er12
  Scaleform::Render::Tessellator::PendingEndType *v13; // rax
  char v14; // r8
  int *v15; // rdi
  Scaleform::Render::Tessellator::MonotoneType *v16; // r14
  unsigned __int64 v17; // rsi
  Scaleform::Render::Tessellator::MonoVertexType *v18; // rdx
  signed __int64 v19; // rcx
  signed __int64 v20; // rdx
  signed __int64 v21; // rdi
  unsigned __int64 v22; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v23; // rdx
  signed __int64 v24; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v25; // rdi
  unsigned __int64 v26; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v27; // rdx
  signed __int64 v28; // rcx
  signed __int64 v29; // rdx
  signed __int64 v30; // rsi
  unsigned __int64 v31; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v32; // rdx
  signed __int64 v33; // rcx
  unsigned __int64 v34; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v35; // rdx
  signed __int64 v36; // rcx
  signed __int64 v37; // rdx
  signed __int64 v38; // rsi
  unsigned __int64 v39; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v40; // rdx
  signed __int64 v41; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v42; // rax
  Scaleform::Render::Tessellator::MonotoneType *v43; // rsi
  unsigned int v44; // er14
  unsigned __int64 v45; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v46; // rdx
  signed __int64 v47; // rcx
  signed __int64 v48; // rdx
  signed __int64 v49; // r15
  unsigned __int64 v50; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v51; // rdx
  signed __int64 v52; // rcx
  unsigned __int64 v53; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v54; // rdx
  signed __int64 v55; // rcx
  signed __int64 v56; // rdx
  signed __int64 v57; // r14
  unsigned __int64 v58; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v59; // rdx
  signed __int64 v60; // rcx
  __int64 v61; // rdi
  unsigned __int64 v62; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v63; // rdx
  signed __int64 v64; // rcx
  signed __int64 v65; // rdx
  signed __int64 v66; // rsi
  unsigned __int64 v67; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v68; // rdx
  signed __int64 v69; // rcx
  unsigned __int64 v70; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v71; // rdx
  signed __int64 v72; // rcx
  signed __int64 v73; // rdx
  signed __int64 v74; // rsi
  unsigned __int64 v75; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v76; // rdx
  signed __int64 v77; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v78; // rsi
  unsigned __int64 v79; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v80; // rdx
  signed __int64 v81; // rcx
  signed __int64 v82; // rdx
  signed __int64 v83; // rdi
  unsigned __int64 v84; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v85; // rdx
  signed __int64 v86; // rcx
  Scaleform::Render::Tessellator::PendingEndType **v87; // rdx
  unsigned __int64 v88; // rax
  __int64 v89; // rdi
  unsigned __int64 v90; // rax
  unsigned __int64 v91; // rax
  unsigned int v92; // [rsp+20h] [rbp-D0h]
  int v93; // [rsp+28h] [rbp-C8h]
  __int64 v94; // [rsp+30h] [rbp-C0h]
  __int64 v95; // [rsp+40h] [rbp-B0h]
  __int64 v96; // [rsp+50h] [rbp-A0h]
  __int64 v97; // [rsp+60h] [rbp-90h]
  Scaleform::Render::Tessellator::BaseLineType *v98; // [rsp+70h] [rbp-80h]
  __int64 v99; // [rsp+78h] [rbp-78h]
  __int64 v100; // [rsp+78h] [rbp-78h]
  __int64 v101; // [rsp+88h] [rbp-68h]
  __int64 v102; // [rsp+98h] [rbp-58h]
  int v103; // [rsp+A8h] [rbp-48h]
  Scaleform::Render::Tessellator::MonotoneType *v104; // [rsp+B0h] [rbp-40h]
  int vars0; // [rsp+110h] [rbp+20h]
  Scaleform::Render::Tessellator::ScanChainType *retaddr; // [rsp+118h] [rbp+28h]
  unsigned int v107; // [rsp+120h] [rbp+30h]
  unsigned int v108; // [rsp+128h] [rbp+38h]

  v3 = scan->monotone;
  v4 = v3->style;
  v5 = this;
  v6 = targetVertex;
  v7 = v3->lowerBase;
  v3->lowerBase = 0i64;
  v8 = v7->firstChain;
  v9 = v7->vertexLeft;
  v10 = v7->numChains;
  v104 = scan->monotone;
  v11 = scan;
  v93 = v7->vertexRight;
  v98 = v7;
  v108 = v4;
  v13 = this->PendingEnds.Pages[(unsigned __int64)v8 >> 4];
  v103 = v9;
  v92 = v8;
  v12 = v13[v8 & 0xF].vertex;
  LODWORD(v13) = v7->styleLeft;
  vars0 = v10;
  v14 = 1;
  v15 = &v103;
  while ( 1 )
  {
    if ( v9 == v12 )
      goto LABEL_84;
    if ( v14 )
    {
      v16 = v11->monotone;
      LODWORD(v96) = v12;
      HIDWORD(v96) = v12;
      if ( v16->start )
      {
        v21 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v16->d.m.lastIdx >> 4][v16->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v21 == v12 )
          goto LABEL_13;
        v22 = v5->MonoVertices.Size >> 4;
        if ( v22 >= v5->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
            v5->MonoVertices.Size >> 4);
          v6 = v107;
          v11 = retaddr;
        }
        v23 = v5->MonoVertices.Pages[v22];
        v10 = vars0;
        v24 = v5->MonoVertices.Size & 0xF;
        *(_QWORD *)&v23[v24].srcVer = v96;
        v23[v24].next = 0i64;
        *(_QWORD *)(v21 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v16->d.m.prevIdx2 = v16->d.m.prevIdx1;
        v16->d.m.prevIdx1 = v16->d.m.lastIdx;
      }
      else
      {
        v17 = v5->MonoVertices.Size >> 4;
        if ( v17 >= v5->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
            v5->MonoVertices.Size >> 4);
          v6 = v107;
          v11 = retaddr;
        }
        v18 = v5->MonoVertices.Pages[v17];
        v19 = v5->MonoVertices.Size & 0xF;
        *(_QWORD *)&v18[v19].srcVer = v96;
        v18[v19].next = 0i64;
        v20 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v16->d.t.numTriangles = -1i64;
        v16->start = (Scaleform::Render::Tessellator::MonoVertexType *)v20;
      }
      v16->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
LABEL_13:
      v25 = v11->monotone;
      if ( v6 == -1 )
        goto LABEL_84;
      LODWORD(v99) = v6 | 0x80000000;
      HIDWORD(v99) = v6 | 0x80000000;
      if ( v25->start )
      {
        v30 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v25->d.m.lastIdx >> 4][v25->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v30 == (v6 | 0x80000000) )
          goto LABEL_23;
        v31 = v5->MonoVertices.Size >> 4;
        if ( v31 >= v5->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
            v5->MonoVertices.Size >> 4);
          v6 = v107;
        }
        v32 = v5->MonoVertices.Pages[v31];
        v33 = v5->MonoVertices.Size & 0xF;
        *(_QWORD *)&v32[v33].srcVer = v99;
        v32[v33].next = 0i64;
        *(_QWORD *)(v30 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v25->d.m.prevIdx2 = v25->d.m.prevIdx1;
        v25->d.m.prevIdx1 = v25->d.m.lastIdx;
      }
      else
      {
        v26 = v5->MonoVertices.Size >> 4;
        if ( v26 >= v5->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
            v5->MonoVertices.Size >> 4);
          v6 = v107;
        }
        v27 = v5->MonoVertices.Pages[v26];
        v28 = v5->MonoVertices.Size & 0xF;
        *(_QWORD *)&v27[v28].srcVer = v99;
        v27[v28].next = 0i64;
        v29 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v25->d.t.numTriangles = -1i64;
        v25->start = (Scaleform::Render::Tessellator::MonoVertexType *)v29;
      }
      v25->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
LABEL_23:
      LODWORD(v94) = v6 & 0x7FFFFFFF;
      HIDWORD(v94) = v6 & 0x7FFFFFFF;
      if ( v25->start )
      {
        v38 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v25->d.m.lastIdx >> 4][v25->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v38 != (v6 & 0x7FFFFFFF) )
        {
          v39 = v5->MonoVertices.Size >> 4;
          if ( v39 >= v5->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
              v5->MonoVertices.Size >> 4);
            v6 = v107;
          }
          v40 = v5->MonoVertices.Pages[v39];
          v41 = v5->MonoVertices.Size & 0xF;
          *(_QWORD *)&v40[v41].srcVer = v94;
          v40[v41].next = 0i64;
          *(_QWORD *)(v38 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          v25->d.m.prevIdx2 = v25->d.m.prevIdx1;
          v25->d.m.prevIdx1 = v25->d.m.lastIdx;
          v25->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
        }
      }
      else
      {
        v34 = v5->MonoVertices.Size >> 4;
        if ( v34 >= v5->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
            v5->MonoVertices.Size >> 4);
          v6 = v107;
        }
        v35 = v5->MonoVertices.Pages[v34];
        v36 = v5->MonoVertices.Size & 0xF;
        *(_QWORD *)&v35[v36].srcVer = v94;
        v35[v36].next = 0i64;
        v37 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v25->d.t.numTriangles = -1i64;
        v25->start = (Scaleform::Render::Tessellator::MonoVertexType *)v37;
        v25->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
      }
      goto LABEL_83;
    }
    if ( (_DWORD)v13 != v4 || !*((_QWORD *)v15 + 1) )
    {
      v42 = Scaleform::Render::Tessellator::startMonotone(v5, v4);
      v43 = v42;
      *((_QWORD *)v15 + 1) = v42;
      if ( v9 == -1 )
        goto LABEL_43;
      v44 = v9 | 0x80000000;
      LODWORD(v102) = v44;
      HIDWORD(v102) = v44;
      if ( v42->start )
      {
        v49 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v42->d.m.lastIdx >> 4][v42->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v49 == v44 )
          goto LABEL_43;
        v50 = v5->MonoVertices.Size >> 4;
        if ( v50 >= v5->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
            v5->MonoVertices.Size >> 4);
        v51 = v5->MonoVertices.Pages[v50];
        v52 = v5->MonoVertices.Size & 0xF;
        *(_QWORD *)&v51[v52].srcVer = v102;
        v51[v52].next = 0i64;
        *(_QWORD *)(v49 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v43->d.m.prevIdx2 = v43->d.m.prevIdx1;
        v43->d.m.prevIdx1 = v43->d.m.lastIdx;
      }
      else
      {
        v45 = v5->MonoVertices.Size >> 4;
        if ( v45 >= v5->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
            v5->MonoVertices.Size >> 4);
        v46 = v5->MonoVertices.Pages[v45];
        v47 = v5->MonoVertices.Size & 0xF;
        *(_QWORD *)&v46[v47].srcVer = v102;
        v46[v47].next = 0i64;
        v48 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v43->d.t.numTriangles = -1i64;
        v43->start = (Scaleform::Render::Tessellator::MonoVertexType *)v48;
      }
      v43->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
LABEL_43:
      if ( v12 != -1 )
      {
        LODWORD(v95) = v12 & 0x7FFFFFFF;
        HIDWORD(v95) = v12 & 0x7FFFFFFF;
        if ( !v43->start )
        {
          v53 = v5->MonoVertices.Size >> 4;
          if ( v53 >= v5->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
              v5->MonoVertices.Size >> 4);
          v54 = v5->MonoVertices.Pages[v53];
          v55 = v5->MonoVertices.Size & 0xF;
          *(_QWORD *)&v54[v55].srcVer = v95;
          v54[v55].next = 0i64;
          v56 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)&v43->d.t.numTriangles = -1i64;
          v43->start = (Scaleform::Render::Tessellator::MonoVertexType *)v56;
LABEL_52:
          v43->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
          goto LABEL_53;
        }
        v57 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v43->d.m.lastIdx >> 4][v43->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v57 != (v12 & 0x7FFFFFFF) )
        {
          v58 = v5->MonoVertices.Size >> 4;
          if ( v58 >= v5->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
              v5->MonoVertices.Size >> 4);
          v59 = v5->MonoVertices.Pages[v58];
          v60 = v5->MonoVertices.Size & 0xF;
          *(_QWORD *)&v59[v60].srcVer = v95;
          v59[v60].next = 0i64;
          *(_QWORD *)(v57 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          v43->d.m.prevIdx2 = v43->d.m.prevIdx1;
          v43->d.m.prevIdx1 = v43->d.m.lastIdx;
          goto LABEL_52;
        }
      }
LABEL_53:
      v11 = retaddr;
      v6 = v107;
    }
    if ( !vars0 )
    {
      v78 = (Scaleform::Render::Tessellator::MonotoneType *)*((_QWORD *)v15 + 1);
      v11->monotone = v78;
      LODWORD(v101) = v6 | 0x80000000;
      HIDWORD(v101) = v6 | 0x80000000;
      if ( v78->start )
      {
        v83 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v78->d.m.lastIdx >> 4][v78->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v83 == (v6 | 0x80000000) )
          goto LABEL_82;
        v84 = v5->MonoVertices.Size >> 4;
        if ( v84 >= v5->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
            v5->MonoVertices.Size >> 4);
          v6 = v107;
        }
        v85 = v5->MonoVertices.Pages[v84];
        v86 = v5->MonoVertices.Size & 0xF;
        *(_QWORD *)&v85[v86].srcVer = v101;
        v85[v86].next = 0i64;
        *(_QWORD *)(v83 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v78->d.m.prevIdx2 = v78->d.m.prevIdx1;
        v78->d.m.prevIdx1 = v78->d.m.lastIdx;
      }
      else
      {
        v79 = v5->MonoVertices.Size >> 4;
        if ( v79 >= v5->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
            v5->MonoVertices.Size >> 4);
          v6 = v107;
        }
        v80 = v5->MonoVertices.Pages[v79];
        v81 = v5->MonoVertices.Size & 0xF;
        *(_QWORD *)&v80[v81].srcVer = v101;
        v80[v81].next = 0i64;
        v82 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v78->d.t.numTriangles = -1i64;
        v78->start = (Scaleform::Render::Tessellator::MonoVertexType *)v82;
      }
      v78->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
      goto LABEL_82;
    }
    v61 = *((_QWORD *)v15 + 1);
    if ( v6 != -1 )
    {
      LODWORD(v97) = v6 | 0x80000000;
      HIDWORD(v97) = v6 | 0x80000000;
      if ( *(_QWORD *)v61 )
      {
        v66 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)*(unsigned int *)(v61 + 8) >> 4][*(_DWORD *)(v61 + 8) & 0xF];
        if ( *(_DWORD *)v66 == (v6 | 0x80000000) )
          goto LABEL_65;
        v67 = v5->MonoVertices.Size >> 4;
        if ( v67 >= v5->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
            v5->MonoVertices.Size >> 4);
          v6 = v107;
        }
        v68 = v5->MonoVertices.Pages[v67];
        v69 = v5->MonoVertices.Size & 0xF;
        *(_QWORD *)&v68[v69].srcVer = v97;
        v68[v69].next = 0i64;
        *(_QWORD *)(v66 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        *(_DWORD *)(v61 + 16) = *(_DWORD *)(v61 + 12);
        *(_DWORD *)(v61 + 12) = *(_DWORD *)(v61 + 8);
      }
      else
      {
        v62 = v5->MonoVertices.Size >> 4;
        if ( v62 >= v5->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
            v5->MonoVertices.Size >> 4);
          v6 = v107;
        }
        v63 = v5->MonoVertices.Pages[v62];
        v64 = v5->MonoVertices.Size & 0xF;
        *(_QWORD *)&v63[v64].srcVer = v97;
        v63[v64].next = 0i64;
        v65 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)(v61 + 12) = -1i64;
        *(_QWORD *)v61 = v65;
      }
      *(_DWORD *)(v61 + 8) = LODWORD(v5->MonoVertices.Size) - 1;
LABEL_65:
      LODWORD(v100) = v6 & 0x7FFFFFFF;
      HIDWORD(v100) = v6 & 0x7FFFFFFF;
      if ( *(_QWORD *)v61 )
      {
        v74 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)*(unsigned int *)(v61 + 8) >> 4][*(_DWORD *)(v61 + 8) & 0xF];
        if ( *(_DWORD *)v74 != (v6 & 0x7FFFFFFF) )
        {
          v75 = v5->MonoVertices.Size >> 4;
          if ( v75 >= v5->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
              v5->MonoVertices.Size >> 4);
            v6 = v107;
          }
          v76 = v5->MonoVertices.Pages[v75];
          v77 = v5->MonoVertices.Size & 0xF;
          *(_QWORD *)&v76[v77].srcVer = v100;
          v76[v77].next = 0i64;
          *(_QWORD *)(v74 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          *(_DWORD *)(v61 + 16) = *(_DWORD *)(v61 + 12);
          *(_DWORD *)(v61 + 12) = *(_DWORD *)(v61 + 8);
          *(_DWORD *)(v61 + 8) = LODWORD(v5->MonoVertices.Size) - 1;
        }
      }
      else
      {
        v70 = v5->MonoVertices.Size >> 4;
        if ( v70 >= v5->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
            v5->MonoVertices.Size >> 4);
          v6 = v107;
        }
        v71 = v5->MonoVertices.Pages[v70];
        v72 = v5->MonoVertices.Size & 0xF;
        *(_QWORD *)&v71[v72].srcVer = v100;
        v71[v72].next = 0i64;
        v73 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)(v61 + 12) = -1i64;
        *(_QWORD *)v61 = v73;
        *(_DWORD *)(v61 + 8) = LODWORD(v5->MonoVertices.Size) - 1;
      }
    }
LABEL_82:
    v8 = v92;
LABEL_83:
    v10 = vars0;
LABEL_84:
    v14 = 0;
    if ( !v10 )
      break;
    v87 = v5->PendingEnds.Pages;
    --v10;
    v88 = v8;
    v89 = v8++ & 0xF;
    vars0 = v10;
    v15 = (int *)&v87[v88 >> 4][v89];
    v9 = v12;
    v92 = v8;
    if ( v10 )
      v12 = v87[(unsigned __int64)v8 >> 4][v8 & 0xF].vertex;
    else
      v12 = v93;
    v13 = (Scaleform::Render::Tessellator::PendingEndType *)*((_QWORD *)v15 + 1);
    v11 = retaddr;
    v4 = v108;
    if ( v13 )
      LODWORD(v13) = *(&v13[1].vertex + 1);
  }
  if ( v98 == &v5->BaseLines.Pages[(v5->BaseLines.Size - 1) >> 4][(LODWORD(v5->BaseLines.Size) - 1) & 0xF] )
  {
    v90 = v98->firstChain;
    if ( v90 < v5->PendingEnds.Size )
      v5->PendingEnds.Size = v90;
    v91 = v5->BaseLines.Size;
    if ( v91 )
      v5->BaseLines.Size = v91 - 1;
  }
}= v90;
    v91 = v5->BaseLines.Size;
    if ( v91 )
      v5->BaseLines.Size = v91 - 1;
  }
}

// File Line: 1147
// RVA: 0x9D7E70
void __fastcall Scaleform::Render::Tessellator::connectPendingToRight(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::ScanChainType *scan, unsigned int targetVertex)
{
  Scaleform::Render::Tessellator::MonotoneType *v3; // rax
  Scaleform::Render::Tessellator *v4; // rbx
  Scaleform::Render::Tessellator::ScanChainType *v5; // r13
  Scaleform::Render::Tessellator::BaseLineType *v6; // rdx
  unsigned int v7; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v8; // r14
  unsigned int v9; // ST60_4
  Scaleform::Render::Tessellator::PendingEndType **v10; // rax
  unsigned int v11; // er12
  unsigned __int64 v12; // rsi
  Scaleform::Render::Tessellator::MonoVertexType *v13; // rdx
  signed __int64 v14; // rcx
  signed __int64 v15; // rdx
  signed __int64 v16; // rdi
  unsigned __int64 v17; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v18; // rdx
  signed __int64 v19; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v20; // rsi
  unsigned __int64 v21; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v22; // rdx
  signed __int64 v23; // rcx
  signed __int64 v24; // rdx
  signed __int64 v25; // rdi
  unsigned __int64 v26; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v27; // rdx
  signed __int64 v28; // rcx
  unsigned int v29; // er9
  unsigned int v30; // ecx
  Scaleform::Render::Tessellator::PendingEndType **v31; // rdx
  unsigned __int64 v32; // rax
  __int64 v33; // rsi
  signed __int64 v34; // rsi
  unsigned int v35; // er14
  __int64 v36; // rax
  int v37; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v38; // rax
  Scaleform::Render::Tessellator::MonotoneType *v39; // rdi
  unsigned int v40; // er14
  unsigned __int64 v41; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v42; // rdx
  signed __int64 v43; // rcx
  signed __int64 v44; // rdx
  signed __int64 v45; // r15
  unsigned __int64 v46; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v47; // rdx
  signed __int64 v48; // rcx
  unsigned __int64 v49; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v50; // rdx
  signed __int64 v51; // rcx
  signed __int64 v52; // rdx
  signed __int64 v53; // r14
  unsigned __int64 v54; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v55; // rdx
  signed __int64 v56; // rcx
  __int64 v57; // rdi
  unsigned __int64 v58; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v59; // rdx
  signed __int64 v60; // rcx
  signed __int64 v61; // rdx
  signed __int64 v62; // rsi
  unsigned __int64 v63; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v64; // rdx
  signed __int64 v65; // rcx
  unsigned __int64 v66; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v67; // rdx
  signed __int64 v68; // rcx
  signed __int64 v69; // rdx
  signed __int64 v70; // rsi
  unsigned __int64 v71; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v72; // rdx
  signed __int64 v73; // rcx
  unsigned __int64 v74; // rax
  unsigned __int64 v75; // rax
  unsigned int v76; // [rsp+10h] [rbp-49h]
  Scaleform::Render::Tessellator::BaseLineType *v77; // [rsp+18h] [rbp-41h]
  __int64 v78; // [rsp+20h] [rbp-39h]
  __int64 v79; // [rsp+20h] [rbp-39h]
  __int64 v80; // [rsp+20h] [rbp-39h]
  __int64 v81; // [rsp+30h] [rbp-29h]
  __int64 v82; // [rsp+40h] [rbp-19h]
  __int64 v83; // [rsp+50h] [rbp-9h]
  unsigned int vars0; // [rsp+C0h] [rbp+67h]
  unsigned int retaddr; // [rsp+C8h] [rbp+6Fh]
  unsigned int v86; // [rsp+D0h] [rbp+77h]
  unsigned int style; // [rsp+D8h] [rbp+7Fh]

  v3 = scan->monotone;
  v4 = this;
  v5 = scan;
  v6 = v3->lowerBase;
  v7 = v3->style;
  v3->lowerBase = 0i64;
  v8 = v5->monotone;
  v9 = v6->vertexLeft;
  style = v7;
  vars0 = v6->numChains;
  retaddr = v6->vertexRight;
  v10 = v4->PendingEnds.Pages;
  v77 = v6;
  v76 = v6->firstChain;
  v11 = v10[(unsigned __int64)v76 >> 4][v76 & 0xF].vertex;
  LODWORD(v78) = v10[(unsigned __int64)v76 >> 4][v76 & 0xF].vertex;
  HIDWORD(v78) = v10[(unsigned __int64)v76 >> 4][v76 & 0xF].vertex;
  if ( !v8->start )
  {
    v12 = v4->MonoVertices.Size >> 4;
    if ( v12 >= v4->MonoVertices.NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
        v4->MonoVertices.Size >> 4);
      targetVertex = v86;
    }
    v13 = v4->MonoVertices.Pages[v12];
    v14 = v4->MonoVertices.Size & 0xF;
    *(_QWORD *)&v13[v14].srcVer = v78;
    v13[v14].next = 0i64;
    v15 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size) - 1) & 0xF];
    *(_QWORD *)&v8->d.t.numTriangles = -1i64;
    v8->start = (Scaleform::Render::Tessellator::MonoVertexType *)v15;
LABEL_9:
    v8->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
    goto LABEL_10;
  }
  v16 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v8->d.m.lastIdx >> 4][v8->d.m.lastIdx & 0xF];
  if ( *(_DWORD *)v16 != v11 )
  {
    v17 = v4->MonoVertices.Size >> 4;
    if ( v17 >= v4->MonoVertices.NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
        v4->MonoVertices.Size >> 4);
      targetVertex = v86;
    }
    v18 = v4->MonoVertices.Pages[v17];
    v19 = v4->MonoVertices.Size & 0xF;
    *(_QWORD *)&v18[v19].srcVer = v78;
    v18[v19].next = 0i64;
    *(_QWORD *)(v16 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                      - 1) & 0xF];
    v8->d.m.prevIdx2 = v8->d.m.prevIdx1;
    v8->d.m.prevIdx1 = v8->d.m.lastIdx;
    goto LABEL_9;
  }
LABEL_10:
  v20 = v5->monotone;
  LODWORD(v79) = targetVertex;
  HIDWORD(v79) = targetVertex;
  if ( v20->start )
  {
    v25 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v20->d.m.lastIdx >> 4][v20->d.m.lastIdx & 0xF];
    if ( *(_DWORD *)v25 != targetVertex )
    {
      v26 = v4->MonoVertices.Size >> 4;
      if ( v26 >= v4->MonoVertices.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
          v4->MonoVertices.Size >> 4);
        targetVertex = v86;
      }
      v27 = v4->MonoVertices.Pages[v26];
      v28 = v4->MonoVertices.Size & 0xF;
      *(_QWORD *)&v27[v28].srcVer = v79;
      v27[v28].next = 0i64;
      *(_QWORD *)(v25 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                        - 1) & 0xF];
      v20->d.m.prevIdx2 = v20->d.m.prevIdx1;
      v20->d.m.prevIdx1 = v20->d.m.lastIdx;
      v20->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
    }
  }
  else
  {
    v21 = v4->MonoVertices.Size >> 4;
    if ( v21 >= v4->MonoVertices.NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
        v4->MonoVertices.Size >> 4);
      targetVertex = v86;
    }
    v22 = v4->MonoVertices.Pages[v21];
    v23 = v4->MonoVertices.Size & 0xF;
    *(_QWORD *)&v22[v23].srcVer = v79;
    v22[v23].next = 0i64;
    v24 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size) - 1) & 0xF];
    *(_QWORD *)&v20->d.t.numTriangles = -1i64;
    v20->start = (Scaleform::Render::Tessellator::MonoVertexType *)v24;
    v20->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
  }
LABEL_18:
  v29 = v76;
  while ( 1 )
  {
    v30 = vars0;
    if ( !vars0 )
      break;
    v31 = v4->PendingEnds.Pages;
    v32 = v29;
    v33 = v29++ & 0xF;
    --vars0;
    v34 = (signed __int64)&v31[v32 >> 4][v33];
    v35 = v11;
    v76 = v29;
    if ( v30 == 1 )
      v11 = retaddr;
    else
      v11 = v31[(unsigned __int64)v29 >> 4][v29 & 0xF].vertex;
    v36 = *(_QWORD *)(v34 + 8);
    if ( v36 )
      v37 = *(_DWORD *)(v36 + 20);
    else
      v37 = 0;
    if ( v35 != v11 )
    {
      if ( v37 != style || !v36 )
      {
        v38 = Scaleform::Render::Tessellator::startMonotone(v4, style);
        v39 = v38;
        *(_QWORD *)(v34 + 8) = v38;
        if ( v35 != -1 )
        {
          v40 = v35 | 0x80000000;
          LODWORD(v80) = v40;
          HIDWORD(v80) = v40;
          if ( !v38->start )
          {
            v41 = v4->MonoVertices.Size >> 4;
            if ( v41 >= v4->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                v4->MonoVertices.Size >> 4);
            v42 = v4->MonoVertices.Pages[v41];
            v43 = v4->MonoVertices.Size & 0xF;
            *(_QWORD *)&v42[v43].srcVer = v80;
            v42[v43].next = 0i64;
            v44 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                             - 1) & 0xF];
            *(_QWORD *)&v39->d.t.numTriangles = -1i64;
            v39->start = (Scaleform::Render::Tessellator::MonoVertexType *)v44;
            goto LABEL_38;
          }
          v45 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v38->d.m.lastIdx >> 4][v38->d.m.lastIdx & 0xF];
          if ( *(_DWORD *)v45 != v40 )
          {
            v46 = v4->MonoVertices.Size >> 4;
            if ( v46 >= v4->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                v4->MonoVertices.Size >> 4);
            v47 = v4->MonoVertices.Pages[v46];
            v48 = v4->MonoVertices.Size & 0xF;
            *(_QWORD *)&v47[v48].srcVer = v80;
            v47[v48].next = 0i64;
            *(_QWORD *)(v45 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                              - 1) & 0xF];
            v39->d.m.prevIdx2 = v39->d.m.prevIdx1;
            v39->d.m.prevIdx1 = v39->d.m.lastIdx;
LABEL_38:
            v39->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
          }
        }
        if ( v11 != -1 )
        {
          LODWORD(v81) = v11 & 0x7FFFFFFF;
          HIDWORD(v81) = v11 & 0x7FFFFFFF;
          if ( v39->start )
          {
            v53 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v39->d.m.lastIdx >> 4][v39->d.m.lastIdx & 0xF];
            if ( *(_DWORD *)v53 != (v11 & 0x7FFFFFFF) )
            {
              v54 = v4->MonoVertices.Size >> 4;
              if ( v54 >= v4->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                  v4->MonoVertices.Size >> 4);
              v55 = v4->MonoVertices.Pages[v54];
              v56 = v4->MonoVertices.Size & 0xF;
              *(_QWORD *)&v55[v56].srcVer = v81;
              v55[v56].next = 0i64;
              *(_QWORD *)(v53 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                                - 1) & 0xF];
              v39->d.m.prevIdx2 = v39->d.m.prevIdx1;
              v39->d.m.prevIdx1 = v39->d.m.lastIdx;
              v39->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
            }
          }
          else
          {
            v49 = v4->MonoVertices.Size >> 4;
            if ( v49 >= v4->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                v4->MonoVertices.Size >> 4);
            v50 = v4->MonoVertices.Pages[v49];
            v51 = v4->MonoVertices.Size & 0xF;
            *(_QWORD *)&v50[v51].srcVer = v81;
            v50[v51].next = 0i64;
            v52 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                             - 1) & 0xF];
            *(_QWORD *)&v39->d.t.numTriangles = -1i64;
            v39->start = (Scaleform::Render::Tessellator::MonoVertexType *)v52;
            v39->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
          }
        }
        v29 = v76;
        targetVertex = v86;
      }
      v57 = *(_QWORD *)(v34 + 8);
      if ( targetVertex != -1 )
      {
        LODWORD(v82) = targetVertex | 0x80000000;
        HIDWORD(v82) = targetVertex | 0x80000000;
        if ( !*(_QWORD *)v57 )
        {
          v58 = v4->MonoVertices.Size >> 4;
          if ( v58 >= v4->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
            targetVertex = v86;
          }
          v59 = v4->MonoVertices.Pages[v58];
          v60 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v59[v60].srcVer = v82;
          v59[v60].next = 0i64;
          v61 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)(v57 + 12) = -1i64;
          *(_QWORD *)v57 = v61;
LABEL_58:
          *(_DWORD *)(v57 + 8) = LODWORD(v4->MonoVertices.Size) - 1;
          goto LABEL_59;
        }
        v62 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)*(unsigned int *)(v57 + 8) >> 4][*(_DWORD *)(v57 + 8) & 0xF];
        if ( *(_DWORD *)v62 != (targetVertex | 0x80000000) )
        {
          v63 = v4->MonoVertices.Size >> 4;
          if ( v63 >= v4->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
            targetVertex = v86;
          }
          v64 = v4->MonoVertices.Pages[v63];
          v65 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v64[v65].srcVer = v82;
          v64[v65].next = 0i64;
          *(_QWORD *)(v62 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          *(_DWORD *)(v57 + 16) = *(_DWORD *)(v57 + 12);
          *(_DWORD *)(v57 + 12) = *(_DWORD *)(v57 + 8);
          goto LABEL_58;
        }
LABEL_59:
        LODWORD(v83) = targetVertex & 0x7FFFFFFF;
        HIDWORD(v83) = targetVertex & 0x7FFFFFFF;
        if ( !*(_QWORD *)v57 )
        {
          v66 = v4->MonoVertices.Size >> 4;
          if ( v66 >= v4->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
            targetVertex = v86;
          }
          v67 = v4->MonoVertices.Pages[v66];
          v68 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v67[v68].srcVer = v83;
          v67[v68].next = 0i64;
          v69 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)(v57 + 12) = -1i64;
          *(_QWORD *)v57 = v69;
          *(_DWORD *)(v57 + 8) = LODWORD(v4->MonoVertices.Size) - 1;
          goto LABEL_18;
        }
        v29 = v76;
        v70 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)*(unsigned int *)(v57 + 8) >> 4][*(_DWORD *)(v57 + 8) & 0xF];
        if ( *(_DWORD *)v70 != (targetVertex & 0x7FFFFFFF) )
        {
          v71 = v4->MonoVertices.Size >> 4;
          if ( v71 >= v4->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
            targetVertex = v86;
          }
          v72 = v4->MonoVertices.Pages[v71];
          v73 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v72[v73].srcVer = v83;
          v72[v73].next = 0i64;
          *(_QWORD *)(v70 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          *(_DWORD *)(v57 + 16) = *(_DWORD *)(v57 + 12);
          *(_DWORD *)(v57 + 12) = *(_DWORD *)(v57 + 8);
          *(_DWORD *)(v57 + 8) = LODWORD(v4->MonoVertices.Size) - 1;
          goto LABEL_18;
        }
      }
    }
  }
  if ( v77 == &v4->BaseLines.Pages[(v4->BaseLines.Size - 1) >> 4][(LODWORD(v4->BaseLines.Size) - 1) & 0xF] )
  {
    v74 = v77->firstChain;
    if ( v74 < v4->PendingEnds.Size )
      v4->PendingEnds.Size = v74;
    v75 = v4->BaseLines.Size;
    if ( v75 )
      v4->BaseLines.Size = v75 - 1;
  }
}

// File Line: 1183
// RVA: 0x9D8A50
void __fastcall Scaleform::Render::Tessellator::connectStartingToLeft(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::ScanChainType *scan, Scaleform::Render::Tessellator::BaseLineType *upperBase, unsigned int targetVertex)
{
  unsigned __int64 v4; // rax
  unsigned int v5; // esi
  Scaleform::Render::Tessellator::ScanChainType *v6; // r14
  Scaleform::Render::Tessellator *v7; // rbx
  unsigned int v8; // eax
  unsigned int v9; // edi
  unsigned int v10; // er15
  unsigned int v11; // er12
  Scaleform::Render::Tessellator::MonotoneType *v12; // rax
  Scaleform::Render::Tessellator::MonotoneType *v13; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v14; // r13
  Scaleform::Render::Tessellator::BaseLineType *v15; // rcx
  unsigned int v16; // edx
  Scaleform::Render::Tessellator::MonotoneType *v17; // rcx
  unsigned int v18; // eax
  Scaleform::Render::Tessellator::MonotoneType *v19; // rdi
  unsigned int v20; // edx
  unsigned __int64 v21; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v22; // rdx
  signed __int64 v23; // rcx
  signed __int64 v24; // rdx
  signed __int64 v25; // rsi
  unsigned __int64 v26; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v27; // rdx
  signed __int64 v28; // rcx
  unsigned __int64 v29; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v30; // rdx
  signed __int64 v31; // rcx
  signed __int64 v32; // rdx
  signed __int64 v33; // rsi
  unsigned __int64 v34; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v35; // rdx
  signed __int64 v36; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v37; // rdi
  unsigned __int64 v38; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v39; // rdx
  signed __int64 v40; // rcx
  signed __int64 v41; // rdx
  signed __int64 v42; // rsi
  unsigned __int64 v43; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v44; // rdx
  signed __int64 v45; // rcx
  unsigned __int64 v46; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v47; // rdx
  signed __int64 v48; // rcx
  signed __int64 v49; // rdx
  signed __int64 v50; // rsi
  unsigned __int64 v51; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v52; // rdx
  signed __int64 v53; // rcx
  unsigned __int64 v54; // rsi
  Scaleform::Render::Tessellator::MonoVertexType *v55; // rdx
  signed __int64 v56; // rcx
  signed __int64 v57; // rdx
  signed __int64 v58; // rdi
  unsigned __int64 v59; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v60; // rdx
  signed __int64 v61; // rcx
  unsigned __int64 v62; // rsi
  Scaleform::Render::Tessellator::MonoVertexType *v63; // rdx
  signed __int64 v64; // rcx
  signed __int64 v65; // rdx
  signed __int64 v66; // rdi
  unsigned __int64 v67; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v68; // rdx
  signed __int64 v69; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v70; // rdi
  unsigned int v71; // er15
  unsigned __int64 v72; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v73; // rdx
  signed __int64 v74; // rcx
  signed __int64 v75; // rdx
  signed __int64 v76; // rsi
  unsigned __int64 v77; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v78; // rdx
  signed __int64 v79; // rcx
  unsigned __int64 v80; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v81; // rdx
  signed __int64 v82; // rcx
  signed __int64 v83; // rdx
  signed __int64 v84; // rsi
  unsigned __int64 v85; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v86; // rdx
  signed __int64 v87; // rcx
  Scaleform::Render::Tessellator::ScanChainType **v88; // rdx
  unsigned int v89; // esi
  unsigned __int64 v90; // rax
  signed __int64 v91; // rcx
  unsigned int v92; // [rsp+20h] [rbp-99h]
  unsigned int style; // [rsp+24h] [rbp-95h]
  unsigned int v94; // [rsp+28h] [rbp-91h]
  Scaleform::Render::Tessellator::MonotoneType *v95; // [rsp+30h] [rbp-89h]
  unsigned int v96; // [rsp+38h] [rbp-81h]
  Scaleform::Render::Tessellator::ScanChainType *scana; // [rsp+40h] [rbp-79h]
  unsigned int v98; // [rsp+48h] [rbp-71h]
  __int64 v99; // [rsp+50h] [rbp-69h]
  __int64 v100; // [rsp+60h] [rbp-59h]
  __int64 v101; // [rsp+70h] [rbp-49h]
  __int64 v102; // [rsp+80h] [rbp-39h]
  __int64 v103; // [rsp+90h] [rbp-29h]
  __int64 v104; // [rsp+A0h] [rbp-19h]
  __int64 v105; // [rsp+B0h] [rbp-9h]
  __int64 v106; // [rsp+C0h] [rbp+7h]
  char v107; // [rsp+120h] [rbp+67h]
  unsigned int v108; // [rsp+128h] [rbp+6Fh]
  Scaleform::Render::Tessellator::BaseLineType *v109; // [rsp+130h] [rbp+77h]
  unsigned int v110; // [rsp+138h] [rbp+7Fh]

  v110 = targetVertex;
  v109 = upperBase;
  v4 = upperBase->leftAbove;
  v5 = targetVertex;
  v6 = scan;
  v7 = this;
  if ( (_DWORD)v4 == -1 )
    scana = scan;
  else
    scana = &this->ChainsAbove.Pages[v4 >> 4][v4 & 0xF];
  v8 = upperBase->firstChain;
  v9 = upperBase->numChains;
  v10 = upperBase->vertexLeft;
  v98 = v8;
  v96 = upperBase->vertexRight;
  v94 = upperBase->numChains;
  v107 = 1;
  v11 = this->ChainsAbove.Pages[(unsigned __int64)upperBase->firstChain >> 4][v8 & 0xF].vertex;
  v108 = upperBase->styleLeft;
  v92 = this->ChainsAbove.Pages[(unsigned __int64)upperBase->firstChain >> 4][v8 & 0xF].vertex;
  style = scan->monotone->style;
  v12 = Scaleform::Render::Tessellator::startMonotone(this, 0);
  v13 = v6->monotone;
  v14 = v12;
  v95 = v12;
  v12->start = v13->start;
  *(_QWORD *)&v12->d.m.lastIdx = *(_QWORD *)&v13->d.m.lastIdx;
  *(_QWORD *)&v12->d.t.meshIdx = *(_QWORD *)&v13->d.t.meshIdx;
  v15 = v13->lowerBase;
  v16 = style;
  v12->lowerBase = v15;
  v17 = v6->monotone;
  v18 = v108;
  v17->start = 0i64;
  *(_QWORD *)&v17->d.m.lastIdx = -1i64;
  v17->d.m.prevIdx2 = -1;
  v17->style = style;
  v17->lowerBase = 0i64;
  while ( 1 )
  {
    if ( !v9 )
    {
      v6->monotone = v14;
      if ( v10 == -1 )
        goto LABEL_56;
      LODWORD(v100) = v10 | 0x80000000;
      HIDWORD(v100) = v10 | 0x80000000;
      if ( v14->start )
      {
        v58 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v14->d.m.lastIdx >> 4][v14->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v58 == (v10 | 0x80000000) )
          goto LABEL_56;
        v59 = v7->MonoVertices.Size >> 4;
        if ( v59 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v60 = v7->MonoVertices.Pages[v59];
        v11 = v92;
        v61 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v60[v61].srcVer = v100;
        v60[v61].next = 0i64;
        *(_QWORD *)(v58 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v14->d.m.prevIdx2 = v14->d.m.prevIdx1;
        v14->d.m.prevIdx1 = v14->d.m.lastIdx;
      }
      else
      {
        v54 = v7->MonoVertices.Size >> 4;
        if ( v54 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v55 = v7->MonoVertices.Pages[v54];
        v56 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v55[v56].srcVer = v100;
        v55[v56].next = 0i64;
        v57 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v14->d.t.numTriangles = -1i64;
        v14->start = (Scaleform::Render::Tessellator::MonoVertexType *)v57;
      }
      v14->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
LABEL_56:
      if ( v11 != -1 )
      {
        LODWORD(v102) = v11 & 0x7FFFFFFF;
        HIDWORD(v102) = v11 & 0x7FFFFFFF;
        if ( v14->start )
        {
          v66 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v14->d.m.lastIdx >> 4][v14->d.m.lastIdx & 0xF];
          if ( *(_DWORD *)v66 != (v11 & 0x7FFFFFFF) )
          {
            v67 = v7->MonoVertices.Size >> 4;
            if ( v67 >= v7->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
                v7->MonoVertices.Size >> 4);
            v68 = v7->MonoVertices.Pages[v67];
            v11 = v92;
            v69 = v7->MonoVertices.Size & 0xF;
            *(_QWORD *)&v68[v69].srcVer = v102;
            v68[v69].next = 0i64;
            *(_QWORD *)(v66 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                              - 1) & 0xF];
            v14->d.m.prevIdx2 = v14->d.m.prevIdx1;
            v14->d.m.prevIdx1 = v14->d.m.lastIdx;
            v14->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
          }
        }
        else
        {
          v62 = v7->MonoVertices.Size >> 4;
          if ( v62 >= v7->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
              v7->MonoVertices.Size >> 4);
          v63 = v7->MonoVertices.Pages[v62];
          v64 = v7->MonoVertices.Size & 0xF;
          *(_QWORD *)&v63[v64].srcVer = v102;
          v63[v64].next = 0i64;
          v65 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)&v14->d.t.numTriangles = -1i64;
          v14->start = (Scaleform::Render::Tessellator::MonoVertexType *)v65;
          v14->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
        }
      }
      goto LABEL_66;
    }
    if ( v10 != v11 )
    {
      Scaleform::Render::Tessellator::replaceMonotone(v7, v6, v16);
      v19 = v6->monotone;
      if ( v5 == -1 )
        goto LABEL_26;
      v20 = v5 | 0x80000000;
      LODWORD(v99) = v5 | 0x80000000;
      HIDWORD(v99) = v5 | 0x80000000;
      if ( v19->start )
      {
        v25 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v19->d.m.lastIdx >> 4][v19->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v25 == v20 )
          goto LABEL_17;
        v26 = v7->MonoVertices.Size >> 4;
        if ( v26 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v27 = v7->MonoVertices.Pages[v26];
        v28 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v27[v28].srcVer = v99;
        v27[v28].next = 0i64;
        *(_QWORD *)(v25 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v19->d.m.prevIdx2 = v19->d.m.prevIdx1;
        v19->d.m.prevIdx1 = v19->d.m.lastIdx;
      }
      else
      {
        v21 = v7->MonoVertices.Size >> 4;
        if ( v21 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v22 = v7->MonoVertices.Pages[v21];
        v23 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v22[v23].srcVer = v99;
        v22[v23].next = 0i64;
        v24 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v19->d.t.numTriangles = -1i64;
        v19->start = (Scaleform::Render::Tessellator::MonoVertexType *)v24;
      }
      v19->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
LABEL_17:
      LODWORD(v101) = v110 & 0x7FFFFFFF;
      HIDWORD(v101) = v110 & 0x7FFFFFFF;
      if ( v19->start )
      {
        v33 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v19->d.m.lastIdx >> 4][v19->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v33 == (v110 & 0x7FFFFFFF) )
          goto LABEL_26;
        v34 = v7->MonoVertices.Size >> 4;
        if ( v34 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v35 = v7->MonoVertices.Pages[v34];
        v36 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v35[v36].srcVer = v101;
        v35[v36].next = 0i64;
        *(_QWORD *)(v33 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v19->d.m.prevIdx2 = v19->d.m.prevIdx1;
        v19->d.m.prevIdx1 = v19->d.m.lastIdx;
      }
      else
      {
        v29 = v7->MonoVertices.Size >> 4;
        if ( v29 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v30 = v7->MonoVertices.Pages[v29];
        v31 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v30[v31].srcVer = v101;
        v30[v31].next = 0i64;
        v32 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v19->d.t.numTriangles = -1i64;
        v19->start = (Scaleform::Render::Tessellator::MonoVertexType *)v32;
      }
      v19->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
LABEL_26:
      v37 = v6->monotone;
      if ( v10 == -1 )
        goto LABEL_36;
      LODWORD(v105) = v10 | 0x80000000;
      HIDWORD(v105) = v10 | 0x80000000;
      if ( v37->start )
      {
        v42 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v37->d.m.lastIdx >> 4][v37->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v42 == (v10 | 0x80000000) )
          goto LABEL_36;
        v43 = v7->MonoVertices.Size >> 4;
        if ( v43 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v44 = v7->MonoVertices.Pages[v43];
        v45 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v44[v45].srcVer = v105;
        v44[v45].next = 0i64;
        *(_QWORD *)(v42 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v37->d.m.prevIdx2 = v37->d.m.prevIdx1;
        v37->d.m.prevIdx1 = v37->d.m.lastIdx;
      }
      else
      {
        v38 = v7->MonoVertices.Size >> 4;
        if ( v38 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v39 = v7->MonoVertices.Pages[v38];
        v40 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v39[v40].srcVer = v105;
        v39[v40].next = 0i64;
        v41 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v37->d.t.numTriangles = -1i64;
        v37->start = (Scaleform::Render::Tessellator::MonoVertexType *)v41;
      }
      v37->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
LABEL_36:
      v11 = v92;
      if ( v92 != -1 )
      {
        LODWORD(v103) = v92 & 0x7FFFFFFF;
        HIDWORD(v103) = v92 & 0x7FFFFFFF;
        if ( !v37->start )
        {
          v46 = v7->MonoVertices.Size >> 4;
          if ( v46 >= v7->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
              v7->MonoVertices.Size >> 4);
          v47 = v7->MonoVertices.Pages[v46];
          v48 = v7->MonoVertices.Size & 0xF;
          *(_QWORD *)&v47[v48].srcVer = v103;
          v47[v48].next = 0i64;
          v49 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)&v37->d.t.numTriangles = -1i64;
          v37->start = (Scaleform::Render::Tessellator::MonoVertexType *)v49;
LABEL_41:
          v14 = v95;
          v11 = v92;
          v37->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
LABEL_66:
          v18 = v108;
          goto LABEL_67;
        }
        v50 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v37->d.m.lastIdx >> 4][v37->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v50 != (v92 & 0x7FFFFFFF) )
        {
          v51 = v7->MonoVertices.Size >> 4;
          if ( v51 >= v7->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
              v7->MonoVertices.Size >> 4);
          v52 = v7->MonoVertices.Pages[v51];
          v53 = v7->MonoVertices.Size & 0xF;
          *(_QWORD *)&v52[v53].srcVer = v103;
          v52[v53].next = 0i64;
          *(_QWORD *)(v50 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          v37->d.m.prevIdx2 = v37->d.m.prevIdx1;
          v37->d.m.prevIdx1 = v37->d.m.lastIdx;
          goto LABEL_41;
        }
      }
      v14 = v95;
      goto LABEL_66;
    }
LABEL_67:
    if ( v18 == style && v6->monotone )
      goto LABEL_93;
    if ( !v18 )
    {
      v6->monotone = 0i64;
      goto LABEL_93;
    }
    if ( v107 )
      v6 = scana;
    Scaleform::Render::Tessellator::replaceMonotone(v7, v6, v18);
    v70 = v6->monotone;
    if ( v10 != -1 )
    {
      v71 = v10 | 0x80000000;
      LODWORD(v104) = v71;
      HIDWORD(v104) = v71;
      if ( !v70->start )
      {
        v72 = v7->MonoVertices.Size >> 4;
        if ( v72 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v73 = v7->MonoVertices.Pages[v72];
        v74 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v73[v74].srcVer = v104;
        v73[v74].next = 0i64;
        v75 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v70->d.t.numTriangles = -1i64;
        v70->start = (Scaleform::Render::Tessellator::MonoVertexType *)v75;
LABEL_82:
        v70->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
        goto LABEL_83;
      }
      v76 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v70->d.m.lastIdx >> 4][v70->d.m.lastIdx & 0xF];
      if ( *(_DWORD *)v76 != v71 )
      {
        v77 = v7->MonoVertices.Size >> 4;
        if ( v77 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v78 = v7->MonoVertices.Pages[v77];
        v79 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v78[v79].srcVer = v104;
        v78[v79].next = 0i64;
        *(_QWORD *)(v76 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v70->d.m.prevIdx2 = v70->d.m.prevIdx1;
        v70->d.m.prevIdx1 = v70->d.m.lastIdx;
        goto LABEL_82;
      }
    }
LABEL_83:
    if ( v11 == -1 )
      goto LABEL_93;
    LODWORD(v106) = v11 & 0x7FFFFFFF;
    HIDWORD(v106) = v11 & 0x7FFFFFFF;
    if ( v70->start )
    {
      v84 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v70->d.m.lastIdx >> 4][v70->d.m.lastIdx & 0xF];
      if ( *(_DWORD *)v84 == (v11 & 0x7FFFFFFF) )
        goto LABEL_93;
      v85 = v7->MonoVertices.Size >> 4;
      if ( v85 >= v7->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
          v7->MonoVertices.Size >> 4);
      v86 = v7->MonoVertices.Pages[v85];
      v87 = v7->MonoVertices.Size & 0xF;
      *(_QWORD *)&v86[v87].srcVer = v106;
      v86[v87].next = 0i64;
      *(_QWORD *)(v84 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                        - 1) & 0xF];
      v70->d.m.prevIdx2 = v70->d.m.prevIdx1;
      v70->d.m.prevIdx1 = v70->d.m.lastIdx;
    }
    else
    {
      v80 = v7->MonoVertices.Size >> 4;
      if ( v80 >= v7->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
          v7->MonoVertices.Size >> 4);
      v81 = v7->MonoVertices.Pages[v80];
      v82 = v7->MonoVertices.Size & 0xF;
      *(_QWORD *)&v81[v82].srcVer = v106;
      v81[v82].next = 0i64;
      v83 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                       - 1) & 0xF];
      *(_QWORD *)&v70->d.t.numTriangles = -1i64;
      v70->start = (Scaleform::Render::Tessellator::MonoVertexType *)v83;
    }
    v70->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
LABEL_93:
    v107 = 0;
    if ( !v94 )
      break;
    v88 = v7->ChainsAbove.Pages;
    v9 = v94 - 1;
    v89 = v98 + 1;
    v94 = v9;
    v10 = v11;
    v90 = (unsigned __int64)v98 >> 4;
    v91 = v98++ & 0xF;
    v6 = &v88[v90][v91];
    if ( v9 )
      v11 = v88[(unsigned __int64)v89 >> 4][v89 & 0xF].vertex;
    else
      v11 = v96;
    v5 = v110;
    v16 = style;
    v18 = v6->chain->rightAbove;
    v92 = v11;
    v108 = v6->chain->rightAbove;
  }
  v109->numChains = 0;
}D(v7->MonoVertices.Size) - 1;
LABEL_93:
    v107 = 0;
    if ( !v94 )
      break;
    v88 = v7->ChainsAbove.Pages;
    v9 = v94 - 1;
    v89 = v98 + 1;
    v94 = v9;
    v10 = v11;
    v90 = (unsigned __int64)v98 >> 4;
    v91 = v98++ & 0xF;
    v6 = &v88[v90][v91];
    if ( v9 )
      v11 = v88[(unsigned __int64)v89 >> 4][v89 & 0xF].vertex;
    else
      v11 = v96;
    v5 = v110

// File Line: 1235
// RVA: 0x9DAF10
void __fastcall Scaleform::Render::Tessellator::connectStartingToRight(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::ScanChainType *scan, Scaleform::Render::Tessellator::BaseLineType *upperBase, unsigned int targetVertex)
{
  unsigned __int64 v4; // rax
  unsigned int v5; // esi
  Scaleform::Render::Tessellator::ScanChainType *v6; // r14
  Scaleform::Render::Tessellator *v7; // rbx
  unsigned int v8; // eax
  unsigned int v9; // er15
  char v10; // di
  unsigned int v11; // er13
  unsigned int v12; // ecx
  unsigned int v13; // eax
  Scaleform::Render::Tessellator::MonotoneType *v14; // rdi
  unsigned __int64 v15; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v16; // rdx
  signed __int64 v17; // rcx
  signed __int64 v18; // rdx
  signed __int64 v19; // rsi
  unsigned __int64 v20; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v21; // rdx
  signed __int64 v22; // rcx
  unsigned __int64 v23; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v24; // rdx
  signed __int64 v25; // rcx
  signed __int64 v26; // rdx
  signed __int64 v27; // rsi
  signed __int64 v28; // r13
  unsigned __int64 v29; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v30; // rdx
  __int64 v31; // rax
  Scaleform::Render::Tessellator::MonotoneType *v32; // rdi
  unsigned int v33; // edx
  unsigned __int64 v34; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v35; // rdx
  signed __int64 v36; // rcx
  signed __int64 v37; // rdx
  signed __int64 v38; // rsi
  unsigned __int64 v39; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v40; // rdx
  signed __int64 v41; // rcx
  unsigned __int64 v42; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v43; // rdx
  signed __int64 v44; // rcx
  signed __int64 v45; // rdx
  signed __int64 v46; // rsi
  unsigned __int64 v47; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v48; // rdx
  signed __int64 v49; // rcx
  unsigned __int64 v50; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v51; // rdx
  signed __int64 v52; // rcx
  signed __int64 v53; // rdx
  signed __int64 v54; // rsi
  unsigned __int64 v55; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v56; // rdx
  signed __int64 v57; // rcx
  unsigned __int64 v58; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v59; // rdx
  signed __int64 v60; // rcx
  signed __int64 v61; // rdx
  unsigned __int64 v62; // r12
  signed __int64 v63; // rcx
  __int64 v64; // rax
  __int64 v65; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v66; // rdi
  unsigned int v67; // er15
  unsigned __int64 v68; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v69; // rdx
  signed __int64 v70; // rcx
  signed __int64 v71; // rdx
  signed __int64 v72; // rsi
  unsigned __int64 v73; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v74; // rdx
  signed __int64 v75; // rcx
  unsigned __int64 v76; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v77; // rdx
  signed __int64 v78; // rcx
  signed __int64 v79; // rdx
  signed __int64 v80; // rsi
  unsigned __int64 v81; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v82; // rdx
  signed __int64 v83; // rcx
  unsigned int v84; // er10
  Scaleform::Render::Tessellator::ScanChainType **v85; // rdx
  unsigned int v86; // er9
  unsigned __int64 v87; // rax
  signed __int64 v88; // rcx
  unsigned int v89; // [rsp+20h] [rbp-89h]
  unsigned int v90; // [rsp+24h] [rbp-85h]
  unsigned int v91; // [rsp+28h] [rbp-81h]
  unsigned int v92; // [rsp+2Ch] [rbp-7Dh]
  Scaleform::Render::Tessellator::ScanChainType *scana; // [rsp+30h] [rbp-79h]
  unsigned int v94; // [rsp+38h] [rbp-71h]
  __int64 v95; // [rsp+40h] [rbp-69h]
  __int64 v96; // [rsp+50h] [rbp-59h]
  __int64 v97; // [rsp+60h] [rbp-49h]
  __int64 v98; // [rsp+70h] [rbp-39h]
  __int64 v99; // [rsp+80h] [rbp-29h]
  __int64 v100; // [rsp+90h] [rbp-19h]
  __int64 v101; // [rsp+A0h] [rbp-9h]
  __int64 v102; // [rsp+B0h] [rbp+7h]
  char v103; // [rsp+110h] [rbp+67h]
  unsigned int style; // [rsp+118h] [rbp+6Fh]
  Scaleform::Render::Tessellator::BaseLineType *v105; // [rsp+120h] [rbp+77h]
  unsigned int v106; // [rsp+128h] [rbp+7Fh]

  v106 = targetVertex;
  v105 = upperBase;
  v4 = upperBase->leftAbove;
  v5 = targetVertex;
  v6 = scan;
  v7 = this;
  if ( (_DWORD)v4 == -1 )
    scana = scan;
  else
    scana = &this->ChainsAbove.Pages[v4 >> 4][v4 & 0xF];
  v8 = upperBase->firstChain;
  v9 = upperBase->vertexLeft;
  v94 = v8;
  v91 = upperBase->numChains;
  v92 = upperBase->vertexRight;
  v10 = 1;
  v11 = this->ChainsAbove.Pages[(unsigned __int64)v8 >> 4][v8 & 0xF].vertex;
  v103 = 1;
  style = upperBase->styleLeft;
  v12 = scan->monotone->style;
  v13 = upperBase->styleLeft;
  v90 = scan->monotone->style;
  while ( 1 )
  {
    v89 = v11;
    if ( v10 )
    {
      v14 = v6->monotone;
      if ( v9 != -1 )
      {
        LODWORD(v95) = v9 | 0x80000000;
        HIDWORD(v95) = v9 | 0x80000000;
        if ( !v14->start )
        {
          v15 = v7->MonoVertices.Size >> 4;
          if ( v15 >= v7->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
              v7->MonoVertices.Size >> 4);
          v16 = v7->MonoVertices.Pages[v15];
          v17 = v7->MonoVertices.Size & 0xF;
          *(_QWORD *)&v16[v17].srcVer = v95;
          v16[v17].next = 0i64;
          v18 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)&v14->d.t.numTriangles = -1i64;
          v14->start = (Scaleform::Render::Tessellator::MonoVertexType *)v18;
LABEL_15:
          v14->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
          goto LABEL_16;
        }
        v19 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v14->d.m.lastIdx >> 4][v14->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v19 != (v9 | 0x80000000) )
        {
          v20 = v7->MonoVertices.Size >> 4;
          if ( v20 >= v7->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
              v7->MonoVertices.Size >> 4);
          v21 = v7->MonoVertices.Pages[v20];
          v22 = v7->MonoVertices.Size & 0xF;
          *(_QWORD *)&v21[v22].srcVer = v95;
          v21[v22].next = 0i64;
          *(_QWORD *)(v19 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          v14->d.m.prevIdx2 = v14->d.m.prevIdx1;
          v14->d.m.prevIdx1 = v14->d.m.lastIdx;
          goto LABEL_15;
        }
      }
LABEL_16:
      if ( v11 != -1 )
      {
        LODWORD(v97) = v11 & 0x7FFFFFFF;
        HIDWORD(v97) = v11 & 0x7FFFFFFF;
        if ( !v14->start )
        {
          v23 = v7->MonoVertices.Size >> 4;
          if ( v23 >= v7->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
              v7->MonoVertices.Size >> 4);
          v24 = v7->MonoVertices.Pages[v23];
          v25 = v7->MonoVertices.Size & 0xF;
          *(_QWORD *)&v24[v25].srcVer = v97;
          v24[v25].next = 0i64;
          v26 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)&v14->d.t.numTriangles = -1i64;
          v14->start = (Scaleform::Render::Tessellator::MonoVertexType *)v26;
          goto LABEL_64;
        }
        v27 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v14->d.m.lastIdx >> 4][v14->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v27 != (v11 & 0x7FFFFFFF) )
        {
          v28 = (signed __int64)&v7->MonoVertices;
          v29 = v7->MonoVertices.Size >> 4;
          if ( v29 >= v7->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
              v7->MonoVertices.Size >> 4);
          v30 = v7->MonoVertices.Pages[v29];
          v31 = v97;
LABEL_63:
          v63 = *(_DWORD *)(v28 + 8) & 0xF;
          *(_QWORD *)&v30[v63].srcVer = v31;
          v30[v63].next = 0i64;
          ++*(_QWORD *)(v28 + 8);
          v64 = *(_QWORD *)(v28 + 32);
          v65 = *(_QWORD *)(v28 + 8);
          v11 = v89;
          *(_QWORD *)(v27 + 8) = *(_QWORD *)(v64 + 8 * ((unsigned __int64)(v65 - 1) >> 4))
                               + 16i64 * (((_DWORD)v65 - 1) & 0xF);
          v14->d.m.prevIdx2 = v14->d.m.prevIdx1;
          v14->d.m.prevIdx1 = v14->d.m.lastIdx;
LABEL_64:
          v14->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
          goto LABEL_65;
        }
      }
      goto LABEL_65;
    }
    if ( v9 != v11 )
    {
      Scaleform::Render::Tessellator::replaceMonotone(v7, v6, v12);
      v32 = v6->monotone;
      if ( v5 == -1 )
        goto LABEL_45;
      v33 = v5 | 0x80000000;
      LODWORD(v101) = v5 | 0x80000000;
      HIDWORD(v101) = v5 | 0x80000000;
      if ( v32->start )
      {
        v38 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v32->d.m.lastIdx >> 4][v32->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v38 == v33 )
          goto LABEL_36;
        v39 = v7->MonoVertices.Size >> 4;
        if ( v39 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v40 = v7->MonoVertices.Pages[v39];
        v41 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v40[v41].srcVer = v101;
        v40[v41].next = 0i64;
        *(_QWORD *)(v38 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v32->d.m.prevIdx2 = v32->d.m.prevIdx1;
        v32->d.m.prevIdx1 = v32->d.m.lastIdx;
      }
      else
      {
        v34 = v7->MonoVertices.Size >> 4;
        if ( v34 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v35 = v7->MonoVertices.Pages[v34];
        v36 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v35[v36].srcVer = v101;
        v35[v36].next = 0i64;
        v37 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v32->d.t.numTriangles = -1i64;
        v32->start = (Scaleform::Render::Tessellator::MonoVertexType *)v37;
      }
      v32->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
LABEL_36:
      LODWORD(v99) = v106 & 0x7FFFFFFF;
      HIDWORD(v99) = v106 & 0x7FFFFFFF;
      if ( v32->start )
      {
        v46 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v32->d.m.lastIdx >> 4][v32->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v46 == (v106 & 0x7FFFFFFF) )
          goto LABEL_45;
        v47 = v7->MonoVertices.Size >> 4;
        if ( v47 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v48 = v7->MonoVertices.Pages[v47];
        v49 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v48[v49].srcVer = v99;
        v48[v49].next = 0i64;
        *(_QWORD *)(v46 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v32->d.m.prevIdx2 = v32->d.m.prevIdx1;
        v32->d.m.prevIdx1 = v32->d.m.lastIdx;
      }
      else
      {
        v42 = v7->MonoVertices.Size >> 4;
        if ( v42 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v43 = v7->MonoVertices.Pages[v42];
        v44 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v43[v44].srcVer = v99;
        v43[v44].next = 0i64;
        v45 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v32->d.t.numTriangles = -1i64;
        v32->start = (Scaleform::Render::Tessellator::MonoVertexType *)v45;
      }
      v32->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
LABEL_45:
      v14 = v6->monotone;
      if ( v9 != -1 )
      {
        LODWORD(v96) = v9 | 0x80000000;
        HIDWORD(v96) = v9 | 0x80000000;
        if ( v14->start )
        {
          v54 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v14->d.m.lastIdx >> 4][v14->d.m.lastIdx & 0xF];
          if ( *(_DWORD *)v54 != (v9 | 0x80000000) )
          {
            v55 = v7->MonoVertices.Size >> 4;
            if ( v55 >= v7->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
                v7->MonoVertices.Size >> 4);
            v56 = v7->MonoVertices.Pages[v55];
            v57 = v7->MonoVertices.Size & 0xF;
            *(_QWORD *)&v56[v57].srcVer = v96;
            v56[v57].next = 0i64;
            *(_QWORD *)(v54 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                              - 1) & 0xF];
            v14->d.m.prevIdx2 = v14->d.m.prevIdx1;
            v14->d.m.prevIdx1 = v14->d.m.lastIdx;
            v14->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
          }
        }
        else
        {
          v50 = v7->MonoVertices.Size >> 4;
          if ( v50 >= v7->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
              v7->MonoVertices.Size >> 4);
          v51 = v7->MonoVertices.Pages[v50];
          v52 = v7->MonoVertices.Size & 0xF;
          *(_QWORD *)&v51[v52].srcVer = v96;
          v51[v52].next = 0i64;
          v53 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)&v14->d.t.numTriangles = -1i64;
          v14->start = (Scaleform::Render::Tessellator::MonoVertexType *)v53;
          v14->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
        }
      }
      if ( v11 == -1 )
        goto LABEL_65;
      LODWORD(v98) = v11 & 0x7FFFFFFF;
      HIDWORD(v98) = v11 & 0x7FFFFFFF;
      if ( !v14->start )
      {
        v58 = v7->MonoVertices.Size >> 4;
        if ( v58 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v59 = v7->MonoVertices.Pages[v58];
        v60 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v59[v60].srcVer = v98;
        v59[v60].next = 0i64;
        v61 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v14->d.t.numTriangles = -1i64;
        v14->start = (Scaleform::Render::Tessellator::MonoVertexType *)v61;
        goto LABEL_64;
      }
      v27 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v14->d.m.lastIdx >> 4][v14->d.m.lastIdx & 0xF];
      if ( *(_DWORD *)v27 != (v11 & 0x7FFFFFFF) )
      {
        v28 = (signed __int64)&v7->MonoVertices;
        v62 = v7->MonoVertices.Size >> 4;
        if ( v62 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v30 = v7->MonoVertices.Pages[v62];
        v31 = v98;
        goto LABEL_63;
      }
LABEL_65:
      v10 = v103;
      v13 = style;
    }
    if ( v13 == v90 && v6->monotone )
      goto LABEL_92;
    if ( !v13 )
    {
      v6->monotone = 0i64;
      goto LABEL_92;
    }
    if ( v10 )
      v6 = scana;
    Scaleform::Render::Tessellator::replaceMonotone(v7, v6, v13);
    v66 = v6->monotone;
    if ( v9 != -1 )
    {
      v67 = v9 | 0x80000000;
      LODWORD(v100) = v67;
      HIDWORD(v100) = v67;
      if ( !v66->start )
      {
        v68 = v7->MonoVertices.Size >> 4;
        if ( v68 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v69 = v7->MonoVertices.Pages[v68];
        v70 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v69[v70].srcVer = v100;
        v69[v70].next = 0i64;
        v71 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v66->d.t.numTriangles = -1i64;
        v66->start = (Scaleform::Render::Tessellator::MonoVertexType *)v71;
LABEL_81:
        v66->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
        goto LABEL_82;
      }
      v72 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v66->d.m.lastIdx >> 4][v66->d.m.lastIdx & 0xF];
      if ( *(_DWORD *)v72 != v67 )
      {
        v73 = v7->MonoVertices.Size >> 4;
        if ( v73 >= v7->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
            v7->MonoVertices.Size >> 4);
        v74 = v7->MonoVertices.Pages[v73];
        v75 = v7->MonoVertices.Size & 0xF;
        *(_QWORD *)&v74[v75].srcVer = v100;
        v74[v75].next = 0i64;
        *(_QWORD *)(v72 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v66->d.m.prevIdx2 = v66->d.m.prevIdx1;
        v66->d.m.prevIdx1 = v66->d.m.lastIdx;
        goto LABEL_81;
      }
    }
LABEL_82:
    if ( v11 == -1 )
      goto LABEL_92;
    LODWORD(v102) = v11 & 0x7FFFFFFF;
    HIDWORD(v102) = v11 & 0x7FFFFFFF;
    if ( v66->start )
    {
      v80 = (signed __int64)&v7->MonoVertices.Pages[(unsigned __int64)v66->d.m.lastIdx >> 4][v66->d.m.lastIdx & 0xF];
      if ( *(_DWORD *)v80 == (v11 & 0x7FFFFFFF) )
        goto LABEL_92;
      v81 = v7->MonoVertices.Size >> 4;
      if ( v81 >= v7->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
          v7->MonoVertices.Size >> 4);
      v82 = v7->MonoVertices.Pages[v81];
      v83 = v7->MonoVertices.Size & 0xF;
      *(_QWORD *)&v82[v83].srcVer = v102;
      v82[v83].next = 0i64;
      *(_QWORD *)(v80 + 8) = &v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                        - 1) & 0xF];
      v66->d.m.prevIdx2 = v66->d.m.prevIdx1;
      v66->d.m.prevIdx1 = v66->d.m.lastIdx;
    }
    else
    {
      v76 = v7->MonoVertices.Size >> 4;
      if ( v76 >= v7->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v7->MonoVertices,
          v7->MonoVertices.Size >> 4);
      v77 = v7->MonoVertices.Pages[v76];
      v78 = v7->MonoVertices.Size & 0xF;
      *(_QWORD *)&v77[v78].srcVer = v102;
      v77[v78].next = 0i64;
      v79 = (signed __int64)&v7->MonoVertices.Pages[(++v7->MonoVertices.Size - 1) >> 4][(LODWORD(v7->MonoVertices.Size)
                                                                                       - 1) & 0xF];
      *(_QWORD *)&v66->d.t.numTriangles = -1i64;
      v66->start = (Scaleform::Render::Tessellator::MonoVertexType *)v79;
    }
    v66->d.m.lastIdx = LODWORD(v7->MonoVertices.Size) - 1;
LABEL_92:
    v84 = v91;
    v10 = 0;
    v103 = 0;
    if ( !v91 )
      break;
    v85 = v7->ChainsAbove.Pages;
    v86 = v94 + 1;
    --v91;
    v9 = v11;
    v87 = (unsigned __int64)v94 >> 4;
    v88 = v94++ & 0xF;
    v6 = &v85[v87][v88];
    if ( v84 == 1 )
      v11 = v92;
    else
      v11 = v85[(unsigned __int64)v86 >> 4][v86 & 0xF].vertex;
    v5 = v106;
    v12 = v90;
    v13 = v6->chain->rightAbove;
    style = v6->chain->rightAbove;
  }
  v105->numChains = 0;
}

// File Line: 1282
// RVA: 0x9D9630
void __fastcall Scaleform::Render::Tessellator::connectStartingToPending(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::ScanChainType *scan, Scaleform::Render::Tessellator::BaseLineType *upperBase)
{
  Scaleform::Render::Tessellator::MonotoneType *v3; // rax
  Scaleform::Render::Tessellator *v4; // rbx
  Scaleform::Render::Tessellator::BaseLineType *v5; // r10
  unsigned int v6; // ecx
  unsigned int v7; // esi
  unsigned int v8; // er9
  unsigned int v9; // er15
  unsigned int v10; // er12
  unsigned int v11; // ecx
  Scaleform::Render::Tessellator::PendingEndType **v12; // rax
  Scaleform::Render::Tessellator::ScanChainType *v13; // rdi
  Scaleform::Render::Tessellator::PendingEndType *v14; // rax
  Scaleform::Render::Tessellator::ScanChainType **v15; // rdx
  unsigned int v16; // er10
  unsigned int v17; // er11
  Scaleform::Render::Tessellator::ScanChainType *v18; // r13
  unsigned int v19; // er14
  unsigned int v20; // eax
  BOOL v21; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v22; // rdi
  unsigned __int64 v23; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v24; // rdx
  signed __int64 v25; // rcx
  signed __int64 v26; // rdx
  signed __int64 v27; // rsi
  unsigned __int64 v28; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v29; // rdx
  signed __int64 v30; // rcx
  unsigned __int64 v31; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v32; // rdx
  signed __int64 v33; // rcx
  signed __int64 v34; // rdx
  signed __int64 v35; // rsi
  unsigned __int64 v36; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v37; // rdx
  signed __int64 v38; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v39; // rdi
  unsigned __int64 v40; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v41; // rdx
  signed __int64 v42; // rcx
  signed __int64 v43; // rdx
  signed __int64 v44; // rsi
  unsigned __int64 v45; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v46; // rdx
  signed __int64 v47; // rcx
  unsigned __int64 v48; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v49; // rdx
  signed __int64 v50; // rcx
  signed __int64 v51; // rdx
  signed __int64 v52; // rsi
  unsigned __int64 v53; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v54; // rdx
  signed __int64 v55; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v56; // rdi
  unsigned __int64 v57; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v58; // rdx
  signed __int64 v59; // rcx
  signed __int64 v60; // rdx
  signed __int64 v61; // rsi
  unsigned __int64 v62; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v63; // rdx
  signed __int64 v64; // rcx
  unsigned __int64 v65; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v66; // rdx
  signed __int64 v67; // rcx
  signed __int64 v68; // rdx
  signed __int64 v69; // rsi
  unsigned __int64 v70; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v71; // rdx
  signed __int64 v72; // rcx
  Scaleform::Render::Tessellator::PendingEndType **v73; // rdx
  unsigned int v74; // er10
  unsigned int v75; // eax
  Scaleform::Render::Tessellator::MonotoneType *v76; // rax
  unsigned int v77; // esi
  Scaleform::Render::Tessellator::ScanChainType **v78; // rdx
  unsigned int v79; // er8
  unsigned __int64 v80; // rax
  signed __int64 v81; // rcx
  Scaleform::Render::Tessellator::ScanChainType *v82; // rax
  unsigned int v83; // er15
  unsigned int v84; // esi
  Scaleform::Render::Tessellator::MonotoneType *v85; // r8
  Scaleform::Render::Tessellator::PendingEndType **v86; // rdx
  unsigned int v87; // eax
  Scaleform::Render::Tessellator::ScanChainType **v88; // rdx
  int v89; // er10
  unsigned int v90; // er9
  unsigned __int64 v91; // rax
  __int64 v92; // rcx
  Scaleform::Render::Tessellator::ScanChainType *v93; // r12
  unsigned int v94; // edx
  unsigned int v95; // edi
  Scaleform::Render::Tessellator::MonotoneType *v96; // rax
  Scaleform::Render::Tessellator::MonotoneType *v97; // rax
  Scaleform::Render::Tessellator::MonotoneType *v98; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v99; // rcx
  unsigned int v100; // eax
  Scaleform::Render::Tessellator::MonotoneType *v101; // rax
  Scaleform::Render::Tessellator::MonotoneType *v102; // rdi
  unsigned __int64 v103; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v104; // rdx
  signed __int64 v105; // rcx
  signed __int64 v106; // rdx
  signed __int64 v107; // rsi
  unsigned __int64 v108; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v109; // rdx
  signed __int64 v110; // rcx
  unsigned __int64 v111; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v112; // rdx
  signed __int64 v113; // rcx
  signed __int64 v114; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v115; // rdi
  unsigned __int64 v116; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v117; // rdx
  signed __int64 v118; // rcx
  signed __int64 v119; // rdx
  signed __int64 v120; // rsi
  unsigned __int64 v121; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v122; // rdx
  signed __int64 v123; // rcx
  signed __int64 v124; // rsi
  unsigned __int64 v125; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v126; // rdx
  signed __int64 v127; // rcx
  unsigned int v128; // er13
  signed __int64 v129; // rsi
  unsigned __int64 v130; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v131; // rdx
  __int64 v132; // rax
  signed __int64 v133; // rsi
  unsigned __int64 v134; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v135; // rdx
  signed __int64 v136; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v137; // rdi
  unsigned int v138; // edx
  unsigned __int64 v139; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v140; // rdx
  signed __int64 v141; // rcx
  signed __int64 v142; // rdx
  signed __int64 v143; // rsi
  unsigned __int64 v144; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v145; // rdx
  signed __int64 v146; // rcx
  unsigned __int64 v147; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v148; // rdx
  signed __int64 v149; // rcx
  signed __int64 v150; // rdx
  signed __int64 v151; // rsi
  unsigned __int64 v152; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v153; // rdx
  signed __int64 v154; // rcx
  unsigned __int64 v155; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v156; // rdx
  signed __int64 v157; // rcx
  signed __int64 v158; // rdx
  signed __int64 v159; // rsi
  unsigned __int64 v160; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v161; // rdx
  signed __int64 v162; // rcx
  bool v163; // zf
  unsigned __int64 v164; // r14
  signed __int64 v165; // rcx
  signed __int64 v166; // rsi
  unsigned __int64 v167; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v168; // rdx
  signed __int64 v169; // rcx
  Scaleform::Render::Tessellator::MonotoneType *v170; // rdi
  unsigned int v171; // er14
  unsigned __int64 v172; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v173; // rdx
  signed __int64 v174; // rcx
  signed __int64 v175; // rdx
  signed __int64 v176; // rsi
  unsigned __int64 v177; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v178; // rdx
  signed __int64 v179; // rcx
  unsigned __int64 v180; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v181; // rdx
  signed __int64 v182; // rcx
  signed __int64 v183; // rdx
  signed __int64 v184; // rsi
  unsigned __int64 v185; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v186; // rdx
  signed __int64 v187; // rcx
  Scaleform::Render::Tessellator::ScanChainType **v188; // rdx
  unsigned int v189; // er9
  signed __int64 v190; // rcx
  Scaleform::Render::Tessellator::ScanChainType *v191; // rax
  unsigned int v192; // edx
  unsigned __int64 v193; // rax
  unsigned __int64 v194; // rax
  BOOL v195; // [rsp+20h] [rbp-E0h]
  unsigned int v196; // [rsp+20h] [rbp-E0h]
  unsigned int v197; // [rsp+24h] [rbp-DCh]
  unsigned int v198; // [rsp+24h] [rbp-DCh]
  unsigned int v199; // [rsp+28h] [rbp-D8h]
  unsigned int v200; // [rsp+2Ch] [rbp-D4h]
  unsigned int v201; // [rsp+2Ch] [rbp-D4h]
  unsigned int v202; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Tessellator::ScanChainType *v203; // [rsp+38h] [rbp-C8h]
  Scaleform::Render::Tessellator::MonotoneType *v204; // [rsp+38h] [rbp-C8h]
  unsigned int v205; // [rsp+40h] [rbp-C0h]
  unsigned int v206; // [rsp+44h] [rbp-BCh]
  unsigned int v207; // [rsp+48h] [rbp-B8h]
  unsigned int v208; // [rsp+48h] [rbp-B8h]
  unsigned int v209; // [rsp+50h] [rbp-B0h]
  unsigned int v210; // [rsp+58h] [rbp-A8h]
  __int64 v211; // [rsp+58h] [rbp-A8h]
  __int64 v212; // [rsp+68h] [rbp-98h]
  __int64 v213; // [rsp+68h] [rbp-98h]
  __int64 v214; // [rsp+78h] [rbp-88h]
  __int64 v215; // [rsp+78h] [rbp-88h]
  __int64 v216; // [rsp+88h] [rbp-78h]
  __int64 v217; // [rsp+88h] [rbp-78h]
  __int64 v218; // [rsp+98h] [rbp-68h]
  __int64 v219; // [rsp+98h] [rbp-68h]
  __int64 v220; // [rsp+A8h] [rbp-58h]
  __int64 v221; // [rsp+A8h] [rbp-58h]
  __int64 v222; // [rsp+B8h] [rbp-48h]
  __int64 v223; // [rsp+B8h] [rbp-48h]
  Scaleform::Render::Tessellator::ScanChainType scana; // [rsp+C8h] [rbp-38h]
  __int64 v225; // [rsp+E8h] [rbp-18h]
  Scaleform::Render::Tessellator::BaseLineType *v226; // [rsp+F8h] [rbp-8h]
  unsigned int v227; // [rsp+150h] [rbp+50h]
  unsigned int v228; // [rsp+158h] [rbp+58h]
  int v229; // [rsp+158h] [rbp+58h]
  Scaleform::Render::Tessellator::BaseLineType *v230; // [rsp+160h] [rbp+60h]
  unsigned int style; // [rsp+168h] [rbp+68h]

  v230 = upperBase;
  v3 = scan->monotone;
  v4 = this;
  v5 = v3->lowerBase;
  v6 = v3->style;
  v3->lowerBase = 0i64;
  v7 = upperBase->numChains;
  v8 = v5->numChains;
  v9 = v5->vertexLeft;
  v10 = upperBase->vertexLeft;
  scana.monotone = scan->monotone;
  style = v6;
  v11 = v5->firstChain;
  v209 = v5->vertexRight;
  v12 = v4->PendingEnds.Pages;
  v210 = v11;
  v13 = scan;
  v203 = scan;
  v226 = v5;
  v14 = v12[(unsigned __int64)v11 >> 4];
  v15 = v4->ChainsAbove.Pages;
  v16 = v5->styleLeft;
  v202 = v9;
  LODWORD(scana.chain) = v9;
  v17 = v14[v11 & 0xF].vertex;
  LODWORD(v14) = upperBase->firstChain;
  v207 = (unsigned int)v14;
  v206 = upperBase->vertexRight;
  v197 = v8;
  v18 = &scana;
  v19 = v15[(unsigned __int64)upperBase->firstChain >> 4][(unsigned __int8)v14 & 0xF].vertex;
  v20 = upperBase->styleLeft;
  v199 = v17;
  v21 = v8 < v7;
  v205 = v16;
  v228 = v7;
  v195 = v8 < v7;
LABEL_2:
  v200 = v20;
  v227 = v19;
  while ( 1 )
  {
    if ( (v9 != v17 || v10 != -1 && v19 != -1) && (v10 != v19 || v9 != -1 && v17 != -1) && (v9 != v17 || v10 != v19) )
    {
      if ( v16 == style )
        goto LABEL_32;
      Scaleform::Render::Tessellator::replaceMonotone(v4, v18, style);
      v22 = v18->monotone;
      if ( v9 != -1 )
      {
        LODWORD(v216) = v9 | 0x80000000;
        HIDWORD(v216) = v9 | 0x80000000;
        if ( v22->start )
        {
          v27 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v22->d.m.lastIdx >> 4][v22->d.m.lastIdx & 0xF];
          if ( *(_DWORD *)v27 == (v9 | 0x80000000) )
            goto LABEL_22;
          v28 = v4->MonoVertices.Size >> 4;
          if ( v28 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v29 = v4->MonoVertices.Pages[v28];
          v30 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v29[v30].srcVer = v216;
          v29[v30].next = 0i64;
          *(_QWORD *)(v27 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          v22->d.m.prevIdx2 = v22->d.m.prevIdx1;
          v22->d.m.prevIdx1 = v22->d.m.lastIdx;
        }
        else
        {
          v23 = v4->MonoVertices.Size >> 4;
          if ( v23 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v24 = v4->MonoVertices.Pages[v23];
          v25 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v24[v25].srcVer = v216;
          v24[v25].next = 0i64;
          v26 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)&v22->d.t.numTriangles = -1i64;
          v22->start = (Scaleform::Render::Tessellator::MonoVertexType *)v26;
        }
        v22->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
      }
LABEL_22:
      if ( v199 == -1 )
        goto LABEL_32;
      LODWORD(v222) = v199 & 0x7FFFFFFF;
      HIDWORD(v222) = v199 & 0x7FFFFFFF;
      if ( v22->start )
      {
        v35 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v22->d.m.lastIdx >> 4][v22->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v35 == (v199 & 0x7FFFFFFF) )
          goto LABEL_32;
        v36 = v4->MonoVertices.Size >> 4;
        if ( v36 >= v4->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
            v4->MonoVertices.Size >> 4);
        v37 = v4->MonoVertices.Pages[v36];
        v38 = v4->MonoVertices.Size & 0xF;
        *(_QWORD *)&v37[v38].srcVer = v222;
        v37[v38].next = 0i64;
        *(_QWORD *)(v35 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v22->d.m.prevIdx2 = v22->d.m.prevIdx1;
        v22->d.m.prevIdx1 = v22->d.m.lastIdx;
      }
      else
      {
        v31 = v4->MonoVertices.Size >> 4;
        if ( v31 >= v4->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
            v4->MonoVertices.Size >> 4);
        v32 = v4->MonoVertices.Pages[v31];
        v33 = v4->MonoVertices.Size & 0xF;
        *(_QWORD *)&v32[v33].srcVer = v222;
        v32[v33].next = 0i64;
        v34 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v22->d.t.numTriangles = -1i64;
        v22->start = (Scaleform::Render::Tessellator::MonoVertexType *)v34;
      }
      v22->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
LABEL_32:
      v39 = v18->monotone;
      if ( v10 == -1 )
        goto LABEL_42;
      LODWORD(v220) = v10 | 0x80000000;
      HIDWORD(v220) = v10 | 0x80000000;
      if ( v39->start )
      {
        v44 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v39->d.m.lastIdx >> 4][v39->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v44 == (v10 | 0x80000000) )
          goto LABEL_42;
        v45 = v4->MonoVertices.Size >> 4;
        if ( v45 >= v4->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
            v4->MonoVertices.Size >> 4);
        v46 = v4->MonoVertices.Pages[v45];
        v47 = v4->MonoVertices.Size & 0xF;
        *(_QWORD *)&v46[v47].srcVer = v220;
        v46[v47].next = 0i64;
        *(_QWORD *)(v44 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        v39->d.m.prevIdx2 = v39->d.m.prevIdx1;
        v39->d.m.prevIdx1 = v39->d.m.lastIdx;
      }
      else
      {
        v40 = v4->MonoVertices.Size >> 4;
        if ( v40 >= v4->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
            v4->MonoVertices.Size >> 4);
        v41 = v4->MonoVertices.Pages[v40];
        v42 = v4->MonoVertices.Size & 0xF;
        *(_QWORD *)&v41[v42].srcVer = v220;
        v41[v42].next = 0i64;
        v43 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        *(_QWORD *)&v39->d.t.numTriangles = -1i64;
        v39->start = (Scaleform::Render::Tessellator::MonoVertexType *)v43;
      }
      v39->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
LABEL_42:
      v19 = v227;
      if ( v227 != -1 )
      {
        LODWORD(v212) = v227 & 0x7FFFFFFF;
        HIDWORD(v212) = v227 & 0x7FFFFFFF;
        if ( !v39->start )
        {
          v48 = v4->MonoVertices.Size >> 4;
          if ( v48 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v49 = v4->MonoVertices.Pages[v48];
          v50 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v49[v50].srcVer = v212;
          v49[v50].next = 0i64;
          v51 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)&v39->d.t.numTriangles = -1i64;
          v39->start = (Scaleform::Render::Tessellator::MonoVertexType *)v51;
LABEL_51:
          v19 = v227;
          v39->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
          goto LABEL_52;
        }
        v52 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v39->d.m.lastIdx >> 4][v39->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v52 != (v227 & 0x7FFFFFFF) )
        {
          v53 = v4->MonoVertices.Size >> 4;
          if ( v53 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v54 = v4->MonoVertices.Pages[v53];
          v55 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v54[v55].srcVer = v212;
          v54[v55].next = 0i64;
          *(_QWORD *)(v52 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          v39->d.m.prevIdx2 = v39->d.m.prevIdx1;
          v39->d.m.prevIdx1 = v39->d.m.lastIdx;
          goto LABEL_51;
        }
      }
LABEL_52:
      v13 = v203;
      v8 = v197;
      v21 = v195;
      v203->monotone = v18->monotone;
      v20 = v200;
    }
    if ( v20 != style || !v13->monotone )
    {
      if ( !v20 )
      {
        v13->monotone = 0i64;
        goto LABEL_78;
      }
      Scaleform::Render::Tessellator::replaceMonotone(v4, v13, v20);
      v56 = v13->monotone;
      if ( v10 != -1 )
      {
        LODWORD(v214) = v10 | 0x80000000;
        HIDWORD(v214) = v10 | 0x80000000;
        if ( !v56->start )
        {
          v57 = v4->MonoVertices.Size >> 4;
          if ( v57 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v58 = v4->MonoVertices.Pages[v57];
          v59 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v58[v59].srcVer = v214;
          v58[v59].next = 0i64;
          v60 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)&v56->d.t.numTriangles = -1i64;
          v56->start = (Scaleform::Render::Tessellator::MonoVertexType *)v60;
          goto LABEL_66;
        }
        v61 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v56->d.m.lastIdx >> 4][v56->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v61 != (v10 | 0x80000000) )
        {
          v62 = v4->MonoVertices.Size >> 4;
          if ( v62 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v63 = v4->MonoVertices.Pages[v62];
          v64 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v63[v64].srcVer = v214;
          v63[v64].next = 0i64;
          *(_QWORD *)(v61 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          v56->d.m.prevIdx2 = v56->d.m.prevIdx1;
          v56->d.m.prevIdx1 = v56->d.m.lastIdx;
LABEL_66:
          v19 = v227;
          v56->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
        }
      }
      if ( v19 != -1 )
      {
        LODWORD(v218) = v19 & 0x7FFFFFFF;
        HIDWORD(v218) = v19 & 0x7FFFFFFF;
        if ( !v56->start )
        {
          v65 = v4->MonoVertices.Size >> 4;
          if ( v65 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v66 = v4->MonoVertices.Pages[v65];
          v67 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v66[v67].srcVer = v218;
          v66[v67].next = 0i64;
          v68 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                           - 1) & 0xF];
          *(_QWORD *)&v56->d.t.numTriangles = -1i64;
          v56->start = (Scaleform::Render::Tessellator::MonoVertexType *)v68;
          goto LABEL_76;
        }
        v69 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v56->d.m.lastIdx >> 4][v56->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v69 != (v19 & 0x7FFFFFFF) )
        {
          v70 = v4->MonoVertices.Size >> 4;
          if ( v70 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v71 = v4->MonoVertices.Pages[v70];
          v72 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v71[v72].srcVer = v218;
          v71[v72].next = 0i64;
          *(_QWORD *)(v69 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          v56->d.m.prevIdx2 = v56->d.m.prevIdx1;
          v56->d.m.prevIdx1 = v56->d.m.lastIdx;
LABEL_76:
          v19 = v227;
          v56->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
        }
      }
      v21 = v195;
      v8 = v197;
      v13 = v203;
    }
LABEL_78:
    if ( v8 == v21 )
      break;
    if ( v8 )
    {
      v73 = v4->PendingEnds.Pages;
      v9 = v199;
      v202 = v199;
      --v8;
      v74 = v210 + 1;
      v18 = (Scaleform::Render::Tessellator::ScanChainType *)&v73[(unsigned __int64)v210 >> 4][v210 & 0xF];
      v197 = v8;
      ++v210;
      if ( v8 )
      {
        v75 = v73[(unsigned __int64)v74 >> 4][v74 & 0xF].vertex;
        v21 = v195;
      }
      else
      {
        v75 = v209;
      }
      v199 = v75;
      v76 = v18->monotone;
      if ( v76 )
      {
        v16 = v76->style;
        v205 = v76->style;
      }
      else
      {
        v16 = 0;
        v205 = 0;
      }
    }
    else
    {
      v16 = v205;
      v9 = v202;
    }
    v77 = v228;
    v20 = v200;
    v17 = v199;
    if ( v228 )
    {
      v78 = v4->ChainsAbove.Pages;
      v79 = v207 + 1;
      --v228;
      v10 = v19;
      v80 = (unsigned __int64)v207 >> 4;
      v81 = v207++ & 0xF;
      v82 = v78[v80];
      v13 = &v82[v81];
      v203 = &v82[v81];
      if ( v77 == 1 )
        v19 = v206;
      else
        v19 = v78[(unsigned __int64)v79 >> 4][v79 & 0xF].vertex;
      v21 = v195;
      v20 = v13->chain->rightAbove;
      goto LABEL_2;
    }
  }
  v83 = v202;
  v84 = v202;
  if ( v199 != -1 )
    v84 = v199;
  v201 = v84;
  if ( v228 && v84 != -1 )
  {
    v85 = 0i64;
    v204 = 0i64;
    if ( v8 )
    {
      v86 = v4->PendingEnds.Pages;
      v83 = v199;
      v202 = v199;
      v18 = (Scaleform::Render::Tessellator::ScanChainType *)&v86[(unsigned __int64)v210 >> 4][v210 & 0xF];
      if ( v8 == 1 )
        v87 = v209;
      else
        v87 = v86[(unsigned __int64)(v210 + 1) >> 4][(v210 + 1) & 0xF].vertex;
      v199 = v87;
    }
    v88 = v4->ChainsAbove.Pages;
    v89 = v228 - 1;
    v90 = v207 + 1;
    v229 = v89;
    v91 = v207;
    v92 = v207 & 0xF;
    v208 = v207 + 1;
    v93 = &v88[v91 >> 4][v92];
    if ( v89 )
      v94 = v88[(unsigned __int64)v90 >> 4][v90 & 0xF].vertex;
    else
      v94 = v206;
    v95 = style;
    v198 = v94;
    v96 = v18->monotone;
    v196 = v93->chain->rightAbove;
    if ( v96 && v96->style == style )
    {
      v97 = Scaleform::Render::Tessellator::startMonotone(v4, style);
      v98 = v18->monotone;
      v89 = v229;
      v85 = v97;
      v97->start = v98->start;
      v204 = v97;
      *(_QWORD *)&v97->d.m.lastIdx = *(_QWORD *)&v98->d.m.lastIdx;
      *(_QWORD *)&v97->d.t.meshIdx = *(_QWORD *)&v98->d.t.meshIdx;
      v97->lowerBase = v98->lowerBase;
      v99 = v18->monotone;
      v99->start = 0i64;
      *(_QWORD *)&v99->d.m.lastIdx = -1i64;
      v99->d.m.prevIdx2 = -1;
      v99->style = style;
      v99->lowerBase = 0i64;
    }
    v100 = v196;
    while ( v89 )
    {
      v128 = v198;
      if ( v19 != v198 )
      {
        Scaleform::Render::Tessellator::replaceMonotone(v4, v93, v95);
        v137 = v93->monotone;
        v138 = v84 | 0x80000000;
        LODWORD(v223) = v84 | 0x80000000;
        HIDWORD(v223) = v84 | 0x80000000;
        if ( v137->start )
        {
          v143 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v137->d.m.lastIdx >> 4][v137->d.m.lastIdx & 0xF];
          if ( *(_DWORD *)v143 != v138 )
          {
            v144 = v4->MonoVertices.Size >> 4;
            if ( v144 >= v4->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                v4->MonoVertices.Size >> 4);
            v145 = v4->MonoVertices.Pages[v144];
            v146 = v4->MonoVertices.Size & 0xF;
            *(_QWORD *)&v145[v146].srcVer = v223;
            v145[v146].next = 0i64;
            ++v4->MonoVertices.Size;
            v19 = v227;
            *(_QWORD *)(v143 + 8) = &v4->MonoVertices.Pages[(v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                             - 1) & 0xF];
            v137->d.m.prevIdx2 = v137->d.m.prevIdx1;
            v137->d.m.prevIdx1 = v137->d.m.lastIdx;
            v137->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
          }
        }
        else
        {
          v139 = v4->MonoVertices.Size >> 4;
          if ( v139 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v140 = v4->MonoVertices.Pages[v139];
          v19 = v227;
          v141 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v140[v141].srcVer = v223;
          v140[v141].next = 0i64;
          v142 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          *(_QWORD *)&v137->d.t.numTriangles = -1i64;
          v137->start = (Scaleform::Render::Tessellator::MonoVertexType *)v142;
          v137->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
        }
        LODWORD(v217) = v201 & 0x7FFFFFFF;
        HIDWORD(v217) = v201 & 0x7FFFFFFF;
        if ( !v137->start )
        {
          v147 = v4->MonoVertices.Size >> 4;
          if ( v147 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v148 = v4->MonoVertices.Pages[v147];
          v149 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v148[v149].srcVer = v217;
          v148[v149].next = 0i64;
          v150 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          *(_QWORD *)&v137->d.t.numTriangles = -1i64;
          v137->start = (Scaleform::Render::Tessellator::MonoVertexType *)v150;
          goto LABEL_166;
        }
        v151 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v137->d.m.lastIdx >> 4][v137->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v151 != (v201 & 0x7FFFFFFF) )
        {
          v152 = v4->MonoVertices.Size >> 4;
          if ( v152 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v153 = v4->MonoVertices.Pages[v152];
          v154 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v153[v154].srcVer = v217;
          v153[v154].next = 0i64;
          *(_QWORD *)(v151 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                             - 1) & 0xF];
          v137->d.m.prevIdx2 = v137->d.m.prevIdx1;
          v137->d.m.prevIdx1 = v137->d.m.lastIdx;
LABEL_166:
          v19 = v227;
          v137->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
        }
        v115 = v93->monotone;
        if ( v19 != -1 )
        {
          LODWORD(v211) = v19 | 0x80000000;
          HIDWORD(v211) = v19 | 0x80000000;
          if ( !v115->start )
          {
            v155 = v4->MonoVertices.Size >> 4;
            if ( v155 >= v4->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                v4->MonoVertices.Size >> 4);
            v156 = v4->MonoVertices.Pages[v155];
            v157 = v4->MonoVertices.Size & 0xF;
            *(_QWORD *)&v156[v157].srcVer = v211;
            v156[v157].next = 0i64;
            v158 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                              - 1) & 0xF];
            *(_QWORD *)&v115->d.t.numTriangles = -1i64;
            v115->start = (Scaleform::Render::Tessellator::MonoVertexType *)v158;
            goto LABEL_176;
          }
          v159 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v115->d.m.lastIdx >> 4][v115->d.m.lastIdx & 0xF];
          if ( *(_DWORD *)v159 != (v19 | 0x80000000) )
          {
            v160 = v4->MonoVertices.Size >> 4;
            if ( v160 >= v4->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                v4->MonoVertices.Size >> 4);
            v161 = v4->MonoVertices.Pages[v160];
            v162 = v4->MonoVertices.Size & 0xF;
            *(_QWORD *)&v161[v162].srcVer = v211;
            v161[v162].next = 0i64;
            *(_QWORD *)(v159 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                               - 1) & 0xF];
            v115->d.m.prevIdx2 = v115->d.m.prevIdx1;
            v115->d.m.prevIdx1 = v115->d.m.lastIdx;
LABEL_176:
            v19 = v227;
            v115->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
          }
        }
        if ( v198 != -1 )
        {
          v163 = v115->start == 0i64;
          scana.vertex = v198 & 0x7FFFFFFF;
          *(&scana.vertex + 1) = v198 & 0x7FFFFFFF;
          if ( v163 )
          {
            v129 = (signed __int64)&v4->MonoVertices;
            v164 = v4->MonoVertices.Size >> 4;
            if ( v164 >= v4->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                v4->MonoVertices.Size >> 4);
            v131 = v4->MonoVertices.Pages[v164];
            v132 = *(_QWORD *)&scana.vertex;
LABEL_182:
            v165 = *(_DWORD *)(v129 + 8) & 0xF;
            *(_QWORD *)&v131[v165].srcVer = v132;
            v131[v165].next = 0i64;
            v115->start = (Scaleform::Render::Tessellator::MonoVertexType *)(*(_QWORD *)(*(_QWORD *)(v129 + 32)
                                                                                       + 8
                                                                                       * ((unsigned __int64)(++*(_QWORD *)(v129 + 8) - 1i64) >> 4))
                                                                           + 16i64 * ((*(_DWORD *)(v129 + 8) - 1) & 0xF));
            *(_QWORD *)&v115->d.t.numTriangles = -1i64;
LABEL_183:
            v19 = v227;
            v115->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
          }
          else
          {
            v166 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v115->d.m.lastIdx >> 4][v115->d.m.lastIdx & 0xF];
            if ( *(_DWORD *)v166 != (v198 & 0x7FFFFFFF) )
            {
              v167 = v4->MonoVertices.Size >> 4;
              if ( v167 >= v4->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                  v4->MonoVertices.Size >> 4);
              v168 = v4->MonoVertices.Pages[v167];
              v169 = v4->MonoVertices.Size & 0xF;
              *(_QWORD *)&v168[v169].srcVer = *(_QWORD *)&scana.vertex;
              v168[v169].next = 0i64;
              *(_QWORD *)(v166 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                                 - 1) & 0xF];
              v115->d.m.prevIdx2 = v115->d.m.prevIdx1;
              v115->d.m.prevIdx1 = v115->d.m.lastIdx;
              goto LABEL_183;
            }
          }
        }
LABEL_184:
        v100 = v196;
        v89 = v229;
        v95 = style;
      }
      if ( v100 != v95 || !v93->monotone )
      {
        if ( !v100 )
        {
          v93->monotone = 0i64;
          goto LABEL_214;
        }
        Scaleform::Render::Tessellator::replaceMonotone(v4, v93, v100);
        v170 = v93->monotone;
        if ( v19 != -1 )
        {
          v171 = v19 | 0x80000000;
          v163 = v170->start == 0i64;
          LODWORD(v225) = v171;
          HIDWORD(v225) = v171;
          if ( v163 )
          {
            v172 = v4->MonoVertices.Size >> 4;
            if ( v172 >= v4->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                v4->MonoVertices.Size >> 4);
            v173 = v4->MonoVertices.Pages[v172];
            v174 = v4->MonoVertices.Size & 0xF;
            *(_QWORD *)&v173[v174].srcVer = v225;
            v173[v174].next = 0i64;
            v175 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                              - 1) & 0xF];
            *(_QWORD *)&v170->d.t.numTriangles = -1i64;
            v170->start = (Scaleform::Render::Tessellator::MonoVertexType *)v175;
            goto LABEL_202;
          }
          v176 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v170->d.m.lastIdx >> 4][v170->d.m.lastIdx & 0xF];
          if ( *(_DWORD *)v176 != v171 )
          {
            v177 = v4->MonoVertices.Size >> 4;
            if ( v177 >= v4->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                v4->MonoVertices.Size >> 4);
            v178 = v4->MonoVertices.Pages[v177];
            v179 = v4->MonoVertices.Size & 0xF;
            *(_QWORD *)&v178[v179].srcVer = v225;
            v178[v179].next = 0i64;
            *(_QWORD *)(v176 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                               - 1) & 0xF];
            v170->d.m.prevIdx2 = v170->d.m.prevIdx1;
            v170->d.m.prevIdx1 = v170->d.m.lastIdx;
LABEL_202:
            v170->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
          }
        }
        if ( v128 != -1 )
        {
          v163 = v170->start == 0i64;
          LODWORD(scana.chain) = v128 & 0x7FFFFFFF;
          HIDWORD(scana.chain) = v128 & 0x7FFFFFFF;
          if ( v163 )
          {
            v180 = v4->MonoVertices.Size >> 4;
            if ( v180 >= v4->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                v4->MonoVertices.Size >> 4);
            v181 = v4->MonoVertices.Pages[v180];
            v182 = v4->MonoVertices.Size & 0xF;
            *(_QWORD *)&v181[v182].srcVer = scana.chain;
            v181[v182].next = 0i64;
            v183 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                              - 1) & 0xF];
            *(_QWORD *)&v170->d.t.numTriangles = -1i64;
            v170->start = (Scaleform::Render::Tessellator::MonoVertexType *)v183;
            goto LABEL_212;
          }
          v184 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v170->d.m.lastIdx >> 4][v170->d.m.lastIdx & 0xF];
          if ( *(_DWORD *)v184 != (v128 & 0x7FFFFFFF) )
          {
            v185 = v4->MonoVertices.Size >> 4;
            if ( v185 >= v4->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
                v4->MonoVertices.Size >> 4);
            v186 = v4->MonoVertices.Pages[v185];
            v187 = v4->MonoVertices.Size & 0xF;
            *(_QWORD *)&v186[v187].srcVer = scana.chain;
            v186[v187].next = 0i64;
            *(_QWORD *)(v184 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                               - 1) & 0xF];
            v170->d.m.prevIdx2 = v170->d.m.prevIdx1;
            v170->d.m.prevIdx1 = v170->d.m.lastIdx;
LABEL_212:
            v170->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
          }
        }
        v95 = style;
        v89 = v229;
      }
LABEL_214:
      if ( !v89 )
        goto LABEL_219;
      v188 = v4->ChainsAbove.Pages;
      --v89;
      v189 = v208 + 1;
      v229 = v89;
      v19 = v128;
      v190 = v208 & 0xF;
      v227 = v128;
      v191 = v188[(unsigned __int64)v208++ >> 4];
      v93 = &v191[v190];
      if ( v89 )
        v192 = v188[(unsigned __int64)v189 >> 4][v189 & 0xF].vertex;
      else
        v192 = v206;
      v85 = v204;
      v84 = v201;
      v100 = v93->chain->rightAbove;
      v83 = v202;
      v198 = v192;
      v196 = v93->chain->rightAbove;
    }
    v93->monotone = v85;
    if ( !v85 )
    {
      v101 = Scaleform::Render::Tessellator::startMonotone(v4, v95);
      v102 = v101;
      v93->monotone = v101;
      if ( v83 != -1 )
      {
        LODWORD(v219) = v83 | 0x80000000;
        HIDWORD(v219) = v83 | 0x80000000;
        if ( !v101->start )
        {
          v103 = v4->MonoVertices.Size >> 4;
          if ( v103 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v104 = v4->MonoVertices.Pages[v103];
          v105 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v104[v105].srcVer = v219;
          v104[v105].next = 0i64;
          v106 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          *(_QWORD *)&v102->d.t.numTriangles = -1i64;
          v102->start = (Scaleform::Render::Tessellator::MonoVertexType *)v106;
          goto LABEL_119;
        }
        v107 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v101->d.m.lastIdx >> 4][v101->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v107 != (v83 | 0x80000000) )
        {
          v108 = v4->MonoVertices.Size >> 4;
          if ( v108 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v109 = v4->MonoVertices.Pages[v108];
          v110 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v109[v110].srcVer = v219;
          v109[v110].next = 0i64;
          *(_QWORD *)(v107 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                             - 1) & 0xF];
          v102->d.m.prevIdx2 = v102->d.m.prevIdx1;
          v102->d.m.prevIdx1 = v102->d.m.lastIdx;
LABEL_119:
          v102->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
        }
      }
      if ( v199 == -1 )
      {
LABEL_125:
        v19 = v227;
      }
      else
      {
        LODWORD(v215) = v199 & 0x7FFFFFFF;
        HIDWORD(v215) = v199 & 0x7FFFFFFF;
        if ( !v102->start )
        {
          v111 = v4->MonoVertices.Size >> 4;
          if ( v111 >= v4->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
              v4->MonoVertices.Size >> 4);
          v112 = v4->MonoVertices.Pages[v111];
          v113 = v4->MonoVertices.Size & 0xF;
          *(_QWORD *)&v112[v113].srcVer = v215;
          v112[v113].next = 0i64;
          v114 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          *(_QWORD *)&v102->d.t.numTriangles = -1i64;
          v102->start = (Scaleform::Render::Tessellator::MonoVertexType *)v114;
          v102->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
          goto LABEL_125;
        }
        v120 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v102->d.m.lastIdx >> 4][v102->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v120 == (v199 & 0x7FFFFFFF) )
          goto LABEL_125;
        v121 = v4->MonoVertices.Size >> 4;
        if ( v121 >= v4->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
            v4->MonoVertices.Size >> 4);
        v122 = v4->MonoVertices.Pages[v121];
        v123 = v4->MonoVertices.Size & 0xF;
        *(_QWORD *)&v122[v123].srcVer = v215;
        v122[v123].next = 0i64;
        ++v4->MonoVertices.Size;
        v19 = v227;
        *(_QWORD *)(v120 + 8) = &v4->MonoVertices.Pages[(v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                         - 1) & 0xF];
        v102->d.m.prevIdx2 = v102->d.m.prevIdx1;
        v102->d.m.prevIdx1 = v102->d.m.lastIdx;
        v102->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
      }
    }
    v115 = v93->monotone;
    if ( v19 != -1 )
    {
      LODWORD(v213) = v19 | 0x80000000;
      HIDWORD(v213) = v19 | 0x80000000;
      if ( !v115->start )
      {
        v116 = v4->MonoVertices.Size >> 4;
        if ( v116 >= v4->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
            v4->MonoVertices.Size >> 4);
        v117 = v4->MonoVertices.Pages[v116];
        v118 = v4->MonoVertices.Size & 0xF;
        *(_QWORD *)&v117[v118].srcVer = v213;
        v117[v118].next = 0i64;
        v119 = (signed __int64)&v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                          - 1) & 0xF];
        *(_QWORD *)&v115->d.t.numTriangles = -1i64;
        v115->start = (Scaleform::Render::Tessellator::MonoVertexType *)v119;
        goto LABEL_139;
      }
      v124 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v115->d.m.lastIdx >> 4][v115->d.m.lastIdx & 0xF];
      if ( *(_DWORD *)v124 != (v19 | 0x80000000) )
      {
        v125 = v4->MonoVertices.Size >> 4;
        if ( v125 >= v4->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
            v4->MonoVertices.Size >> 4);
        v126 = v4->MonoVertices.Pages[v125];
        v127 = v4->MonoVertices.Size & 0xF;
        *(_QWORD *)&v126[v127].srcVer = v213;
        v126[v127].next = 0i64;
        *(_QWORD *)(v124 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                           - 1) & 0xF];
        v115->d.m.prevIdx2 = v115->d.m.prevIdx1;
        v115->d.m.prevIdx1 = v115->d.m.lastIdx;
LABEL_139:
        v19 = v227;
        v115->d.m.lastIdx = LODWORD(v4->MonoVertices.Size) - 1;
      }
    }
    v128 = v198;
    if ( v198 != -1 )
    {
      LODWORD(v221) = v198 & 0x7FFFFFFF;
      HIDWORD(v221) = v198 & 0x7FFFFFFF;
      if ( !v115->start )
      {
        v129 = (signed __int64)&v4->MonoVertices;
        v130 = v4->MonoVertices.Size >> 4;
        if ( v130 >= v4->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
            v4->MonoVertices.Size >> 4);
        v131 = v4->MonoVertices.Pages[v130];
        v132 = v221;
        goto LABEL_182;
      }
      v133 = (signed __int64)&v4->MonoVertices.Pages[(unsigned __int64)v115->d.m.lastIdx >> 4][v115->d.m.lastIdx & 0xF];
      if ( *(_DWORD *)v133 != (v198 & 0x7FFFFFFF) )
      {
        v134 = v4->MonoVertices.Size >> 4;
        if ( v134 >= v4->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v4->MonoVertices,
            v4->MonoVertices.Size >> 4);
        v135 = v4->MonoVertices.Pages[v134];
        v136 = v4->MonoVertices.Size & 0xF;
        *(_QWORD *)&v135[v136].srcVer = v221;
        v135[v136].next = 0i64;
        *(_QWORD *)(v133 + 8) = &v4->MonoVertices.Pages[(++v4->MonoVertices.Size - 1) >> 4][(LODWORD(v4->MonoVertices.Size)
                                                                                           - 1) & 0xF];
        v115->d.m.prevIdx2 = v115->d.m.prevIdx1;
        v115->d.m.prevIdx1 = v115->d.m.lastIdx;
        goto LABEL_183;
      }
    }
    goto LABEL_184;
  }
LABEL_219:
  if ( v226 == &v4->BaseLines.Pages[(v4->BaseLines.Size - 1) >> 4][(LODWORD(v4->BaseLines.Size) - 1) & 0xF] )
  {
    v193 = v226->firstChain;
    if ( v193 < v4->PendingEnds.Size )
      v4->PendingEnds.Size = v193;
    v194 = v4->BaseLines.Size;
    if ( v194 )
      v4->BaseLines.Size = v194 - 1;
  }
  v230->numChains = 0;
}f ( v194 )
      v4->BaseLines.Size = v194 - 1;
  }
  v230->numChains = 0;
}

// File Line: 1418
// RVA: 0x9D8770
void __fastcall Scaleform::Render::Tessellator::connectStarting(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::ScanChainType *scan, Scaleform::Render::Tessellator::BaseLineType *upperBase)
{
  Scaleform::Render::Tessellator::BaseLineType *v3; // rdi
  Scaleform::Render::Tessellator::ScanChainType *v4; // rbp
  Scaleform::Render::Tessellator *v5; // rsi
  Scaleform::Render::Tessellator::MonotoneType *v6; // rax
  unsigned __int64 v7; // rcx
  signed int v8; // ebx
  unsigned int v9; // er14
  Scaleform::Render::Tessellator::MonotoneType *v10; // rax
  unsigned __int64 v11; // rcx
  signed int v12; // eax
  Scaleform::Render::Tessellator::MonotoneType *v13; // r12
  unsigned __int64 v14; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v15; // rcx
  signed __int64 v16; // rdx
  signed __int64 v17; // r14
  unsigned __int64 v18; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v19; // rcx
  signed __int64 v20; // rdx
  __int64 v21; // [rsp+20h] [rbp-38h]

  v3 = upperBase;
  v4 = scan;
  v5 = this;
  if ( !scan )
    goto LABEL_35;
  v6 = scan->monotone;
  if ( !v6 )
    goto LABEL_35;
  v7 = v6->d.m.lastIdx;
  if ( (_DWORD)v7 == -1 )
    v8 = -1;
  else
    v8 = v5->MonoVertices.Pages[v7 >> 4][v6->d.m.lastIdx & 0xF].srcVer;
  *(_QWORD *)&upperBase->vertexLeft = -1i64;
  v9 = 0;
  do
  {
    if ( v8 == -1 || v3->y > v5->MeshVertices.Pages[(unsigned __int64)(v8 & 0xFFFFFFF) >> 4][v8 & 0xF].y )
      break;
    if ( v8 >= 0 )
      v3->vertexRight = v8;
    else
      v3->vertexLeft = v8 & 0xFFFFFFF;
    Scaleform::Render::Tessellator::removeLastMonoVertex(v5, v4->monotone);
    v10 = v4->monotone;
    v11 = v10->d.m.lastIdx;
    v8 = (_DWORD)v11 == -1 ? -1 : v5->MonoVertices.Pages[v11 >> 4][v10->d.m.lastIdx & 0xF].srcVer;
    ++v9;
  }
  while ( v9 < 2 );
  if ( v4->monotone->lowerBase )
  {
    Scaleform::Render::Tessellator::connectStartingToPending(v5, v4, v3);
    return;
  }
  if ( v8 == -1 )
  {
    v12 = v3->vertexRight;
    if ( v12 == -1 )
    {
      v12 = v3->vertexLeft;
      if ( v12 == -1 )
        goto LABEL_32;
      v3->vertexLeft = -1;
    }
    else
    {
      v3->vertexRight = -1;
    }
    v13 = v4->monotone;
    v8 = v12;
    LODWORD(v21) = v12;
    HIDWORD(v21) = v12;
    if ( v13->start )
    {
      v17 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v13->d.m.lastIdx >> 4][v13->d.m.lastIdx & 0xF];
      if ( *(_DWORD *)v17 == v12 )
        goto LABEL_32;
      v18 = v5->MonoVertices.Size >> 4;
      if ( v18 >= v5->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
          v5->MonoVertices.Size >> 4);
      v19 = v5->MonoVertices.Pages[v18];
      v20 = v5->MonoVertices.Size & 0xF;
      *(_QWORD *)&v19[v20].srcVer = v21;
      v19[v20].next = 0i64;
      *(_QWORD *)(v17 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                        - 1) & 0xF];
      v13->d.m.prevIdx2 = v13->d.m.prevIdx1;
      v13->d.m.prevIdx1 = v13->d.m.lastIdx;
    }
    else
    {
      v14 = v5->MonoVertices.Size >> 4;
      if ( v14 >= v5->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
          v5->MonoVertices.Size >> 4);
      v15 = v5->MonoVertices.Pages[v14];
      v16 = v5->MonoVertices.Size & 0xF;
      *(_QWORD *)&v15[v16].srcVer = v21;
      v15[v16].next = 0i64;
      v13->start = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size) - 1) & 0xF];
      *(_QWORD *)&v13->d.t.numTriangles = -1i64;
    }
    v13->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
  }
LABEL_32:
  if ( v8 >= 0 )
    Scaleform::Render::Tessellator::connectStartingToRight(v5, v4, v3, v8);
  else
    Scaleform::Render::Tessellator::connectStartingToLeft(v5, v4, v3, v8 & 0xFFFFFFF);
LABEL_35:
  v3->numChains = 0;
}

// File Line: 1524
// RVA: 0x9F40D0
void __usercall Scaleform::Render::Tessellator::sweepScanbeam(Scaleform::Render::Tessellator *this@<rcx>, Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8> *aet@<rdx>, float yb@<xmm2>, signed __int64 a4@<r8>)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8> *v4; // r11
  Scaleform::Render::Tessellator *v5; // rsi
  unsigned __int64 v6; // rdi
  Scaleform::Render::Tessellator::MonoChainType *v7; // r15
  bool v8; // zf
  unsigned __int64 v9; // r14
  Scaleform::Render::Tessellator::ScanChainType *v10; // rdx
  __int64 v11; // rax
  unsigned int v12; // er12
  unsigned int v13; // er14
  Scaleform::Render::Tessellator::ScanChainType *v14; // r15
  unsigned __int64 v15; // rax
  signed __int64 v16; // rbx
  Scaleform::Render::Tessellator::ScanChainType *v17; // rdi
  signed __int64 v18; // r13
  Scaleform::Render::Tessellator::MonoChainType *v19; // r8
  unsigned int v20; // ecx
  Scaleform::Render::Tessellator::MonoChainType *v21; // rdx
  unsigned int v22; // eax
  unsigned int v23; // eax
  Scaleform::Render::Tessellator::ScanChainType *v24; // rbx
  signed __int64 v25; // rdi
  Scaleform::Render::Tessellator::ScanChainType *v26; // rbx
  unsigned int v27; // eax
  unsigned int v28; // er9
  unsigned __int64 v29; // r12
  unsigned int v30; // eax
  unsigned int v31; // er10
  Scaleform::Render::Tessellator::ScanChainType *v32; // r13
  unsigned __int64 v33; // rcx
  unsigned __int64 v34; // rax
  unsigned __int64 v35; // rdx
  signed __int64 v36; // rcx
  Scaleform::Render::Tessellator::ScanChainType *v37; // rax
  signed int v38; // ebx
  Scaleform::Render::Tessellator::ScanChainType *v39; // r14
  Scaleform::Render::Tessellator::ScanChainType *v40; // rax
  signed int v41; // er8
  signed __int64 v42; // rcx
  int v43; // eax
  int v44; // eax
  int v45; // eax
  Scaleform::Render::Tessellator::MonotoneType *v46; // rdi
  Scaleform::Render::Tessellator::BaseLineType *v47; // r8
  unsigned __int64 v48; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v49; // rcx
  signed __int64 v50; // rdx
  signed __int64 v51; // rdx
  signed __int64 v52; // r14
  unsigned __int64 v53; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v54; // rcx
  signed __int64 v55; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v56; // rbx
  signed int v57; // er8
  Scaleform::Render::Tessellator::BaseLineType *v58; // r9
  unsigned __int64 v59; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v60; // rcx
  signed __int64 v61; // rdx
  signed __int64 v62; // rdx
  signed __int64 v63; // rdi
  unsigned __int64 v64; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v65; // rcx
  signed __int64 v66; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v67; // rax
  __int64 v68; // rax
  unsigned int v69; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v70; // rax
  Scaleform::Render::Tessellator::BaseLineType *v71; // rax
  Scaleform::Render::Tessellator::MonotoneType *v72; // rbx
  Scaleform::Render::Tessellator::BaseLineType *v73; // r9
  unsigned __int64 v74; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v75; // rcx
  signed __int64 v76; // rdx
  signed __int64 v77; // rdx
  signed __int64 v78; // rdi
  unsigned __int64 v79; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v80; // rcx
  signed __int64 v81; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v82; // rdi
  Scaleform::Render::Tessellator::BaseLineType *v83; // r8
  unsigned __int64 v84; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v85; // rcx
  signed __int64 v86; // rdx
  signed __int64 v87; // rdx
  signed __int64 v88; // r14
  unsigned __int64 v89; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v90; // rcx
  signed __int64 v91; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v92; // rdi
  Scaleform::Render::Tessellator::BaseLineType *v93; // r8
  unsigned __int64 v94; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v95; // rcx
  signed __int64 v96; // rdx
  signed __int64 v97; // rdx
  signed __int64 v98; // r14
  unsigned __int64 v99; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v100; // rcx
  signed __int64 v101; // rdx
  unsigned int v102; // er14
  unsigned int v103; // edi
  unsigned int v104; // er10
  unsigned int v105; // er11
  Scaleform::Render::Tessellator::ScanChainType *v106; // r13
  signed __int64 v107; // r9
  signed __int64 v108; // r8
  Scaleform::Render::Tessellator::ScanChainType *v109; // r13
  Scaleform::Render::Tessellator::ScanChainType *v110; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v111; // rdi
  Scaleform::Render::Tessellator::BaseLineType *v112; // r8
  unsigned __int64 v113; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v114; // rcx
  signed __int64 v115; // rdx
  signed __int64 v116; // rdx
  signed __int64 v117; // r14
  signed __int64 v118; // r15
  unsigned __int64 v119; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v120; // rcx
  __int64 v121; // rax
  Scaleform::Render::Tessellator::ScanChainType *v122; // r15
  signed int v123; // er8
  Scaleform::Render::Tessellator::MonotoneType *v124; // rdi
  Scaleform::Render::Tessellator::BaseLineType *v125; // r9
  unsigned __int64 v126; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v127; // rcx
  signed __int64 v128; // rdx
  signed __int64 v129; // rdx
  signed __int64 v130; // r14
  unsigned __int64 v131; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v132; // rcx
  signed __int64 v133; // rdx
  Scaleform::Render::Tessellator::BaseLineType *v134; // r8
  unsigned __int64 v135; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v136; // rcx
  signed __int64 v137; // rdx
  signed __int64 v138; // rdx
  unsigned __int64 v139; // r12
  signed __int64 v140; // rdx
  signed int v141; // edi
  Scaleform::Render::Tessellator::MonotoneType *v142; // r14
  Scaleform::Render::Tessellator::BaseLineType *v143; // r8
  unsigned __int64 v144; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v145; // rcx
  signed __int64 v146; // rdx
  signed __int64 v147; // rdx
  signed __int64 v148; // r15
  unsigned __int64 v149; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v150; // rcx
  signed __int64 v151; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v152; // rdi
  Scaleform::Render::Tessellator::BaseLineType *v153; // r8
  unsigned __int64 v154; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v155; // rcx
  signed __int64 v156; // rdx
  signed __int64 v157; // rdx
  signed __int64 v158; // r14
  unsigned __int64 v159; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v160; // rcx
  signed __int64 v161; // rdx
  Scaleform::Render::Tessellator::ScanChainType *v162; // rcx
  Scaleform::Render::Tessellator::ScanChainType *v163; // rax
  signed int v164; // er8
  Scaleform::Render::Tessellator::MonotoneType *v165; // rbx
  Scaleform::Render::Tessellator::BaseLineType *v166; // r9
  unsigned __int64 v167; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v168; // rcx
  signed __int64 v169; // rdx
  signed __int64 v170; // rdx
  signed __int64 v171; // rdi
  unsigned __int64 v172; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v173; // rcx
  signed __int64 v174; // rdx
  unsigned __int64 v175; // rdx
  signed __int64 v176; // rcx
  Scaleform::Render::Tessellator::ScanChainType *v177; // rax
  signed int v178; // er8
  Scaleform::Render::Tessellator::ScanChainType *v179; // r13
  Scaleform::Render::Tessellator::MonotoneType *v180; // rbx
  Scaleform::Render::Tessellator::BaseLineType *v181; // r9
  unsigned __int64 v182; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v183; // rcx
  signed __int64 v184; // rdx
  signed __int64 v185; // rdx
  signed __int64 v186; // rdi
  unsigned __int64 v187; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v188; // rcx
  signed __int64 v189; // rdx
  Scaleform::Render::Tessellator::MonotoneType *v190; // rbx
  signed int v191; // er8
  Scaleform::Render::Tessellator::BaseLineType *v192; // r9
  unsigned __int64 v193; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v194; // rcx
  signed __int64 v195; // rdx
  signed __int64 v196; // rdx
  signed __int64 v197; // rdi
  unsigned __int64 v198; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v199; // rcx
  signed __int64 v200; // rdx
  unsigned __int64 v201; // r14
  unsigned __int64 v202; // rdi
  signed __int64 v203; // r15
  Scaleform::Render::Tessellator::ScanChainType *v204; // r12
  Scaleform::Render::Tessellator::ScanChainType *v205; // rdx
  signed __int64 v206; // r8
  unsigned __int64 v207; // rdx
  unsigned __int64 v208; // rcx
  Scaleform::Render::Tessellator::MonoChainType *v209; // rdx
  unsigned __int16 v210; // ax
  int v211; // [rsp+20h] [rbp-E0h]
  Scaleform::Render::Tessellator::ScanChainType *v212; // [rsp+28h] [rbp-D8h]
  Scaleform::Render::Tessellator::ScanChainType *dst; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Tessellator::ScanChainType *scan; // [rsp+38h] [rbp-C8h]
  Scaleform::Render::Tessellator::BaseLineType upperBase; // [rsp+40h] [rbp-C0h]
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
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8> *v232; // [rsp+1A8h] [rbp+A8h]
  unsigned int v233; // [rsp+1B0h] [rbp+B0h]
  signed int v234; // [rsp+1B8h] [rbp+B8h]
  int v235; // [rsp+1B8h] [rbp+B8h]

  v232 = aet;
  this->LastX = -1.0e30;
  this->ChainsAbove.Size = 0i64;
  v4 = aet;
  v5 = this;
  v6 = 0i64;
  if ( aet->Size )
  {
    do
    {
      v7 = v4->Pages[v6 >> 4][v6 & 0xF];
      v8 = (v7->flags & 4) == 0;
      v7->posScan = v6;
      if ( !v8 )
      {
        LODWORD(v227) = -1;
        v9 = v5->ChainsAbove.Size >> 4;
        if ( v9 >= v5->ChainsAbove.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::ScanChainType,4,8>::allocPage(
            &v5->ChainsAbove,
            v5->ChainsAbove.Size >> 4);
          v4 = v232;
        }
        v10 = v5->ChainsAbove.Pages[v9];
        a4 = 3i64 * (v5->ChainsAbove.Size & 0xF);
        v11 = v227;
        *((_QWORD *)&v10->chain + a4) = v7;
        *((_QWORD *)&v10->monotone + a4) = 0i64;
        *((_QWORD *)&v10->vertex + a4) = v11;
        ++v5->ChainsAbove.Size;
      }
      ++v6;
    }
    while ( v6 < v4->Size );
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
        v15 = v5->ChainsBelow.Size;
        if ( v12 >= v15 || v13 >= v5->ChainsAbove.Size )
          break;
        v16 = v12 & 0xF;
        v17 = v5->ChainsBelow.Pages[(unsigned __int64)v12 >> 4];
        v18 = v13 & 0xF;
        v19 = v17[v12 & 0xF].chain;
        v20 = v19->posScan;
        v21 = v5->ChainsAbove.Pages[(unsigned __int64)v13 >> 4][v13 & 0xF].chain;
        v230 = v5->ChainsAbove.Pages[(unsigned __int64)v13 >> 4];
        v22 = v21->posScan;
        if ( v22 == v20 )
        {
          v23 = Scaleform::Render::Tessellator::addEventVertex(v5, v21, yb, 0);
          ++v12;
          v230[v13 & 0xF].vertex = v23;
          v17[v16].vertex = v23;
          ++v13;
        }
        else if ( v22 >= v20 )
        {
          ++v12;
          v17[v16].vertex = Scaleform::Render::Tessellator::addEventVertex(v5, v19, yb, 1);
        }
        else
        {
          ++v13;
          v230[v18].vertex = Scaleform::Render::Tessellator::addEventVertex(v5, v21, yb, 1);
        }
      }
      LODWORD(a4) = v13;
      if ( v13 >= v5->ChainsAbove.Size )
        break;
      v24 = v5->ChainsAbove.Pages[(unsigned __int64)v13++ >> 4];
      v24[a4].vertex = Scaleform::Render::Tessellator::addEventVertex(v5, v24[a4 & 0xF].chain, yb, 1);
    }
    if ( v12 >= v15 )
      break;
    v25 = v12 & 0xF;
    v26 = v5->ChainsBelow.Pages[(unsigned __int64)v12 >> 4];
    v27 = Scaleform::Render::Tessellator::addEventVertex(v5, v26[v12++ & 0xF].chain, yb, 1);
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
        v34 = v5->ChainsBelow.Size;
        if ( v33 >= v34 || v31 >= v5->ChainsAbove.Size )
          break;
        v35 = (unsigned int)v33;
        v36 = v33 & 0xF;
        v37 = v5->ChainsBelow.Pages[v35 >> 4];
        v38 = v37[v36].vertex;
        v39 = &v37[v36];
        v212 = &v37[v36];
        v40 = v5->ChainsAbove.Pages[(unsigned __int64)v31 >> 4];
        v41 = v40[v31 & 0xF].vertex;
        v42 = (signed __int64)&v40[v31 & 0xF];
        v43 = 1;
        scan = (Scaleform::Render::Tessellator::ScanChainType *)v42;
        if ( v38 != v41 )
          v43 = 3 - (*(_DWORD *)(*(_QWORD *)v42 + 40i64) < v39->chain->posScan);
        v44 = v43 - 1;
        if ( !v44 )
        {
          if ( v38 == -1 )
          {
            if ( upperBase.numChains )
            {
              Scaleform::Render::Tessellator::connectStarting(v5, v14, &upperBase);
              v31 = v233;
            }
            v106 = v39;
LABEL_241:
            v162 = scan;
            scan->monotone = v106->monotone;
            goto LABEL_242;
          }
          if ( v14 )
          {
            v82 = v14->monotone;
            if ( v82 )
            {
              v83 = v82->lowerBase;
              if ( !v83 )
              {
                v8 = v82->start == 0i64;
                LODWORD(v219) = v38;
                HIDWORD(v219) = v38;
                if ( v8 )
                {
                  v84 = v5->MonoVertices.Size >> 4;
                  if ( v84 >= v5->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                      v5->MonoVertices.Size >> 4);
                  v85 = v5->MonoVertices.Pages[v84];
                  v86 = v5->MonoVertices.Size & 0xF;
                  v29 = 0i64;
                  *(_QWORD *)&v85[v86].srcVer = v219;
                  v85[v86].next = 0i64;
                  v87 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size) - 1) & 0xF];
                  *(_QWORD *)&v82->d.t.numTriangles = -1i64;
                  v82->start = (Scaleform::Render::Tessellator::MonoVertexType *)v87;
                }
                else
                {
                  v88 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v82->d.m.lastIdx >> 4][v82->d.m.lastIdx & 0xF];
                  if ( *(_DWORD *)v88 == v38 )
                    goto LABEL_113;
                  v89 = v5->MonoVertices.Size >> 4;
                  if ( v89 >= v5->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                      v5->MonoVertices.Size >> 4);
                  v90 = v5->MonoVertices.Pages[v89];
                  v91 = v5->MonoVertices.Size & 0xF;
                  v29 = 0i64;
                  *(_QWORD *)&v90[v91].srcVer = v219;
                  v90[v91].next = 0i64;
                  ++v5->MonoVertices.Size;
                  v32 = dst;
                  *(_QWORD *)(v88 + 8) = &v5->MonoVertices.Pages[(v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                                  - 1) & 0xF];
                  v82->d.m.prevIdx2 = v82->d.m.prevIdx1;
                  v82->d.m.prevIdx1 = v82->d.m.lastIdx;
                }
                v82->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
                goto LABEL_113;
              }
              if ( v5->MeshVertices.Pages[(unsigned __int64)(v38 & 0xFFFFFFF) >> 4][v38 & 0xF].y == v83->y )
              {
                v83->vertexRight = v38 & 0xFFFFFFF;
              }
              else if ( v38 >= 0 )
              {
                Scaleform::Render::Tessellator::connectPendingToRight(v5, v14, v38);
              }
              else
              {
                Scaleform::Render::Tessellator::connectPendingToLeft(v5, v14, v38);
              }
            }
          }
LABEL_113:
          if ( v32 )
          {
            v92 = v32->monotone;
            if ( v92 )
            {
              v93 = v92->lowerBase;
              if ( v93 )
              {
                if ( v5->MeshVertices.Pages[(unsigned __int64)(v38 & 0xFFFFFFF) >> 4][v38 & 0xF].y == v93->y )
                {
                  v93->vertexRight = v38 & 0xFFFFFFF;
                }
                else if ( v38 >= 0 )
                {
                  Scaleform::Render::Tessellator::connectPendingToRight(v5, v32, v38);
                }
                else
                {
                  Scaleform::Render::Tessellator::connectPendingToLeft(v5, v32, v38);
                }
                goto LABEL_130;
              }
              v8 = v92->start == 0i64;
              LODWORD(v216) = v38;
              HIDWORD(v216) = v38;
              if ( v8 )
              {
                v94 = v5->MonoVertices.Size >> 4;
                if ( v94 >= v5->MonoVertices.NumPages )
                  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                    (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                    v5->MonoVertices.Size >> 4);
                v95 = v5->MonoVertices.Pages[v94];
                v96 = v5->MonoVertices.Size & 0xF;
                v29 = 0i64;
                *(_QWORD *)&v95[v96].srcVer = v216;
                v95[v96].next = 0i64;
                v97 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                                 - 1) & 0xF];
                *(_QWORD *)&v92->d.t.numTriangles = -1i64;
                v92->start = (Scaleform::Render::Tessellator::MonoVertexType *)v97;
                goto LABEL_129;
              }
              v98 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v92->d.m.lastIdx >> 4][v92->d.m.lastIdx & 0xF];
              if ( *(_DWORD *)v98 != v38 )
              {
                v99 = v5->MonoVertices.Size >> 4;
                if ( v99 >= v5->MonoVertices.NumPages )
                  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                    (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                    v5->MonoVertices.Size >> 4);
                v100 = v5->MonoVertices.Pages[v99];
                v101 = v5->MonoVertices.Size & 0xF;
                v29 = 0i64;
                *(_QWORD *)&v100[v101].srcVer = v216;
                v100[v101].next = 0i64;
                *(_QWORD *)(v98 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                                  - 1) & 0xF];
                v92->d.m.prevIdx2 = v92->d.m.prevIdx1;
                v92->d.m.prevIdx1 = v92->d.m.lastIdx;
LABEL_129:
                v92->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
              }
            }
          }
LABEL_130:
          if ( upperBase.numChains )
            Scaleform::Render::Tessellator::connectStarting(v5, v14, &upperBase);
          v102 = v231;
          v103 = v233;
          v104 = v231 + 1;
          v105 = v233 + 1;
          v235 = v231 + 1;
          v211 = v233 + 1;
          while ( 2 )
          {
            v106 = v212;
LABEL_137:
            v107 = 0i64;
            v108 = 0i64;
            if ( v104 < v5->ChainsBelow.Size )
              v107 = (signed __int64)&v5->ChainsBelow.Pages[(unsigned __int64)v104 >> 4][v104 & 0xF];
            if ( v105 < v5->ChainsAbove.Size )
              v108 = (signed __int64)&v5->ChainsAbove.Pages[(unsigned __int64)v105 >> 4][v105 & 0xF];
            if ( v107 )
            {
              if ( v108 )
              {
                if ( *(_DWORD *)(v107 + 16) == *(_DWORD *)(v108 + 16) )
                  goto LABEL_201;
                goto LABEL_144;
              }
            }
            else
            {
LABEL_144:
              if ( v108 && *(_DWORD *)(v108 + 16) == v38 )
              {
                ++v103;
                v109 = scan;
                dst = scan;
                v233 = v103;
                v211 = v105 + 1;
                v110 = scan;
                scan = &v5->ChainsAbove.Pages[(unsigned __int64)v103 >> 4][v103 & 0xF];
                Scaleform::Render::Tessellator::startMonotone(v5, v110, v38 | 0x80000000);
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
                    if ( v5->MeshVertices.Pages[(unsigned __int64)(v38 & 0xFFFFFFF) >> 4][v38 & 0xF].y == v112->y )
                    {
                      v106 = v212;
                      v112->vertexRight = v38 & 0xFFFFFFF;
                    }
                    else
                    {
                      if ( v38 >= 0 )
                        Scaleform::Render::Tessellator::connectPendingToRight(v5, v109, v38);
                      else
                        Scaleform::Render::Tessellator::connectPendingToLeft(v5, v109, v38);
                      v106 = v212;
                      v104 = v235;
                      v105 = v211;
                    }
                    goto LABEL_136;
                  }
                  v8 = v111->start == 0i64;
                  LODWORD(v221) = v38;
                  HIDWORD(v221) = v38;
                  if ( v8 )
                  {
                    v113 = v5->MonoVertices.Size >> 4;
                    if ( v113 >= v5->MonoVertices.NumPages )
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                        v5->MonoVertices.Size >> 4);
                    v106 = v212;
                    v114 = v5->MonoVertices.Pages[v113];
                    v115 = v5->MonoVertices.Size & 0xF;
                    *(_QWORD *)&v114[v115].srcVer = v221;
                    v114[v115].next = 0i64;
                    v116 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size) - 1) & 0xF];
                    *(_QWORD *)&v111->d.t.numTriangles = -1i64;
                    v111->start = (Scaleform::Render::Tessellator::MonoVertexType *)v116;
                    goto LABEL_200;
                  }
                  v106 = v212;
                  v117 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v111->d.m.lastIdx >> 4][v111->d.m.lastIdx & 0xF];
                  if ( *(_DWORD *)v117 != v38 )
                  {
                    v118 = (signed __int64)&v5->MonoVertices;
                    v119 = v5->MonoVertices.Size >> 4;
                    if ( v119 >= v5->MonoVertices.NumPages )
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                        v5->MonoVertices.Size >> 4);
                    v120 = v5->MonoVertices.Pages[v119];
                    v121 = v221;
LABEL_199:
                    v29 = 0i64;
                    v140 = *(_DWORD *)(v118 + 8) & 0xF;
                    *(_QWORD *)&v120[v140].srcVer = v121;
                    v120[v140].next = 0i64;
                    *(_QWORD *)(v117 + 8) = *(_QWORD *)(*(_QWORD *)(v118 + 32)
                                                      + 8 * ((unsigned __int64)(++*(_QWORD *)(v118 + 8) - 1i64) >> 4))
                                          + 16i64 * ((*(_DWORD *)(v118 + 8) - 1) & 0xF);
                    v111->d.m.prevIdx2 = v111->d.m.prevIdx1;
                    v111->d.m.prevIdx1 = v111->d.m.lastIdx;
                    goto LABEL_200;
                  }
                  goto LABEL_135;
                }
                v106 = v212;
                goto LABEL_136;
              }
            }
            break;
          }
          if ( v107 && *(_DWORD *)(v107 + 16) == v38 )
          {
            ++v102;
            v122 = v106;
            ++v104;
            v231 = v102;
            v235 = v104;
            v106 = &v5->ChainsBelow.Pages[(unsigned __int64)v102 >> 4][v102 & 0xF];
            v212 = &v5->ChainsBelow.Pages[(unsigned __int64)v102 >> 4][v102 & 0xF];
            v123 = v38 | 0x80000000;
            if ( !v122 )
              goto LABEL_137;
            v124 = v122->monotone;
            if ( !v124 )
            {
LABEL_183:
              v111 = v122->monotone;
              v104 = v235;
              v105 = v211;
              if ( v111 )
              {
                v134 = v111->lowerBase;
                if ( v134 )
                {
                  if ( v5->MeshVertices.Pages[(unsigned __int64)(v38 & 0xFFFFFFF) >> 4][v38 & 0xF].y == v134->y )
                  {
                    v134->vertexRight = v38 & 0xFFFFFFF;
                  }
                  else
                  {
                    if ( v38 >= 0 )
                      Scaleform::Render::Tessellator::connectPendingToRight(v5, v122, v38);
                    else
                      Scaleform::Render::Tessellator::connectPendingToLeft(v5, v122, v38);
                    v104 = v235;
                    v105 = v211;
                  }
                  goto LABEL_136;
                }
                v8 = v111->start == 0i64;
                LODWORD(v217) = v38;
                HIDWORD(v217) = v38;
                if ( v8 )
                {
                  v135 = v5->MonoVertices.Size >> 4;
                  if ( v135 >= v5->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                      v5->MonoVertices.Size >> 4);
                  v136 = v5->MonoVertices.Pages[v135];
                  v137 = v5->MonoVertices.Size & 0xF;
                  *(_QWORD *)&v136[v137].srcVer = v217;
                  v136[v137].next = 0i64;
                  v138 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size) - 1) & 0xF];
                  *(_QWORD *)&v111->d.t.numTriangles = -1i64;
                  v111->start = (Scaleform::Render::Tessellator::MonoVertexType *)v138;
LABEL_200:
                  v104 = v235;
                  v105 = v211;
                  v111->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
                }
                else
                {
                  v117 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v111->d.m.lastIdx >> 4][v111->d.m.lastIdx & 0xF];
                  if ( *(_DWORD *)v117 != v38 )
                  {
                    v118 = (signed __int64)&v5->MonoVertices;
                    v139 = v5->MonoVertices.Size >> 4;
                    if ( v139 >= v5->MonoVertices.NumPages )
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                        v5->MonoVertices.Size >> 4);
                    v120 = v5->MonoVertices.Pages[v139];
                    v121 = v217;
                    goto LABEL_199;
                  }
                }
LABEL_135:
                v102 = v231;
              }
LABEL_136:
              v103 = v233;
              goto LABEL_137;
            }
            v125 = v124->lowerBase;
            if ( v125 )
            {
              if ( v5->MeshVertices.Pages[(unsigned __int64)((v38 | 0x80000000) & 0xFFFFFFF) >> 4][v38 & 0xF].y == v125->y )
              {
                v125->vertexRight = v123 & 0xFFFFFFF;
              }
              else if ( v123 >= 0 )
              {
                Scaleform::Render::Tessellator::connectPendingToRight(v5, v122, v123);
              }
              else
              {
                Scaleform::Render::Tessellator::connectPendingToLeft(v5, v122, v123);
              }
              goto LABEL_183;
            }
            v8 = v124->start == 0i64;
            LODWORD(v225) = v38 | 0x80000000;
            HIDWORD(v225) = v38 | 0x80000000;
            if ( v8 )
            {
              v126 = v5->MonoVertices.Size >> 4;
              if ( v126 >= v5->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                  v5->MonoVertices.Size >> 4);
              v127 = v5->MonoVertices.Pages[v126];
              v128 = v5->MonoVertices.Size & 0xF;
              v29 = 0i64;
              *(_QWORD *)&v127[v128].srcVer = v225;
              v127[v128].next = 0i64;
              v129 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                                - 1) & 0xF];
              *(_QWORD *)&v124->d.t.numTriangles = -1i64;
              v124->start = (Scaleform::Render::Tessellator::MonoVertexType *)v129;
              goto LABEL_181;
            }
            v130 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v124->d.m.lastIdx >> 4][v124->d.m.lastIdx & 0xF];
            if ( *(_DWORD *)v130 != v123 )
            {
              v131 = v5->MonoVertices.Size >> 4;
              if ( v131 >= v5->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                  v5->MonoVertices.Size >> 4);
              v132 = v5->MonoVertices.Pages[v131];
              v133 = v5->MonoVertices.Size & 0xF;
              v29 = 0i64;
              *(_QWORD *)&v132[v133].srcVer = v225;
              v132[v133].next = 0i64;
              ++v5->MonoVertices.Size;
              v106 = v212;
              *(_QWORD *)(v130 + 8) = &v5->MonoVertices.Pages[(v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                               - 1) & 0xF];
              v124->d.m.prevIdx2 = v124->d.m.prevIdx1;
              v124->d.m.prevIdx1 = v124->d.m.lastIdx;
LABEL_181:
              v124->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
            }
            v102 = v231;
            goto LABEL_183;
          }
LABEL_201:
          v141 = v38 | 0x80000000;
          if ( v106 )
          {
            v142 = v106->monotone;
            if ( v142 )
            {
              v143 = v142->lowerBase;
              if ( v143 )
              {
                if ( v5->MeshVertices.Pages[(unsigned __int64)((v38 | 0x80000000) & 0xFFFFFFF) >> 4][v38 & 0xF].y == v143->y )
                {
                  v143->vertexRight = v141 & 0xFFFFFFF;
                }
                else if ( v141 >= 0 )
                {
                  Scaleform::Render::Tessellator::connectPendingToRight(v5, v106, v141);
                }
                else
                {
                  Scaleform::Render::Tessellator::connectPendingToLeft(v5, v106, v141);
                }
              }
              else
              {
                v8 = v142->start == 0i64;
                LODWORD(v218) = v38 | 0x80000000;
                HIDWORD(v218) = v38 | 0x80000000;
                if ( v8 )
                {
                  v144 = v5->MonoVertices.Size >> 4;
                  if ( v144 >= v5->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                      v5->MonoVertices.Size >> 4);
                  v145 = v5->MonoVertices.Pages[v144];
                  v146 = v5->MonoVertices.Size & 0xF;
                  v29 = 0i64;
                  *(_QWORD *)&v145[v146].srcVer = v218;
                  v145[v146].next = 0i64;
                  v147 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size) - 1) & 0xF];
                  *(_QWORD *)&v142->d.t.numTriangles = -1i64;
                  v142->start = (Scaleform::Render::Tessellator::MonoVertexType *)v147;
                }
                else
                {
                  v148 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v142->d.m.lastIdx >> 4][v142->d.m.lastIdx & 0xF];
                  if ( *(_DWORD *)v148 == v141 )
                    goto LABEL_218;
                  v149 = v5->MonoVertices.Size >> 4;
                  if ( v149 >= v5->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                      v5->MonoVertices.Size >> 4);
                  v150 = v5->MonoVertices.Pages[v149];
                  v151 = v5->MonoVertices.Size & 0xF;
                  v29 = 0i64;
                  *(_QWORD *)&v150[v151].srcVer = v218;
                  v150[v151].next = 0i64;
                  ++v5->MonoVertices.Size;
                  v106 = v212;
                  *(_QWORD *)(v148 + 8) = &v5->MonoVertices.Pages[(v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size) - 1) & 0xF];
                  v142->d.m.prevIdx2 = v142->d.m.prevIdx1;
                  v142->d.m.prevIdx1 = v142->d.m.lastIdx;
                }
                v142->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
              }
            }
          }
LABEL_218:
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
                  if ( v5->MeshVertices.Pages[(unsigned __int64)(v38 & 0xFFFFFFF) >> 4][v38 & 0xF].y == v153->y )
                  {
                    v31 = v233;
                    v153->vertexRight = v38 & 0xFFFFFFF;
                  }
                  else
                  {
                    if ( v38 >= 0 )
                      Scaleform::Render::Tessellator::connectPendingToRight(v5, dst, v38);
                    else
                      Scaleform::Render::Tessellator::connectPendingToLeft(v5, dst, v38);
                    v31 = v233;
                  }
                  goto LABEL_241;
                }
                v8 = v152->start == 0i64;
                LODWORD(v220) = v38;
                HIDWORD(v220) = v38;
                if ( v8 )
                {
                  v154 = v5->MonoVertices.Size >> 4;
                  if ( v154 >= v5->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                      v5->MonoVertices.Size >> 4);
                  v31 = v233;
                  v155 = v5->MonoVertices.Pages[v154];
                  v156 = v5->MonoVertices.Size & 0xF;
                  *(_QWORD *)&v155[v156].srcVer = v220;
                  v155[v156].next = 0i64;
                  v157 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size) - 1) & 0xF];
                  *(_QWORD *)&v152->d.t.numTriangles = -1i64;
                  v152->start = (Scaleform::Render::Tessellator::MonoVertexType *)v157;
                  v152->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
                  goto LABEL_241;
                }
                v158 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v152->d.m.lastIdx >> 4][v152->d.m.lastIdx & 0xF];
                if ( *(_DWORD *)v158 != v38 )
                {
                  v159 = v5->MonoVertices.Size >> 4;
                  if ( v159 >= v5->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                      v5->MonoVertices.Size >> 4);
                  v160 = v5->MonoVertices.Pages[v159];
                  v161 = v5->MonoVertices.Size & 0xF;
                  *(_QWORD *)&v160[v161].srcVer = v220;
                  v160[v161].next = 0i64;
                  *(_QWORD *)(v158 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size) - 1) & 0xF];
                  v152->d.m.prevIdx2 = v152->d.m.prevIdx1;
                  v152->d.m.prevIdx1 = v152->d.m.lastIdx;
                  v152->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
                }
              }
            }
            v31 = v233;
            goto LABEL_241;
          }
          Scaleform::Render::Tessellator::startMonotone(v5, scan, v141);
          v162 = scan;
          v31 = v233;
LABEL_242:
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
                  if ( v5->MeshVertices.Pages[(unsigned __int64)((v39->vertex | 0x80000000) & 0xFFFFFFF) >> 4][v39->vertex & 0xF].y == v58->y )
                  {
                    v58->vertexRight = v57 & 0xFFFFFFF;
                  }
                  else if ( v57 >= 0 )
                  {
                    Scaleform::Render::Tessellator::connectPendingToRight(v5, v39, v57);
                  }
                  else
                  {
                    Scaleform::Render::Tessellator::connectPendingToLeft(v5, v39, v57);
                  }
                  goto LABEL_62;
                }
                v8 = v56->start == 0i64;
                LODWORD(v229) = v39->vertex | 0x80000000;
                HIDWORD(v229) = v57;
                if ( v8 )
                {
                  v59 = v5->MonoVertices.Size >> 4;
                  if ( v59 >= v5->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                      v5->MonoVertices.Size >> 4);
                  v60 = v5->MonoVertices.Pages[v59];
                  v61 = v5->MonoVertices.Size & 0xF;
                  *(_QWORD *)&v60[v61].srcVer = v229;
                  v60[v61].next = 0i64;
                  v62 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size) - 1) & 0xF];
                  *(_QWORD *)&v56->d.t.numTriangles = -1i64;
                  v56->start = (Scaleform::Render::Tessellator::MonoVertexType *)v62;
LABEL_61:
                  v39 = v212;
                  v56->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
                  goto LABEL_62;
                }
                v63 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v56->d.m.lastIdx >> 4][v56->d.m.lastIdx & 0xF];
                if ( *(_DWORD *)v63 != v57 )
                {
                  v64 = v5->MonoVertices.Size >> 4;
                  if ( v64 >= v5->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                      v5->MonoVertices.Size >> 4);
                  v65 = v5->MonoVertices.Pages[v64];
                  v66 = v5->MonoVertices.Size & 0xF;
                  v29 = 0i64;
                  *(_QWORD *)&v65[v66].srcVer = v229;
                  v65[v66].next = 0i64;
                  *(_QWORD *)(v63 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size) - 1) & 0xF];
                  v56->d.m.prevIdx2 = v56->d.m.prevIdx1;
                  v56->d.m.prevIdx1 = v56->d.m.lastIdx;
                  goto LABEL_61;
                }
              }
LABEL_62:
              if ( upperBase.numChains )
                Scaleform::Render::Tessellator::connectStarting(v5, v14, &upperBase);
              Scaleform::Render::Tessellator::addPendingEnd(v5, v32, v39, yb);
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
              if ( v5->MeshVertices.Pages[(unsigned __int64)(v38 & 0xFFFFFFF) >> 4][v38 & 0xF].y == v47->y )
              {
                v47->vertexRight = v38 & 0xFFFFFFF;
              }
              else if ( v38 >= 0 )
              {
                Scaleform::Render::Tessellator::connectPendingToRight(v5, v14, v38);
              }
              else
              {
                Scaleform::Render::Tessellator::connectPendingToLeft(v5, v14, v38);
              }
              goto LABEL_46;
            }
            v8 = v46->start == 0i64;
            LODWORD(v228) = v38;
            HIDWORD(v228) = v38;
            if ( v8 )
            {
              v48 = v5->MonoVertices.Size >> 4;
              if ( v48 >= v5->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                  v5->MonoVertices.Size >> 4);
              v49 = v5->MonoVertices.Pages[v48];
              v50 = v5->MonoVertices.Size & 0xF;
              *(_QWORD *)&v49[v50].srcVer = v228;
              v49[v50].next = 0i64;
              v51 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                               - 1) & 0xF];
              *(_QWORD *)&v46->d.t.numTriangles = -1i64;
              v46->start = (Scaleform::Render::Tessellator::MonoVertexType *)v51;
            }
            else
            {
              v52 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v46->d.m.lastIdx >> 4][v46->d.m.lastIdx & 0xF];
              if ( *(_DWORD *)v52 == v38 )
              {
LABEL_45:
                v39 = v212;
                goto LABEL_46;
              }
              v53 = v5->MonoVertices.Size >> 4;
              if ( v53 >= v5->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                  v5->MonoVertices.Size >> 4);
              v54 = v5->MonoVertices.Pages[v53];
              v55 = v5->MonoVertices.Size & 0xF;
              v29 = 0i64;
              *(_QWORD *)&v54[v55].srcVer = v228;
              v54[v55].next = 0i64;
              *(_QWORD *)(v52 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                                - 1) & 0xF];
              v46->d.m.prevIdx2 = v46->d.m.prevIdx1;
              v46->d.m.prevIdx1 = v46->d.m.lastIdx;
            }
            v46->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
            goto LABEL_45;
          }
        }
        else
        {
          if ( !v14 || (v67 = v14->monotone) == 0i64 || !v67->style )
          {
            if ( !v32 )
              goto LABEL_93;
            v72 = v32->monotone;
            if ( !v72 )
              goto LABEL_93;
            v73 = v72->lowerBase;
            if ( v73 )
            {
              if ( v5->MeshVertices.Pages[(unsigned __int64)(v41 & 0xFFFFFFF) >> 4][v41 & 0xF].y == v73->y )
              {
                v73->vertexRight = v41 & 0xFFFFFFF;
              }
              else if ( v41 >= 0 )
              {
                Scaleform::Render::Tessellator::connectPendingToRight(v5, v32, v41);
              }
              else
              {
                Scaleform::Render::Tessellator::connectPendingToLeft(v5, v32, v41);
              }
              goto LABEL_93;
            }
            v8 = v72->start == 0i64;
            LODWORD(v223) = v41;
            HIDWORD(v223) = v41;
            if ( v8 )
            {
              v74 = v5->MonoVertices.Size >> 4;
              if ( v74 >= v5->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                  v5->MonoVertices.Size >> 4);
              v75 = v5->MonoVertices.Pages[v74];
              v76 = v5->MonoVertices.Size & 0xF;
              *(_QWORD *)&v75[v76].srcVer = v223;
              v75[v76].next = 0i64;
              v77 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                               - 1) & 0xF];
              *(_QWORD *)&v72->d.t.numTriangles = -1i64;
              v72->start = (Scaleform::Render::Tessellator::MonoVertexType *)v77;
              goto LABEL_92;
            }
            v78 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v72->d.m.lastIdx >> 4][v72->d.m.lastIdx & 0xF];
            if ( *(_DWORD *)v78 != v41 )
            {
              v79 = v5->MonoVertices.Size >> 4;
              if ( v79 >= v5->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                  v5->MonoVertices.Size >> 4);
              v80 = v5->MonoVertices.Pages[v79];
              v81 = v5->MonoVertices.Size & 0xF;
              v29 = 0i64;
              *(_QWORD *)&v80[v81].srcVer = v223;
              v80[v81].next = 0i64;
              *(_QWORD *)(v78 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                                - 1) & 0xF];
              v72->d.m.prevIdx2 = v72->d.m.prevIdx1;
              v72->d.m.prevIdx1 = v72->d.m.lastIdx;
LABEL_92:
              v72->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
            }
LABEL_93:
            Scaleform::Render::Tessellator::startMonotone(v5, scan, scan->vertex | 0x80000000);
            v28 = v234;
            v31 = v233;
            goto LABEL_94;
          }
          if ( upperBase.numChains )
          {
            ++upperBase.numChains;
          }
          else
          {
            v68 = *(_QWORD *)v42;
            upperBase.firstChain = v31;
            upperBase.numChains = 1;
            v69 = *(unsigned __int16 *)(v68 + 30);
            upperBase.leftAbove = v28;
            upperBase.styleLeft = v69;
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
LABEL_94:
          v30 = v231;
          ++v31;
          v32 = scan;
          dst = scan;
          v233 = v31;
        }
      }
      if ( v31 >= v5->ChainsAbove.Size )
        break;
      v163 = v5->ChainsAbove.Pages[(unsigned __int64)v31 >> 4];
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
            if ( v5->MeshVertices.Pages[(unsigned __int64)(v164 & 0xFFFFFFF) >> 4][v164 & 0xF].y == v166->y )
            {
              v166->vertexRight = v164 & 0xFFFFFFF;
            }
            else if ( v164 >= 0 )
            {
              Scaleform::Render::Tessellator::connectPendingToRight(v5, dst, v164);
            }
            else
            {
              Scaleform::Render::Tessellator::connectPendingToLeft(v5, dst, v164);
            }
          }
          else
          {
            v8 = v165->start == 0i64;
            LODWORD(v222) = v163[v31 & 0xF].vertex;
            HIDWORD(v222) = v164;
            if ( v8 )
            {
              v167 = v5->MonoVertices.Size >> 4;
              if ( v167 >= v5->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                  v5->MonoVertices.Size >> 4);
              v168 = v5->MonoVertices.Pages[v167];
              v169 = v5->MonoVertices.Size & 0xF;
              *(_QWORD *)&v168[v169].srcVer = v222;
              v168[v169].next = 0i64;
              v170 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                                - 1) & 0xF];
              *(_QWORD *)&v165->d.t.numTriangles = -1i64;
              v165->start = (Scaleform::Render::Tessellator::MonoVertexType *)v170;
            }
            else
            {
              v171 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v165->d.m.lastIdx >> 4][v165->d.m.lastIdx & 0xF];
              if ( *(_DWORD *)v171 == v164 )
                goto LABEL_261;
              v172 = v5->MonoVertices.Size >> 4;
              if ( v172 >= v5->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                  v5->MonoVertices.Size >> 4);
              v173 = v5->MonoVertices.Pages[v172];
              v174 = v5->MonoVertices.Size & 0xF;
              v29 = 0i64;
              *(_QWORD *)&v173[v174].srcVer = v222;
              v173[v174].next = 0i64;
              *(_QWORD *)(v171 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                                 - 1) & 0xF];
              v165->d.m.prevIdx2 = v165->d.m.prevIdx1;
              v165->d.m.prevIdx1 = v165->d.m.lastIdx;
            }
            v165->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
          }
        }
      }
LABEL_261:
      Scaleform::Render::Tessellator::startMonotone(v5, v32, v32->vertex | 0x80000000);
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
      v177 = v5->ChainsBelow.Pages[v175];
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
            if ( v5->MeshVertices.Pages[(unsigned __int64)(v178 & 0xFFFFFFF) >> 4][v178 & 0xF].y == v181->y )
            {
              v181->vertexRight = v178 & 0xFFFFFFF;
            }
            else if ( v178 >= 0 )
            {
              Scaleform::Render::Tessellator::connectPendingToRight(v5, v14, v178);
            }
            else
            {
              Scaleform::Render::Tessellator::connectPendingToLeft(v5, v14, v178);
            }
          }
          else
          {
            v8 = v180->start == 0i64;
            LODWORD(v224) = v177[v176].vertex;
            HIDWORD(v224) = v178;
            if ( v8 )
            {
              v182 = v5->MonoVertices.Size >> 4;
              if ( v182 >= v5->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                  v5->MonoVertices.Size >> 4);
              v183 = v5->MonoVertices.Pages[v182];
              v184 = v5->MonoVertices.Size & 0xF;
              *(_QWORD *)&v183[v184].srcVer = v224;
              v183[v184].next = 0i64;
              v185 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                                - 1) & 0xF];
              *(_QWORD *)&v180->d.t.numTriangles = -1i64;
              v180->start = (Scaleform::Render::Tessellator::MonoVertexType *)v185;
            }
            else
            {
              v186 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v180->d.m.lastIdx >> 4][v180->d.m.lastIdx & 0xF];
              if ( *(_DWORD *)v186 == v178 )
                goto LABEL_280;
              v187 = v5->MonoVertices.Size >> 4;
              if ( v187 >= v5->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
                  v5->MonoVertices.Size >> 4);
              v188 = v5->MonoVertices.Pages[v187];
              v189 = v5->MonoVertices.Size & 0xF;
              v29 = 0i64;
              *(_QWORD *)&v188[v189].srcVer = v224;
              v188[v189].next = 0i64;
              *(_QWORD *)(v186 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                                 - 1) & 0xF];
              v180->d.m.prevIdx2 = v180->d.m.prevIdx1;
              v180->d.m.prevIdx1 = v180->d.m.lastIdx;
            }
            v180->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
          }
        }
      }
LABEL_280:
      v190 = v179->monotone;
      v191 = v179->vertex | 0x80000000;
      if ( v190 )
      {
        v192 = v190->lowerBase;
        if ( v192 )
        {
          if ( v5->MeshVertices.Pages[(unsigned __int64)((v179->vertex | 0x80000000) & 0xFFFFFFF) >> 4][v179->vertex & 0xF].y == v192->y )
          {
            v192->vertexRight = v191 & 0xFFFFFFF;
          }
          else if ( v191 >= 0 )
          {
            Scaleform::Render::Tessellator::connectPendingToRight(v5, v179, v191);
          }
          else
          {
            Scaleform::Render::Tessellator::connectPendingToLeft(v5, v179, v191);
          }
          goto LABEL_296;
        }
        v8 = v190->start == 0i64;
        LODWORD(v226) = v179->vertex | 0x80000000;
        HIDWORD(v226) = v191;
        if ( v8 )
        {
          v193 = v5->MonoVertices.Size >> 4;
          if ( v193 >= v5->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
              v5->MonoVertices.Size >> 4);
          v194 = v5->MonoVertices.Pages[v193];
          v195 = v5->MonoVertices.Size & 0xF;
          *(_QWORD *)&v194[v195].srcVer = v226;
          v194[v195].next = 0i64;
          v196 = (signed __int64)&v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                            - 1) & 0xF];
          *(_QWORD *)&v190->d.t.numTriangles = -1i64;
          v190->start = (Scaleform::Render::Tessellator::MonoVertexType *)v196;
          goto LABEL_295;
        }
        v197 = (signed __int64)&v5->MonoVertices.Pages[(unsigned __int64)v190->d.m.lastIdx >> 4][v190->d.m.lastIdx & 0xF];
        if ( *(_DWORD *)v197 != v191 )
        {
          v198 = v5->MonoVertices.Size >> 4;
          if ( v198 >= v5->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->MonoVertices,
              v5->MonoVertices.Size >> 4);
          v199 = v5->MonoVertices.Pages[v198];
          v200 = v5->MonoVertices.Size & 0xF;
          v29 = 0i64;
          *(_QWORD *)&v199[v200].srcVer = v226;
          v199[v200].next = 0i64;
          *(_QWORD *)(v197 + 8) = &v5->MonoVertices.Pages[(++v5->MonoVertices.Size - 1) >> 4][(LODWORD(v5->MonoVertices.Size)
                                                                                             - 1) & 0xF];
          v190->d.m.prevIdx2 = v190->d.m.prevIdx1;
          v190->d.m.prevIdx1 = v190->d.m.lastIdx;
LABEL_295:
          v190->d.m.lastIdx = LODWORD(v5->MonoVertices.Size) - 1;
        }
      }
LABEL_296:
      if ( upperBase.numChains )
        Scaleform::Render::Tessellator::connectStarting(v5, v14, &upperBase);
      Scaleform::Render::Tessellator::addPendingEnd(v5, dst, v179, yb);
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
  v8 = v5->ChainsAbove.Size == 0;
  v5->ChainsBelow.Size = 0i64;
  v201 = 0i64;
  if ( !v8 )
  {
    do
    {
      v202 = v5->ChainsBelow.Size >> 4;
      v203 = v201 & 0xF;
      v204 = v5->ChainsAbove.Pages[v201 >> 4];
      if ( v202 >= v5->ChainsBelow.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::ScanChainType,4,8>::allocPage(
          &v5->ChainsBelow,
          v5->ChainsBelow.Size >> 4);
      ++v201;
      v205 = v5->ChainsBelow.Pages[v202];
      v206 = v5->ChainsBelow.Size & 0xF;
      v205[v206].chain = v204[v203].chain;
      v205[v206].monotone = v204[v203].monotone;
      *(_QWORD *)&v205[v206].vertex = *(_QWORD *)&v204[v203].vertex;
      ++v5->ChainsBelow.Size;
    }
    while ( v201 < v5->ChainsAbove.Size );
    v29 = 0i64;
  }
  if ( v232->Size )
  {
    do
    {
      v207 = v29 >> 4;
      v208 = v29++ & 0xF;
      v209 = v232->Pages[v207][v208];
      v210 = v209->leftAbove;
      v209->flags &= 0xFFEFu;
      v209->leftBelow = v210;
      v209->rightBelow = v209->rightAbove;
    }
    while ( v29 < v232->Size );
  }
}

// File Line: 1809
// RVA: 0x9F3BA0
void __fastcall Scaleform::Render::Tessellator::swapChains(Scaleform::Render::Tessellator *this, unsigned int startIn, unsigned int endIn)
{
  Scaleform::Render::Tessellator *v3; // rbx
  __int64 v4; // rsi
  unsigned __int64 v5; // rdi
  signed __int64 v6; // rax
  unsigned __int64 v7; // r8
  signed __int64 v8; // rcx
  Scaleform::Render::Tessellator::IntersectionType *v9; // rax
  unsigned int **v10; // r8
  Scaleform::Render::Tessellator::IntersectionType *v11; // r11
  unsigned int v12; // edx
  unsigned __int64 v13; // r10
  signed __int64 v14; // r9
  Scaleform::Render::Tessellator::MonoChainType *v15; // rax
  signed __int64 v16; // rdx
  unsigned __int64 v17; // r8
  Scaleform::Render::Tessellator::MonoChainType *v18; // rax
  Scaleform::Render::Tessellator::MonoChainType ***v19; // rcx
  Scaleform::Render::Tessellator::MonoChainType **v20; // r8
  Scaleform::Render::Tessellator::MonoChainType **v21; // rcx
  Scaleform::Render::Tessellator::MonoChainType **v22; // r8
  Scaleform::Render::Tessellator::MonoChainType *v23; // rdx
  unsigned int **v24; // rdx
  unsigned int *v25; // r8
  __int64 v26; // r9
  unsigned int *v27; // rax

  v3 = this;
  if ( startIn < endIn )
  {
    v4 = endIn - startIn;
    v5 = startIn;
    do
    {
      v6 = v5 & 0xF;
      v7 = v5++ >> 4;
      v8 = v6;
      v9 = v3->Intersections.Pages[v7];
      v10 = v3->InteriorOrder.Pages;
      v11 = &v9[v8];
      v12 = v10[(unsigned __int64)v9[v8].pos1 >> 4][v9[v8].pos1 & 0xF];
      LODWORD(v10) = v10[(unsigned __int64)v11->pos2 >> 4][v11->pos2 & 0xF];
      v13 = (unsigned __int64)v12 >> 4;
      v14 = v12 & 0xF;
      v15 = v3->InteriorChains.Pages[v13][v14];
      v15->flags |= 0x10u;
      v16 = (unsigned __int8)v10 & 0xF;
      v17 = (unsigned __int64)(unsigned int)v10 >> 4;
      v18 = v3->InteriorChains.Pages[v17][v16];
      v18->flags |= 0x10u;
      v19 = v3->InteriorChains.Pages;
      v20 = v19[v17];
      v21 = v19[v13];
      v22 = &v20[v16];
      v23 = v21[v14];
      v21[v14] = *v22;
      *v22 = v23;
      v24 = v3->InteriorOrder.Pages;
      v25 = &v24[(unsigned __int64)v11->pos2 >> 4][v11->pos2 & 0xF];
      v26 = v11->pos1 & 0xF;
      v27 = v24[(unsigned __int64)v11->pos1 >> 4];
      LODWORD(v24) = v27[v26];
      v27[v26] = *v25;
      *v25 = (unsigned int)v24;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 1825
// RVA: 0x9ED640
int Scaleform::Render::Tessellator::processInterior(...)
{
  unsigned __int64 v4; // r8
  unsigned int v5; // ebx
  unsigned int v6; // esi
  Scaleform::Render::Tessellator *v7; // rdi
  float v8; // xmm8_4
  __int128 v9; // xmm7
  unsigned __int64 v10; // rdx
  unsigned __int64 v11; // r8
  unsigned __int64 i; // rcx
  __int128 v13; // xmm6
  unsigned int v14; // esi

  v4 = this->Intersections.Size;
  v5 = 0;
  v6 = perceiveFlag;
  v7 = this;
  v8 = *(float *)&yb;
  v9 = yb;
  if ( v4 )
  {
    v10 = 0i64;
    do
    {
      v9 = LODWORD(this->Intersections.Pages[v10 >> 4][v10 & 0xF].y);
      if ( *(float *)&v9 > *(float *)&yb )
        break;
      ++v5;
      v6 = 1;
      v10 = v5;
    }
    while ( v5 < v4 );
  }
  Scaleform::Render::Tessellator::swapChains(this, 0, v5);
  if ( v6 )
    Scaleform::Render::Tessellator::perceiveStyles(v7, &v7->InteriorChains);
  v11 = v7->Intersections.Size;
  for ( i = v5; v5 < v11; v9 = v13 )
  {
    v13 = v9;
    v14 = v5;
    if ( i < v11 )
    {
      do
      {
        v13 = LODWORD(v7->Intersections.Pages[i >> 4][i & 0xF].y);
        if ( *(float *)&v13 > *(float *)&v9 )
          break;
        i = ++v5;
      }
      while ( v5 < v11 );
    }
    Scaleform::Render::Tessellator::perceiveStyles(v7, &v7->InteriorChains);
    Scaleform::Render::Tessellator::sweepScanbeam(v7, &v7->InteriorChains, v8);
    Scaleform::Render::Tessellator::swapChains(v7, v14, v5);
    v11 = v7->Intersections.Size;
    i = v5;
    v8 = *(float *)&v9;
  }
  Scaleform::Render::Tessellator::perceiveStyles(v7, &v7->ActiveChains);
  if ( *(float *)&v9 < yTop )
    Scaleform::Render::Tessellator::sweepScanbeam(v7, &v7->ActiveChains, *(float *)&v9);
}

// File Line: 1878
// RVA: 0x9E9CA0
void __fastcall Scaleform::Render::Tessellator::monotonize(Scaleform::Render::Tessellator *this)
{
  Scaleform::Render::Tessellator *v1; // rdi
  unsigned __int64 v2; // rbp
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // rdx
  unsigned __int64 v5; // r8
  float v6; // xmm2_4
  unsigned int **v7; // rbx
  __int64 v8; // r9
  Scaleform::Render::Tessellator::SrcVertexType *v9; // r10
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // rbp
  void *v14; // r14
  Scaleform::Render::Tessellator::MonoChainType **v15; // rdx
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // r9
  unsigned __int64 v18; // rdx
  unsigned __int64 v19; // r8
  unsigned int v20; // er15
  unsigned int v21; // ebx
  unsigned int v22; // edx
  unsigned __int64 v23; // rcx
  __int64 v24; // rdx
  float v25; // xmm7_4
  unsigned __int64 v26; // rax
  float v27; // xmm6_4
  unsigned __int64 v28; // rsi
  unsigned __int64 v29; // rcx
  unsigned int v30; // er9
  unsigned int v31; // eax
  char v32; // bp
  unsigned __int64 v33; // rdx
  unsigned __int64 v34; // r8
  Scaleform::Render::Tessellator::MonoChainType ***v35; // r9
  Scaleform::Render::Tessellator::MonoChainType *v36; // r10
  unsigned __int64 v37; // rax
  unsigned __int64 v38; // rcx

  v1 = this;
  if ( this->SrcVertices.Size )
  {
    Scaleform::Render::ArrayUnsafe<int>::Resize(&this->StyleCounts, this->MaxStyle + 1);
    v2 = 0i64;
    if ( v1->SrcVertices.Size )
    {
      do
      {
        v3 = v1->Scanbeams.Size >> 4;
        if ( v3 >= v1->Scanbeams.NumPages )
          Scaleform::Render::ArrayPaged<unsigned int,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)&v1->Scanbeams,
            v1->Scanbeams.Size >> 4);
        v1->Scanbeams.Pages[v3][v1->Scanbeams.Size & 0xF] = v2;
        ++v1->Scanbeams.Size;
        ++v2;
      }
      while ( v2 < v1->SrcVertices.Size );
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<unsigned int,4,16>,Scaleform::Render::Tessellator::CmpScanbeams>(
      &v1->Scanbeams,
      0i64,
      v1->Scanbeams.Size,
      (Scaleform::Render::Tessellator::CmpScanbeams)&v1->SrcVertices);
    v4 = 0i64;
    v5 = 0i64;
    v6 = FLOAT_N1_0e30;
    if ( v1->Scanbeams.Size )
    {
      do
      {
        v7 = v1->Scanbeams.Pages;
        v8 = v7[v4 >> 4][v4 & 0xF] & 0xF;
        v9 = v1->SrcVertices.Pages[(unsigned __int64)v7[v4 >> 4][v4 & 0xF] >> 4];
        if ( (float)(v9[v8].y - v6) <= (float)(COERCE_FLOAT(LODWORD(v9[v8].y) & _xmm) * v1->Epsilon) )
        {
          v9[v8].y = v6;
        }
        else
        {
          v10 = v5 >> 4;
          v11 = v5++ & 0xF;
          v7[v10][v11] = v7[v4 >> 4][v4 & 0xF];
          v6 = v9[v8].y;
        }
        ++v4;
      }
      while ( v4 < v1->Scanbeams.Size );
    }
    if ( v5 < v1->Scanbeams.Size )
      v1->Scanbeams.Size = v5;
    v12 = 0i64;
    if ( v1->Paths.Size )
    {
      do
      {
        Scaleform::Render::Tessellator::decomposePath(v1, &v1->Paths.Pages[v12 >> 4][v12 & 0xF]);
        ++v12;
      }
      while ( v12 < v1->Paths.Size );
    }
    v13 = v1->MonoChains.Size;
    if ( v13 > v1->MonoChainsSorted.Size )
    {
      v14 = Scaleform::Render::LinearHeap::Alloc(v1->MonoChainsSorted.pHeap, 8 * v13);
      memset(v14, 0, 8 * v13);
      v15 = v1->MonoChainsSorted.Array;
      if ( v15 )
      {
        v16 = v1->MonoChainsSorted.Size;
        if ( v16 )
          memmove(v14, v15, 8 * v16);
      }
      v1->MonoChainsSorted.Array = (Scaleform::Render::Tessellator::MonoChainType **)v14;
    }
    v17 = 0i64;
    v1->MonoChainsSorted.Size = v13;
    if ( v1->MonoChains.Size )
    {
      do
      {
        v18 = v17 & 0xF;
        v19 = v17++ >> 4;
        v1->MonoChainsSorted.Array[v17 - 1] = &v1->MonoChains.Pages[v19][v18];
      }
      while ( v17 < v1->MonoChains.Size );
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayUnsafe<Scaleform::Render::Tessellator::MonoChainType *>,bool (*)(Scaleform::Render::Tessellator::MonoChainType const *,Scaleform::Render::Tessellator::MonoChainType const *)>(
      &v1->MonoChainsSorted,
      0i64,
      v1->MonoChainsSorted.Size,
      Scaleform::Render::Hairliner::cmpMonoChains);
    v20 = 0;
    v21 = 0;
    v22 = **v1->Scanbeams.Pages;
    v23 = v22;
    v24 = v22 & 0xF;
    v23 >>= 4;
    v25 = v1->SrcVertices.Pages[v23][v24].y;
    v26 = v1->Scanbeams.Size;
    v27 = v1->SrcVertices.Pages[v23][v24].y;
    if ( v26 )
    {
      v28 = 0i64;
      do
      {
        if ( ++v20 < v26 )
          v25 = v1->SrcVertices.Pages[(unsigned __int64)v1->Scanbeams.Pages[(unsigned __int64)v20 >> 4][v20 & 0xF] >> 4][v1->Scanbeams.Pages[(unsigned __int64)v20 >> 4][v20 & 0xF] & 0xF].y;
        v29 = v1->MonoChainsSorted.Size;
        v30 = v21;
        if ( v28 < v29 )
        {
          do
          {
            if ( v27 < v1->MonoChainsSorted.Array[v28]->ySort )
              break;
            v28 = ++v21;
          }
          while ( v21 < v29 );
        }
        v31 = Scaleform::Render::Tessellator::nextScanbeam(v1, v27, v25, v30, v21 - v30);
        v32 = v31;
        if ( v1->Intersections.Size )
        {
          Scaleform::Render::Tessellator::processInterior(v1, v27, v25, v31);
        }
        else
        {
          if ( v31 )
            Scaleform::Render::Tessellator::perceiveStyles(v1, &v1->ActiveChains);
          Scaleform::Render::Tessellator::sweepScanbeam(v1, &v1->ActiveChains, v27);
        }
        if ( v32 & 2 )
        {
          v33 = 0i64;
          v34 = 0i64;
          if ( v1->ActiveChains.Size )
          {
            do
            {
              v35 = v1->ActiveChains.Pages;
              v36 = v35[v33 >> 4][v33 & 0xF];
              if ( !(v36->flags & 2) )
              {
                v37 = v34 >> 4;
                v38 = v34++ & 0xF;
                v35[v37][v38] = v36;
              }
              ++v33;
            }
            while ( v33 < v1->ActiveChains.Size );
          }
          if ( v34 < v1->ActiveChains.Size )
            v1->ActiveChains.Size = v34;
        }
        v26 = v1->Scanbeams.Size;
        v27 = v25;
      }
      while ( v20 < v26 );
    }
  }
}

// File Line: 1980
// RVA: 0x9F0AA0
__int64 __fastcall Scaleform::Render::Tessellator::setMesh(Scaleform::Render::Tessellator *this, unsigned int style)
{
  __int64 v2; // rsi
  Scaleform::Render::Tessellator *v3; // rbx
  unsigned __int16 *v5; // r10
  unsigned int v6; // er12
  unsigned __int64 v7; // r15
  Scaleform::Render::TessMesh *v8; // rax
  signed __int64 v9; // rcx

  v2 = style;
  v3 = this;
  if ( !this->HasComplexFill )
    return 0i64;
  v5 = &this->StyleMatrix.Array[style * (this->StyleMatrix.Size + 1)];
  if ( *v5 == -1 )
  {
    if ( (1 << (style & 0x1F)) & this->ComplexFlags.Array[(unsigned __int64)style >> 5] )
    {
      *v5 = this->Meshes.Size;
      v6 = this->Meshes.Size;
      v7 = this->Meshes.Size >> 4;
      if ( v7 >= this->Meshes.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::allocPage(&this->Meshes, this->Meshes.Size >> 4);
      v8 = v3->Meshes.Pages[v7];
      v9 = v3->Meshes.Size & 0xF;
      v8[v9].MeshIdx = v6;
      v8[v9].Style1 = v2;
      v8[v9].Style2 = v2;
      v8[v9].Flags1 = 0x8000;
      *(_QWORD *)&v8[v9].Flags2 = 0x8000i64;
      v8[v9].VertexCount = 0;
      ++v3->Meshes.Size;
      Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(&v3->MeshTriangles);
    }
    else
    {
      *v5 = 0;
    }
  }
  return v3->StyleMatrix.Array[v2 * (v3->StyleMatrix.Size + 1)];
}

// File Line: 2019
// RVA: 0x9F0BE0
__int64 __fastcall Scaleform::Render::Tessellator::setMesh(Scaleform::Render::Tessellator *this, unsigned int style1, __int64 style2)
{
  unsigned int v3; // er12
  unsigned __int64 v4; // r13
  Scaleform::Render::Tessellator *v5; // rbx
  unsigned __int64 v7; // r9
  unsigned __int16 *v8; // r10
  __int64 v9; // rdi
  unsigned int *v10; // rdx
  int v11; // ebp
  int v12; // esi
  unsigned int v13; // eax
  unsigned __int16 v14; // r14
  unsigned __int16 v15; // r8
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4> *v16; // r8
  unsigned int v17; // eax
  unsigned __int64 v18; // rax
  Scaleform::Render::TessMesh *v19; // rax
  signed __int64 v20; // rcx
  unsigned __int16 *v21; // rax
  signed __int64 v22; // rcx
  unsigned __int16 *v23; // rax
  signed __int64 v24; // rcx
  unsigned __int64 v25; // [rsp+20h] [rbp-48h]
  unsigned int v26; // [rsp+70h] [rbp+8h]
  unsigned int v27; // [rsp+88h] [rbp+20h]

  v3 = style2;
  v4 = style1;
  v5 = this;
  if ( !this->HasComplexFill )
    return 0i64;
  v7 = this->StyleMatrix.Size;
  v8 = this->StyleMatrix.Array;
  v9 = style1;
  style2 = (unsigned int)style2;
  if ( v8[(unsigned int)style2 + style1 * this->StyleMatrix.Size] == -1 )
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
      v15 = v8[(unsigned int)v4 * (v7 + 1)];
      if ( v12 || v15 == -1 || this->Meshes.Pages[(unsigned __int64)v15 >> 4][v15 & 0xF].Flags2 & 0x8000 )
      {
        v16 = &this->Meshes;
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
          v16 = &v5->Meshes;
        }
        v19 = v16->Pages[v25];
        v20 = v16->Size & 0xF;
        v19[v20].MeshIdx = v26;
        v19[v20].Style1 = v4;
        v19[v20].Style2 = v27;
        v19[v20].Flags1 = v11;
        v19[v20].Flags2 = v12;
        *(_QWORD *)&v19[v20].StartVertex = 0i64;
        ++v16->Size;
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(&v5->MeshTriangles);
      }
      else
      {
        v14 = v8[(unsigned int)v4 * (v7 + 1)];
      }
      style2 = v3;
      v5->StyleMatrix.Array[v3 + v5->StyleMatrix.Size * (unsigned int)v4] = v14;
      v5->StyleMatrix.Array[(unsigned int)v4 + v5->StyleMatrix.Size * v3] = v14;
      v21 = v5->StyleMatrix.Array;
      v22 = (unsigned int)v4 * (v5->StyleMatrix.Size + 1);
      if ( v5->InvasiveMerge )
      {
        if ( v21[v22] == -1 )
          v21[v22] = v14;
        v23 = v5->StyleMatrix.Array;
        v24 = v3 * (v5->StyleMatrix.Size + 1);
        if ( v23[v24] == -1 )
          v23[v24] = v14;
      }
      else if ( v21[v22] == -1 && v11 && !v12 )
      {
        v21[v22] = v14;
      }
    }
    else
    {
      v8[v4 * (v7 + 1)] = 0;
      this->StyleMatrix.Array[(unsigned int)style2 * (this->StyleMatrix.Size + 1)] = 0;
      this->StyleMatrix.Array[(unsigned int)style2 + this->StyleMatrix.Size * v4] = 0;
      this->StyleMatrix.Array[v4 + this->StyleMatrix.Size * (unsigned int)style2] = 0;
    }
  }
  return v5->StyleMatrix.Array[style2 + v5->StyleMatrix.Size * v9];
}

// File Line: 2099
// RVA: 0x989240
void __fastcall Scaleform::Render::Tessellator::GetMesh(Scaleform::Render::Tessellator *this, unsigned int meshIdx, Scaleform::Render::TessMesh *mesh)
{
  Scaleform::Render::TessMesh *v3; // rcx

  v3 = &this->Meshes.Pages[(unsigned __int64)meshIdx >> 4][meshIdx & 0xF];
  mesh->MeshIdx = v3->MeshIdx;
  mesh->Style1 = v3->Style1;
  mesh->Style2 = v3->Style2;
  mesh->Flags1 = v3->Flags1;
  mesh->Flags2 = v3->Flags2;
  mesh->StartVertex = v3->StartVertex;
  mesh->VertexCount = v3->VertexCount;
  mesh->StartVertex = 0;
}

// File Line: 2106
// RVA: 0x98F260
__int64 __fastcall Scaleform::Render::Tessellator::GetVertices(Scaleform::Render::Tessellator *this, Scaleform::Render::TessMesh *mesh, Scaleform::Render::TessVertex *vertices, unsigned int num)
{
  __int64 v4; // r11
  unsigned int v5; // edi
  Scaleform::Render::TessMesh *v6; // r10
  Scaleform::Render::Tessellator *v7; // rbx
  unsigned __int64 v8; // rax
  Scaleform::Render::TessVertex **v9; // r9
  __int64 v10; // rcx
  Scaleform::Render::TessVertex *v11; // rdx
  Scaleform::Render::TessVertex *v12; // r9

  v4 = 0i64;
  v5 = num;
  v6 = mesh;
  v7 = this;
  if ( num )
  {
    do
    {
      v8 = v6->StartVertex;
      if ( v8 >= v7->MeshVertices.Size )
        break;
      v9 = v7->MeshVertices.Pages;
      if ( v9[(unsigned __int64)(unsigned int)v8 >> 4][v8 & 0xF].Mesh == v6->MeshIdx )
      {
        v10 = v4;
        v4 = (unsigned int)(v4 + 1);
        v11 = v9[(unsigned __int64)(unsigned int)v8 >> 4];
        v12 = &vertices[v10];
        v12->x = v11[v8 & 0xF].x;
        v12->y = v11[v8 & 0xF].y;
        v12->Idx = v11[v8 & 0xF].Idx;
        *(_DWORD *)v12->Styles = *(_DWORD *)v11[v8 & 0xF].Styles;
        *(_DWORD *)&v12->Flags = *(_DWORD *)&v11[v8 & 0xF].Flags;
      }
      ++v6->StartVertex;
    }
    while ( (unsigned int)v4 < v5 );
  }
  return (unsigned int)v4;
}

// File Line: 2122
// RVA: 0x98E090
void __fastcall Scaleform::Render::Tessellator::GetTrianglesI16(Scaleform::Render::Tessellator *this, unsigned int meshIdx, unsigned __int16 *idx, unsigned int start, unsigned int num)
{
  unsigned int v5; // ebx
  unsigned int v6; // esi
  unsigned int v7; // eax
  Scaleform::Render::Tessellator::TriangleType *v8; // r9

  v5 = 0;
  v6 = start;
  if ( num )
  {
    do
    {
      v7 = v5++ + v6;
      idx += 3;
      v8 = &this->MeshTriangles.Arrays[meshIdx].Pages[(unsigned __int64)v7 >> 4][v7 & 0xF];
      *(idx - 3) = this->MeshVertices.Pages[(unsigned __int64)v8->d.t.v1 >> 4][v8->d.t.v1 & 0xF].Idx;
      *(idx - 2) = this->MeshVertices.Pages[(unsigned __int64)v8->d.t.v2 >> 4][v8->d.t.v2 & 0xF].Idx;
      *(idx - 1) = this->MeshVertices.Pages[(unsigned __int64)v8->d.t.v3 >> 4][v8->d.t.v3 & 0xF].Idx;
    }
    while ( v5 < num );
  }
}

// File Line: 2135
// RVA: 0x9E16E0
__int64 __fastcall Scaleform::Render::Tessellator::emitVertex(Scaleform::Render::Tessellator *this, unsigned int meshIdx, unsigned int ver, unsigned int style, unsigned int flags)
{
  Scaleform::Render::TessVertex **v5; // rbx
  unsigned int v6; // er8
  unsigned int v7; // er11
  Scaleform::Render::Tessellator *v8; // rdi
  Scaleform::Render::TessVertex *v9; // rax
  unsigned int v10; // edx
  signed __int64 v11; // rax
  __int64 result; // rax
  unsigned int v13; // edx
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *v14; // rbx
  unsigned __int64 v15; // rsi
  int v16; // ebp
  int v17; // er14
  int v18; // ST2C_4
  __int64 v19; // rcx
  unsigned __int64 v20; // rdi
  _DWORD *v21; // r8
  int v22; // [rsp+2Ch] [rbp-1Ch]
  int v23; // [rsp+30h] [rbp-18h]

  v5 = this->MeshVertices.Pages;
  v6 = ver & 0xFFFFFFF;
  v7 = meshIdx;
  v8 = this;
  v9 = v5[(unsigned __int64)v6 >> 4];
  v10 = v9[v6 & 0xF].Idx;
  v11 = (signed __int64)&v9[v6 & 0xF];
  if ( v10 == -1 )
  {
    *(_DWORD *)(v11 + 8) = v6;
    *(_WORD *)(v11 + 14) = style;
    *(_WORD *)(v11 + 12) = style;
    *(_WORD *)(v11 + 16) = flags;
    *(_WORD *)(v11 + 18) = v7;
    return v6;
  }
  if ( *(unsigned __int16 *)(v11 + 18) == v7 && *(unsigned __int16 *)(v11 + 12) == style )
    return v6;
  if ( v10 == v6 )
  {
LABEL_10:
    v14 = &this->MeshVertices;
    v15 = this->MeshVertices.Size;
    *(_DWORD *)(v11 + 8) = v15;
    v16 = *(_DWORD *)v11;
    v17 = *(_DWORD *)(v11 + 4);
    v18 = *(_DWORD *)(v11 + 12);
    v19 = *(unsigned int *)(v11 + 16);
    v20 = v8->MeshVertices.Size >> 4;
    HIWORD(v22) = style;
    LOWORD(v23) = flags;
    HIWORD(v23) = v7;
    LOWORD(v22) = style;
    if ( v20 >= v14->NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(v14, v20);
    result = (unsigned int)v15;
    v21 = (_DWORD *)&v14->Pages[v20][v14->Size & 0xF].x;
    *v21 = v16;
    v21[1] = v17;
    v21[2] = v15;
    v21[3] = v22;
    v21[4] = v23;
    ++v14->Size;
  }
  else
  {
    while ( 1 )
    {
      v13 = *(_DWORD *)(v11 + 8);
      v11 = (signed __int64)&v5[(unsigned __int64)*(unsigned int *)(v11 + 8) >> 4][*(_DWORD *)(v11 + 8) & 0xF];
      if ( *(unsigned __int16 *)(v11 + 18) == v7 && *(unsigned __int16 *)(v11 + 12) == style )
        break;
      if ( *(_DWORD *)(v11 + 8) == v13 )
        goto LABEL_10;
    }
    result = v13;
  }
  return result;
}

// File Line: 2189
// RVA: 0x9F2AF0
void __fastcall Scaleform::Render::Tessellator::splitMesh(Scaleform::Render::Tessellator *this, Scaleform::Render::TessMesh *mesh)
{
  Scaleform::Render::Tessellator *v2; // r13
  Scaleform::Render::TessMesh *v3; // rdi
  unsigned int v4; // esi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *v5; // r14
  signed __int64 v6; // rbp
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *v7; // rbx
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *v8; // r9
  unsigned __int64 v9; // r15
  unsigned int v10; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v11; // rcx
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
  signed __int64 v22; // rdi
  unsigned __int64 v23; // rdx
  unsigned int v24; // er14
  Scaleform::Render::TessMesh *v25; // rcx
  unsigned int v26; // er12
  unsigned __int64 v27; // rsi
  Scaleform::Render::TessMesh *v28; // rax
  signed __int64 v29; // rcx
  unsigned __int64 v30; // rbp
  __int64 v31; // r9
  unsigned __int64 v32; // rcx
  Scaleform::Render::TessVertex **v33; // r8
  Scaleform::Render::Tessellator::TriangleType *v34; // r9
  signed __int64 v35; // r12
  signed __int64 v36; // r14
  signed __int64 v37; // r15
  unsigned __int64 v38; // rsi
  unsigned __int64 v39; // rdx
  Scaleform::Render::LinearHeap *v40; // rcx
  void *v41; // rdi
  unsigned __int64 v42; // rax
  Scaleform::Render::TessVertex *v43; // rax
  _DWORD *v44; // rdx
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
  unsigned int v58; // [rsp+20h] [rbp-78h]
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayAdaptor arr; // [rsp+28h] [rbp-70h]
  unsigned int v60; // [rsp+A0h] [rbp+8h]
  __int64 v61; // [rsp+A0h] [rbp+8h]
  unsigned int v62; // [rsp+A8h] [rbp+10h]
  Scaleform::Render::Tessellator::TriangleType *v63; // [rsp+A8h] [rbp+10h]
  unsigned int v64; // [rsp+B0h] [rbp+18h]
  unsigned __int64 v65; // [rsp+B0h] [rbp+18h]
  unsigned int v66; // [rsp+B8h] [rbp+20h]
  unsigned __int64 v67; // [rsp+B8h] [rbp+20h]

  v2 = this;
  v3 = mesh;
  v4 = mesh->MeshIdx;
  v5 = &this->MeshTriangles;
  v6 = mesh->MeshIdx;
  v7 = &this->MeshVertices;
  v8 = &this->MeshVertices;
  v9 = (this->VertexLimit - (this->VertexLimit >> 2) + mesh->VertexCount - 1)
     / (this->VertexLimit - (this->VertexLimit >> 2));
  v10 = this->MeshTriangles.Arrays[mesh->MeshIdx].Size;
  v11 = this->MeshTriangles.Arrays;
  v12 = v11[v6].Size;
  arr.Pages = v11[v6].Pages;
  v13 = v10 / (unsigned int)v9;
  arr.Size = v12;
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayAdaptor,Scaleform::Render::Tessellator::CmpVer1>(
    &arr,
    0i64,
    v12,
    (Scaleform::Render::Tessellator::CmpVer1)v8);
  v14 = 0i64;
  v15 = v2->MeshTriangles.Arrays[v3->MeshIdx].Size;
  if ( v15 )
  {
    do
    {
      v16 = v14 >> 4;
      v17 = v14++ & 0xF;
      v18 = &v2->MeshTriangles.Arrays[v6].Pages[v16][v17];
      v2->MeshVertices.Pages[(unsigned __int64)v18->d.t.v1 >> 4][v18->d.t.v1 & 0xF].Mesh = -1;
      v2->MeshVertices.Pages[(unsigned __int64)v18->d.t.v2 >> 4][v18->d.t.v2 & 0xF].Mesh = -1;
      v2->MeshVertices.Pages[(unsigned __int64)v18->d.t.v3 >> 4][v18->d.t.v3 & 0xF].Mesh = -1;
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
      if ( !Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::Split(v5, v4, v21) )
        break;
      v22 = v4 & 0xF;
      v23 = (unsigned __int64)v4 >> 4;
      v2->Meshes.Pages[v23][v22].VertexCount = -1;
      v24 = v2->Meshes.Size;
      v25 = v2->Meshes.Pages[v23];
      v26 = v25[v22].Style1;
      LODWORD(arr.Size) = v25[v22].MeshIdx;
      v60 = v25[v22].Style2;
      v62 = v25[v22].Flags1;
      v64 = v25[v22].Flags2;
      v66 = v25[v22].StartVertex;
      v58 = v25[v22].VertexCount;
      v27 = v2->Meshes.Size >> 4;
      if ( v27 >= v2->Meshes.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::allocPage(&v2->Meshes, v27);
      v28 = v2->Meshes.Pages[v27];
      ++v19;
      v4 = v24;
      v29 = v2->Meshes.Size & 0xF;
      v28[v29].MeshIdx = v24;
      v28[v29].Style1 = v26;
      v28[v29].Style2 = v60;
      v5 = &v2->MeshTriangles;
      v28[v29].Flags1 = v62;
      v28[v29].Flags2 = v64;
      v28[v29].StartVertex = v66;
      v28[v29].VertexCount = v58;
      ++v2->Meshes.Size;
    }
    while ( v19 < v20 );
    v7 = &v2->MeshVertices;
  }
  v30 = 0i64;
  if ( v2->Meshes.Size )
  {
    v31 = 0i64;
    v61 = 0i64;
    do
    {
      if ( v2->Meshes.Pages[v30 >> 4][v30 & 0xF].VertexCount == -1 )
      {
        v32 = 0i64;
        v65 = 0i64;
        v67 = *(unsigned __int64 *)((char *)&v2->MeshTriangles.Arrays->Size + v31);
        if ( v67 )
        {
          do
          {
            v33 = v2->MeshVertices.Pages;
            v34 = &(*(Scaleform::Render::Tessellator::TriangleType ***)((char *)&v2->MeshTriangles.Arrays->Pages + v31))[v32 >> 4][v32 & 0xF];
            v63 = v34;
            v35 = (signed __int64)&v33[(unsigned __int64)v34->d.t.v1 >> 4][v34->d.t.v1 & 0xF];
            v36 = (signed __int64)&v33[(unsigned __int64)v34->d.t.v2 >> 4][v34->d.t.v2 & 0xF];
            v37 = (signed __int64)&v33[(unsigned __int64)v34->d.t.v3 >> 4][v34->d.t.v3 & 0xF];
            if ( *(_WORD *)(v35 + 18) == -1 )
              *(_WORD *)(v35 + 18) = v30;
            if ( *(_WORD *)(v36 + 18) == -1 )
              *(_WORD *)(v36 + 18) = v30;
            if ( *(_WORD *)(v37 + 18) == -1 )
              *(_WORD *)(v37 + 18) = v30;
            if ( *(unsigned __int16 *)(v35 + 18) != v30 )
            {
              v34->d.t.v1 = v2->MeshVertices.Size;
              v38 = v7->Size >> 4;
              if ( v38 >= v7->NumPages )
              {
                v39 = v7->MaxPages;
                if ( v38 >= v39 )
                {
                  v40 = v7->pHeap;
                  if ( v7->Pages )
                  {
                    v41 = Scaleform::Render::LinearHeap::Alloc(v40, 16 * v39);
                    memmove(v41, v7->Pages, 8 * v7->NumPages);
                    v42 = v7->MaxPages;
                    v7->Pages = (Scaleform::Render::TessVertex **)v41;
                    v7->MaxPages = 2 * v42;
                  }
                  else
                  {
                    v7->MaxPages = 16i64;
                    v7->Pages = (Scaleform::Render::TessVertex **)Scaleform::Render::LinearHeap::Alloc(v40, 0x80ui64);
                  }
                }
                v43 = (Scaleform::Render::TessVertex *)Scaleform::Render::LinearHeap::Alloc(v7->pHeap, 0x140ui64);
                v34 = v63;
                v7->Pages[v38] = v43;
                ++v7->NumPages;
              }
              v44 = (_DWORD *)&v7->Pages[v38][v7->Size & 0xF].x;
              *v44 = *(_DWORD *)v35;
              v44[1] = *(_DWORD *)(v35 + 4);
              v44[2] = *(_DWORD *)(v35 + 8);
              v44[3] = *(_DWORD *)(v35 + 12);
              v44[4] = *(_DWORD *)(v35 + 16);
              v7->Pages[(++v7->Size - 1) >> 4][(LODWORD(v7->Size) - 1) & 0xF].Mesh = v30;
            }
            if ( *(unsigned __int16 *)(v36 + 18) != v30 )
            {
              v34->d.t.v2 = v2->MeshVertices.Size;
              v45 = v7->Size >> 4;
              if ( v45 >= v7->NumPages )
              {
                v46 = v7->MaxPages;
                if ( v45 >= v46 )
                {
                  v47 = v7->pHeap;
                  if ( v7->Pages )
                  {
                    v48 = Scaleform::Render::LinearHeap::Alloc(v47, 16 * v46);
                    memmove(v48, v7->Pages, 8 * v7->NumPages);
                    v49 = v7->MaxPages;
                    v7->Pages = (Scaleform::Render::TessVertex **)v48;
                    v7->MaxPages = 2 * v49;
                  }
                  else
                  {
                    v7->MaxPages = 16i64;
                    v7->Pages = (Scaleform::Render::TessVertex **)Scaleform::Render::LinearHeap::Alloc(v47, 0x80ui64);
                  }
                }
                v50 = (Scaleform::Render::TessVertex *)Scaleform::Render::LinearHeap::Alloc(v7->pHeap, 0x140ui64);
                v34 = v63;
                v7->Pages[v45] = v50;
                ++v7->NumPages;
              }
              v51 = (_DWORD *)&v7->Pages[v45][v7->Size & 0xF].x;
              *v51 = *(_DWORD *)v36;
              v51[1] = *(_DWORD *)(v36 + 4);
              v51[2] = *(_DWORD *)(v36 + 8);
              v51[3] = *(_DWORD *)(v36 + 12);
              v51[4] = *(_DWORD *)(v36 + 16);
              v7->Pages[(++v7->Size - 1) >> 4][(LODWORD(v7->Size) - 1) & 0xF].Mesh = v30;
            }
            if ( *(unsigned __int16 *)(v37 + 18) != v30 )
            {
              v34->d.t.v3 = v2->MeshVertices.Size;
              v52 = v7->Size >> 4;
              if ( v52 >= v7->NumPages )
              {
                v53 = v7->MaxPages;
                if ( v52 >= v53 )
                {
                  v54 = v7->pHeap;
                  if ( v7->Pages )
                  {
                    v55 = Scaleform::Render::LinearHeap::Alloc(v54, 16 * v53);
                    memmove(v55, v7->Pages, 8 * v7->NumPages);
                    v56 = v7->MaxPages;
                    v7->Pages = (Scaleform::Render::TessVertex **)v55;
                    v7->MaxPages = 2 * v56;
                  }
                  else
                  {
                    v7->MaxPages = 16i64;
                    v7->Pages = (Scaleform::Render::TessVertex **)Scaleform::Render::LinearHeap::Alloc(v54, 0x80ui64);
                  }
                }
                v7->Pages[v52] = (Scaleform::Render::TessVertex *)Scaleform::Render::LinearHeap::Alloc(
                                                                    v7->pHeap,
                                                                    0x140ui64);
                ++v7->NumPages;
              }
              v57 = (_DWORD *)&v7->Pages[v52][v7->Size & 0xF].x;
              *v57 = *(_DWORD *)v37;
              v57[1] = *(_DWORD *)(v37 + 4);
              v57[2] = *(_DWORD *)(v37 + 8);
              v57[3] = *(_DWORD *)(v37 + 12);
              v57[4] = *(_DWORD *)(v37 + 16);
              v7->Pages[(++v7->Size - 1) >> 4][(LODWORD(v7->Size) - 1) & 0xF].Mesh = v30;
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
    while ( v30 < v2->Meshes.Size );
  }
}

// File Line: 2260
// RVA: 0x9B76F0
void __fastcall Scaleform::Render::Tessellator::SplitMeshes(Scaleform::Render::Tessellator *this)
{
  Scaleform::Render::Tessellator *v1; // rbx
  unsigned __int64 v2; // rsi
  char v3; // r8
  unsigned __int64 v4; // rdi
  Scaleform::Render::TessMesh *v5; // rdx
  unsigned __int64 i; // r8
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // rcx
  unsigned __int64 j; // r9
  Scaleform::Render::TessVertex *v10; // rax
  signed __int64 v11; // r8
  unsigned __int16 v12; // ax
  signed __int64 v13; // rdx
  Scaleform::Render::TessMesh *v14; // rcx

  v1 = this;
  while ( 1 )
  {
    v2 = v1->Meshes.Size;
    v3 = 1;
    v4 = 0i64;
    if ( !v2 )
      break;
    do
    {
      v5 = &v1->Meshes.Pages[v4 >> 4][v4 & 0xF];
      if ( v5->VertexCount > v1->VertexLimit )
      {
        Scaleform::Render::Tessellator::splitMesh(v1, v5);
        v3 = 0;
      }
      ++v4;
    }
    while ( v4 < v2 );
    if ( v3 )
      break;
    for ( i = 0i64; i < v1->Meshes.Size; v1->Meshes.Pages[v7][v8].VertexCount = 0 )
    {
      v7 = i >> 4;
      v8 = i++ & 0xF;
    }
    for ( j = 0i64; j < v1->MeshVertices.Size; ++j )
    {
      v10 = v1->MeshVertices.Pages[j >> 4];
      v11 = (signed __int64)&v10[j & 0xF];
      v12 = v10[j & 0xF].Mesh;
      if ( v12 != -1 )
      {
        v13 = v12 & 0xF;
        v14 = v1->Meshes.Pages[(unsigned __int64)v12 >> 4];
        *(_DWORD *)(v11 + 8) = v14[v13].VertexCount++;
      }
    }
  }
}

// File Line: 2294
// RVA: 0x9E1870
__int64 __fastcall Scaleform::Render::Tessellator::emitVertex(Scaleform::Render::Tessellator *this, unsigned int meshIdx, unsigned int ver, unsigned int style1, unsigned int style2, unsigned int flags, bool strictStyle)
{
  Scaleform::Render::TessVertex **v7; // rsi
  unsigned int v8; // er8
  unsigned int v9; // edi
  Scaleform::Render::Tessellator *v10; // r15
  Scaleform::Render::TessVertex *v11; // rax
  unsigned int v12; // edx
  signed __int64 v13; // rax
  __int64 result; // rax
  unsigned int v15; // edx
  unsigned __int64 v16; // rsi
  int v17; // ebp
  int v18; // er14
  int v19; // ST2C_4
  __int64 v20; // rcx
  unsigned __int64 v21; // rdi
  _DWORD *v22; // r8
  int v23; // [rsp+2Ch] [rbp-2Ch]
  int v24; // [rsp+30h] [rbp-28h]

  v7 = this->MeshVertices.Pages;
  v8 = ver & 0xFFFFFFF;
  v9 = meshIdx;
  v10 = this;
  v11 = v7[(unsigned __int64)v8 >> 4];
  v12 = v11[v8 & 0xF].Idx;
  v13 = (signed __int64)&v11[v8 & 0xF];
  if ( v12 == -1 )
  {
    *(_DWORD *)(v13 + 8) = v8;
    *(_WORD *)(v13 + 12) = style1;
    *(_WORD *)(v13 + 14) = style2;
    *(_WORD *)(v13 + 18) = v9;
    *(_WORD *)(v13 + 16) = flags;
    result = v8;
  }
  else if ( *(unsigned __int16 *)(v13 + 18) != v9
         || *(unsigned __int16 *)(v13 + 12) != style1
         || *(unsigned __int16 *)(v13 + 14) != style2
         || strictStyle && *(unsigned __int16 *)(v13 + 16) != flags )
  {
    if ( v12 == v8 )
    {
LABEL_16:
      v16 = this->MeshVertices.Size;
      *(_DWORD *)(v13 + 8) = v16;
      v17 = *(_DWORD *)v13;
      v18 = *(_DWORD *)(v13 + 4);
      v19 = *(_DWORD *)(v13 + 12);
      v20 = *(unsigned int *)(v13 + 16);
      HIWORD(v24) = v9;
      HIWORD(v23) = style2;
      LOWORD(v23) = style1;
      LOWORD(v24) = flags;
      v21 = v10->MeshVertices.Size >> 4;
      if ( v21 >= v10->MeshVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(&v10->MeshVertices, v21);
      result = (unsigned int)v16;
      v22 = (_DWORD *)&v10->MeshVertices.Pages[v21][v10->MeshVertices.Size & 0xF].x;
      *v22 = v17;
      v22[1] = v18;
      v22[2] = v16;
      v22[3] = v23;
      v22[4] = v24;
      ++v10->MeshVertices.Size;
    }
    else
    {
      while ( 1 )
      {
        v15 = *(_DWORD *)(v13 + 8);
        v13 = (signed __int64)&v7[(unsigned __int64)*(unsigned int *)(v13 + 8) >> 4][*(_DWORD *)(v13 + 8) & 0xF];
        if ( *(unsigned __int16 *)(v13 + 18) == v9
          && *(unsigned __int16 *)(v13 + 12) == style1
          && *(unsigned __int16 *)(v13 + 14) == style2
          && (!strictStyle || *(unsigned __int16 *)(v13 + 16) == flags) )
        {
          break;
        }
        if ( *(_DWORD *)(v13 + 8) == v15 )
          goto LABEL_16;
      }
      result = v15;
    }
  }
  else
  {
    result = v8;
  }
  return result;
}

// File Line: 2346
// RVA: 0x9D6360
void __fastcall Scaleform::Render::Tessellator::collectFanEdges(Scaleform::Render::Tessellator *this, Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *chain, Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *oppos, unsigned int style)
{
  __int16 v4; // r14
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *v5; // rbx
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *v6; // r11
  Scaleform::Render::Tessellator *v7; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v8; // rbp
  unsigned __int64 v9; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v10; // rdi
  __int16 v11; // si
  unsigned __int64 v12; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v13; // r10
  unsigned __int64 v14; // r8
  Scaleform::Render::TessVertex *v15; // rcx
  signed __int64 v16; // r9
  signed __int64 v17; // r8

  v4 = style;
  v5 = oppos;
  v6 = chain;
  v7 = this;
  if ( oppos->Size )
    v8 = **oppos->Pages;
  else
    v8 = chain->Pages[(chain->Size - 1) >> 4][(LODWORD(chain->Size) - 1) & 0xF];
  v9 = chain->Size;
  v10 = **v6->Pages;
  if ( v9 )
  {
    v11 = style ^ 0x8000;
    v12 = 1i64;
    do
    {
      if ( v12 >= v9 )
      {
        v14 = v5->Size;
        if ( v14 )
          v13 = v5->Pages[(v14 - 1) >> 4][((_DWORD)v14 - 1) & 0xF];
        else
          v13 = **v6->Pages;
      }
      else
      {
        v13 = v6->Pages[v12 >> 4][v12 & 0xF];
      }
      ++v12;
      v15 = v7->MeshVertices.Pages[(unsigned __int64)(v10->srcVer & 0xFFFFFFF) >> 4];
      v16 = (signed __int64)&v15[v10->srcVer & 0xF];
      v17 = (signed __int64)&v7->EdgeFans.Array[(unsigned int)v15[v10->srcVer & 0xF].Mesh + *(_DWORD *)(v16 + 8)];
      *(_QWORD *)v17 = v10;
      *(_QWORD *)(v17 + 8) = v8;
      *(_WORD *)(v17 + 18) = 0;
      *(_WORD *)(v17 + 16) = v4;
      *(_QWORD *)(v17 + 24) = v10;
      *(_QWORD *)(v17 + 32) = v13;
      *(_WORD *)(v17 + 42) = 0;
      *(_WORD *)(v17 + 40) = v11;
      *(_WORD *)(v16 + 18) += 2;
      v9 = v6->Size;
      v8 = v10;
      v10 = v13;
    }
    while ( v12 - 1 < v9 );
  }
}

// File Line: 2381
// RVA: 0x9DCC50
__int64 __fastcall Scaleform::Render::Tessellator::countFanEdges(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::MonotoneType *m)
{
  Scaleform::Render::Tessellator::MonoVertexType *v2; // r10
  unsigned int v3; // edi
  Scaleform::Render::Tessellator::MonotoneType *v4; // r11
  Scaleform::Render::Tessellator *v5; // rsi
  Scaleform::Render::Tessellator::MonoVertexType *v6; // r8
  Scaleform::Render::Tessellator::MonoVertexType *v7; // rax
  int v8; // er9
  int v9; // edx
  int v10; // ecx
  __int64 result; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v12; // rbx
  Scaleform::Render::Tessellator::MonoVertexType *v13; // r8
  Scaleform::Render::TessVertex *v14; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v15; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v16; // rax
  __int64 v17; // rcx
  Scaleform::Render::Tessellator::BaseLineType *v18; // rcx
  Scaleform::Render::Tessellator::MonotoneType val; // [rsp+20h] [rbp-28h]

  v2 = m->start;
  v3 = 0;
  v4 = m;
  v5 = this;
  if ( m->start && (v6 = v2->next) != 0i64 )
  {
    v7 = v6->next;
    if ( v7 )
    {
      while ( 1 )
      {
        v8 = v2->srcVer & 0xFFFFFFF;
        v9 = v6->srcVer & 0xFFFFFFF;
        v10 = v7->srcVer & 0xFFFFFFF;
        if ( v8 != v9 && v9 != v10 && v10 != v8 )
          break;
        v2 = v6;
        v6 = v7;
        v7 = v7->next;
        if ( !v7 )
          goto LABEL_8;
      }
      v12 = 0i64;
      v4->start = v2;
      v13 = v2;
      if ( v2 )
      {
        while ( !v12 || (v12->srcVer ^ v13->srcVer) & 0xFFFFFFF )
        {
          v12 = v13;
          v3 += 2;
          v14 = v5->MeshVertices.Pages[(unsigned __int64)(v13->srcVer & 0xFFFFFFF) >> 4];
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
            v16 = v4->start;
            *(_QWORD *)&val.d.m.lastIdx = *(_QWORD *)&v4->d.m.lastIdx;
            v17 = *(_QWORD *)&v4->d.t.meshIdx;
            val.start = v16;
            *(_QWORD *)&val.d.t.meshIdx = v17;
            v18 = v4->lowerBase;
            val.start = v13;
            val.lowerBase = v18;
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16>::PushBack(
              &v5->Monotones,
              &val);
          }
        }
        v12->next = 0i64;
      }
      result = v3;
    }
    else
    {
LABEL_8:
      v4->start = 0i64;
      result = 0i64;
    }
  }
  else
  {
    m->start = 0i64;
    result = 0i64;
  }
  return result;
}

// File Line: 2449
// RVA: 0x9D64D0
void __fastcall Scaleform::Render::Tessellator::collectFanEdges(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::MonotoneType *m)
{
  Scaleform::Render::Tessellator::MonotoneType *v2; // r14
  Scaleform::Render::Tessellator::MonoVertexType *v3; // rbx
  Scaleform::Render::Tessellator *v4; // rbp
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *v5; // rdi
  unsigned __int64 v6; // rsi

  v2 = m;
  this->LeftChain.Size = 0i64;
  this->RightChain.Size = 0i64;
  v3 = m->start;
  v4 = this;
  if ( m->start )
  {
    do
    {
      v5 = &v4->LeftChain;
      if ( (v3->srcVer & 0x80000000) == 0 )
        v5 = &v4->RightChain;
      v6 = v5->Size >> 4;
      if ( v6 >= v5->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8>::allocPage(v5, v5->Size >> 4);
      v5->Pages[v6][v5->Size & 0xF] = v3;
      ++v5->Size;
      v3 = v3->next;
    }
    while ( v3 );
  }
  if ( v4->LeftChain.Size )
    Scaleform::Render::Tessellator::collectFanEdges(v4, &v4->LeftChain, &v4->RightChain, v2->style | 0x8000);
  if ( v4->RightChain.Size )
    Scaleform::Render::Tessellator::collectFanEdges(v4, &v4->RightChain, &v4->LeftChain, v2->style);
}

// File Line: 2485
// RVA: 0x9D6E80
__int64 __fastcall Scaleform::Render::Tessellator::computeMiter(Scaleform::Render::Tessellator *this, Scaleform::Render::TessVertex *v1, Scaleform::Render::TessVertex *v2, Scaleform::Render::TessVertex *v3, Scaleform::Render::TessVertex *newVer1, Scaleform::Render::TessVertex *newVer2)
{
  float v6; // xmm7_4
  Scaleform::Render::TessVertex *v7; // rbp
  Scaleform::Render::TessVertex *v8; // rdi
  Scaleform::Render::Tessellator *v9; // rsi
  Scaleform::Render::TessVertex *v10; // rbx
  __int128 v11; // xmm8
  __m128 v12; // xmm12
  __m128 v13; // xmm6
  float v14; // xmm13_4
  __m128 v15; // xmm0
  float v16; // xmm10_4
  __m128 v17; // xmm0
  float len2; // xmm11_4
  float v19; // xmm4_4
  float v20; // xmm9_4
  bool v21; // cl
  unsigned __int8 v22; // dl
  float v23; // xmm12_4
  float v24; // xmm15_4
  float v25; // xmm14_4
  float v26; // xmm5_4
  __int128 v27; // xmm2
  float v28; // xmm3_4
  __int64 result; // rax
  float v30; // xmm6_4
  float v31; // xmm1_4
  __int128 v32; // xmm0
  float v33; // xmm13_4
  float v34; // xmm3_4
  float v35; // xmm6_4
  float v36; // xmm1_4
  float v37; // xmm6_4
  __m128 v38; // xmm13
  __m128 v39; // xmm1
  float v40; // xmm0_4
  float v41; // xmm4_4
  float v42; // xmm4_4
  float v43; // xmm4_4
  float v44; // [rsp+30h] [rbp-E8h]
  float v45; // [rsp+38h] [rbp-E0h]
  float v46; // [rsp+120h] [rbp+8h]
  float v47; // [rsp+128h] [rbp+10h]

  v6 = v2->x;
  v7 = v2;
  v8 = v1;
  v9 = this;
  v10 = v3;
  v11 = LODWORD(v2->y);
  v12 = (__m128)LODWORD(v3->y);
  v12.m128_f32[0] = v12.m128_f32[0] - *(float *)&v11;
  v13 = (__m128)LODWORD(v2->y);
  v13.m128_f32[0] = *(float *)&v11 - v1->y;
  v14 = v3->x;
  v15 = v13;
  v15.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)((float)(v6 - v1->x) * (float)(v6 - v1->x));
  LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v15);
  v17 = v12;
  v17.m128_f32[0] = (float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)((float)(v3->x - v6) * (float)(v3->x - v6));
  LODWORD(len2) = (unsigned __int128)_mm_sqrt_ps(v17);
  v17.m128_f32[0] = Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType>(
                      v1,
                      v2,
                      v3,
                      v16,
                      len2);
  v19 = v9->EdgeAAWidth;
  v20 = 0.0;
  v21 = v17.m128_f32[0] < 0.0;
  v22 = 0;
  LODWORD(v45) = v17.m128_i32[0] & _xmm;
  v23 = (float)(v12.m128_f32[0] * v19) * (float)(1.0 / len2);
  v24 = (float)(v9->EdgeAAWidth * v13.m128_f32[0]) * (float)(1.0 / v16);
  v25 = (float)((float)(v8->x - v6) * v19) * (float)(1.0 / v16);
  v26 = (float)((float)(v6 - v14) * v19) * (float)(1.0 / len2);
  if ( COERCE_FLOAT(v17.m128_i32[0] & _xmm) < 0.125 )
  {
    if ( v16 <= len2 )
    {
      v28 = v6 + v23;
      *(float *)&v27 = *(float *)&v11 + v26;
      goto LABEL_5;
    }
    v6 = v6 + v24;
    *(float *)&v11 = *(float *)&v11 + v25;
    goto LABEL_4;
  }
  v30 = v8->x + v24;
  v44 = v30;
  v31 = (float)(v10->y + v26) - (float)(*(float *)&v11 + v26);
  v47 = v6 + v23;
  v32 = v11;
  v33 = (float)(v14 + v23) - (float)(v6 + v23);
  *(float *)&v32 = *(float *)&v11 + v25;
  v27 = v32;
  v34 = (float)(v6 + v24) - v30;
  *(float *)&v27 = (float)(*(float *)&v11 + v25) - (float)(v8->y + v25);
  v46 = v8->y + v25;
  v35 = (float)(v31 * v34) - (float)(v33 * *(float *)&v27);
  if ( COERCE_FLOAT(LODWORD(v35) & _xmm) < (float)((float)(len2 + v16) * v9->IntersectionEpsilon) )
  {
LABEL_4:
    LODWORD(v27) = v11;
    v28 = v6;
    goto LABEL_5;
  }
  v36 = (float)((float)((float)(v46 - (float)(*(float *)&v11 + v26)) * v33) - (float)((float)(v44 - v47) * v31)) / v35;
  *(float *)&v27 = (float)(*(float *)&v27 * v36) + v46;
  v28 = (float)(v34 * v36) + v44;
  v38 = (__m128)v27;
  v37 = v28 - v6;
  v38.m128_f32[0] = *(float *)&v27 - *(float *)&v11;
  v39 = v38;
  v39.m128_f32[0] = (float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v37 * v37);
  LODWORD(v40) = (unsigned __int128)_mm_sqrt_ps(v39);
  if ( v21 )
  {
    v41 = v19 * 4.0;
  }
  else
  {
    if ( v16 >= len2 )
      v42 = len2;
    else
      v42 = v16;
    v41 = v42 / v45;
  }
  if ( v40 > v41 )
  {
    if ( newVer2 )
    {
      if ( v21 )
        v20 = FLOAT_2_0;
      v22 = 1;
      *(float *)&v27 = (float)(v20 * v24) + (float)(*(float *)&v11 + v25);
      v28 = (float)(v6 + v24) - (float)(v20 * v25);
      newVer2->x = (float)(v20 * v26) + v47;
      newVer2->y = (float)(v26 + v7->y) - (float)(v20 * v23);
    }
    else
    {
      v43 = v41 / v40;
      v28 = (float)(v37 * v43) + v6;
      *(float *)&v27 = (float)(v38.m128_f32[0] * v43) + *(float *)&v11;
    }
  }
LABEL_5:
  result = v22;
  newVer1->x = v28;
  LODWORD(newVer1->y) = v27;
  return result;
}

// File Line: 2579
// RVA: 0x9EC880
void __fastcall Scaleform::Render::Tessellator::processFan(Scaleform::Render::Tessellator *this, unsigned int start, unsigned int end)
{
  unsigned int v3; // esi
  unsigned int v4; // er14
  Scaleform::Render::Tessellator *v5; // rbx
  unsigned int v6; // er12
  unsigned __int64 v7; // r13
  unsigned int v8; // er13
  signed __int64 v9; // r14
  Scaleform::Render::Tessellator::EdgeAAType *v10; // r8
  bool v11; // zf
  unsigned __int64 v12; // r15
  unsigned __int64 v13; // r15
  Scaleform::Render::Tessellator::EdgeAAType *v14; // r9
  Scaleform::Render::TessVertex *v15; // rax
  float v16; // xmm6_4
  float v17; // xmm7_4
  signed __int64 v18; // rdx
  unsigned __int64 v19; // r8
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *v20; // rbx
  unsigned __int64 v21; // rdi
  unsigned int v22; // xmm0_4
  int v23; // xmm1_4
  signed __int64 v24; // rdx
  Scaleform::Render::TessVertex *v25; // rax
  int v26; // xmm0_4
  unsigned int *v27; // r14
  unsigned __int64 v28; // rsi
  unsigned __int64 v29; // r8
  Scaleform::Render::Tessellator::EdgeAAType *v30; // rax
  unsigned int v31; // edx
  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *v32; // rsi
  unsigned __int64 v33; // rdx
  unsigned __int64 v34; // r13
  unsigned __int64 v35; // r8
  unsigned int **v36; // rax
  __int64 v37; // rdi
  unsigned __int64 v38; // rcx
  unsigned int *v39; // rax
  Scaleform::Render::Tessellator::EdgeAAType *v40; // r8
  __int64 v41; // r15
  Scaleform::Render::Tessellator::EdgeAAType *v42; // r12
  unsigned int v43; // er11
  Scaleform::Render::Tessellator::MonoVertexType *v44; // rax
  unsigned int v45; // er10
  unsigned int v46; // ecx
  float v47; // xmm6_4
  float v48; // xmm7_4
  Scaleform::Render::TessVertex **v49; // r8
  unsigned int v50; // er10
  unsigned __int64 v51; // rax
  unsigned int v52; // er10
  Scaleform::Render::TessVertex *v53; // rax
  unsigned int v54; // er8
  unsigned int v55; // esi
  int v56; // edx
  __int64 v57; // rax
  unsigned __int16 v58; // ax
  unsigned __int64 v59; // rdi
  unsigned int v60; // xmm0_4
  int v61; // xmm1_4
  signed __int64 v62; // rdx
  Scaleform::Render::TessVertex *v63; // rax
  int v64; // xmm0_4
  unsigned __int64 v65; // rdi
  Scaleform::Render::Tessellator::EdgeAAType *v66; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v67; // r8
  signed __int64 v68; // r13
  unsigned int v69; // er11
  unsigned int v70; // er9
  unsigned __int64 v71; // r15
  Scaleform::Render::Tessellator::InnerQuadType *v72; // rcx
  signed __int64 v73; // rdx
  char v74; // r15
  unsigned int v75; // er10
  char v76; // al
  float v77; // xmm6_4
  float v78; // xmm7_4
  Scaleform::Render::TessVertex **v79; // r8
  unsigned int v80; // er10
  unsigned __int64 v81; // rax
  unsigned int v82; // er10
  Scaleform::Render::TessVertex *v83; // rax
  unsigned int v84; // er12
  unsigned __int16 v85; // ax
  unsigned __int16 v86; // cx
  unsigned __int64 v87; // rdi
  unsigned int v88; // xmm0_4
  int v89; // xmm1_4
  signed __int64 v90; // rdx
  Scaleform::Render::TessVertex *v91; // rax
  int v92; // xmm0_4
  unsigned __int64 v93; // rdi
  Scaleform::Render::TessVertex *v94; // rdx
  signed __int64 v95; // r8
  int v96; // eax
  unsigned __int64 v97; // rdi
  signed __int64 v98; // r15
  unsigned __int64 v99; // rdi
  unsigned __int64 v100; // rcx
  signed __int64 v101; // r15
  Scaleform::Render::VertexBasic *v102; // r13
  unsigned __int64 v103; // rdi
  signed __int64 v104; // r15
  unsigned __int64 v105; // rdi
  unsigned __int64 v106; // rcx
  signed __int64 v107; // r15
  Scaleform::Render::VertexBasic *v108; // r13
  int v109; // ecx
  unsigned __int64 v110; // r15
  Scaleform::Render::Tessellator::OuterEdgeType *v111; // rcx
  signed __int64 v112; // rdx
  __int64 v113; // rax
  unsigned __int64 v114; // r15
  Scaleform::Render::Tessellator::OuterEdgeType *v115; // rcx
  signed __int64 v116; // rdx
  Scaleform::Render::TessVertex newVer1; // [rsp+10h] [rbp-69h]
  Scaleform::Render::TessVertex *newVer2; // [rsp+28h] [rbp-51h]
  Scaleform::Render::TessVertex v119; // [rsp+30h] [rbp-49h]
  Scaleform::Render::VertexBasic v120; // [rsp+48h] [rbp-31h]
  Scaleform::Render::Tessellator::EdgeAAType *v121; // [rsp+50h] [rbp-29h]
  Scaleform::Render::Tessellator::EdgeAAType *v122; // [rsp+58h] [rbp-21h]
  unsigned __int64 v123; // [rsp+60h] [rbp-19h]
  __int64 v124; // [rsp+70h] [rbp-9h]
  char v125; // [rsp+E8h] [rbp+6Fh]
  unsigned int vars0; // [rsp+F0h] [rbp+77h]
  unsigned __int64 retaddr; // [rsp+F8h] [rbp+7Fh]

  if ( start != end )
  {
    v3 = start;
    v4 = end;
    v5 = this;
    v6 = end - 1;
    this->StartFan.Size = 0i64;
    this->EndFan.Size = 0i64;
    v7 = start;
    retaddr = start;
    LODWORD(newVer2) = end - start;
    if ( start < end )
    {
      v8 = vars0;
      v9 = start;
      while ( 1 )
      {
        v10 = v5->EdgeFans.Array;
        if ( !((v10[v6].rayVer->srcVer ^ v10[v9].rayVer->srcVer) & 0xFFFFFFF) )
          break;
        if ( v10[v6].slope != v10[v9].slope && !(v10[v6].style & 0x8000) )
        {
          v11 = (v10[v9].style & 0x8000u) == 0;
LABEL_9:
          if ( !v11 )
          {
            v12 = v5->StartFan.Size >> 3;
            if ( v12 >= v5->StartFan.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)&v5->StartFan,
                v5->StartFan.Size >> 3);
            v5->StartFan.Pages[v12][v5->StartFan.Size & 7] = v3;
            ++v5->StartFan.Size;
            v13 = v5->EndFan.Size >> 3;
            if ( v13 >= v5->EndFan.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)&v5->EndFan,
                v5->EndFan.Size >> 3);
            v5->EndFan.Pages[v13][v5->EndFan.Size & 7] = v6;
            ++v5->EndFan.Size;
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
      v11 = ((v10[v6].style ^ v10[v9].style) & 0x7FFF) == 0;
      goto LABEL_9;
    }
LABEL_17:
    if ( v5->StartFan.Size )
    {
      v27 = *v5->EndFan.Pages;
      v28 = v5->EndFan.Size >> 3;
      if ( v28 >= v5->EndFan.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)&v5->EndFan,
          v5->EndFan.Size >> 3);
      v29 = 0i64;
      v5->EndFan.Pages[v28][v5->EndFan.Size & 7] = *v27;
      ++v5->EndFan.Size;
      v30 = v5->EdgeFans.Array;
      v31 = v5->StarVertices.Size;
      HIDWORD(newVer2) = v5->StarVertices.Size;
      v11 = v5->StartFan.Size == 0;
      LODWORD(v120.x) = v30[v7].cntVer->srcVer & 0xFFFFFFF;
      if ( !v11 )
      {
        v32 = (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&v5->StarVertices;
        do
        {
          v33 = v29 & 7;
          v34 = v29 >> 3;
          v35 = v29 + 1;
          v36 = v5->EndFan.Pages;
          retaddr = v33;
          v37 = v5->StartFan.Pages[v34][v33];
          v38 = v35 & 7;
          v123 = v35;
          v39 = v36[v35 >> 3];
          v40 = v5->EdgeFans.Array;
          v41 = v39[v38];
          v42 = &v40[v37];
          v43 = v40[v37].rayVer->srcVer;
          v44 = v42->cntVer;
          v121 = &v40[v37];
          v45 = v44->srcVer;
          if ( (v43 & 0xFFFFFFF) == (v44->srcVer & 0xFFFFFFF)
            || (v46 = v40[v41].rayVer->srcVer, (v46 & 0xFFFFFFF) == (v44->srcVer & 0xFFFFFFF)) )
          {
            v49 = v5->MeshVertices.Pages;
            v50 = v45 & 0xFFFFFFF;
            v48 = v49[(unsigned __int64)v50 >> 4][v50 & 0xF].x;
            v51 = (unsigned __int64)v50 >> 4;
            v52 = v50 & 0xF;
            newVer1.x = v48;
            v53 = v49[v51];
            v47 = v53[v52].y;
            newVer1.y = v53[v52].y;
          }
          else
          {
            Scaleform::Render::Tessellator::computeMiter(
              v5,
              &v5->MeshVertices.Pages[(unsigned __int64)(v43 & 0xFFFFFFF) >> 4][v43 & 0xF],
              &v5->MeshVertices.Pages[(unsigned __int64)(v45 & 0xFFFFFFF) >> 4][v45 & 0xF],
              &v5->MeshVertices.Pages[(unsigned __int64)(v46 & 0xFFFFFFF) >> 4][v46 & 0xF],
              &newVer1,
              0i64);
            v47 = newVer1.y;
            v48 = newVer1.x;
          }
          v54 = v5->MeshVertices.Size;
          if ( (unsigned int)v41 >= (unsigned int)v37
            || (LODWORD(v41) = (_DWORD)newVer2 + v41, (unsigned int)v37 <= (unsigned int)v41) )
          {
            v55 = vars0;
            v56 = -(signed int)newVer2;
            do
            {
              if ( (unsigned int)v37 >= v55 )
                v57 = (unsigned int)(v56 + v37);
              else
                v57 = (unsigned int)v37;
              LODWORD(v37) = v37 + 1;
              v5->EdgeFans.Array[v57].cntVer->aaVer = v54;
            }
            while ( (unsigned int)v37 <= (unsigned int)v41 );
            v32 = (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&v5->StarVertices;
          }
          v58 = v42->style & 0x7FFF;
          v59 = v5->MeshVertices.Size >> 4;
          newVer1.Idx = -1;
          *(_DWORD *)&newVer1.Flags = -65534;
          LODWORD(v120.y) = v54;
          newVer1.Styles[1] = v58;
          newVer1.Styles[0] = v58;
          if ( v59 >= v5->MeshVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(&v5->MeshVertices, v59);
          v60 = newVer1.Idx;
          v61 = *(_DWORD *)newVer1.Styles;
          v62 = v5->MeshVertices.Size & 0xF;
          v63 = v5->MeshVertices.Pages[v59];
          v63[v62].x = v48;
          v63[v62].y = v47;
          v63[v62].Idx = v60;
          v64 = *(_DWORD *)&newVer1.Flags;
          *(_DWORD *)v63[v62].Styles = v61;
          *(_DWORD *)&v63[v62].Flags = v64;
          ++v5->MeshVertices.Size;
          v65 = v32->Size >> 4;
          if ( v65 >= v32->NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(v32, v32->Size >> 4);
          v32->Pages[v65][v32->Size & 0xF] = v120;
          ++v32->Size;
          v66 = v5->EdgeFans.Array;
          v67 = v66[v5->EndFan.Pages[v34][retaddr]].rayVer;
          v68 = (signed __int64)&v66[v5->EndFan.Pages[v34][retaddr]];
          v69 = v67->srcVer;
          v70 = v42->rayVer->srcVer;
          v122 = (Scaleform::Render::Tessellator::EdgeAAType *)v68;
          if ( (v70 & 0xFFFFFFF) == (v69 & 0xFFFFFFF) )
          {
            if ( !(v67->aaVer & 0x40000000) )
            {
              v71 = v5->InnerQuads.Size >> 4;
              if ( v71 >= v5->InnerQuads.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->InnerQuads,
                  v5->InnerQuads.Size >> 4);
              v72 = v5->InnerQuads.Pages[v71];
              v73 = v5->InnerQuads.Size & 0xF;
              v72[v73].e1 = v42;
              v72[v73].e2 = (Scaleform::Render::Tessellator::EdgeAAType *)v68;
              ++v5->InnerQuads.Size;
              v42->cntVer->aaVer |= 0x40000000u;
            }
          }
          else
          {
            v74 = 0;
            v75 = v42->cntVer->srcVer;
            v125 = 0;
            if ( (v70 & 0xFFFFFFF) == (v75 & 0xFFFFFFF) || (v69 & 0xFFFFFFF) == (v75 & 0xFFFFFFF) )
            {
              v79 = v5->MeshVertices.Pages;
              v80 = v75 & 0xFFFFFFF;
              v78 = v79[(unsigned __int64)v80 >> 4][v80 & 0xF].x;
              v81 = (unsigned __int64)v80 >> 4;
              v82 = v80 & 0xF;
              newVer1.x = v78;
              v83 = v79[v81];
              v77 = v83[v82].y;
              newVer1.y = v83[v82].y;
            }
            else
            {
              v76 = Scaleform::Render::Tessellator::computeMiter(
                      v5,
                      &v5->MeshVertices.Pages[(unsigned __int64)(v69 & 0xFFFFFFF) >> 4][v69 & 0xF],
                      &v5->MeshVertices.Pages[(unsigned __int64)(v75 & 0xFFFFFFF) >> 4][v75 & 0xF],
                      &v5->MeshVertices.Pages[(unsigned __int64)(v70 & 0xFFFFFFF) >> 4][v70 & 0xF],
                      &newVer1,
                      &v119);
              v77 = newVer1.y;
              v78 = newVer1.x;
              v74 = v76;
              v125 = v76;
            }
            v84 = v5->MeshVertices.Size;
            LODWORD(retaddr) = v5->MeshVertices.Size;
            v85 = *(_WORD *)(v68 + 16) & 0x7FFF;
            v86 = v121->style & 0x7FFF;
            newVer1.Idx = -1;
            *(_DWORD *)&v119.Flags = -65536;
            *(_DWORD *)&newVer1.Flags = -65536;
            newVer1.Styles[1] = v85;
            newVer1.Styles[0] = v85;
            v119.Styles[1] = v86;
            v119.Styles[0] = v86;
            if ( v85 != v86 )
              Scaleform::Render::Tessellator::setMesh(v5, v85, v86);
            v87 = v5->MeshVertices.Size >> 4;
            if ( v87 >= v5->MeshVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
                &v5->MeshVertices,
                v5->MeshVertices.Size >> 4);
            v88 = newVer1.Idx;
            v89 = *(_DWORD *)newVer1.Styles;
            v90 = v5->MeshVertices.Size & 0xF;
            v91 = v5->MeshVertices.Pages[v87];
            v91[v90].x = v78;
            v91[v90].y = v77;
            v91[v90].Idx = v88;
            v92 = *(_DWORD *)&newVer1.Flags;
            *(_DWORD *)v91[v90].Styles = v89;
            *(_DWORD *)&v91[v90].Flags = v92;
            ++v5->MeshVertices.Size;
            if ( v74 )
            {
              v93 = v5->MeshVertices.Size >> 4;
              LODWORD(retaddr) = v5->MeshVertices.Size;
              if ( v93 >= v5->MeshVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
                  &v5->MeshVertices,
                  v5->MeshVertices.Size >> 4);
              v94 = v5->MeshVertices.Pages[v93];
              v95 = v5->MeshVertices.Size & 0xF;
              v94[v95].x = v119.x;
              v94[v95].y = v119.y;
              v96 = *(_DWORD *)v119.Styles;
              v94[v95].Idx = -1;
              *(_DWORD *)v94[v95].Styles = v96;
              *(_DWORD *)&v94[v95].Flags = *(_DWORD *)&v119.Flags;
              ++v5->MeshVertices.Size;
            }
            v97 = v32->Size;
            v98 = v97 - 1;
            v99 = v97 >> 4;
            v100 = v98;
            v101 = v98 & 0xF;
            v102 = v32->Pages[v100 >> 4];
            if ( v99 >= v32->NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(v32, v99);
            v32->Pages[v99][v32->Size & 0xF] = v102[v101];
            v103 = ++v32->Size;
            if ( v125 )
            {
              v104 = v103 - 1;
              v105 = v103 >> 4;
              v106 = v104;
              v107 = v104 & 0xF;
              v108 = v32->Pages[v106 >> 4];
              if ( v105 >= v32->NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(v32, v105);
              v32->Pages[v105][v32->Size & 0xF] = v108[v107];
              ++v32->Size;
              v5->StarVertices.Pages[(v5->StarVertices.Size - 3) >> 4][(LODWORD(v5->StarVertices.Size) - 3) & 0xF].starVer = v84;
              v109 = retaddr;
              v5->StarVertices.Pages[(v5->StarVertices.Size - 2) >> 4][(LODWORD(v5->StarVertices.Size) - 2) & 0xF].starVer = retaddr;
            }
            else
            {
              v109 = retaddr;
              v5->StarVertices.Pages[(v5->StarVertices.Size - 2) >> 4][(LODWORD(v5->StarVertices.Size) - 2) & 0xF].starVer = v84;
            }
            LODWORD(v124) = v109;
            v110 = v5->OuterEdges.Size >> 4;
            if ( v110 >= v5->OuterEdges.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->OuterEdges,
                v5->OuterEdges.Size >> 4);
            v111 = v5->OuterEdges.Pages[v110];
            v112 = v5->OuterEdges.Size & 0xF;
            v111[v112].edge = v121;
            v113 = v124;
            LODWORD(v124) = v84 | 0x40000000;
            *(_QWORD *)&v111[v112].outVer = v113;
            v114 = ++v5->OuterEdges.Size >> 4;
            if ( v114 >= v5->OuterEdges.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::InnerQuadType,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&v5->OuterEdges,
                v5->OuterEdges.Size >> 4);
            v115 = v5->OuterEdges.Pages[v114];
            v116 = v5->OuterEdges.Size & 0xF;
            v115[v116].edge = v122;
            *(_QWORD *)&v115[v116].outVer = v124;
            ++v5->OuterEdges.Size;
          }
          v29 = v123;
        }
        while ( v123 < v5->StartFan.Size );
        v31 = HIDWORD(newVer2);
      }
      if ( v31 + 3 > v5->StarVertices.Size && v31 < v5->StarVertices.Size )
        v5->StarVertices.Size = v31;
    }
    else
    {
      v14 = v5->EdgeFans.Array;
      newVer1.Idx = -1;
      *(_DWORD *)&newVer1.Flags = -65534;
      v15 = v5->MeshVertices.Pages[(unsigned __int64)(v14[v7].cntVer->srcVer & 0xFFFFFFF) >> 4];
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
          ++v18;
          v5->EdgeFans.Array[v18 - 1].cntVer->aaVer = v5->MeshVertices.Size;
          --v19;
        }
        while ( v19 );
      }
      v20 = &v5->MeshVertices;
      v21 = v20->Size >> 4;
      if ( v21 >= v20->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(v20, v20->Size >> 4);
      v22 = newVer1.Idx;
      v23 = *(_DWORD *)newVer1.Styles;
      v24 = v20->Size & 0xF;
      v25 = v20->Pages[v21];
      v25[v24].x = v16;
      v25[v24].y = v17;
      v25[v24].Idx = v22;
      v26 = *(_DWORD *)&newVer1.Flags;
      *(_DWORD *)v25[v24].Styles = v23;
      *(_DWORD *)&v25[v24].Flags = v26;
      ++v20->Size;
    }
  }
}

// File Line: 2780
// RVA: 0x9E0940
void __fastcall Scaleform::Render::Tessellator::emitTriangles(Scaleform::Render::Tessellator *this)
{
  unsigned int v1; // er8
  Scaleform::Render::Tessellator *v2; // r13
  unsigned __int64 v3; // rdi
  Scaleform::Render::Tessellator::MonotoneType *v4; // rdi
  unsigned int v5; // er9
  unsigned int v6; // er12
  signed int v7; // esi
  unsigned int v8; // er14
  int flags; // esi
  signed __int64 v10; // r15
  signed __int64 v11; // rbx
  __int64 v12; // rax
  int v13; // ecx
  __int64 v14; // rax
  unsigned __int64 v15; // rdx
  unsigned __int64 v16; // rcx
  signed __int64 v17; // rdx
  Scaleform::Render::Tessellator::InnerQuadType *v18; // rax
  Scaleform::Render::Tessellator::EdgeAAType *v19; // r14
  Scaleform::Render::Tessellator::EdgeAAType *v20; // r15
  int v21; // ebx
  int v22; // edi
  unsigned int v23; // er10
  signed __int64 v24; // rsi
  Scaleform::Render::TessMesh *v25; // r8
  unsigned int v26; // ecx
  Scaleform::Render::Tessellator::EdgeAAType *v27; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v28; // rdx
  signed int v29; // er14
  int v30; // eax
  unsigned int v31; // er15
  int v32; // er14
  signed __int64 v33; // rsi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v34; // rbx
  unsigned __int64 v35; // rdi
  signed __int64 v36; // rdx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v37; // rbx
  unsigned __int64 v38; // rdi
  signed __int64 v39; // rdx
  signed __int64 v40; // rsi
  unsigned __int64 v41; // r14
  unsigned int v42; // edx
  unsigned __int64 v43; // rbx
  Scaleform::Render::Tessellator::OuterEdgeType **v44; // r12
  unsigned int *v45; // rbx
  __int64 v46; // r8
  __int64 v47; // r10
  unsigned __int64 v48; // r11
  __int64 v49; // rsi
  unsigned __int64 *v50; // rax
  bool v51; // cf
  int v52; // er12
  unsigned int v53; // er14
  unsigned int v54; // er15
  __int64 v55; // rdi
  unsigned int v56; // esi
  unsigned int v57; // eax
  unsigned int *v58; // rdi
  unsigned int v59; // eax
  signed __int64 v60; // r14
  int v61; // er12
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v62; // rbx
  unsigned __int64 v63; // rdi
  Scaleform::Render::Tessellator::TriangleType *v64; // rdx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v65; // rbx
  unsigned __int64 v66; // rdi
  Scaleform::Render::Tessellator::TriangleType *v67; // rdx
  unsigned __int64 v68; // rdx
  unsigned int v69; // er12
  Scaleform::Render::Tessellator::StarVertexType **v70; // r8
  unsigned __int64 v71; // r9
  unsigned __int64 v72; // rax
  unsigned int v73; // er14
  Scaleform::Render::Tessellator::StarVertexType *v74; // r11
  signed __int64 v75; // rcx
  signed __int64 v76; // rax
  unsigned int *v77; // r11
  Scaleform::Render::TessVertex **v78; // r10
  unsigned int v79; // edx
  unsigned int v80; // er8
  unsigned int v81; // ecx
  unsigned __int64 v82; // rax
  signed __int64 v83; // rcx
  Scaleform::Render::TessVertex *v84; // rax
  unsigned __int64 v85; // rdi
  signed __int64 v86; // r9
  Scaleform::Render::TessVertex *v87; // rax
  unsigned __int64 v88; // r15
  unsigned int v89; // edx
  Scaleform::Render::TessVertex *v90; // rax
  unsigned int v91; // esi
  unsigned int v92; // ebx
  unsigned int v93; // ecx
  unsigned __int64 v94; // rcx
  Scaleform::Render::Tessellator::StarVertexType **v95; // rdx
  unsigned int v96; // ecx
  Scaleform::Render::TessVertex **v97; // r8
  unsigned __int64 v98; // rax
  signed __int64 v99; // rcx
  Scaleform::Render::TessVertex *v100; // rax
  unsigned int v101; // edi
  int v102; // er12
  Scaleform::Render::TessVertex *v103; // rax
  unsigned int v104; // er15
  int v105; // esi
  unsigned int v106; // eax
  unsigned int v107; // er10
  Scaleform::Render::TessMesh *v108; // rbx
  unsigned int v109; // eax
  unsigned int v110; // edx
  unsigned int v111; // eax
  Scaleform::Render::Tessellator::StarVertexType **v112; // rcx
  unsigned int v113; // er10
  unsigned int v114; // er11
  Scaleform::Render::TessMesh *v115; // rcx
  unsigned int *v116; // rdx
  unsigned int v117; // er8
  int v118; // er12
  int v119; // edi
  int v120; // er15
  unsigned int v121; // eax
  unsigned int v122; // eax
  bool v123; // zf
  unsigned int v124; // ecx
  unsigned int v125; // ecx
  unsigned int v126; // er12
  signed __int64 v127; // rsi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v128; // rdi
  unsigned __int64 v129; // rbx
  signed __int64 v130; // rdx
  unsigned int v131; // er12
  int v132; // eax
  int v133; // ecx
  int v134; // ecx
  int v135; // eax
  unsigned int v136; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v137; // rbx
  unsigned __int64 v138; // rdi
  signed __int64 v139; // rdx
  unsigned int ver; // [rsp+40h] [rbp-59h]
  unsigned int vera; // [rsp+40h] [rbp-59h]
  unsigned int verb; // [rsp+40h] [rbp-59h]
  __int128 v143; // [rsp+48h] [rbp-51h]
  Scaleform::Render::Tessellator::MonoVertexType *v144; // [rsp+58h] [rbp-41h]
  Scaleform::Render::Tessellator::MonoVertexType *v145; // [rsp+60h] [rbp-39h]
  __int64 v146; // [rsp+60h] [rbp-39h]
  Scaleform::Render::Tessellator::MonoVertexType *v147; // [rsp+68h] [rbp-31h]
  unsigned int v148; // [rsp+68h] [rbp-31h]
  unsigned int v149; // [rsp+68h] [rbp-31h]
  unsigned int v150; // [rsp+70h] [rbp-29h]
  unsigned int v151; // [rsp+74h] [rbp-25h]
  unsigned int v152; // [rsp+78h] [rbp-21h]
  __int64 v153; // [rsp+80h] [rbp-19h]
  signed __int64 v154; // [rsp+88h] [rbp-11h]
  unsigned __int64 v155; // [rsp+90h] [rbp-9h]
  signed __int64 v156; // [rsp+98h] [rbp-1h]
  signed __int64 v157; // [rsp+A0h] [rbp+7h]
  unsigned __int64 v158; // [rsp+A8h] [rbp+Fh]
  unsigned int style2; // [rsp+100h] [rbp+67h]
  unsigned int style2a; // [rsp+100h] [rbp+67h]
  unsigned int style2b; // [rsp+100h] [rbp+67h]
  unsigned int style2c; // [rsp+100h] [rbp+67h]
  unsigned int style2d; // [rsp+100h] [rbp+67h]
  unsigned int meshIdx; // [rsp+108h] [rbp+6Fh]
  unsigned int meshIdxa; // [rsp+108h] [rbp+6Fh]
  unsigned int meshIdxb; // [rsp+108h] [rbp+6Fh]
  unsigned int meshIdxc; // [rsp+108h] [rbp+6Fh]
  Scaleform::Render::Tessellator::MonoVertexType *style1; // [rsp+110h] [rbp+77h]
  unsigned int *style1a; // [rsp+110h] [rbp+77h]
  int style1b; // [rsp+110h] [rbp+77h]
  unsigned int style1c; // [rsp+110h] [rbp+77h]
  unsigned int style1d; // [rsp+110h] [rbp+77h]
  Scaleform::Render::Tessellator::MonoVertexType *v173; // [rsp+118h] [rbp+7Fh]
  signed __int64 v174; // [rsp+118h] [rbp+7Fh]
  unsigned int v175; // [rsp+118h] [rbp+7Fh]
  unsigned int v176; // [rsp+118h] [rbp+7Fh]

  v1 = 0;
  v2 = this;
  style2 = 0;
  if ( this->Monotones.Size )
  {
    v3 = 0i64;
    do
    {
      v4 = &v2->Monotones.Pages[v3 >> 4][v3 & 0xF];
      v5 = v4->d.m.prevIdx1;
      if ( v5 )
      {
        v6 = v4->d.m.prevIdx2;
        v7 = 0;
        if ( v4->style == v2->Meshes.Pages[(unsigned __int64)v6 >> 4][v4->d.m.prevIdx2 & 0xF].Style1 )
          v7 = 8;
        v8 = 0;
        flags = v7 | 2;
        if ( v5 )
        {
          v10 = v4->d.m.prevIdx2;
          do
          {
            v11 = (signed __int64)&v2->MeshTriangles.Arrays[v10].Pages[(unsigned __int64)(v8 + v4->d.m.lastIdx) >> 4][((_BYTE)v8 + LOBYTE(v4->d.m.lastIdx)) & 0xF];
            *(_DWORD *)(*(_QWORD *)v11 + 4i64) = Scaleform::Render::Tessellator::emitVertex(
                                                   v2,
                                                   v6,
                                                   *(_DWORD *)(*(_QWORD *)v11 + 4i64),
                                                   v4->style,
                                                   flags);
            *(_DWORD *)(*(_QWORD *)(v11 + 8) + 4i64) = Scaleform::Render::Tessellator::emitVertex(
                                                         v2,
                                                         v6,
                                                         *(_DWORD *)(*(_QWORD *)(v11 + 8) + 4i64),
                                                         v4->style,
                                                         flags);
            ++v8;
            *(_DWORD *)(*(_QWORD *)(v11 + 16) + 4i64) = Scaleform::Render::Tessellator::emitVertex(
                                                          v2,
                                                          v6,
                                                          *(_DWORD *)(*(_QWORD *)(v11 + 16) + 4i64),
                                                          v4->style,
                                                          flags);
            v12 = *(_QWORD *)(v11 + 8);
            *(_DWORD *)v11 = *(_DWORD *)(*(_QWORD *)v11 + 4i64) & 0xFFFFFFF;
            v13 = *(_DWORD *)(v12 + 4);
            v14 = *(_QWORD *)(v11 + 16);
            *(_DWORD *)(v11 + 4) = v13 & 0xFFFFFFF;
            *(_DWORD *)(v11 + 8) = *(_DWORD *)(v14 + 4) & 0xFFFFFFF;
          }
          while ( v8 < v4->d.m.prevIdx1 );
          v1 = style2;
        }
      }
      v3 = ++v1;
      style2 = v1;
    }
    while ( v1 < v2->Monotones.Size );
  }
  style2a = 0;
  if ( v2->InnerQuads.Size )
  {
    v15 = 0i64;
    do
    {
      v16 = v15;
      v17 = v15 & 0xF;
      v18 = v2->InnerQuads.Pages[v16 >> 4];
      v19 = v18[v17].e1;
      v20 = v18[v17].e2;
      v21 = v19->style & 0x7FFF;
      v22 = v20->style & 0x7FFF;
      v23 = Scaleform::Render::Tessellator::setMesh(v2, v21, v22);
      meshIdx = v23;
      v24 = v23;
      v25 = &v2->Meshes.Pages[(unsigned __int64)v23 >> 4][v23 & 0xF];
      v26 = v25->Style1;
      if ( v26 && v21 != v26 )
      {
        v27 = v19;
        v19 = v20;
        v20 = v27;
        LODWORD(v27) = v21;
        v21 = v22;
        v22 = (signed int)v27;
      }
      v28 = v19->cntVer;
      v145 = v19->rayVer;
      v29 = 0;
      v173 = v20->rayVer;
      style1 = v28;
      v30 = v25->Flags1 ^ v25->Flags2;
      v147 = v20->cntVer;
      v31 = v21;
      if ( _bittest(&v30, 0xFu) )
      {
        v31 = v22;
        v29 = 32;
      }
      v32 = v29 | 0xA;
      v28->aaVer = Scaleform::Render::Tessellator::emitVertex(v2, v23, v28->aaVer, v21, v31, v32, 0);
      v145->aaVer = Scaleform::Render::Tessellator::emitVertex(v2, meshIdx, v145->aaVer, v21, v31, v32, 0);
      v147->aaVer = Scaleform::Render::Tessellator::emitVertex(v2, meshIdx, v147->aaVer, v22, 2u);
      v33 = v24;
      v173->aaVer = Scaleform::Render::Tessellator::emitVertex(v2, meshIdx, v173->aaVer, v22, 2u);
      v34 = &v2->MeshTriangles.Arrays[v33];
      LODWORD(v143) = style1->aaVer & 0xFFFFFFF;
      v35 = v34->Size >> 4;
      DWORD1(v143) = v145->aaVer & 0xFFFFFFF;
      DWORD2(v143) = v147->aaVer & 0xFFFFFFF;
      if ( v35 >= v34->NumPages )
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
          &v2->MeshTriangles,
          v34,
          v35);
      v36 = (signed __int64)&v34->Pages[v35][v34->Size & 0xF];
      *(_OWORD *)v36 = v143;
      *(_QWORD *)(v36 + 16) = v144;
      ++v2->MeshTriangles.Arrays[v33].Size;
      v37 = &v2->MeshTriangles.Arrays[v33];
      LODWORD(v143) = v173->aaVer & 0xFFFFFFF;
      v38 = v37->Size >> 4;
      DWORD1(v143) = v147->aaVer & 0xFFFFFFF;
      DWORD2(v143) = v145->aaVer & 0xFFFFFFF;
      if ( v38 >= v37->NumPages )
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
          &v2->MeshTriangles,
          v37,
          v38);
      v39 = (signed __int64)&v37->Pages[v38][v37->Size & 0xF];
      *(_OWORD *)v39 = v143;
      *(_QWORD *)(v39 + 16) = v144;
      ++v2->MeshTriangles.Arrays[v33].Size;
      v15 = ++style2a;
    }
    while ( style2a < v2->InnerQuads.Size );
  }
  v40 = (signed __int64)&v2->OuterEdges;
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::OuterEdgeType,4,16>,bool (*)(Scaleform::Render::Tessellator::OuterEdgeType const &,Scaleform::Render::Tessellator::OuterEdgeType const &)>(
    &v2->OuterEdges,
    0i64,
    v2->OuterEdges.Size,
    Scaleform::Render::Tessellator::cmpOuterEdges);
  v41 = v2->OuterEdges.Size;
  v42 = 0;
  style2b = 0;
  if ( v41 )
  {
    v43 = 0i64;
    do
    {
      v44 = v2->OuterEdges.Pages;
      v45 = (unsigned int *)&v44[v43 >> 4][v43 & 0xF];
      style1a = v45;
      if ( !(v45[2] & 0x40000000) )
      {
        v46 = *(_QWORD *)(v40 + 8);
        v47 = 0i64;
        v48 = *(_QWORD *)(*(_QWORD *)v45 + 8i64);
        if ( v46 > 0 )
        {
          v49 = *(_QWORD *)(v40 + 32);
          do
          {
            v50 = *(unsigned __int64 **)(*(_QWORD *)(v49 + 8 * ((unsigned __int64)((v46 >> 1) + v47) >> 4))
                                       + 16i64 * (((unsigned __int8)(v46 >> 1) + (_BYTE)v47) & 0xF));
            v51 = *v50 < v48;
            if ( *v50 == v48 )
              v51 = v50[1] < **(_QWORD **)v45;
            if ( v51 )
            {
              v47 += (v46 >> 1) + 1;
              v46 += -1 - (v46 >> 1);
            }
            else
            {
              v46 >>= 1;
            }
          }
          while ( v46 > 0 );
          v42 = style2b;
        }
        if ( (unsigned int)v47 < v41 )
        {
          v174 = (signed __int64)&v44[(unsigned __int64)(unsigned int)v47 >> 4][v47 & 0xF];
          if ( **(_QWORD **)v174 == v48 )
          {
            v52 = *(_WORD *)(*(_QWORD *)v45 + 16i64) & 0x7FFF;
            v53 = 0;
            v54 = Scaleform::Render::Tessellator::setMesh(v2, v52);
            if ( v52 == v2->Meshes.Pages[(unsigned __int64)v54 >> 4][v54 & 0xF].Style1 )
              v53 = 8;
            v55 = *(_QWORD *)(*(_QWORD *)v45 + 8i64);
            v56 = Scaleform::Render::Tessellator::emitVertex(
                    v2,
                    v54,
                    *(_DWORD *)(**(_QWORD **)v45 + 4i64),
                    v52,
                    v53 | 2);
            v57 = Scaleform::Render::Tessellator::emitVertex(v2, v54, *(_DWORD *)(v55 + 4), v52, v53 | 2);
            v58 = v45;
            meshIdxa = v57;
            v45[2] = Scaleform::Render::Tessellator::emitVertex(v2, v54, v45[2], v52, v53) | 0x40000000;
            v59 = Scaleform::Render::Tessellator::emitVertex(v2, v54, *(_DWORD *)(v174 + 8), v52, v53);
            *(_DWORD *)(v174 + 8) = v59 | 0x40000000;
            v60 = v54;
            v61 = (v59 | 0x40000000) & 0xFFFFFFF;
            v62 = &v2->MeshTriangles.Arrays[v60];
            style1b = style1a[2] & 0xFFFFFFF;
            DWORD2(v143) = v58[2] & 0xFFFFFFF;
            v63 = v62->Size >> 4;
            if ( v63 >= v62->NumPages )
              Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
                &v2->MeshTriangles,
                v62,
                v62->Size >> 4);
            v64 = &v62->Pages[v63][v62->Size & 0xF];
            v64->d.m.v1 = (Scaleform::Render::Tessellator::MonoVertexType *)__PAIR__(meshIdxa, v56);
            v64->d.m.v2 = (Scaleform::Render::Tessellator::MonoVertexType *)*((_QWORD *)&v143 + 1);
            v64->d.m.v3 = v144;
            ++v2->MeshTriangles.Arrays[v60].Size;
            v65 = &v2->MeshTriangles.Arrays[v60];
            DWORD2(v143) = meshIdxa;
            v66 = v65->Size >> 4;
            if ( v66 >= v65->NumPages )
              Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
                &v2->MeshTriangles,
                v65,
                v66);
            v67 = &v65->Pages[v66][v65->Size & 0xF];
            v67->d.m.v1 = (Scaleform::Render::Tessellator::MonoVertexType *)__PAIR__(style1b, v61);
            v67->d.m.v2 = (Scaleform::Render::Tessellator::MonoVertexType *)*((_QWORD *)&v143 + 1);
            v67->d.m.v3 = v144;
            ++v2->MeshTriangles.Arrays[v60].Size;
            v42 = style2b;
          }
        }
      }
      v41 = v2->OuterEdges.Size;
      ++v42;
      v40 = (signed __int64)&v2->OuterEdges;
      v43 = v42;
      style2b = v42;
    }
    while ( v42 < v41 );
  }
  v68 = v2->StarVertices.Size;
  v69 = 0;
  v175 = 0;
  if ( v68 )
  {
    while ( 1 )
    {
      v70 = v2->StarVertices.Pages;
      v71 = v69;
      v72 = (unsigned __int64)v69 >> 4;
      v146 = v69;
      v73 = v69;
      v74 = v70[v72];
      v75 = 8 * v72;
      v76 = v69 & 0xF;
      v154 = v75;
      v77 = (unsigned int *)&v74[v76];
      v156 = v76;
      v148 = *v77;
      do
        ++v73;
      while ( v73 < v68 && *v77 == v70[(unsigned __int64)v73 >> 4][v73 & 0xF].cntVer );
      if ( v69 + 3 == v73 )
        break;
LABEL_54:
      v94 = v73 - 1;
      if ( v69 < v73 )
      {
        do
        {
          v95 = v2->StarVertices.Pages;
          style2d = v95[v94 >> 4][v94 & 0xF].starVer;
          v96 = v95[v94 >> 4][v94 & 0xF].starVer;
          v97 = v2->MeshVertices.Pages;
          v98 = v96;
          meshIdxc = v95[v71 >> 4][v71 & 0xF].starVer;
          v99 = v96 & 0xF;
          v100 = v97[v98 >> 4];
          v101 = v100[v99].Styles[0];
          v102 = v100[v99].Flags & 2;
          v103 = v97[(unsigned __int64)meshIdxc >> 4];
          v104 = v103[meshIdxc & 0xF].Styles[0];
          style1d = v102;
          v105 = v103[meshIdxc & 0xF].Flags & 2;
          v106 = Scaleform::Render::Tessellator::setMesh(v2, v101, v104);
          v107 = v106;
          v153 = v106;
          vera = v106;
          v108 = &v2->Meshes.Pages[(unsigned __int64)v106 >> 4][v106 & 0xF];
          v109 = v108->Style1;
          if ( v109 && v101 != v109 )
          {
            v110 = meshIdxc;
            style1d = v105;
            meshIdxc = style2d;
            v111 = v101;
            v101 = v104;
            v104 = v111;
            v105 = v102;
          }
          else
          {
            v110 = style2d;
          }
          v131 = v101;
          v132 = v108->Flags2 ^ v108->Flags1;
          v133 = style1d | 8;
          if ( _bittest(&v132, 0xFu) )
          {
            v131 = v104;
            v133 = style1d | 0x28;
          }
          LODWORD(v143) = Scaleform::Render::Tessellator::emitVertex(v2, v107, v110, v101, v131, v133, 0);
          DWORD1(v143) = Scaleform::Render::Tessellator::emitVertex(v2, vera, meshIdxc, v104, v105);
          v134 = v108->Flags2 | v108->Flags1;
          v135 = (((unsigned __int8)style1d & (unsigned __int8)v105 & 2) != 0) + 1;
          if ( _bittest(&v134, 0xFu) )
          {
            v136 = v135 & 0xFFFFFFF7 | 0x24;
          }
          else
          {
            v131 = v104;
            v136 = v135 | 0x10;
          }
          DWORD2(v143) = Scaleform::Render::Tessellator::emitVertex(v2, vera, v148, v101, v131, v136, 1);
          v137 = &v2->MeshTriangles.Arrays[v153];
          v138 = v137->Size >> 4;
          if ( v138 >= v137->NumPages )
            Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
              &v2->MeshTriangles,
              v137,
              v137->Size >> 4);
          v71 = v146 + 1;
          v139 = (signed __int64)&v137->Pages[v138][v137->Size & 0xF];
          v94 = v175;
          *(_OWORD *)v139 = v143;
          ++v175;
          *(_QWORD *)(v139 + 16) = v144;
          ++v146;
          ++v2->MeshTriangles.Arrays[v153].Size;
        }
        while ( v175 < v73 );
      }
LABEL_94:
      v68 = v2->StarVertices.Size;
      v69 = v73;
      v175 = v73;
      if ( v73 >= v68 )
        return;
    }
    v78 = v2->MeshVertices.Pages;
    v158 = (unsigned __int64)(v69 + 1) >> 4;
    v79 = v70[v158][((_BYTE)v69 + 1) & 0xF].starVer;
    v157 = ((_BYTE)v69 + 1) & 0xF;
    v155 = (unsigned __int64)(v69 + 2) >> 4;
    v80 = v70[v155][((_BYTE)v69 + 2) & 0xF].starVer;
    v81 = v77[1];
    v82 = v81;
    v83 = v81 & 0xF;
    v84 = v78[v82 >> 4];
    v85 = v84[v83].Styles[0];
    v86 = (signed __int64)&v84[v83];
    style1c = v85;
    v87 = v78[(unsigned __int64)v79 >> 4];
    v88 = v87[v79 & 0xF].Styles[0];
    v89 = v87[v79 & 0xF].Flags;
    v151 = *(unsigned __int16 *)(v86 + 16);
    v90 = v78[(unsigned __int64)v80 >> 4];
    v152 = v89;
    v91 = v90[v80 & 0xF].Styles[0];
    meshIdxb = v88;
    v150 = v90[v80 & 0xF].Flags;
    style2c = v90[v80 & 0xF].Styles[0];
    ver = Scaleform::Render::Tessellator::setMesh(v2, v85, v88);
    v92 = Scaleform::Render::Tessellator::setMesh(v2, v88, v91);
    v93 = Scaleform::Render::Tessellator::setMesh(v2, v91, v85);
    if ( ver == v92 || ver == v93 )
    {
      v92 = ver;
    }
    else if ( v92 != v93 )
    {
LABEL_53:
      v71 = v69;
      goto LABEL_54;
    }
    if ( v92 != -1 )
    {
      v112 = v2->StarVertices.Pages;
      v113 = (*(Scaleform::Render::Tessellator::StarVertexType **)((char *)v112 + v154))[v156].starVer;
      v114 = v112[v158][v157].starVer;
      v149 = (*(Scaleform::Render::Tessellator::StarVertexType **)((char *)v112 + v154))[v156].starVer;
      v176 = v112[v158][v157].starVer;
      verb = v112[v155][((_BYTE)v69 + 2) & 0xF].starVer;
      *(_QWORD *)((char *)&v143 + 4) = -1i64;
      v115 = v2->Meshes.Pages[(unsigned __int64)v92 >> 4];
      LODWORD(v143) = -1;
      LODWORD(v115) = v115[v92 & 0xF].Flags1 ^ v115[v92 & 0xF].Flags2;
      if ( _bittest((const signed int *)&v115, 0xFu) )
      {
        v116 = v2->ComplexFlags.Array;
        v117 = style2c;
        v118 = v116[v85 >> 5] & (1 << (v85 & 0x1F));
        v119 = v116[v88 >> 5] & (1 << (v88 & 0x1F));
        v120 = v116[(unsigned __int64)style2c >> 5] & (1 << (style2c & 0x1F));
        if ( v118 )
        {
          v121 = meshIdxb;
          if ( v119 )
            v121 = style2c;
          v122 = Scaleform::Render::Tessellator::emitVertex(v2, v92, v113, style1c, v121, v151 | 0x20, 0);
          v117 = style2c;
          v114 = v176;
          LODWORD(v143) = v122;
        }
        v123 = v119 == 0;
        LODWORD(v85) = style1c;
        if ( !v123 )
        {
          v124 = v117;
          if ( v120 )
            v124 = style1c;
          DWORD1(v143) = Scaleform::Render::Tessellator::emitVertex(v2, v92, v114, meshIdxb, v124, v152 | 0x20, 0);
        }
        v123 = v120 == 0;
        LODWORD(v88) = meshIdxb;
        if ( v123 )
        {
          v126 = style2c;
        }
        else
        {
          v125 = style1c;
          v123 = v118 == 0;
          v126 = style2c;
          if ( !v123 )
            v125 = meshIdxb;
          DWORD2(v143) = Scaleform::Render::Tessellator::emitVertex(v2, v92, verb, style2c, v125, v150 | 0x20, 0);
        }
        if ( (_DWORD)v143 == -1 )
        {
          v113 = v149;
          goto LABEL_76;
        }
      }
      else
      {
        v126 = style2c;
LABEL_76:
        LODWORD(v143) = Scaleform::Render::Tessellator::emitVertex(v2, v92, v113, v85, v151);
      }
      if ( DWORD1(v143) == -1 )
        DWORD1(v143) = Scaleform::Render::Tessellator::emitVertex(v2, v92, v176, v88, v152);
      if ( DWORD2(v143) == -1 )
        DWORD2(v143) = Scaleform::Render::Tessellator::emitVertex(v2, v92, verb, v126, v150);
      v127 = v92;
      v128 = &v2->MeshTriangles.Arrays[v127];
      v129 = v128->Size >> 4;
      if ( v129 >= v128->NumPages )
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
          &v2->MeshTriangles,
          &v2->MeshTriangles.Arrays[v127],
          v128->Size >> 4);
      v130 = (signed __int64)&v128->Pages[v129][v128->Size & 0xF];
      *(_OWORD *)v130 = v143;
      *(_QWORD *)(v130 + 16) = v144;
      ++v2->MeshTriangles.Arrays[v127].Size;
      goto LABEL_94;
    }
    goto LABEL_53;
  }
}16) = v144;
      ++v2->MeshTriangles.Arrays[v127].Size;
      goto LABEL_94;
    }
    goto LABEL_53;
  }
}

// File Line: 3058
// RVA: 0x9EA0C0
void __fastcall Scaleform::Render::Tessellator::moveVertexAA(Scaleform::Render::Tessellator *this, Scaleform::Render::TessVertex *refVer, Scaleform::Render::TessVertex *aaVer, Scaleform::Render::TessVertex *v2, Scaleform::Render::TessVertex *v3)
{
  float v5; // xmm8_4
  float v6; // xmm11_4
  float v7; // xmm10_4
  float v8; // xmm15_4
  float v9; // xmm9_4
  float v10; // xmm14_4
  float v11; // xmm13_4
  float v12; // xmm12_4
  float v13; // xmm1_4

  v5 = refVer->x;
  v6 = refVer->y;
  v7 = aaVer->y - v6;
  v8 = v2->y;
  v9 = aaVer->x - refVer->x;
  v10 = v3->x - v2->x;
  v11 = v3->y - v8;
  v12 = (float)(v9 * v11) - (float)(v10 * v7);
  if ( COERCE_FLOAT(LODWORD(v12) & _xmm) < (float)((float)((float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(refVer->y - aaVer->y) & _xmm)
                                                                         + COERCE_FLOAT(COERCE_UNSIGNED_INT(refVer->x - aaVer->x) & _xmm))
                                                                 + COERCE_FLOAT(COERCE_UNSIGNED_INT(v2->x - v3->x) & _xmm))
                                                         + COERCE_FLOAT(COERCE_UNSIGNED_INT(v2->y - v3->y) & _xmm))
                                                 * this->IntersectionEpsilon)
    || (v13 = (float)((float)((float)(v6 - v8) * v10) - (float)((float)(v5 - v2->x) * v11)) / v12, v13 <= 0.0)
    || v13 >= 1.0 )
  {
    aaVer->x = v5;
    aaVer->y = refVer->y;
  }
  else
  {
    aaVer->x = (float)((float)(v5 - (float)((float)(v9 * v13) + v5)) * 0.125) + (float)((float)(v9 * v13) + v5);
    aaVer->y = (float)((float)(refVer->y - (float)((float)(v7 * v13) + v6)) * 0.125) + (float)((float)(v7 * v13) + v6);
  }
}

// File Line: 3082
// RVA: 0x9CAF40
void __fastcall Scaleform::Render::Tessellator::addTriangleAA(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::MonoVertexType *v1, Scaleform::Render::Tessellator::MonoVertexType *v2, Scaleform::Render::Tessellator::MonoVertexType *v3, float cp)
{
  Scaleform::Render::Tessellator::MonoVertexType *v5; // r12
  Scaleform::Render::Tessellator::MonoVertexType *v6; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v7; // r14
  Scaleform::Render::Tessellator *v8; // rbx
  Scaleform::Render::TessVertex **v9; // r8
  Scaleform::Render::TessVertex *v10; // rdi
  Scaleform::Render::TessVertex *v11; // rsi
  Scaleform::Render::TessVertex *v12; // rax
  float v13; // xmm3_4
  Scaleform::Render::TessVertex *v14; // rbp
  float v15; // xmm0_4
  Scaleform::Render::TessVertex *v16; // rax
  Scaleform::Render::TessVertex *v17; // rdx
  Scaleform::Render::TessVertex *v18; // r13
  Scaleform::Render::Tessellator::MonoVertexType *v19; // ST30_8
  unsigned int v20; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *v21; // rbp
  signed __int64 v22; // rsi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v23; // rdi
  unsigned __int64 v24; // rbx
  signed __int64 v25; // rdx
  Scaleform::Render::Tessellator::TriangleType *v26; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v27; // [rsp+38h] [rbp-50h]
  Scaleform::Render::Tessellator::MonoVertexType *v28; // [rsp+40h] [rbp-48h]
  signed __int64 v29; // [rsp+90h] [rbp+8h]

  v5 = v3;
  v6 = v2;
  v7 = v1;
  v8 = this;
  if ( this->EdgeAAFlag )
  {
    v9 = this->MeshVertices.Pages;
    v10 = &v9[(unsigned __int64)(v1->srcVer & 0xFFFFFFF) >> 4][v1->srcVer & 0xF];
    v11 = &v9[(unsigned __int64)(v6->srcVer & 0xFFFFFFF) >> 4][v6->srcVer & 0xF];
    v12 = v9[(unsigned __int64)(v3->srcVer & 0xFFFFFFF) >> 4];
    v13 = v12[v3->srcVer & 0xF].x;
    v14 = &v12[v3->srcVer & 0xF];
    v15 = v12[v3->srcVer & 0xF].y;
    v16 = v9[(unsigned __int64)(v1->aaVer & 0xFFFFFFF) >> 4];
    v17 = &v9[(unsigned __int64)(v6->aaVer & 0xFFFFFFF) >> 4][v6->aaVer & 0xF];
    v29 = (signed __int64)&v9[(unsigned __int64)(v6->aaVer & 0xFFFFFFF) >> 4][v6->aaVer & 0xF];
    v18 = &v9[(unsigned __int64)(v3->aaVer & 0xFFFFFFF) >> 4][v3->aaVer & 0xF];
    if ( (float)((float)((float)(v16[v7->aaVer & 0xF].x - v13) * (float)(v15 - v11->y))
               - (float)((float)(v16[v7->aaVer & 0xF].y - v15) * (float)(v13 - v11->x))) >= 0.0 )
    {
      Scaleform::Render::Tessellator::moveVertexAA(this, v10, &v16[v7->aaVer & 0xF], v11, v14);
      v17 = (Scaleform::Render::TessVertex *)v29;
    }
    if ( (float)((float)((float)(v10->y - v14->y) * (float)(v17->x - v10->x))
               - (float)((float)(v17->y - v10->y) * (float)(v10->x - v14->x))) >= 0.0 )
      Scaleform::Render::Tessellator::moveVertexAA(v8, v11, v17, v14, v10);
    if ( (float)((float)((float)(v18->x - v11->x) * (float)(v11->y - v10->y))
               - (float)((float)(v18->y - v11->y) * (float)(v11->x - v10->x))) >= 0.0 )
      Scaleform::Render::Tessellator::moveVertexAA(v8, v14, v18, v10, v11);
  }
  else
  {
    LODWORD(v19) = Scaleform::Render::Tessellator::emitVertex(
                     this,
                     this->MeshIdx,
                     v1->srcVer & 0xFFFFFFF,
                     this->MonoStyle,
                     this->FactorOneFlag);
    HIDWORD(v19) = Scaleform::Render::Tessellator::emitVertex(
                     v8,
                     v8->MeshIdx,
                     v6->srcVer & 0xFFFFFFF,
                     v8->MonoStyle,
                     v8->FactorOneFlag);
    v20 = Scaleform::Render::Tessellator::emitVertex(
            v8,
            v8->MeshIdx,
            v5->srcVer & 0xFFFFFFF,
            v8->MonoStyle,
            v8->FactorOneFlag);
    v5 = v28;
    v7 = v19;
    LODWORD(v27) = v20;
    v6 = v27;
  }
  v21 = &v8->MeshTriangles;
  v22 = v8->MeshIdx;
  v23 = &v8->MeshTriangles.Arrays[v22];
  v24 = v23->Size >> 4;
  if ( v24 >= v23->NumPages )
    Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
      v21,
      v23,
      v23->Size >> 4);
  v25 = v23->Size & 0xF;
  v26 = v23->Pages[v24];
  v26[v25].d.m.v1 = v7;
  v26[v25].d.m.v2 = v6;
  v26[v25].d.m.v3 = v5;
  ++v21->Arrays[v22].Size;
}

// File Line: 3152
// RVA: 0x9F77C0
void __fastcall Scaleform::Render::Tessellator::triangulateMountainAA(Scaleform::Render::Tessellator *this)
{
  unsigned __int64 v1; // r9
  Scaleform::Render::Tessellator *v2; // rbp
  Scaleform::Render::Tessellator::MonoVertexType ***v3; // r11
  Scaleform::Render::TessVertex **v4; // r10
  unsigned int v5; // er13
  float v6; // xmm2_4
  signed __int64 v7; // r8
  Scaleform::Render::TessVertex *v8; // rdi
  Scaleform::Render::TessVertex *v9; // rdx
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  char v14; // cl
  unsigned __int64 v15; // rax
  unsigned int v16; // edx
  signed int v17; // edi
  unsigned int v18; // ecx
  unsigned int v19; // er15
  Scaleform::Render::Tessellator::MonoVertexType ***v20; // r14
  Scaleform::Render::TessVertex **v21; // r12
  unsigned int v22; // edi
  unsigned __int64 v23; // rsi
  Scaleform::Render::TessVertex *v24; // r10
  Scaleform::Render::TessVertex *v25; // r8
  unsigned int v26; // ebx
  Scaleform::Render::TessVertex *v27; // rax
  float v28; // xmm8_4
  Scaleform::Render::TessVertex *v29; // rcx
  float v30; // xmm6_4
  unsigned int v31; // edi
  __int64 v32; // rdx
  unsigned int v33; // ebx
  Scaleform::Render::TessVertex *v34; // r10
  Scaleform::Render::TessVertex *v35; // r8
  Scaleform::Render::TessVertex *v36; // rcx
  signed __int64 v37; // rdx
  float v38; // xmm9_4
  Scaleform::Render::TessVertex *v39; // r10
  Scaleform::Render::TessVertex *v40; // r8
  Scaleform::Render::TessVertex *v41; // rcx
  float v42; // xmm0_4
  unsigned int v43; // ebx
  float v44; // xmm2_4
  int v45; // xmm1_4
  float v46; // xmm0_4
  unsigned __int64 v47; // r8
  __int64 v48; // r9
  Scaleform::Render::Tessellator::MonoVertexType ***v49; // rax
  unsigned int v50; // eax
  Scaleform::Render::Tessellator::MonoVertexType **v51; // rdx
  Scaleform::Render::Tessellator::MonoVertexType **v52; // rcx
  Scaleform::Render::Tessellator::MonoVertexType ***v53; // rax
  unsigned __int64 v54; // rdi
  float v55; // xmm6_4
  Scaleform::Render::TessVertex *v56; // r10
  Scaleform::Render::TessVertex *v57; // r8
  Scaleform::Render::TessVertex *v58; // rcx
  float v59; // xmm0_4
  unsigned __int64 v60; // r10
  unsigned __int64 v61; // r11
  Scaleform::Render::Tessellator::MonoVertexType ***v62; // r9
  unsigned __int64 v63; // r8
  unsigned __int64 v64; // rdx
  Scaleform::Render::Tessellator::MonoVertexType **v65; // rax
  Scaleform::Render::Tessellator::MonoVertexType **v66; // rcx
  Scaleform::Render::Tessellator::MonoVertexType ***v67; // rdx
  signed int v68; // [rsp+30h] [rbp-118h]
  signed int v69; // [rsp+40h] [rbp-108h]
  __int64 v70; // [rsp+48h] [rbp-100h]
  unsigned __int64 v71; // [rsp+50h] [rbp-F8h]
  __int64 v72; // [rsp+58h] [rbp-F0h]
  unsigned __int64 v73; // [rsp+60h] [rbp-E8h]
  __int64 v74; // [rsp+68h] [rbp-E0h]
  unsigned __int64 v75; // [rsp+70h] [rbp-D8h]
  unsigned __int64 v76; // [rsp+78h] [rbp-D0h]
  __int64 v77; // [rsp+80h] [rbp-C8h]
  __int64 v78; // [rsp+88h] [rbp-C0h]
  unsigned __int64 v79; // [rsp+90h] [rbp-B8h]
  unsigned __int64 v80; // [rsp+98h] [rbp-B0h]
  __int64 v81; // [rsp+A0h] [rbp-A8h]
  __int64 v82; // [rsp+A8h] [rbp-A0h]
  Scaleform::Render::Tessellator *v83; // [rsp+150h] [rbp+8h]
  unsigned int v84; // [rsp+158h] [rbp+10h]
  unsigned int v85; // [rsp+160h] [rbp+18h]
  unsigned int v86; // [rsp+168h] [rbp+20h]

  v83 = this;
  v1 = this->MonoStack.Size;
  v2 = this;
  if ( v1 <= 2 )
    return;
  v3 = this->MonoStack.Pages;
  v4 = this->MeshVertices.Pages;
  v5 = 1;
  v6 = 0.0;
  v7 = 1i64;
  v8 = v4[(unsigned __int64)((**v3)->srcVer & 0xFFFFFFF) >> 4];
  v9 = v4[(unsigned __int64)(v3[(v1 - 1) >> 4][((_DWORD)v1 - 1) & 0xF]->srcVer & 0xFFFFFFF) >> 4];
  if ( v1 > 2 )
  {
    v10 = v9[v3[(v1 - 1) >> 4][((_DWORD)v1 - 1) & 0xF]->srcVer & 0xF].y;
    v11 = v9[v3[(v1 - 1) >> 4][((_DWORD)v1 - 1) & 0xF]->srcVer & 0xF].x;
    v12 = v9[v3[(v1 - 1) >> 4][((_DWORD)v1 - 1) & 0xF]->srcVer & 0xF].y - v8[(**v3)->srcVer & 0xF].y;
    v13 = v9[v3[(v1 - 1) >> 4][((_DWORD)v1 - 1) & 0xF]->srcVer & 0xF].x - v8[(**v3)->srcVer & 0xF].x;
    do
    {
      v14 = v7;
      v15 = v7++;
      v16 = v3[v15 >> 4][v14 & 0xF]->srcVer & 0xFFFFFFF;
      v6 = v6
         + (float)((float)((float)(v4[(unsigned __int64)v16 >> 4][v16 & 0xF].x - v11) * v12)
                 - (float)((float)(v4[(unsigned __int64)v16 >> 4][v16 & 0xF].y - v10) * v13));
    }
    while ( v7 + 1 < v1 );
  }
  v17 = -1;
  v84 = v1;
  if ( v6 > 0.0 )
    v17 = 1;
  v18 = 0;
  v69 = v17;
  v85 = 0;
  v74 = v17;
  if ( (unsigned int)v1 <= 3 )
  {
LABEL_58:
    v67 = v2->MonoStack.Pages;
    Scaleform::Render::Tessellator::addTriangleAA(
      v2,
      v67[(unsigned __int64)(v18 - v17 + 1) >> 4][(v18 - v17 + 1) & 0xF],
      v67[(unsigned __int64)(v18 + 1) >> 4][(v18 + 1) & 0xF],
      v67[(unsigned __int64)(v18 + v17 + 1) >> 4][((_BYTE)v18 + (_BYTE)v17 + 1) & 0xF],
      0.0);
    return;
  }
  v19 = 2;
  v86 = 3;
  v68 = 2;
  while ( 1 )
  {
    v20 = v2->MonoStack.Pages;
    v21 = v2->MeshVertices.Pages;
    v76 = (unsigned __int64)v5 >> 4;
    v77 = v5 & 0xF;
    v70 = v18 & 0xF;
    v73 = (unsigned __int64)v18 >> 4;
    v22 = v20[v76][v77]->srcVer & 0xFFFFFFF;
    v81 = v19 & 0xF;
    v23 = v5;
    v79 = (unsigned __int64)v19 >> 4;
    v24 = v21[(unsigned __int64)v22 >> 4];
    v25 = v21[(unsigned __int64)(v20[v73][v70]->srcVer & 0xFFFFFFF) >> 4];
    v26 = v20[v79][v81]->srcVer & 0xFFFFFFF;
    v27 = v21[(unsigned __int64)v26 >> 4];
    v28 = Scaleform::Render::Math2D::LinePointDistance(
            v27[v20[v79][v81]->srcVer & 0xF].x,
            v27[v20[v79][v81]->srcVer & 0xF].y,
            v25[v20[v73][v70]->srcVer & 0xF].x,
            v25[v20[v73][v70]->srcVer & 0xF].y,
            v24[v20[v76][v77]->srcVer & 0xF].x,
            v24[v20[v76][v77]->srcVer & 0xF].y);
    v29 = v21[(unsigned __int64)(v20[(unsigned __int64)v86 >> 4][v86 & 0xF]->srcVer & 0xFFFFFFF) >> 4];
    v30 = Scaleform::Render::Math2D::LinePointDistance(
            v29[v20[(unsigned __int64)v86 >> 4][v86 & 0xF]->srcVer & 0xF].x,
            v29[v20[(unsigned __int64)v86 >> 4][v86 & 0xF]->srcVer & 0xF].y,
            v21[(unsigned __int64)v22 >> 4][v22 & 0xF].x,
            v21[(unsigned __int64)v22 >> 4][v22 & 0xF].y,
            v21[(unsigned __int64)v26 >> 4][v26 & 0xF].x,
            v21[(unsigned __int64)v26 >> 4][v26 & 0xF].y);
    v75 = (unsigned __int64)(v84 - 2) >> 4;
    v78 = (v84 - 2) & 0xF;
    v82 = (v84 - 3) & 0xF;
    v80 = (unsigned __int64)(v84 - 3) >> 4;
    v31 = v20[v75][v78]->srcVer & 0xFFFFFFF;
    v32 = (v84 - 1) & 0xF;
    v72 = v32;
    v71 = (unsigned __int64)(v84 - 1) >> 4;
    v33 = v20[v80][v82]->srcVer & 0xFFFFFFF;
    LODWORD(v32) = v20[v71][v32]->srcVer & 0xFFFFFFF;
    v34 = v21[(unsigned __int64)v31 >> 4];
    v35 = v21[(unsigned __int64)v33 >> 4];
    v36 = v21[(unsigned __int64)(unsigned int)v32 >> 4];
    v37 = v32 & 0xF;
    v38 = Scaleform::Render::Math2D::LinePointDistance(
            v36[v37].x,
            v36[v37].y,
            v35[v20[v80][v82]->srcVer & 0xF].x,
            v35[v20[v80][v82]->srcVer & 0xF].y,
            v34[v20[v75][v78]->srcVer & 0xF].x,
            v34[v20[v75][v78]->srcVer & 0xF].y);
    v39 = v21[(unsigned __int64)v33 >> 4];
    v40 = v21[(unsigned __int64)(v20[(unsigned __int64)(v84 - 4) >> 4][((_BYTE)v84 - 4) & 0xF]->srcVer & 0xFFFFFFF) >> 4];
    v41 = v21[(unsigned __int64)v31 >> 4];
    v42 = Scaleform::Render::Math2D::LinePointDistance(
            v41[v31 & 0xF].x,
            v41[v31 & 0xF].y,
            v40[v20[(unsigned __int64)(v84 - 4) >> 4][((_BYTE)v84 - 4) & 0xF]->srcVer & 0xF].x,
            v40[v20[(unsigned __int64)(v84 - 4) >> 4][((_BYTE)v84 - 4) & 0xF]->srcVer & 0xF].y,
            v39[v33 & 0xF].x,
            v39[v33 & 0xF].y);
    v43 = -1;
    v44 = v42;
    if ( v74 <= 0 )
    {
      v46 = v2->EdgeAAWidth;
      if ( v28 > 0.0 && v30 > 0.0 )
      {
        if ( v28 > v46 )
        {
          v46 = v28;
          v43 = v5;
        }
        if ( v30 > v46 )
        {
          v46 = v30;
          v43 = v19;
        }
      }
      if ( v38 > 0.0 && v44 > 0.0 )
      {
        if ( v38 > v46 )
        {
          v43 = v84 - 2;
          v46 = v38;
        }
        if ( v44 > v46 )
          v43 = v84 - 3;
      }
    }
    else
    {
      v45 = LODWORD(v2->EdgeAAWidth) ^ _xmm[0];
      if ( v28 < 0.0 )
      {
        if ( v30 >= 0.0 )
          break;
        if ( v28 < *(float *)&v45 )
        {
          *(float *)&v45 = v28;
          v43 = v5;
        }
        if ( v30 < *(float *)&v45 )
        {
          *(float *)&v45 = v30;
          v43 = v19;
        }
      }
      if ( v30 < 0.0 && v42 < 0.0 )
      {
        if ( v38 < *(float *)&v45 )
        {
          v43 = v84 - 2;
          *(float *)&v45 = v38;
        }
        if ( v42 < *(float *)&v45 )
          v43 = v84 - 3;
      }
    }
    if ( v43 == -1 )
      break;
    v17 = v69;
    Scaleform::Render::Tessellator::addTriangleAA(
      v2,
      v20[(unsigned __int64)(v43 - v69) >> 4][(v43 - v69) & 0xF],
      v20[(unsigned __int64)v43 >> 4][v43 & 0xF],
      v20[(unsigned __int64)(v69 + v43) >> 4][((_BYTE)v69 + (_BYTE)v43) & 0xF],
      0.0);
    if ( v43 == v5 )
    {
      v47 = (unsigned __int64)v5 >> 4;
      v48 = v5 & 0xF;
    }
    else
    {
      v49 = v2->MonoStack.Pages;
      if ( v43 != v19 )
      {
        if ( v43 == v84 - 2 )
        {
          v51 = v49[v75];
          v52 = v49[v71];
        }
        else
        {
          v49[v80][v82] = v49[v75][v78];
          v53 = v2->MonoStack.Pages;
          v52 = v53[v71];
          v51 = v53[v75];
        }
        v51[v78] = v52[v72];
        v50 = v84-- - 1;
        goto LABEL_56;
      }
      v47 = (unsigned __int64)v5 >> 4;
      v48 = v5 & 0xF;
      v49[v79][v81] = v49[v76][v77];
    }
    ++v19;
    ++v5;
    v18 = v85 + 1;
    ++v86;
    v2->MonoStack.Pages[v47][v48] = v2->MonoStack.Pages[v73][v70];
    v50 = v84;
    ++v85;
    v68 = v19;
LABEL_57:
    if ( v50 <= v86 )
      goto LABEL_58;
  }
  v54 = v5 + 1i64;
  v55 = 0.0;
  if ( v54 >= v84 )
    return;
  do
  {
    v56 = v21[(unsigned __int64)(v20[v23 >> 4][v23 & 0xF]->srcVer & 0xFFFFFFF) >> 4];
    v57 = v21[(unsigned __int64)(v20[(v54 - 2) >> 4][((_DWORD)v54 - 2) & 0xF]->srcVer & 0xFFFFFFF) >> 4];
    v58 = v21[(unsigned __int64)(v20[v54 >> 4][v54 & 0xF]->srcVer & 0xFFFFFFF) >> 4];
    v59 = Scaleform::Render::Math2D::LinePointDistance(
            v58[v20[v54 >> 4][v54 & 0xF]->srcVer & 0xF].x,
            v58[v20[v54 >> 4][v54 & 0xF]->srcVer & 0xF].y,
            v57[v20[(v54 - 2) >> 4][((_DWORD)v54 - 2) & 0xF]->srcVer & 0xF].x,
            v57[v20[(v54 - 2) >> 4][((_DWORD)v54 - 2) & 0xF]->srcVer & 0xF].y,
            v56[v20[v23 >> 4][v23 & 0xF]->srcVer & 0xF].x,
            v56[v20[v23 >> 4][v23 & 0xF]->srcVer & 0xF].y);
    if ( v74 <= 0 )
    {
      if ( v59 <= v55 )
        goto LABEL_50;
    }
    else if ( v59 >= v55 )
    {
      goto LABEL_50;
    }
    v43 = v23;
    v55 = v59;
LABEL_50:
    ++v54;
    ++v23;
  }
  while ( v54 < v84 );
  v2 = v83;
  if ( v43 != -1 )
  {
    v17 = v69;
    Scaleform::Render::Tessellator::addTriangleAA(
      v83,
      v20[(unsigned __int64)(v43 - v69) >> 4][(v43 - v69) & 0xF],
      v20[(unsigned __int64)v43 >> 4][v43 & 0xF],
      v20[(unsigned __int64)(v69 + v43) >> 4][((_BYTE)v69 + (_BYTE)v43) & 0xF],
      0.0);
    v60 = v43 + 1;
    if ( v60 < v84 )
    {
      v61 = v43 + 1 - 1i64;
      do
      {
        v62 = v83->MonoStack.Pages;
        v63 = v60 & 0xF;
        v64 = v61 & 0xF;
        v65 = v62[v60 >> 4];
        v66 = v62[v61 >> 4];
        ++v60;
        ++v61;
        v66[v64] = v65[v63];
      }
      while ( v60 < v84 );
    }
    v50 = v84 - 1;
    v19 = v68;
    --v84;
LABEL_56:
    v18 = v85;
    goto LABEL_57;
  }
}6[v64] = v65[v63];
      }
      while ( v60 < v84 );
    }
    v50 = v84 - 1;
    v19 = v68;
    --v84;
LABEL_56:
    v18 = v85;
    goto LABEL_57;
  }
}

// File Line: 3287
// RVA: 0x9F7540
void __fastcall Scaleform::Render::Tessellator::triangulateMonotoneAA(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::MonotoneType *m)
{
  Scaleform::Render::Tessellator::MonoVertexType *v2; // rsi
  Scaleform::Render::Tessellator::MonotoneType *v3; // r15
  unsigned int v4; // edx
  Scaleform::Render::Tessellator *v5; // rbp
  unsigned int v6; // er9
  Scaleform::Render::TessMesh **v7; // rax
  Scaleform::Render::TessMesh **v8; // rdx
  signed int v9; // ecx
  signed __int64 v10; // r9
  int v11; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v12; // rax
  unsigned __int64 v13; // rdi
  Scaleform::Render::Tessellator::MonoVertexType *v14; // rsi
  unsigned __int64 v15; // rdi
  Scaleform::Render::Tessellator::MonoVertexType *i; // rdi
  unsigned __int64 v17; // rsi
  unsigned __int64 v18; // rdx
  unsigned __int64 v19; // rsi
  Scaleform::Render::Tessellator::MonoVertexType *v20; // r14
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // rsi

  v2 = m->start;
  v3 = m;
  v4 = m->style;
  this->MonoStyle = v4;
  v5 = this;
  v6 = Scaleform::Render::Tessellator::setMesh(this, v4);
  v7 = v5->Meshes.Pages;
  v5->MeshIdx = v6;
  v8 = &v7[(unsigned __int64)v6 >> 4];
  v9 = 0;
  v10 = v6 & 0xF;
  if ( v5->MonoStyle == (*v8)[v10].Style1 )
    v9 = 8;
  v11 = v9 | 2;
  v5->FactorOneFlag = v11;
  (*v8)[v10].Flags1 |= v11 & 8;
  v3->d.m.lastIdx = -1;
  v3->d.m.prevIdx1 = 0;
  v3->d.m.prevIdx2 = v5->MeshIdx;
  if ( v2 )
  {
    v12 = v2->next;
    if ( v12 )
    {
      if ( v12->next )
      {
        v3->d.m.lastIdx = v5->MeshTriangles.Arrays[v5->MeshIdx].Size;
        v5->MonoStack.Size = 0i64;
        v13 = v5->MonoStack.Size >> 4;
        if ( v13 >= v5->MonoStack.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
            &v5->MonoStack,
            v5->MonoStack.Size >> 4);
        v5->MonoStack.Pages[v13][v5->MonoStack.Size & 0xF] = v2;
        ++v5->MonoStack.Size;
        v14 = v2->next;
        v15 = v5->MonoStack.Size >> 4;
        if ( v15 >= v5->MonoStack.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
            &v5->MonoStack,
            v5->MonoStack.Size >> 4);
        v5->MonoStack.Pages[v15][v5->MonoStack.Size & 0xF] = v14;
        ++v5->MonoStack.Size;
        for ( i = v14->next; i; i = i->next )
        {
          v17 = v5->MonoStack.Size;
          v18 = v17 - 1;
          v19 = v17 >> 4;
          v20 = v5->MonoStack.Pages[v18 >> 4][v18 & 0xF];
          if ( v19 >= v5->MonoStack.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
              &v5->MonoStack,
              v19);
          v5->MonoStack.Pages[v19][v5->MonoStack.Size & 0xF] = i;
          ++v5->MonoStack.Size;
          if ( (((i->srcVer & 0x80000000) != 0) ^ ((v20->srcVer & 0x80000000) != 0)) & 1 )
          {
            Scaleform::Render::Tessellator::triangulateMountainAA(v5);
            v5->MonoStack.Size = 0i64;
            v21 = v5->MonoStack.Size >> 4;
            if ( v21 >= v5->MonoStack.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
                &v5->MonoStack,
                v5->MonoStack.Size >> 4);
            v5->MonoStack.Pages[v21][v5->MonoStack.Size & 0xF] = v20;
            v22 = ++v5->MonoStack.Size >> 4;
            if ( v22 >= v5->MonoStack.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,2>::allocPage(
                &v5->MonoStack,
                v5->MonoStack.Size >> 4);
            v5->MonoStack.Pages[v22][v5->MonoStack.Size & 0xF] = i;
            ++v5->MonoStack.Size;
          }
        }
        Scaleform::Render::Tessellator::triangulateMountainAA(v5);
        v3->d.m.prevIdx1 = LODWORD(v5->MeshTriangles.Arrays[v5->MeshIdx].Size) - v3->d.m.lastIdx;
      }
    }
  }
}evIdx1 = LODWORD(v5->MeshTriangles.Arrays[v5->MeshIdx].Size) - v3->

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
  Scaleform::Render::TessVertex **v7; // rbx
  Scaleform::Render::Tessellator::TriangleType *v8; // r8
  Scaleform::Render::Tessellator::MonoVertexType *v9; // r11
  Scaleform::Render::Tessellator::MonoVertexType *v10; // r10
  Scaleform::Render::Tessellator::MonoVertexType *v11; // rdx
  signed __int64 v12; // rdi
  Scaleform::Render::TessVertex *v13; // rsi
  signed __int64 v14; // rbp
  Scaleform::Render::TessVertex *v15; // r14
  signed __int64 v16; // r15
  Scaleform::Render::TessVertex *v17; // r12
  signed __int64 v18; // r8
  Scaleform::Render::TessVertex *v19; // r9
  unsigned __int64 v20; // rax
  signed __int64 v21; // r10
  float v22; // xmm9_4
  float v23; // xmm8_4
  Scaleform::Render::TessVertex *v24; // r11
  signed __int64 v25; // rcx
  unsigned __int64 v26; // rax
  signed __int64 v27; // rdx
  float v28; // xmm14_4
  float v29; // xmm13_4
  Scaleform::Render::TessVertex *v30; // rbx
  float v31; // xmm2_4
  float v32; // xmm15_4
  float v33; // xmm10_4
  float v34; // xmm11_4
  float v35; // xmm5_4
  __m128 v36; // xmm6
  float v37; // xmm7_4
  float v38; // xmm6_4
  float v39; // xmm4_4
  __m128 v40; // xmm3
  __m128 v41; // xmm1
  float v42; // xmm2_4
  float v43; // xmm1_4
  int v44; // ecx
  int v45; // ecx
  int v46; // ecx
  float v47; // xmm2_4
  float v48; // xmm4_4
  float v49; // xmm3_4
  float v50; // xmm5_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm4_4
  float v54; // xmm5_4
  float v55; // xmm3_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm4_4
  float v59; // xmm5_4
  float v60; // xmm3_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  float v63; // [rsp+0h] [rbp-108h]
  float v64; // [rsp+4h] [rbp-104h]
  __int64 v65; // [rsp+8h] [rbp-100h]
  unsigned __int64 v66; // [rsp+10h] [rbp-F8h]
  unsigned __int64 v67; // [rsp+18h] [rbp-F0h]
  Scaleform::Render::Tessellator *v68; // [rsp+110h] [rbp+8h]
  char v69; // [rsp+118h] [rbp+10h]
  unsigned int v70; // [rsp+120h] [rbp+18h]
  float v71; // [rsp+128h] [rbp+20h]

  v68 = this;
  v1 = this;
  v2 = 0;
  v70 = 0;
  do
  {
    if ( v2 >= 8 )
      break;
    v3 = 0i64;
    v4 = 0;
    v69 = 0;
    v66 = 0i64;
    if ( v1->MeshTriangles.NumArrays )
    {
      v5 = 0i64;
      v65 = 0i64;
      do
      {
        v6 = 0i64;
        v67 = *(unsigned __int64 *)((char *)&v1->MeshTriangles.Arrays->Size + v5);
        if ( v67 )
        {
          do
          {
            v7 = v1->MeshVertices.Pages;
            v8 = (*(Scaleform::Render::Tessellator::TriangleType ***)((char *)&v1->MeshTriangles.Arrays->Pages + v5))[v6 >> 4];
            v9 = v8[v6 & 0xF].d.m.v1;
            v10 = v8[v6 & 0xF].d.m.v2;
            v11 = v8[v6 & 0xF].d.m.v3;
            v12 = v9->srcVer & 0xF;
            v13 = v7[(unsigned __int64)(v9->srcVer & 0xFFFFFFF) >> 4];
            v14 = v10->srcVer & 0xF;
            v15 = v7[(unsigned __int64)(v10->srcVer & 0xFFFFFFF) >> 4];
            v16 = v11->srcVer & 0xF;
            v17 = v7[(unsigned __int64)(v11->srcVer & 0xFFFFFFF) >> 4];
            v18 = v9->aaVer & 0xF;
            v19 = v7[(unsigned __int64)(v9->aaVer & 0xFFFFFFF) >> 4];
            v20 = v10->aaVer & 0xFFFFFFF;
            v21 = v10->aaVer & 0xF;
            v22 = v19[v9->aaVer & 0xF].x;
            v23 = v19[v9->aaVer & 0xF].y;
            v24 = v7[v20 >> 4];
            v25 = v11->aaVer & 0xF;
            v26 = (unsigned __int64)(v11->aaVer & 0xFFFFFFF) >> 4;
            v27 = v25;
            v28 = v24[v21].x;
            v29 = v24[v21].y;
            v30 = v7[v26];
            v31 = v24[v21].y - v23;
            v32 = v24[v21].x - v22;
            v64 = v31;
            v33 = v30[v25].x;
            v34 = v30[v25].y;
            v35 = v30[v25].x - v28;
            v36 = (__m128)LODWORD(v30[v25].y);
            v36.m128_f32[0] = v36.m128_f32[0] - v29;
            v63 = v35;
            v71 = v36.m128_f32[0];
            if ( (float)((float)(v35 * v31) - (float)(v32 * v36.m128_f32[0])) < 0.0 )
            {
              v4 = v69;
            }
            else
            {
              v40 = v36;
              v40.m128_f32[0] = v36.m128_f32[0] * v36.m128_f32[0];
              v37 = v23 - v34;
              v38 = v22 - v33;
              v39 = (float)(v31 * v31) + (float)(v32 * v32);
              v40.m128_f32[0] = v40.m128_f32[0] + (float)(v35 * v35);
              v41 = v40;
              v42 = (float)(v37 * v37) + (float)(v38 * v38);
              v41.m128_f32[0] = (float)(v40.m128_f32[0] + v39) + v42;
              v43 = COERCE_FLOAT(_mm_sqrt_ps(v41)) * v68->IntersectionEpsilon;
              if ( v39 <= v40.m128_f32[0] )
              {
                v44 = (v40.m128_f32[0] <= v42) + 2;
              }
              else
              {
                v44 = 3;
                if ( v39 > v42 )
                  v44 = 1;
              }
              v45 = v44 - 1;
              if ( v45 )
              {
                v46 = v45 - 1;
                if ( v46 )
                {
                  if ( v46 == 1 )
                  {
                    v47 = v15[v14].x;
                    v48 = v15[v14].y - v29;
                    v49 = v15[v14].x - v28;
                    v50 = (float)(v49 * v37) - (float)(v48 * v38);
                    if ( COERCE_FLOAT(LODWORD(v50) & _xmm) < v43
                      || (v51 = (float)((float)((float)(v29 - v34) * v38) - (float)((float)(v28 - v33) * v37)) / v50,
                          v51 <= 0.0)
                      || v51 >= 1.0 )
                    {
                      v24[v21].x = v47;
                      v24[v21].y = v15[v14].y;
                    }
                    else
                    {
                      v24[v21].x = (float)((float)(v47 - (float)((float)(v49 * v51) + v28)) * 0.125)
                                 + (float)((float)(v49 * v51) + v28);
                      v24[v21].y = (float)((float)(v15[v14].y - (float)((float)(v48 * v51) + v29)) * 0.125)
                                 + (float)((float)(v48 * v51) + v29);
                    }
                  }
                }
                else
                {
                  v52 = v13[v12].x;
                  v53 = v13[v12].x - v22;
                  v54 = v13[v12].y - v23;
                  v55 = (float)(v71 * v53) - (float)(v63 * v54);
                  if ( COERCE_FLOAT(LODWORD(v55) & _xmm) < v43
                    || (v56 = (float)((float)((float)(v23 - v29) * v63) - (float)((float)(v22 - v28) * v71)) / v55,
                        v56 <= 0.0)
                    || v56 >= 1.0 )
                  {
                    v19[v18].x = v52;
                    v19[v18].y = v13[v12].y;
                  }
                  else
                  {
                    v19[v18].x = (float)((float)(v52 - (float)((float)(v56 * v53) + v22)) * 0.125)
                               + (float)((float)(v56 * v53) + v22);
                    v19[v18].y = (float)((float)(v13[v12].y - (float)((float)(v56 * v54) + v23)) * 0.125)
                               + (float)((float)(v56 * v54) + v23);
                  }
                }
              }
              else
              {
                v57 = v17[v16].x;
                v58 = v17[v16].x - v33;
                v59 = v17[v16].y - v34;
                v60 = (float)(v64 * v58) - (float)(v32 * v59);
                if ( COERCE_FLOAT(LODWORD(v60) & _xmm) < v43
                  || (v61 = (float)(v33 - v22) * v64,
                      v62 = (float)((float)((float)(v34 - v23) * v32) - v61) / v60,
                      v62 <= 0.0)
                  || v62 >= 1.0 )
                {
                  v30[v27].x = v57;
                  v30[v27].y = v17[v16].y;
                }
                else
                {
                  v30[v27].x = (float)((float)(v57
                                             - (float)((float)((float)((float)((float)((float)(v34 - v23) * v32) - v61)
                                                                     / v60)
                                                             * v58)
                                                     + v33))
                                     * 0.125)
                             + (float)((float)((float)((float)((float)((float)(v34 - v23) * v32) - v61) / v60) * v58)
                                     + v33);
                  v30[v27].y = (float)((float)(v17[v16].y - (float)((float)(v62 * v59) + v34)) * 0.125)
                             + (float)((float)(v62 * v59) + v34);
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
              v69 = 1;
            }
            v1 = v68;
            v5 = v65;
            ++v6;
          }
          while ( v6 < v67 );
          v3 = v66;
        }
        ++v3;
        v5 += 32i64;
        v66 = v3;
        v65 = v5;
      }
      while ( v3 < v1->MeshTriangles.NumArrays );
      v2 = v70;
    }
    v70 = ++v2;
  }
  while ( v4 );
}

// File Line: 3504
// RVA: 0x9E06F0
void __fastcall Scaleform::Render::Tessellator::emitStrokerTrapezoid(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::StrokerEdgeType *edge, unsigned int v1, unsigned int v2)
{
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *v4; // rbx
  unsigned int v5; // ebp
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v6; // rsi
  Scaleform::Render::Tessellator::StrokerEdgeType *v7; // r14
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

  v4 = &this->MeshTriangles;
  v5 = v2;
  v6 = this->MeshTriangles.Arrays;
  v7 = edge;
  HIDWORD(v14) = v1;
  LODWORD(v16) = v2;
  v8 = v6->Size >> 4;
  LODWORD(v14) = edge->node1 & 0xFFFFFFF;
  if ( v8 >= v6->NumPages )
    Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
      &this->MeshTriangles,
      v6,
      v8);
  v9 = &v6->Pages[v8][v6->Size & 0xF];
  v9->d.m.v1 = v14;
  v10 = v16;
  LODWORD(v16) = v5;
  v9->d.m.v2 = v10;
  v9->d.m.v3 = v17;
  ++v4->Arrays->Size;
  v11 = v4->Arrays;
  LODWORD(v15) = v7->node2 & 0xFFFFFFF;
  v12 = v11->Size >> 4;
  HIDWORD(v15) = v7->node1 & 0xFFFFFFF;
  if ( v12 >= v11->NumPages )
    Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(v4, v11, v12);
  v13 = &v11->Pages[v12][v11->Size & 0xF];
  v13->d.m.v1 = v15;
  v13->d.m.v2 = v16;
  v13->d.m.v3 = v17;
  ++v4->Arrays->Size;
}

// File Line: 3519
// RVA: 0x9E0810
void __fastcall Scaleform::Render::Tessellator::emitStrokerVertex(Scaleform::Render::Tessellator *this, float x, float y)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *v3; // rbx
  unsigned __int64 v4; // rdi
  signed __int64 v5; // rdx
  Scaleform::Render::TessVertex *v6; // rax

  v3 = &this->MeshVertices;
  v4 = this->MeshVertices.Size >> 4;
  if ( v4 >= this->MeshVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
      &this->MeshVertices,
      this->MeshVertices.Size >> 4);
  v5 = v3->Size & 0xF;
  v6 = v3->Pages[v4];
  v6[v5].x = x;
  v6[v5].y = y;
  v6[v5].Idx = -1;
  *(_QWORD *)v6[v5].Styles = 65537i64;
  ++v3->Size;
}

// File Line: 3532
// RVA: 0x9C9C50
signed __int64 __fastcall Scaleform::Render::Tessellator::addStrokerJoin(Scaleform::Render::Tessellator *this, Scaleform::Render::Tessellator::StrokerEdgeType *e1, Scaleform::Render::Tessellator::StrokerEdgeType *e2)
{
  unsigned int v3; // er9
  unsigned int v4; // ebp
  Scaleform::Render::TessVertex **v5; // rdx
  Scaleform::Render::Tessellator *v6; // rdi
  unsigned int v7; // ebp
  unsigned __int64 v8; // rax
  __int64 v9; // r9
  Scaleform::Render::TessVertex *v10; // rax
  float v11; // xmm12_4
  float v12; // xmm7_4
  Scaleform::Render::TessVertex *v13; // rbx
  signed __int64 v14; // rsi
  float v15; // xmm9_4
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  float v18; // xmm11_4
  Scaleform::Render::TessVertex *v19; // r8
  float v20; // xmm15_4
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
  int v47; // ecx
  float v48; // [rsp+34h] [rbp-F4h]
  float v49; // [rsp+38h] [rbp-F0h]
  float v50; // [rsp+3Ch] [rbp-ECh]
  Scaleform::Render::Tessellator::TriangleType val; // [rsp+40h] [rbp-E8h]
  float v52; // [rsp+130h] [rbp+8h]
  float v53; // [rsp+140h] [rbp+18h]

  v3 = e1->node1;
  v4 = e1->node2;
  v5 = this->MeshVertices.Pages;
  v6 = this;
  v3 &= 0xFFFFFFFu;
  v7 = v4 & 0xFFFFFFF;
  v8 = v3;
  v9 = v3 & 0xF;
  v10 = v5[v8 >> 4];
  v11 = this->EdgeAAWidth * -2.0;
  v50 = this->EdgeAAWidth * -2.0;
  v12 = v10[v9].y;
  v13 = &v10[v9];
  v14 = (signed __int64)&v5[(unsigned __int64)v7 >> 4][v7 & 0xF];
  v15 = *(float *)v14;
  v16 = (__m128)*(unsigned int *)(v14 + 4);
  v17 = (__m128)*(unsigned int *)(v14 + 4);
  v18 = *(float *)v14 - v13->x;
  v19 = &v5[(unsigned __int64)(e2->node2 & 0xFFFFFFF) >> 4][e2->node2 & 0xF];
  v20 = v19->x;
  v21 = v19->y;
  v17.m128_f32[0] = (float)((float)(v17.m128_f32[0] - v12) * (float)(v17.m128_f32[0] - v12)) + (float)(v18 * v18);
  LODWORD(v22) = (unsigned __int128)_mm_sqrt_ps(v17);
  v23 = (__m128)LODWORD(v19->y);
  v24 = v19->x - *(float *)v14;
  v23.m128_f32[0] = (float)((float)(v23.m128_f32[0] - v16.m128_f32[0]) * (float)(v23.m128_f32[0] - v16.m128_f32[0]))
                  + (float)(v24 * v24);
  LODWORD(len2) = (unsigned __int128)_mm_sqrt_ps(v23);
  v49 = len2;
  v26 = Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType,Scaleform::Render::Hairliner::OutVertexType>(
          v13,
          (Scaleform::Render::TessVertex *)v14,
          v19,
          v22,
          len2);
  v52 = (float)(len2 + v22) * v6->IntersectionEpsilon;
  v48 = v26;
  v27 = (float)((float)(v12 - v16.m128_f32[0]) * v11) * (float)(1.0 / v22);
  v28 = (float)((float)(v16.m128_f32[0] - v21) * v11) * (float)(1.0 / len2);
  v29 = (float)(v24 * v11) * (float)(1.0 / len2);
  v30 = (float)(v18 * v11) * (float)(1.0 / v22);
  if ( COERCE_FLOAT(LODWORD(v26) & _xmm) >= 0.125 )
  {
    v37 = v16;
    v53 = v13->x + v27;
    v34 = (float)(v21 + v29) - (float)(v16.m128_f32[0] + v29);
    v35 = v13->y + v30;
    v36 = (float)(v20 + v28) - (float)(v15 + v28);
    v37.m128_f32[0] = v16.m128_f32[0] + v30;
    v39 = v37;
    v38 = v15 + v27;
    v39.m128_f32[0] = (float)(v16.m128_f32[0] + v30) - v35;
    v40 = (float)(v15 + v27) - v53;
    v41 = (float)(v34 * v40) - (float)(v36 * v39.m128_f32[0]);
    if ( COERCE_FLOAT(LODWORD(v41) & _xmm) < v52 )
    {
      v46 = v6;
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
      LODWORD(v45) = (unsigned __int128)_mm_sqrt_ps(v44);
      if ( v48 <= 0.0 )
      {
        v46 = v6;
        if ( v45 <= (float)(v50 * -4.0) )
        {
LABEL_11:
          Scaleform::Render::Tessellator::emitStrokerVertex(v46, v43, v39.m128_f32[0]);
          return 1i64;
        }
        Scaleform::Render::Tessellator::emitStrokerVertex(
          v6,
          v38 - (float)(v30 * 2.0),
          (float)(v27 * 2.0) + v37.m128_f32[0]);
        Scaleform::Render::Tessellator::emitStrokerVertex(
          v6,
          (float)(v28 + *(float *)v14) + (float)(v29 * 2.0),
          (float)(v29 + *(float *)(v14 + 4)) - (float)(v28 * 2.0));
        v47 = v6->MeshVertices.Size;
        val.d.t.v1 = v7;
        val.d.t.v2 = v47 - 2;
        val.d.t.v3 = v47 - 1;
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::PushBack(
          &v6->MeshTriangles,
          0i64,
          &val);
        return 2i64;
      }
      if ( v22 >= v49 )
        v22 = v49;
      v46 = v6;
      if ( v45 <= (float)(v22 / v48) )
        goto LABEL_11;
    }
    Scaleform::Render::Tessellator::emitStrokerVertex(v46, v38, v37.m128_f32[0]);
    Scaleform::Render::Tessellator::emitStrokerVertex(v6, v28 + *(float *)v14, v29 + *(float *)(v14 + 4));
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
  Scaleform::Render::Tessellator::emitStrokerVertex(v6, v32, v31);
  return 1i64;
}

// File Line: 3638
// RVA: 0x9ED7D0
void __fastcall Scaleform::Render::Tessellator::processStrokerEdges(Scaleform::Render::Tessellator *this)
{
  unsigned __int64 v1; // r12
  Scaleform::Render::Tessellator *v2; // r15
  Scaleform::Render::Tessellator::MonoVertexType *v3; // rdx
  Scaleform::Render::Tessellator::MonoVertexType *v4; // rsi
  unsigned int v5; // ebp
  unsigned int v6; // er14
  unsigned __int64 v7; // rdi
  Scaleform::Render::Tessellator::MonoVertexType *i; // rdi
  int v9; // ecx
  unsigned __int64 v10; // rsi
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rdi
  signed __int64 v13; // rbx
  unsigned __int64 v14; // rbp
  unsigned __int64 v15; // rsi
  Scaleform::Render::Tessellator::StrokerEdgeType **v16; // r8
  unsigned __int64 v17; // rcx
  Scaleform::Render::Tessellator::StrokerEdgeType *v18; // rax
  unsigned int v19; // ebx
  int *v20; // r14
  signed __int64 v21; // rdx
  int v22; // er13
  unsigned __int64 v23; // r9
  unsigned int v24; // edi
  Scaleform::Render::Tessellator::StrokerEdgeType *v25; // r10
  unsigned int v26; // eax
  bool v27; // cf
  unsigned __int64 v28; // rax
  unsigned __int64 v29; // r9
  Scaleform::Render::Tessellator::StrokerEdgeType *v30; // rax
  unsigned __int64 v31; // r12
  unsigned __int64 v32; // rcx
  Scaleform::Render::Tessellator::StrokerEdgeType *v33; // rax
  Scaleform::Render::Tessellator::StrokerEdgeType *v34; // r14
  unsigned int v35; // ebp
  Scaleform::Render::Tessellator::StrokerEdgeType *v36; // rdi
  unsigned int j; // esi
  __int64 v38; // r8
  unsigned __int64 v39; // rax
  __int64 v40; // rbx
  unsigned __int64 v41; // r8
  Scaleform::Render::Tessellator::StrokerEdgeType *v42; // rbx
  unsigned int v43; // edx
  int v44; // eax
  Scaleform::Render::Tessellator::StrokerEdgeType v45; // [rsp+70h] [rbp+8h]
  unsigned __int64 v46; // [rsp+78h] [rbp+10h]
  Scaleform::Render::Tessellator::StrokerEdgeType v47; // [rsp+80h] [rbp+18h]
  Scaleform::Render::Tessellator::StrokerEdgeType v48; // [rsp+88h] [rbp+20h]

  v1 = 0i64;
  v2 = this;
  if ( this->Monotones.Size )
  {
    do
    {
      v3 = v2->Monotones.Pages[v1 >> 4][v1 & 0xF].start;
      if ( v3 )
      {
        v4 = v3->next;
        v5 = v3->srcVer;
        if ( v4 )
        {
          v6 = v4->srcVer;
          v45.node2 = v4->srcVer & 0xFFFFFFF;
          if ( (v5 & 0xFFFFFFF) != v45.node2 )
          {
            v7 = v2->StrokerEdges.Size >> 4;
            if ( v7 >= v2->StrokerEdges.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&v2->StrokerEdges,
                v2->StrokerEdges.Size >> 4);
            v45.node1 = v5 & 0xFFFFFFF;
            v2->StrokerEdges.Pages[v7][v2->StrokerEdges.Size & 0xF] = v45;
            ++v2->StrokerEdges.Size;
          }
          for ( i = v4->next; i; i = i->next )
          {
            v9 = i->srcVer & 0xFFFFFFF;
            if ( (i->srcVer & 0x80000000) == 0 )
            {
              v47.node2 = i->srcVer & 0xFFFFFFF;
              if ( (v6 & 0xFFFFFFF) != v9 )
              {
                v11 = v2->StrokerEdges.Size >> 4;
                if ( v11 >= v2->StrokerEdges.NumPages )
                  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                    (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&v2->StrokerEdges,
                    v2->StrokerEdges.Size >> 4);
                v47.node1 = v6 & 0xFFFFFFF;
                v2->StrokerEdges.Pages[v11][v2->StrokerEdges.Size & 0xF] = v47;
                ++v2->StrokerEdges.Size;
              }
              v6 = i->srcVer;
            }
            else
            {
              v46 = __PAIR__(v5, v9) & 0xFFFFFFFFFFFFFFFi64;
              if ( v9 != (v5 & 0xFFFFFFF) )
              {
                v10 = v2->StrokerEdges.Size >> 4;
                if ( v10 >= v2->StrokerEdges.NumPages )
                  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                    (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&v2->StrokerEdges,
                    v2->StrokerEdges.Size >> 4);
                v2->StrokerEdges.Pages[v10][v2->StrokerEdges.Size & 0xF] = (Scaleform::Render::Tessellator::StrokerEdgeType)v46;
                ++v2->StrokerEdges.Size;
              }
              v5 = i->srcVer;
            }
          }
          if ( (v6 & 0xFFFFFFF) != (v5 & 0xFFFFFFF) )
          {
            v12 = v2->StrokerEdges.Size >> 4;
            if ( v12 >= v2->StrokerEdges.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&v2->StrokerEdges,
                v2->StrokerEdges.Size >> 4);
            v48.node1 = v6 & 0xFFFFFFF;
            v48.node2 = v5 & 0xFFFFFFF;
            v2->StrokerEdges.Pages[v12][v2->StrokerEdges.Size & 0xF] = v48;
            ++v2->StrokerEdges.Size;
          }
        }
      }
      ++v1;
    }
    while ( v1 < v2->Monotones.Size );
  }
  if ( v2->StrokerEdges.Size >= 2 )
  {
    v13 = (signed __int64)&v2->StrokerEdges;
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType,4,16>,bool (*)(Scaleform::Render::Tessellator::StrokerEdgeType const &,Scaleform::Render::Tessellator::StrokerEdgeType const &)>(
      &v2->StrokerEdges,
      0i64,
      v2->StrokerEdges.Size,
      (bool (__fastcall *)(Scaleform::Render::Tessellator::StrokerEdgeType *, Scaleform::Render::Tessellator::StrokerEdgeType *))Scaleform::Render::Tessellator::cmpStrokerEdges);
    v14 = v2->StrokerEdges.Size;
    v15 = 0i64;
    if ( v14 )
    {
      do
      {
        v16 = v2->StrokerEdges.Pages;
        v17 = v15 & 0xF;
        v18 = v16[v15 >> 4];
        v19 = v18[v17].node1;
        v20 = (int *)&v18[v17];
        if ( !_bittest((const signed int *)&v19, 0x1Eu) )
        {
          v21 = v2->StrokerEdges.Size;
          v22 = v20[1];
          v23 = 0i64;
          if ( v21 > 0 )
          {
            v24 = v22 & 0xFFFFFFF;
            do
            {
              v25 = &v2->StrokerEdges.Pages[((v21 >> 1) + v23) >> 4][((unsigned __int8)(v21 >> 1) + (_BYTE)v23) & 0xF];
              v26 = v25->node1 & 0xFFFFFFF;
              v27 = v26 < v24;
              if ( v26 == v24 )
                v27 = (v25->node2 & 0xFFFFFFF) < (v19 & 0xFFFFFFF);
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
            v16 = v2->StrokerEdges.Pages;
          }
          if ( v23 < v14 )
          {
            v28 = v23;
            v29 = v23 & 0xF;
            v30 = v16[v28 >> 4];
            if ( v19 == v30[v29].node2 && v22 == v30[v29].node1 )
            {
              *v20 = v19 | 0x40000000;
              v30[v29].node1 |= 0x40000000u;
            }
          }
        }
        v14 = v2->StrokerEdges.Size;
        ++v15;
      }
      while ( v15 < v14 );
      v13 = (signed __int64)&v2->StrokerEdges;
    }
    v31 = 0i64;
    if ( v2->StrokerEdges.Size )
    {
      do
      {
        v32 = v31 & 0xF;
        v33 = v2->StrokerEdges.Pages[v31 >> 4];
        v34 = &v33[v32];
        if ( !(v33[v32].node1 & 0x40000000) )
        {
          v35 = -1;
          v36 = &v33[v32];
          for ( j = -1; ; j = LODWORD(v2->MeshVertices.Size) - 1 )
          {
            v38 = *(_QWORD *)(v13 + 8);
            v39 = 0i64;
            if ( v38 > 0 )
            {
              v40 = *(_QWORD *)(v13 + 32);
              do
              {
                if ( (*(_DWORD *)(*(_QWORD *)(v40 + 8 * (((v38 >> 1) + v39) >> 4))
                                + 8i64 * (((unsigned __int8)(v38 >> 1) + (_BYTE)v39) & 0xF)) & 0xFFFFFFFu) >= (v36->node2 & 0xFFFFFFF) )
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
            v41 = v2->StrokerEdges.Size;
            if ( v39 >= v41 )
              break;
            while ( 1 )
            {
              v42 = &v2->StrokerEdges.Pages[v39 >> 4][v39 & 0xF];
              v43 = v42->node1;
              if ( !_bittest((const signed int *)&v43, 0x1Eu) && !((v43 ^ v36->node2) & 0xFFFFFFF) )
                break;
              if ( ++v39 >= v41 )
                goto LABEL_64;
            }
            v44 = Scaleform::Render::Tessellator::addStrokerJoin(v2, v36, v42);
            if ( j == -1 )
            {
              v35 = LODWORD(v2->MeshVertices.Size) - v44;
            }
            else
            {
              Scaleform::Render::Tessellator::emitStrokerTrapezoid(v2, v36, j, LODWORD(v2->MeshVertices.Size) - v44);
              v36->node1 |= 0x40000000u;
            }
            if ( v42 == v34 )
            {
              Scaleform::Render::Tessellator::emitStrokerTrapezoid(v2, v34, LODWORD(v2->MeshVertices.Size) - 1, v35);
              v34->node1 |= 0x40000000u;
              break;
            }
            v36 = v42;
            v13 = (signed __int64)&v2->StrokerEdges;
          }
        }
LABEL_64:
        ++v31;
        v13 = (signed __int64)&v2->StrokerEdges;
      }
      while ( v31 < v2->StrokerEdges.Size );
    }
  }
}

// File Line: 3750
// RVA: 0x9EC320
void __fastcall Scaleform::Render::Tessellator::processEdgeAA(Scaleform::Render::Tessellator *this)
{
  unsigned __int64 v1; // r14
  unsigned __int64 v2; // rbx
  Scaleform::Render::Tessellator *v3; // rsi
  unsigned __int64 i; // rdi
  int v5; // eax
  Scaleform::Render::Tessellator::EdgeAAType *v6; // rbp
  Scaleform::Render::Tessellator::EdgeAAType *v7; // rdx
  unsigned __int64 v8; // rcx
  unsigned int v9; // er11
  unsigned __int64 j; // r10
  signed __int64 v11; // rax
  unsigned __int64 v12; // rdx
  Scaleform::Render::TessVertex *v13; // r8
  signed __int64 v14; // r9
  unsigned __int64 k; // rbx
  unsigned __int64 v16; // rax
  Scaleform::Render::LinearHeap **v17; // rdi
  unsigned __int64 v18; // rdx
  unsigned __int64 v19; // rax
  signed __int64 v20; // r15
  unsigned __int64 v21; // r13
  Scaleform::Render::TessVertex *v22; // r12
  Scaleform::Render::TessVertex **v23; // r10
  Scaleform::Render::Tessellator::EdgeAAType *v24; // rax
  Scaleform::Render::Tessellator::MonoVertexType *v25; // rbx
  Scaleform::Render::TessVertex *v26; // r8
  Scaleform::Render::TessVertex *v27; // rcx
  float v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm1_4
  unsigned __int64 v33; // rbp
  unsigned __int64 v34; // rdx
  Scaleform::Render::LinearHeap *v35; // rcx
  void *v36; // rbx
  unsigned __int64 v37; // rax
  Scaleform::Render::Tessellator::TmpEdgeAAType *v38; // rdx
  signed __int64 v39; // r8
  unsigned __int64 v40; // rbx
  unsigned __int16 v41; // bp
  float l; // xmm1_4
  Scaleform::Render::Tessellator::EdgeAAType *v43; // r10
  unsigned __int64 v44; // r11
  Scaleform::Render::Tessellator::TmpEdgeAAType *v45; // r8
  unsigned __int16 v46; // ax
  __int64 v47; // [rsp+30h] [rbp-A8h]
  unsigned __int64 v48; // [rsp+E0h] [rbp+8h]
  Scaleform::Render::Tessellator::MonoVertexType *v49; // [rsp+E8h] [rbp+10h]
  Scaleform::Render::Tessellator::MonoVertexType *v50; // [rsp+F0h] [rbp+18h]
  unsigned __int64 v51; // [rsp+F8h] [rbp+20h]

  v1 = 0i64;
  v2 = 0i64;
  v3 = this;
  for ( i = 0i64; v2 < v3->Monotones.Size; i = (unsigned int)(v5 + i) )
  {
    v5 = Scaleform::Render::Tessellator::countFanEdges(v3, &v3->Monotones.Pages[v2 >> 4][v2 & 0xF]);
    ++v2;
  }
  if ( i > v3->EdgeFans.Size )
  {
    v6 = (Scaleform::Render::Tessellator::EdgeAAType *)Scaleform::Render::LinearHeap::Alloc(v3->EdgeFans.pHeap, 24 * i);
    memset(v6, 0, 24 * i);
    v7 = v3->EdgeFans.Array;
    if ( v7 )
    {
      v8 = v3->EdgeFans.Size;
      if ( v8 )
        memmove(v6, v7, 24 * v8);
    }
    v3->EdgeFans.Array = v6;
  }
  v3->EdgeFans.Size = i;
  v9 = 0;
  for ( j = 0i64; j < v3->MeshVertices.Size; v9 += v11 )
  {
    v11 = j & 0xF;
    v12 = j++ >> 4;
    v13 = v3->MeshVertices.Pages[v12];
    v14 = v11;
    LODWORD(v11) = v13[v11].Mesh;
    v13[v14].Idx = v9;
    v13[v14].Mesh = 0;
  }
  for ( k = 0i64; k < v3->Monotones.Size; ++k )
    Scaleform::Render::Tessellator::collectFanEdges(v3, &v3->Monotones.Pages[k >> 4][k & 0xF]);
  v16 = 0i64;
  v51 = v3->MeshVertices.Size;
  v48 = 0i64;
  if ( v51 )
  {
    v17 = &v3->TmpEdgeFan.pHeap;
    do
    {
      v18 = v16;
      v19 = v16 & 0xF;
      v20 = v19;
      v21 = 0i64;
      v22 = v3->MeshVertices.Pages[v18 >> 4];
      v3->TmpEdgeFan.Size = 0i64;
      if ( v22[v19].Mesh > 0u )
      {
        do
        {
          v23 = v3->MeshVertices.Pages;
          v24 = v3->EdgeFans.Array;
          v25 = v24[v21 + v22[v20].Idx].cntVer;
          v50 = v24[v21 + v22[v20].Idx].rayVer;
          HIDWORD(v47) = v24[v21 + v22[v20].Idx].style;
          v49 = v24[v21 + v22[v20].Idx].cntVer;
          v26 = v23[(unsigned __int64)(v24[v21 + v22[v20].Idx].rayVer->srcVer & 0xFFFFFFF) >> 4];
          v27 = v23[(unsigned __int64)(v25->srcVer & 0xFFFFFFF) >> 4];
          v28 = v26[v24[v21 + v22[v20].Idx].rayVer->srcVer & 0xF].x - v27[v25->srcVer & 0xF].x;
          v29 = v26[v24[v21 + v22[v20].Idx].rayVer->srcVer & 0xF].y - v27[v25->srcVer & 0xF].y;
          v30 = (float)((float)(v29 * v29) + (float)(v28 * v28)) * 2.0;
          if ( v30 == 0.0 )
          {
            v31 = 0.0;
          }
          else
          {
            v32 = (float)(v28 * v28) / v30;
            if ( v28 < 0.0 )
              LODWORD(v32) ^= _xmm[0];
            if ( v29 > 0.0 )
              v32 = 1.0 - v32;
            v31 = v32 - 0.5;
          }
          *(float *)&v47 = v31;
          v33 = v3->TmpEdgeFan.Size >> 3;
          if ( v33 >= v3->TmpEdgeFan.NumPages )
          {
            v34 = v3->TmpEdgeFan.MaxPages;
            if ( v33 >= v34 )
            {
              v35 = *v17;
              if ( v3->TmpEdgeFan.Pages )
              {
                v36 = Scaleform::Render::LinearHeap::Alloc(v35, 16 * v34);
                memmove(v36, v3->TmpEdgeFan.Pages, 8 * v3->TmpEdgeFan.NumPages);
                v37 = v3->TmpEdgeFan.MaxPages;
                v3->TmpEdgeFan.Pages = (Scaleform::Render::Tessellator::TmpEdgeAAType **)v36;
                v25 = v49;
                v3->TmpEdgeFan.MaxPages = 2 * v37;
              }
              else
              {
                v3->TmpEdgeFan.MaxPages = 4i64;
                v3->TmpEdgeFan.Pages = (Scaleform::Render::Tessellator::TmpEdgeAAType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                           v35,
                                                                                           0x20ui64);
              }
            }
            v3->TmpEdgeFan.Pages[v33] = (Scaleform::Render::Tessellator::TmpEdgeAAType *)Scaleform::Render::LinearHeap::Alloc(
                                                                                           *v17,
                                                                                           0xC0ui64);
            ++v3->TmpEdgeFan.NumPages;
          }
          ++v21;
          v38 = v3->TmpEdgeFan.Pages[v33];
          v39 = v3->TmpEdgeFan.Size & 7;
          v38[v39].cntVer = v25;
          v38[v39].rayVer = v50;
          *(_QWORD *)&v38[v39].slope = v47;
          ++v3->TmpEdgeFan.Size;
        }
        while ( v21 < v22[v20].Mesh );
      }
      Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4>,bool (*)(Scaleform::Render::Tessellator::TmpEdgeAAType const &,Scaleform::Render::Tessellator::TmpEdgeAAType const &)>(
        &v3->TmpEdgeFan,
        0i64,
        v3->TmpEdgeFan.Size,
        Scaleform::Render::Tessellator::cmpEdgeAA);
      v40 = 0i64;
      v41 = 0;
      for ( l = FLOAT_N1_0e30; v40 < v3->TmpEdgeFan.Size; ++v40 )
      {
        v43 = v3->EdgeFans.Array;
        v44 = v40 + v22[v20].Idx;
        v45 = v3->TmpEdgeFan.Pages[v40 >> 3];
        v43[v44].cntVer = v45[v40 & 7].cntVer;
        v43[v44].rayVer = v45[v40 & 7].rayVer;
        v46 = v45[v40 & 7].style;
        v43[v44].slope = v41;
        v43[v44].style = v46;
        if ( v45[v40 & 7].slope != l )
        {
          ++v41;
          l = v45[v40 & 7].slope;
        }
      }
      Scaleform::Render::Tessellator::processFan(v3, v22[v20].Idx, v22[v20].Idx + v22[v20].Mesh);
      v22[v20].Idx = -1;
      v22[v20].Mesh = -1;
      v16 = v48 + 1;
      v48 = v16;
    }
    while ( v16 < v51 );
  }
  if ( v3->Monotones.Size > 0 )
  {
    do
    {
      Scaleform::Render::Tessellator::triangulateMonotoneAA(v3, &v3->Monotones.Pages[v1 >> 4][v1 & 0xF]);
      ++v1;
    }
    while ( v1 < v3->Monotones.Size );
  }
  Scaleform::Render::Tessellator::unflipTriangles(v3);
  Scaleform::Render::Tessellator::emitTriangles(v3);
}

// File Line: 3832
// RVA: 0x9B8C50
void __fastcall Scaleform::Render::Tessellator::Tessellate(Scaleform::Render::Tessellator *this, bool autoSplitMeshes)
{
  bool v2; // r14
  Scaleform::Render::Tessellator *v3; // rdi
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbp
  Scaleform::Render::TessMesh *v6; // rcx
  signed __int64 v7; // rdx
  Scaleform::Render::LinearHeap *v8; // rcx
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // rbx
  unsigned __int16 *v11; // rax
  unsigned __int64 i; // rbx
  signed __int64 v13; // r8
  unsigned int v14; // edx
  unsigned int v15; // er8
  unsigned __int64 j; // rbp
  signed __int64 v17; // rbx
  unsigned int v18; // edx
  unsigned int v19; // edx
  unsigned __int64 k; // rbx
  unsigned __int64 v21; // rbx
  unsigned __int64 l; // rbx
  Scaleform::Render::TessVertex *v23; // r9
  unsigned __int16 v24; // ax
  signed __int64 v25; // rdx
  Scaleform::Render::TessMesh *v26; // rcx
  unsigned __int64 v27; // rax

  v2 = autoSplitMeshes;
  v3 = this;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  Scaleform::Render::Tessellator::monotonize(this);
  v4 = 0i64;
  v5 = v3->Meshes.Size >> 4;
  if ( v5 >= v3->Meshes.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::allocPage(&v3->Meshes, v3->Meshes.Size >> 4);
  v6 = v3->Meshes.Pages[v5];
  v7 = v3->Meshes.Size & 0xF;
  *(_QWORD *)&v6[v7].MeshIdx = 0i64;
  *(_QWORD *)&v6[v7].Style2 = 0i64;
  *(_QWORD *)&v6[v7].Flags2 = 0i64;
  v6[v7].VertexCount = 0;
  ++v3->Meshes.Size;
  if ( v3->HasComplexFill )
  {
    v8 = v3->StyleMatrix.pHeap;
    v9 = v3->MaxStyle + 1;
    v3->StyleMatrix.Size = v9;
    v10 = 2 * v9 * v9;
    v11 = (unsigned __int16 *)Scaleform::Render::LinearHeap::Alloc(v8, v10);
    v3->StyleMatrix.Array = v11;
    memset(v11, 255, v10);
    for ( i = 0i64; i < v3->Paths.Size; ++i )
    {
      v13 = (signed __int64)&v3->Paths.Pages[i >> 4][i & 0xF];
      v14 = *(_DWORD *)(v13 + 8);
      if ( v14 )
      {
        v15 = *(_DWORD *)(v13 + 12);
        if ( v15 )
          Scaleform::Render::Tessellator::setMesh(v3, v14, v15);
      }
    }
    for ( j = 0i64; j < v3->Paths.Size; ++j )
    {
      v17 = (signed __int64)&v3->Paths.Pages[j >> 4][j & 0xF];
      v18 = *(_DWORD *)(v17 + 8);
      if ( v18 )
        Scaleform::Render::Tessellator::setMesh(v3, v18);
      v19 = *(_DWORD *)(v17 + 12);
      if ( v19 )
        Scaleform::Render::Tessellator::setMesh(v3, v19);
    }
  }
  Scaleform::Render::Tessellator::clearHeap1(v3);
  for ( k = 0i64; k < v3->Meshes.Size; ++k )
    Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(&v3->MeshTriangles);
  if ( v3->EdgeAAFlag )
  {
    if ( v3->StrokerMode )
    {
      Scaleform::Render::Tessellator::setMesh(v3, 1u);
      v21 = 0i64;
      for ( v3->EdgeAAFlag = 0; v21 < v3->Monotones.Size; ++v21 )
        Scaleform::Render::Tessellator::triangulateMonotoneAA(v3, &v3->Monotones.Pages[v21 >> 4][v21 & 0xF]);
      v3->EdgeAAFlag = 1;
      Scaleform::Render::Tessellator::processStrokerEdges(v3);
    }
    else
    {
      Scaleform::Render::Tessellator::processEdgeAA(v3);
    }
  }
  else
  {
    for ( l = 0i64; l < v3->Monotones.Size; ++l )
      Scaleform::Render::Tessellator::triangulateMonotoneAA(v3, &v3->Monotones.Pages[l >> 4][l & 0xF]);
  }
  if ( v3->MeshVertices.Size > 0 )
  {
    do
    {
      v23 = v3->MeshVertices.Pages[v4 >> 4];
      v24 = v23[v4 & 0xF].Mesh;
      if ( v24 != -1 )
      {
        v25 = v24 & 0xF;
        v26 = v3->Meshes.Pages[(unsigned __int64)v24 >> 4];
        v23[v4 & 0xF].Idx = v26[v25].VertexCount++;
      }
      ++v4;
    }
    while ( v4 < v3->MeshVertices.Size );
  }
  if ( v2 )
  {
    v27 = v3->VertexLimit;
    if ( (_DWORD)v27 )
    {
      if ( v3->MeshVertices.Size > v27 )
        Scaleform::Render::Tessellator::SplitMeshes(v3);
    }
  }
}

// File Line: 4085
// RVA: 0x9BA8A0
void __fastcall Scaleform::Render::Tessellator::Transform(Scaleform::Render::Tessellator *this, Scaleform::Render::Matrix2x4<float> *m)
{
  unsigned __int64 v2; // r10
  signed __int64 v3; // r9
  Scaleform::Render::TessVertex *v4; // rax
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4

  v2 = 0i64;
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  if ( this->MeshVertices.Size )
  {
    do
    {
      v3 = v2 & 0xF;
      v4 = this->MeshVertices.Pages[v2 >> 4];
      v5 = v4[v2 & 0xF].x;
      v6 = v4[v2 & 0xF].y;
      v4[v3].x = (float)((float)(v4[v2 & 0xF].x * m->M[0][0]) + (float)(v4[v2 & 0xF].y * m->M[0][1])) + m->M[0][3];
      v4[v3].y = (float)((float)(v6 * m->M[1][1]) + (float)(v5 * m->M[1][0])) + m->M[1][3];
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
      ++v2;
    }
    while ( v2 < this->MeshVertices.Size );
  }
}

// File Line: 4105
// RVA: 0x9B8220
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::Tessellator::StretchTo(Scaleform::Render::Tessellator *this, Scaleform::Render::Matrix2x4<float> *result, float x1, float y1, float x2, float y2)
{
  unsigned __int64 v6; // rsi
  int v7; // xmm8_4
  float v8; // xmm9_4
  Scaleform::Render::Matrix2x4<float> *v9; // rbx
  Scaleform::Render::Tessellator *v10; // rdi
  unsigned __int64 v11; // r9
  unsigned __int64 v12; // r8
  float v13; // xmm4_4
  Scaleform::Render::TessVertex **v14; // r10
  float v15; // xmm7_4
  float v16; // xmm5_4
  float v17; // xmm6_4
  Scaleform::Render::TessVertex *v18; // rax
  float v19; // xmm3_4
  int v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  int v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  signed __int64 v27; // rax
  unsigned __int64 v28; // rdx
  signed __int64 v29; // r8
  Scaleform::Render::TessVertex *v30; // rax
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  int v34; // xmm0_4
  int v35; // xmm1_4
  int v36; // xmm0_4
  int v37; // xmm1_4
  int v38; // xmm0_4
  int v39; // xmm1_4
  float dst; // [rsp+20h] [rbp-39h]
  int v42; // [rsp+24h] [rbp-35h]
  float v43; // [rsp+28h] [rbp-31h]
  int v44; // [rsp+2Ch] [rbp-2Dh]
  float v45; // [rsp+30h] [rbp-29h]
  float v46; // [rsp+34h] [rbp-25h]
  float src; // [rsp+40h] [rbp-19h]
  float v48; // [rsp+44h] [rbp-15h]
  int v49; // [rsp+48h] [rbp-11h]
  float v50; // [rsp+4Ch] [rbp-Dh]
  int v51; // [rsp+50h] [rbp-9h]
  float v52; // [rsp+54h] [rbp-5h]
  int v53; // [rsp+58h] [rbp-1h]
  int v54; // [rsp+5Ch] [rbp+3h]

  v6 = 0i64;
  *(_QWORD *)&result->M[0][0] = 1065353216i64;
  *(_QWORD *)&result->M[1][1] = 1065353216i64;
  *(_QWORD *)&result->M[0][2] = 0i64;
  result->M[1][0] = 0.0;
  result->M[1][3] = 0.0;
  v7 = LODWORD(y1);
  v8 = x1;
  v9 = result;
  v10 = this;
  if ( this->MaxX <= this->MinX || this->MaxY <= this->MinY )
  {
    v11 = this->MeshVertices.Size;
    this->MinX = 1.0e30;
    this->MinY = 1.0e30;
    this->MaxX = -1.0e30;
    this->MaxY = -1.0e30;
    v12 = 0i64;
    if ( v11 )
    {
      v13 = FLOAT_N1_0e30;
      v14 = this->MeshVertices.Pages;
      v15 = FLOAT_1_0e30;
      v16 = FLOAT_N1_0e30;
      v17 = FLOAT_1_0e30;
      do
      {
        v18 = v14[v12 >> 4];
        v19 = v18[v12 & 0xF].x;
        v20 = *(_DWORD *)v18[v12 & 0xF].Styles;
        v21 = v18[v12 & 0xF].y;
        v43 = *(float *)&v18[v12 & 0xF].Idx;
        v22 = *(float *)&v18[v12 & 0xF].Flags;
        v44 = v20;
        v45 = v22;
        if ( v19 < v15 )
        {
          this->MinX = v19;
          v15 = v19;
        }
        if ( v21 < v17 )
        {
          this->MinY = v21;
          v17 = v21;
        }
        if ( v19 > v13 )
        {
          this->MaxX = v19;
          v13 = v19;
        }
        if ( v21 > v16 )
        {
          this->MaxY = v21;
          v16 = v21;
        }
        ++v12;
      }
      while ( v12 < v11 );
    }
  }
  v23 = this->MinX;
  v24 = SLODWORD(this->MaxX);
  if ( v23 < *(float *)&v24 )
  {
    v25 = this->MinY;
    v26 = this->MaxY;
    if ( v25 < v26 )
    {
      v48 = this->MinY;
      v50 = v25;
      v43 = x2;
      v45 = x2;
      v46 = y2;
      src = v23;
      v49 = v24;
      v51 = v24;
      v52 = v26;
      dst = v8;
      v42 = v7;
      v44 = v7;
      Scaleform::Render::Matrix2x4<float>::SetParlToParl(result, &src, &dst);
      if ( v10->MeshVertices.Size > 0 )
      {
        do
        {
          v27 = v6 & 0xF;
          v28 = v6++ >> 4;
          v29 = v27;
          v30 = v10->MeshVertices.Pages[v28];
          v31 = v30[v29].x;
          v32 = v30[v29].y;
          v30[v29].x = (float)((float)(v30[v29].x * v9->M[0][0]) + (float)(v30[v29].y * v9->M[0][1])) + v9->M[0][3];
          v30[v29].y = (float)((float)(v31 * v9->M[1][0]) + (float)(v32 * v9->M[1][1])) + v9->M[1][3];
        }
        while ( v6 < v10->MeshVertices.Size );
      }
      v33 = v9->M[0][1];
      src = v9->M[0][0];
      v34 = LODWORD(v9->M[0][2]);
      v48 = v33;
      v35 = LODWORD(v9->M[0][3]);
      v49 = v34;
      v36 = LODWORD(v9->M[1][0]);
      v50 = *(float *)&v35;
      v37 = LODWORD(v9->M[1][1]);
      v51 = v36;
      v38 = LODWORD(v9->M[1][2]);
      v52 = *(float *)&v37;
      v39 = LODWORD(v9->M[1][3]);
      v53 = v38;
      v54 = v39;
      Scaleform::Render::Matrix2x4<float>::SetInverse(v9, (Scaleform::Render::Matrix2x4<float> *)&src);
    }
  }
  return v9;
}

