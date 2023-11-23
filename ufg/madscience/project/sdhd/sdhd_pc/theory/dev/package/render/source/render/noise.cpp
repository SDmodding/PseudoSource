// File Line: 51
// RVA: 0x48A30
void NoiseManager::Init(void)
{
  __int64 v0; // rax
  __int64 v1; // rdx
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx

  v0 = 0i64;
  v1 = 64i64;
  do
  {
    v2 = permutation[v0];
    v0 += 4i64;
    LODWORD(UFG::ColourCubeMgr::mActiveColourCubes.mWeight[v0 + 3]) = v2;
    p[v0 + 252] = v2;
    v3 = *(_DWORD *)&algn_142023004[v0 * 4];
    *(_DWORD *)&algn_1421358A4[v0 * 4] = v3;
    p[v0 + 253] = v3;
    v4 = *(_DWORD *)&algn_142023004[v0 * 4 + 4];
    *(_DWORD *)&algn_1421358A4[v0 * 4 + 4] = v4;
    p[v0 + 254] = v4;
    v5 = *(_DWORD *)&algn_142023004[v0 * 4 + 8];
    *(_DWORD *)&algn_1421358A4[v0 * 4 + 8] = v5;
    p[v0 + 255] = v5;
    --v1;
  }
  while ( v1 );
}

