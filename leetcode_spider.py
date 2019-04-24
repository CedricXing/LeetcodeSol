import urllib.request
import json
import http.cookiejar
import socket

class Extractor:
    def __init__(self):
        self.base_url = 'https://leetcode.com'
        cj = http.cookiejar.CookieJar()
        self.opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cj))
        self.opener.addheaders = [('Host','leetcode.com'),('User-Agent','Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36')]

    def get_problem_list(self):
        with self.opener.open(self.base_url + '/api/problems/algorithms/') as f:
            content = f.read().decode('utf-8')
        content = json.loads(content)
        return content['stat_status_pairs']

    def get_question_detail(self, title_slug):
        QUERY = '''query questionData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionId
    questionFrontendId
    boundTopicId
    title
    titleSlug
    content
    translatedTitle
    translatedContent
    isPaidOnly
    difficulty
    likes
    dislikes
    isLiked
    similarQuestions
    contributors{
        username
        profileUrl
        avatarUrl
        __typename
    }
    langToValidPlayground
    topicTags{
        name
        slug
        translatedName
        __typename
    }
    companyTagStats
    codeSnippets{
        lang
        langSlug
        code
        __typename
    }
    stats
    hints
    solution{
        id
        canSeeDetail
        __typename
    }
    status
    sampleTestCase
    metaData
    judgerAvailable
    judgeType
    mysqlSchemas
    enableRunCode
    enableTestMode
    envInfo
    __typename
    }
}'''
        params = {
            'query': QUERY,
            'operationName': 'questionData',
            'variables': json.dumps({
                'titleSlug': title_slug
            })
        }
        url = self.base_url + '/graphql' + '?' + urllib.parse.urlencode(params, quote_via=urllib.parse.quote).replace(
            '%28', '(').replace('%29', ')').replace('%21', '!')
        while True:
            try:
                with self.opener.open(url,timeout=20) as f:
                    content = f.read().decode('utf-8')
                    content=json.loads(content)
                    return content['data']['question']
            except socket.timeout:
                print('time out, try again')

class Problem:
    originTitle = ''
    title = ''
    likes = 0
    questionId = ''
    difficulty = ''

    def __init__(self,originTitle,title,likes,questionId,difficulty):
        self.originTitle = originTitle
        self.title = title
        self.likes = likes
        self.questionId = questionId
        self.difficulty = difficulty

def main():
    extractor = Extractor()
    problem_list = extractor.get_problem_list()
    f = open('readme.md','w')
    f1 = open('backup.txt','w')
    problems = []
    try:
        for problem in problem_list:
            originTitle = problem['stat']['question__title']
            title = originTitle.lower().replace(' ','-')
            result = extractor.get_question_detail(title)
            if result == None:
                continue
            print(result['questionFrontendId'] + ' : ' + str(result['likes']))
            f1.write(result['questionFrontendId'] + ' ' + originTitle + ' ' + title + ' ' + str(result['likes']) + ' ' + result['difficulty'] + '\n')
            problems.append(Problem(originTitle,title,result['likes'],result['questionFrontendId'],result['difficulty']))
    finally:
        f1.close()
    problems.sort(key=lambda x:x.likes,reverse=True)
    for p in problems:
        f.write('|' + p.questionId + '|[' + p.originTitle + '](https://leetcode.com/problems/' + p.title + '/)|[C++]()|' + p.difficulty + '|' + str(p.likes) + '|')
        f.write('\n')
    f.close()

if __name__ == '__main__':
    main()