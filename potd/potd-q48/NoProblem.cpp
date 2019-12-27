
vector<string> NoProblem(int start, vector<int> created, vector<int> needed) {

    // your code here
	std::vector<string> answer;
	for(unsigned i=0;i<created.size();i++){
		if(start>=needed[i]){
			answer.push_back("No problem! :D");
			start-=needed[i];
		}
		else{
			answer.push_back("No problem. :(");
		}
		start+=created[i];
	}
	return answer;
}
