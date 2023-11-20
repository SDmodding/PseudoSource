// File Line: 11
// RVA: 0xC545B0
void __fastcall hkMatrixDecompositionImpl<float>::decompose4x4ColTransform(const float *matrixIn, hkMatrixDecompositionImpl<float>::Decomposition *decompOut)
{
  hkMatrixDecompositionImpl<float>::Decomposition *v2; // rbx
  hkMatrix4f matrixIna; // [rsp+20h] [rbp-48h]

  v2 = decompOut;
  hkMatrix4f::set4x4ColumnMajor(&matrixIna, matrixIn);
  hkMatrixDecompositionImpl<float>::decomposeMatrix(&matrixIna, v2);
}

