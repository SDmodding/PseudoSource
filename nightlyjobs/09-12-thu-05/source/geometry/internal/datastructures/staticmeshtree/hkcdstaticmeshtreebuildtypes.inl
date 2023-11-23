// File Line: 50
// RVA: 0xDF3DD0
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>::getNumVertices(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *this)
{
  return (*(__int64 (__fastcall **)(hkpBvCompressedMeshShapeCinfo *))this->m_provider->m_meshCInfo->vfptr->gap8)(this->m_provider->m_meshCInfo);
}

// File Line: 52
// RVA: 0xDF4640
void __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider>::getVertex(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::BuildGeometryProvider<hkpBvCompressedMeshShape_Internals::GeometryProvider> *this,
        __int64 vi,
        hkVector4f *vertexOut)
{
  this->m_provider->m_meshCInfo->vfptr->getVertex(this->m_provider->m_meshCInfo, vi, vertexOut);
}

