// File Line: 79
// RVA: 0xA3F3B0
__int64 __fastcall fbxsdk_2014_1::FbxMesh::GetPolygonSize(fbxsdk_2014_1::FbxMesh *this, int pPolygonIndex)
{
  if ( pPolygonIndex < 0 || pPolygonIndex >= this->mPolygons.mSize )
    return 0xFFFFFFFFi64;
  else
    return (unsigned int)this->mPolygons.mArray[pPolygonIndex].mSize;
}

// File Line: 105
// RVA: 0xA3F3E0
__int64 __fastcall fbxsdk_2014_1::FbxMesh::GetPolygonVertex(
        fbxsdk_2014_1::FbxMesh *this,
        int pPolygonIndex,
        int pPositionInPolygon)
{
  __int64 v3; // rdx
  fbxsdk_2014_1::FbxMesh::PolygonDef *mArray; // rax

  if ( pPolygonIndex < 0 )
    return 0xFFFFFFFFi64;
  if ( pPolygonIndex >= this->mPolygons.mSize )
    return 0xFFFFFFFFi64;
  if ( pPositionInPolygon < 0 )
    return 0xFFFFFFFFi64;
  v3 = pPolygonIndex;
  mArray = this->mPolygons.mArray;
  if ( pPositionInPolygon >= mArray[v3].mSize )
    return 0xFFFFFFFFi64;
  else
    return (unsigned int)this->mPolygonVertices.mArray[pPositionInPolygon + (__int64)mArray[v3].mIndex];
}

