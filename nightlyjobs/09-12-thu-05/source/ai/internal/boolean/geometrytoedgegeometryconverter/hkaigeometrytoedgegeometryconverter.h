// File Line: 84
// RVA: 0xB9D770
bool __fastcall hkaiGeometryToEdgeGeometryConverter::_orderTriangles(
        hkaiGeometryToEdgeGeometryConverter::TriangleArea *a,
        hkaiGeometryToEdgeGeometryConverter::TriangleArea *b)
{
  return b->m_area < a->m_area;
}

