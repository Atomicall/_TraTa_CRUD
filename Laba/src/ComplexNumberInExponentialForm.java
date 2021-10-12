public class ComplexNumberInExponentialForm extends  AbstractComplexNumber{

    private float mod;
    private float phase;

    @Override
    void Add(ExponentialFormStorage n) {


    }

    @Override
    void Sub(ExponentialFormStorage n) {


    }

    @Override
    void Mul(ExponentialFormStorage n) {

    }

    @Override
    void Div(ExponentialFormStorage n) {


    }

    AlgebraicFormStorage getInAlgebraicForm(){
        AlgebraicFormStorage result = new AlgebraicFormStorage();
        result.fromExp(mod, phase);
        return result;
    }
}
