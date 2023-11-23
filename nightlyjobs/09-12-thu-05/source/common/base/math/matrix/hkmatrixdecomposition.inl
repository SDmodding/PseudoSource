// File Line: 11
// RVA: 0xC545B0
void __fastcall hkMatrixDecompositionImpl<float>::decompose4x4ColTransform(
        const float *matrixIn,
        hkMatrixDecompositionImpl<float>::Decomposition *decompOut)
{
  hkMatrix4f matrixIna; // [rsp+20h] [rbp-48h] BYREF

  hkMatrix4f::set4x4ColumnMajor(&matrixIna, matrixIn);
  hkMatrixDecompositionImpl<float>::decomposeMatrix(&matrixIna, decompOut);
}

