bool isValidParenthesis(string expression)
{
    stack<int> s;
    for(int i=0; i<expression.size(); i++)
    {
        char curr = expression[i];
        if(curr=='{' or curr=='(' or curr=='[')
            s.push(curr);
        else
        {
            if(s.empty())
                return false;
            char prev = s.top();
            if(curr=='}')
            {
                if(prev=='{')
                    s.pop();
                else
                    return false;
            }
            else if(curr==')')
            {
                if(prev=='(')
                    s.pop();
                else
                    return false;
            }
            else if(curr==']')
            {
                if(prev=='[')
                    s.pop();
                else
                    return false;
            }
        }
    }
    return s.empty();
}
