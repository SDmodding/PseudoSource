// File Line: 79
// RVA: 0xA3F3B0
signed __int64 __fastcall fbxsdk_2014_1::FbxMesh::GetPolygonSize(fbxsdk_2014_1::FbxMesh *this, int pPolygonIndex)
{
  signed __int64 result; // rax

  if ( pPolygonIndex < 0 || pPolygonIndex >= this->mPolygons.mSize )
    result = 0xFFFFFFFFi64;
  else
    result = (unsigned int)this->mPolygons.mArray[pPolygonIndex].mSize;
  return result;
}

// File Line: 105
// RVA: 0xA3F3E0
signed __int64 __fastcall fbxsdk_2014_1::FbxMesh::GetPolygonVertex(fbxsdk_2014_1::FbxMesh *this, int pPolygonIndex, int pPositionInPolygon)
{
  signed __int64 v3; // rdx
  fbxsdk_2014_1::FbxMesh::PolygonDef *v4; // rax
  signed __int64 result; // rax

  if ( pPolygonIndex < 0
    || pPolygonIndex >= this->mPolygons.mSize
    || pPositionInPolygon < 0
    || (v3 = pPolygonIndex, v4 = this->mPolygons.mArray, pPositionInPolygon >= v4[v3].mSize) )
  {
    result = 0xFFFFFFFFi64;
  }
  else
  {
    result = (unsigned int)this->mPolygonVertices.mArray[pPositionInPolygon + (signed __int64)v4[v3].mIndex];
  }
  return result;
}

