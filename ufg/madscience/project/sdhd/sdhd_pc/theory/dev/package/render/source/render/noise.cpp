// File Line: 51
// RVA: 0x48A30
void NoiseManager::Init(void)
{
  _DWORD *v0; // rax
  signed __int64 v1; // rdx
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx

  v0 = 0i64;
  v1 = 64i64;
  do
  {
    v2 = v0[1350601732];
    v0 += 4;
    v0[1350882856] = v2;
    v0[1350883112] = v2;
    v3 = v0[1350601729];
    v0[1350882857] = v3;
    v0[1350883113] = v3;
    v4 = v0[1350601730];
    v0[1350882858] = v4;
    v0[1350883114] = v4;
    v5 = v0[1350601731];
    v0[1350882859] = v5;
    v0[1350883115] = v5;
    --v1;
  }
  while ( v1 );
}

