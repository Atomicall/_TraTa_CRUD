public class ComplexNumberInAlgebraicForm extends AbstractComplexNumber {
    public static float real = 0;
    public static float im = 0;

    @Override
    AlgebraicFormStorage Add(AlgebraicFormStorage n) {
        AlgebraicFormStorage result = new AlgebraicFormStorage();
        result.real = this.real + n.real;
        result.im = this.im + n.im;
        return result;
    }

    @Override
    AlgebraicFormStorage Sub(AlgebraicFormStorage n) {
        AlgebraicFormStorage result = new AlgebraicFormStorage();
        result.real = this.real - n.real;
        result.im = this.im - n.im;
        return result;
    }

    @Override
    AlgebraicFormStorage Mul(AlgebraicFormStorage n) {
        AlgebraicFormStorage result = new AlgebraicFormStorage();
        result.real = this.real * n.real - this.im * n.im;
        result.im = this.real * n.real + this.im * n.im;
        return result;
    }

    @Override
    AlgebraicFormStorage Div(AlgebraicFormStorage n) {
        AlgebraicFormStorage result = new AlgebraicFormStorage(n.real, n.im);
        this.im = (-1)*this.im;
        result = this.Mul(result);

        /*ComplexNumber temp = new ComplexNumber(cn2.getRe(), (-1)* cn2.getIm());
        temp = ComplexNumber.multiply(cn1, temp);
        double denominator = cn2.getRe()*cn2.getRe() + cn2.getIm() * cn2.getIm();
        return new ComplexNumber(temp.getRe()/denominator, temp.getIm()/denominator);*/
    return null;
    }

    ExponentialFormStorage getInComplexForm() {
        ExponentialFormStorage result = new ExponentialFormStorage();
        result.fromAlg(real, im);
        return result;
    }


}
