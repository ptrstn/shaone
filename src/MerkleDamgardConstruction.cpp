#include "Stage.h"
#include "MerkleDamgardConstruction.h"

SHA1_Hash MerkleDamgardConstruction::round(SHA1_Hash input, Word word_j ) {
    SHA1_Hash output = mCurrentHash;
    if(mRoundCounter >= 0 && mRoundCounter < 20){
        output.A = Stage<1>::f(input.B, input.C, input.D);
        output.A += Stage<1>::constant;
    } else if(mRoundCounter >= 20 && mRoundCounter < 40){
        output.A = Stage<2>::f(input.B, input.C, input.D);
        output.A += Stage<2>::constant;
    } else if(mRoundCounter >= 40 && mRoundCounter < 60){
        output.A = Stage<3>::f(input.B, input.C, input.D);
        output.A += Stage<3>::constant;
    } else if(mRoundCounter >= 60 && mRoundCounter < 80){
        output.A = Stage<4>::f(input.B, input.C, input.D);
        output.A += Stage<4>::constant;
    }
    output.A += input.E;
    output.A += input.A.rotateLeft(5);
    output.A += word_j;
    output.B = input.A;
    output.C = input.B.rotateLeft(30);
    output.D = input.C;
    output.E = input.D;

    return mCurrentHash = output;
}